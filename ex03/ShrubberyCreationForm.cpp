/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:53:19 by sbansacc          #+#    #+#             */
/*   Updated: 2026/01/09 18:12:28 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery Creation", 145, 137), _target("Default target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy): AForm(copy), _target(copy._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
		
ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &assignment) {
	if (this != &assignment)
		_target = assignment._target;
	return (*this);
}

void	ShrubberyCreationForm::formAction() const {
	std::string		outfileName(_target + "_shrubbery");
	std::ofstream	outfile(outfileName.c_str());
	if (!outfile)
		throw ShrubberyCreationForm::fileException();
	outfile << 
				"         v" << std::endl <<
				"        >X<" << std::endl <<
				"         A" << std::endl <<
				"        d$b" << std::endl <<
				"      .d\\$$b." << std::endl <<
				"    .d$i$$\\$$b." << std::endl <<
				"       d$$@b" << std::endl <<
				"      d\\$$$ib" << std::endl <<
				"    .d$$$\\$$$b" << std::endl <<
				"  .d$$@$$$$\\$$ib." << std::endl <<
				"      d$$i$$b" << std::endl <<
				"     d\\$$$$@$b" << std::endl <<
				"  .d$@$$\\$$$$$@b." << std::endl <<
				".d$$$$i$$$\\$$$$$$b." << std::endl <<
				"        ###" << std::endl <<
				"        ###" << std::endl <<
				"        ### mh" << std::endl;
	outfile.close();
}

const char*	ShrubberyCreationForm::fileException::what() const throw() {
	return ("file cannot be created");
}