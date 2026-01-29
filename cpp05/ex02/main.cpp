/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmafrid <asmafrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:34:09 by asmafrid          #+#    #+#             */
/*   Updated: 2026/01/29 09:34:11 by asmafrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "\n=== TEST 1: ShrubberyCreationForm ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 137);
        ShrubberyCreationForm shrub("home");
        
        std::cout << shrub << std::endl;
        bob.signForm(shrub);
        bob.executeForm(shrub);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 2: RobotomyRequestForm ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 45);
        RobotomyRequestForm robot("Bender");
        
        std::cout << robot << std::endl;
        alice.signForm(robot);
        alice.executeForm(robot);
        alice.executeForm(robot);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 3: PresidentialPardonForm ===" << std::endl;
    try {
        Bureaucrat president("President", 5);
        PresidentialPardonForm pardon("Arthur Dent");
        
        std::cout << pardon << std::endl;
        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 4: Execute Without Signing ===" << std::endl;
    try {
        Bureaucrat charlie("Charlie", 1);
        ShrubberyCreationForm shrub("garden");
        
        charlie.executeForm(shrub);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 5: Execute With Low Grade ===" << std::endl;
    try {
        Bureaucrat intern("Intern", 150);
        Bureaucrat ceo("CEO", 1);
        PresidentialPardonForm pardon("Ford Prefect");
        
        ceo.signForm(pardon);
        intern.executeForm(pardon);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}