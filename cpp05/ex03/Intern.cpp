/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmafrid <asmafrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:40:03 by asmafrid          #+#    #+#             */
/*   Updated: 2026/01/29 09:42:26 by asmafrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
}

AForm* Intern::makeShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePardon(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    
    AForm* (Intern::*creators[3])(const std::string&) = {
        &Intern::makeShrubbery,
        &Intern::makeRobotomy,
        &Intern::makePardon
    };
    
    for (int i = 0; i < 3; i++)
    {
        if (formNames[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*creators[i])(target);
        }
    }
    
    std::cout << "Error: Form '" << formName << "' does not exist" << std::endl;
    return NULL;
}