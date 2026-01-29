/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmafrid <asmafrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:40:55 by asmafrid          #+#    #+#             */
/*   Updated: 2026/01/29 09:42:42 by asmafrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
    Intern intern;
    Bureaucrat boss("Boss", 1);

    std::cout << "\n=== TEST 1: Create Robotomy Request ===" << std::endl;
    {
        AForm* form = intern.makeForm("robotomy request", "Bender");
        if (form)
        {
            std::cout << *form << std::endl;
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }
    }

    std::cout << "\n=== TEST 2: Create Shrubbery Creation ===" << std::endl;
    {
        AForm* form = intern.makeForm("shrubbery creation", "garden");
        if (form)
        {
            std::cout << *form << std::endl;
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }
    }

    std::cout << "\n=== TEST 3: Create Presidential Pardon ===" << std::endl;
    {
        AForm* form = intern.makeForm("presidential pardon", "Arthur");
        if (form)
        {
            std::cout << *form << std::endl;
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }
    }

    std::cout << "\n=== TEST 4: Invalid Form Name ===" << std::endl;
    {
        AForm* form = intern.makeForm("invalid form", "target");
        if (form)
        {
            delete form;
        }
        else
        {
            std::cout << "Form creation failed as expected" << std::endl;
        }
    }

    std::cout << "\n=== TEST 5: Multiple Forms ===" << std::endl;
    {
        AForm* forms[3];
        forms[0] = intern.makeForm("shrubbery creation", "home");
        forms[1] = intern.makeForm("robotomy request", "target1");
        forms[2] = intern.makeForm("presidential pardon", "criminal");
        
        for (int i = 0; i < 3; i++)
        {
            if (forms[i])
            {
                boss.signForm(*forms[i]);
                boss.executeForm(*forms[i]);
                delete forms[i];
            }
        }
    }

    return 0;
}