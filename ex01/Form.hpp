/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 23:00:00 by sbansacc          #+#    #+#             */
/*   Updated: 2025/12/12 19:20:40 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form();
		Form(std::string const &name, int signGrade, int execGrade);
		Form(Form const &copy);
		~Form();
	
		Form& operator=(Form const &assignment);

		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw(); 
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

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

std::ostream& operator<<(std::ostream& out, Form const &src);

#endif