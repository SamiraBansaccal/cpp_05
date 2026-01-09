/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:24:05 by sbansacc          #+#    #+#             */
/*   Updated: 2025/12/12 19:27:01 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Test 1: Valid Bureaucrat ===" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Grade Too High (0) ===" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 0);
        std::cout << alice << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Grade Too Low (151) ===" << std::endl;
    try
    {
        Bureaucrat charlie("Charlie", 151);
        std::cout << charlie << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Increment Grade ===" << std::endl;
    try
    {
        Bureaucrat dave("Dave", 3);
        std::cout << dave << std::endl;
        dave.incrementGrade();
        std::cout << "After increment: " << dave << std::endl;
        dave.incrementGrade();
        std::cout << "After increment: " << dave << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Increment Beyond Limit ===" << std::endl;
    try
    {
        Bureaucrat eve("Eve", 1);
        std::cout << eve << std::endl;
        eve.incrementGrade(); // Should throw exception
        std::cout << "After increment: " << eve << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: Decrement Grade ===" << std::endl;
    try
    {
        Bureaucrat frank("Frank", 148);
        std::cout << frank << std::endl;
        frank.decrementGrade();
        std::cout << "After decrement: " << frank << std::endl;
        frank.decrementGrade();
        std::cout << "After decrement: " << frank << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 7: Decrement Beyond Limit ===" << std::endl;
    try
    {
        Bureaucrat grace("Grace", 150);
        std::cout << grace << std::endl;
        grace.decrementGrade(); // Should throw exception
        std::cout << "After decrement: " << grace << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 8: Edge Cases (grades 1 and 150) ===" << std::endl;
    try
    {
        Bureaucrat highest("Highest", 1);
        Bureaucrat lowest("Lowest", 150);
        std::cout << highest << std::endl;
        std::cout << lowest << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 9: Getters ===" << std::endl;
    try
    {
        Bureaucrat henry("Henry", 42);
        std::cout << "Name: " << henry.getName() << std::endl;
        std::cout << "Grade: " << henry.getGrade() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 10: Negative Grade ===" << std::endl;
    try
    {
        Bureaucrat negative("Negative", -5);
        std::cout << negative << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 11: Very Large Number ===" << std::endl;
    try
    {
        Bureaucrat huge("Huge", 9999);
        std::cout << huge << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 12: Multiple Operations ===" << std::endl;
    try
    {
        Bureaucrat worker("Worker", 75);
        std::cout << worker << std::endl;
        
        for (int i = 0; i < 5; i++)
        {
            worker.incrementGrade();
            std::cout << "After increment " << (i + 1) << ": " << worker << std::endl;
        }
        
        for (int i = 0; i < 5; i++)
        {
            worker.decrementGrade();
            std::cout << "After decrement " << (i + 1) << ": " << worker << std::endl;
        }
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}