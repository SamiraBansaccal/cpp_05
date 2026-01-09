/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 01:39:31 by sbansacc          #+#    #+#             */
/*   Updated: 2025/12/18 21:59:54 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Bureaucrat.hpp"
#include "headers/AForm.hpp"
#include "headers/ShrubberyCreationForm.hpp"
#include "headers/RobotomyRequestForm.hpp"
#include "headers/PresidentialPardonForm.hpp"


int main() {
	
	Bureaucrat boss("Boss", 1);
	Bureaucrat mid("Mid", 50);
	Bureaucrat low("Low", 150);
	
	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Arthur");
	
	std::cout << "\n--- Boss signe et execute Shrubbery (sign 145, exec 137) ---" << std::endl;
	std::cout << "ATTENDU: Boss signed + Boss executed" << std::endl;
	boss.signForm(shrub);
	boss.executeForm(shrub);
	
	std::cout << "\n--- Boss signe et execute Robotomy (sign 72, exec 45) ---" << std::endl;
	std::cout << "ATTENDU: Boss signed + *drilling noise...* + message" << std::endl;
	boss.signForm(robot);
	boss.executeForm(robot);
	
	std::cout << "\n--- Boss signe et execute Presidential (sign 25, exec 5) ---" << std::endl;
	std::cout << "ATTENDU: Boss signed + pardoned by Zaphod" << std::endl;
	boss.signForm(pardon);
	boss.executeForm(pardon);
	
	std::cout << "\n--- Mid (50) essaye Robotomy (sign 72, exec 45) ---" << std::endl;
	RobotomyRequestForm robot2("Marvin");
	std::cout << "ATTENDU: Mid signed + Mid couldn't execute (Grade Too Low)" << std::endl;
	mid.signForm(robot2);
	mid.executeForm(robot2);
	
	std::cout << "\n--- Mid (50) essaye Presidential (sign 25, exec 5) ---" << std::endl;
	PresidentialPardonForm pardon2("Zaphod");
	std::cout << "ATTENDU: Mid couldn't sign (Grade Too Low)" << std::endl;
	mid.signForm(pardon2);
	
	std::cout << "\n--- Low (150) essaye Shrubbery (sign 145, exec 137) ---" << std::endl;
	ShrubberyCreationForm shrub2("garden");
	std::cout << "ATTENDU: Low couldn't sign (Grade Too Low)" << std::endl;
	low.signForm(shrub2);
	
	std::cout << "\n--- Boss execute formulaire non signe ---" << std::endl;
	ShrubberyCreationForm shrub3("unsigned");
	std::cout << "ATTENDU: Boss couldn't execute (Form Not Signed)" << std::endl;
	boss.executeForm(shrub3);
	
	return 0;
}