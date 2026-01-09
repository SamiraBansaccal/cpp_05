/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 01:39:19 by sbansacc          #+#    #+#             */
/*   Updated: 2025/12/18 20:35:30 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string const &name, int grade):  _name(name), _grade(grade) {
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy): _name(copy._name), _grade(copy._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &assignement) {
	if (this != &assignement)
		_grade = assignement.getGrade();
	return (*this);
}

std::string	Bureaucrat::getName() const { return (_name); }

int	Bureaucrat::getGrade() const { return (_grade); }

void	Bureaucrat::incrementGrade() {
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade() {
		if (_grade + 1 > 150)
			throw GradeTooLowException();
		_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

std::ostream& operator<<(std::ostream &out, Bureaucrat const &src) {
	out << src.getName() << ", bureaucrat grade " << src.getGrade();
	return (out);
}

void	Bureaucrat::signForm(AForm &form) {
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << " form" << std::endl;
	} catch (std::exception& exception) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << exception.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form) {
		try
		{
			form.execute(*this);
			std::cout << _name << " executed " << form.getName() << " form" << std::endl;
		} catch (std::exception& e) {
			std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
		}
}
