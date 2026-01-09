/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 23:00:07 by sbansacc          #+#    #+#             */
/*   Updated: 2025/12/12 19:16:10 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

    std::cout << "---- TEST 1 : Creation de formulaires valides ----" << std::endl;
    try {
        Form f1("FormA", 50, 30);
        std::cout << f1 << std::endl;
    }
    catch (std::exception const &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n---- TEST 2 : Creation de formulaire invalide (grade trop haut) ----" << std::endl;
    try {
        Form f2("BadForm1", 0, 10); // 0 interdit
        std::cout << f2 << std::endl;
    }
    catch (std::exception const &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n---- TEST 3 : Creation de formulaire invalide (grade trop bas) ----" << std::endl;
    try {
        Form f3("BadForm2", 120, 200); // 200 interdit
        std::cout << f3 << std::endl;
    }
    catch (std::exception const &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n---- TEST 4 : Bureaucrate qui signe (OK) ----" << std::endl;
    Bureaucrat bob("Bob", 40);
    Form f4("Papers", 50, 30);

    std::cout << bob << std::endl;
    std::cout << f4 << std::endl;

    bob.signForm(f4);
    std::cout << f4 << std::endl;

    std::cout << "\n---- TEST 5 : Bureaucrate trop nul pour signer ----" << std::endl;
    Bureaucrat jim("Jim", 120);
    Form f5("Top Secret", 50, 10);

    std::cout << jim << std::endl;
    std::cout << f5 << std::endl;

    jim.signForm(f5);
    std::cout << f5 << std::endl;

    std::cout << "\n---- TEST 6 : Bureaucrate améliore son grade puis réussit ----" << std::endl;

    try {
        jim.incrementGrade();  // Jim passe 119
        jim.incrementGrade();  // 118
        jim.incrementGrade();  // 117
        jim.incrementGrade();  // 116
        jim.incrementGrade();  // 115
        // toujours insufisant, mais ça montre le mécanisme
    }
    catch (std::exception const &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    jim.signForm(f5);

    std::cout << "\n---- FIN DES TESTS ----" << std::endl;

    return 0;
}