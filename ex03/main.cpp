/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 01:39:31 by sbansacc          #+#    #+#             */
/*   Updated: 2025/12/19 00:54:54 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Bureaucrat.hpp"
#include "headers/AForm.hpp"
#include "headers/Intern.hpp"


int main(void)
{
    Intern      someRandomIntern;
    Bureaucrat  boss("Boss", 1);
    Bureaucrat  noob("Noob", 150);

    AForm* f1;
    AForm* f2;
    AForm* f3;
    AForm* f4;

    std::cout << "---- Intern creates valid forms ----" << std::endl;

    f1 = someRandomIntern.makeForm("shrubbery creation", "home");
    f2 = someRandomIntern.makeForm("robotomy request", "Bender");
    f3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");

    std::cout << "\n---- Intern tries invalid form ----" << std::endl;
    f4 = someRandomIntern.makeForm("random bullshit", "nobody");

    std::cout << "\n---- Signing forms ----" << std::endl;
    if (f1) boss.signForm(*f1);
    if (f2) boss.signForm(*f2);
    if (f3) boss.signForm(*f3);

    std::cout << "\n---- Executing forms (OK) ----" << std::endl;
    try {
        if (f1) boss.executeForm(*f1);
        if (f2) boss.executeForm(*f2);
        if (f3) boss.executeForm(*f3);
    }
    catch (std::exception const &e) {
        std::cout << "Execution error: " << e.what() << std::endl;
    }

    std::cout << "\n---- Executing forms with low grade ----" << std::endl;
    try {
        if (f1) noob.executeForm(*f1);
    }
    catch (std::exception const &e) {
        std::cout << "Execution error: " << e.what() << std::endl;
    }

    std::cout << "\n---- Cleaning ----" << std::endl;
    delete f1;
    delete f2;
    delete f3;
    delete f4;

    return 0;
}