/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 22:10:25 by sbansacc          #+#    #+#             */
/*   Updated: 2025/12/19 01:07:44 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Intern.hpp"

Intern::Intern() {}
Intern::Intern(Intern const &copy) { (void) copy; }
Intern::~Intern() {}

Intern& Intern::operator=(Intern const &assignment) {
	(void) assignment;
	return (*this);
}
AForm* Intern::makeForm(std::string const &formName, std::string const &target) {
	std::string possibleNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i = 0;
	while (i < 3 && formName != possibleNames[i])
		i++;
	if (i < 3)
		std::cout << "Intern creates " << formName << std::endl;
	switch(i) {
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));
		default:
			std::cout << "Intern could not create " << formName << " because Form name does not exist, sorry loser." << std::endl;
			return (NULL);
	}
}