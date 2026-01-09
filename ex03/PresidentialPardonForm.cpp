/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:58:22 by sbansacc          #+#    #+#             */
/*   Updated: 2025/12/18 22:05:21 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon", 25, 5), _target("Default target") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): AForm("Presidential Pardon", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy): AForm(copy), _target(copy._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &assignment) {
	if (this != &assignment)
		_target = assignment._target;
	return (*this);
}
void	PresidentialPardonForm::formAction() const {
	std::cout << "You are informed that "<< _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}