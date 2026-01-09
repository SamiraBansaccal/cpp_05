/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:58:16 by sbansacc          #+#    #+#             */
/*   Updated: 2025/12/18 22:04:37 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy Request", 72, 45), _target("Default target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm("Robotomy Request", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy): AForm(copy), _target(copy._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &assignment) {
	if (this != &assignment)
		_target = assignment._target;
	return (*this);
}
void	RobotomyRequestForm::formAction() const {
	int chance = rand() % 2;
	std::cout << "*drilling noise...*" << std::endl;
	if (chance)
		std::cout << _target << " has been robotomized with great success!" << std::endl;
	else
		std::cout << "The robotomy of " << _target << " has failed" << std::endl;
}