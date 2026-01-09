/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:24:02 by sbansacc          #+#    #+#             */
/*   Updated: 2025/12/10 22:57:32 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat();

		Bureaucrat& operator=(Bureaucrat const &assignement);

		std::string	getName() const;
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
	private:
		const std::string	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream &out, Bureaucrat const &src);

#endif
