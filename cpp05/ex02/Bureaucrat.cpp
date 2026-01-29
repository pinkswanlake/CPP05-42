/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmafrid <asmafrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:31:18 by asmafrid          #+#    #+#             */
/*   Updated: 2026/01/20 13:42:26 by asmafrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const int Bureaucrat::HIGHEST_GRADE = 1;
const int Bureaucrat::LOWEST_GRADE = 150;

void Bureaucrat::validateGrade(int grade)
{
    if(grade < HIGHEST_GRADE)
    {
        throw GradeTooHighException();
    }
    if(grade > LOWEST_GRADE)
    {
        throw GradeTooLowException();
    }
}


Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
    validateGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if(this != &other)
    {
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}



const std::string& Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const 
{
    return _grade;
}



void Bureaucrat::incrementGrade()
{
    validateGrade(_grade - 1);

    _grade--;
}

void Bureaucrat::decrementGrade()
{
    validateGrade(_grade + 1);

    _grade++;
}



const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high! (minimum grade is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low! (maximum grade is 150)";
}



std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName()
        << ", bureaucrat grade "
        << bureaucrat.getGrade()
        <<".";
    return out;
}
