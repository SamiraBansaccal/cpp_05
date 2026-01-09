/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 01:37:58 by sbansacc          #+#    #+#             */
/*   Updated: 2025/12/19 01:03:14 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		AForm();
		AForm(std::string const &name, int signGrade, int execGrade);
		AForm(AForm const &copy);
		virtual ~AForm();
	
		AForm& operator=(AForm const &assignment);

		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw(); 
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class notSignedException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		virtual void	formAction() const = 0;

		void		execute(Bureaucrat const &executor) const;
		void		beSigned(Bureaucrat const &signer);
		std::string	getName() const;
		bool		isSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
};

std::ostream& operator<<(std::ostream& out, AForm const &src);

#endif