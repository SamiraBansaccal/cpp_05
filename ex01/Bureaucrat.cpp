/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 22:59:42 by sbansacc          #+#    #+#             */
/*   Updated: 2025/12/12 19:22:41 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

void		Bureaucrat::signForm(Form &form) {
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << " form" << std::endl;
	} catch (std::exception& exception) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << exception.what() << std::endl;
	}
}

