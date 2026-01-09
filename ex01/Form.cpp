/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 23:00:03 by sbansacc          #+#    #+#             */
/*   Updated: 2025/12/16 01:50:12 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("Default"), _isSigned(false), _signGrade(150), _execGrade(150) {}

Form::Form(std::string const &name, int signGrade, int execGrade): _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

Form::Form(Form const &copy): _name(copy._name), _isSigned(copy._isSigned), _signGrade(copy._signGrade), _execGrade(copy._execGrade) {}

Form::~Form() {}

Form& Form::operator=(Form const &assignment) {
	if (this != &assignment)
		_isSigned = assignment._isSigned;
	return (*this);
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade Too High");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade Too Low");
}

void		Form::beSigned(Bureaucrat const &signer) {
	if (signer.getGrade() <= _signGrade)
	_isSigned = true;
	else
		throw GradeTooLowException();
}

std::string	Form::getName() const { return (_name); }

bool	Form::isSigned() const { return (_isSigned); }

int	Form::getSignGrade() const { return (_signGrade); }

int	Form::getExecGrade() const { return (_execGrade); }

std::ostream& operator<<(std::ostream& out, Form const &src) {
	out << "Form " << src.getName() << " -- sign grade is " << src.getSignGrade() << " -- execution grade is " << src.getExecGrade() << " -- is signed:";
	if (src.isSigned())
		out << " yes.";
	else
		out << " no.";
	return (out);
}
