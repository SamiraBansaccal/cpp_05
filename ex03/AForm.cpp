/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 01:37:56 by sbansacc          #+#    #+#             */
/*   Updated: 2025/12/18 21:41:01 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/AForm.hpp"

AForm::AForm(): _name("Default"), _isSigned(false), _signGrade(150), _execGrade(150) {}

AForm::AForm(std::string const &name, int signGrade, int execGrade): _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm const &copy): _name(copy._name), _isSigned(copy._isSigned), _signGrade(copy._signGrade), _execGrade(copy._execGrade) {}

AForm::~AForm() {}

AForm& AForm::operator=(AForm const &assignment) {
	if (this != &assignment)
		_isSigned = assignment._isSigned;
	return (*this);
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade Too High");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade Too Low");
}

const char* AForm::notSignedException::what() const throw() {
	return ("Form Not Signed");
}

void	AForm::beSigned(Bureaucrat const &signer) {
	if (signer.getGrade() <= _signGrade)
	_isSigned = true;
	else
		throw GradeTooLowException();
}

void	AForm::execute(Bureaucrat const &executor) const {
	if (!isSigned())
		throw notSignedException();
	if (_execGrade < executor.getGrade())
		throw GradeTooLowException();
	formAction();
}


std::string	AForm::getName() const { return (_name); }

bool	AForm::isSigned() const { return (_isSigned); }

int	AForm::getSignGrade() const { return (_signGrade); }

int	AForm::getExecGrade() const { return (_execGrade); }

std::ostream& operator<<(std::ostream& out, AForm const &src) {
	out << "AForm " << src.getName() << " -- sign grade is " << src.getSignGrade() << " -- execution grade is " << src.getExecGrade() << " -- is signed:";
	if (src.isSigned())
		out << " yes.";
	else
		out << " no.";
	return (out);
}