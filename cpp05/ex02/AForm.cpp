/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmafrid <asmafrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 08:49:03 by asmafrid          #+#    #+#             */
/*   Updated: 2026/01/29 08:49:07 by asmafrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

const int AForm::HIGHEST_GRADE = 1;
const int AForm::LOWEST_GRADE = 150;

void AForm::validateGrade(int grade)
{
    if (grade < HIGHEST_GRADE)
        throw GradeTooHighException();
    if (grade > LOWEST_GRADE)
        throw GradeTooLowException();
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute)
{
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
}

AForm::AForm(const AForm& other)
    : _name(other._name), _signed(other._signed),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        _signed = other._signed;
    return *this;
}

AForm::~AForm()
{
}

const std::string& AForm::getName() const
{
    return _name;
}

bool AForm::isSigned() const
{
    return _signed;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}

void AForm::checkExecution(const Bureaucrat& executor) const
{
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
    out << "Form " << form.getName() << ": "
        << (form.isSigned() ? "signed" : "not signed")
        << ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute();
    return out;
}