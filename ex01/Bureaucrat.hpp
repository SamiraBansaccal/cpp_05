/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 22:59:36 by sbansacc          #+#    #+#             */
/*   Updated: 2025/12/12 19:21:09 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat();

		Bureaucrat& operator=(Bureaucrat const &assignement);

		std::string			getName() const;
		int					getGrade() const;

		class	GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class	GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		void	incrementGrade();
		void	decrementGrade();
		void	signForm(Form &form);
	private:
		const std::string	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream &out, Bureaucrat const &src);

#endif