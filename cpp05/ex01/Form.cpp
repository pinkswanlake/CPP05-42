/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmafrid <asmafrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:38:02 by asmafrid          #+#    #+#             */
/*   Updated: 2026/01/29 09:46:52 by asmafrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// ==========================================
// HELPER - Validate Grade
// ==========================================
void Form::validateGrade(int grade) 
{
    if (grade < HIGHEST_GRADE) 
    {
        throw GradeTooHighException();
    }
    if (grade > LOWEST_GRADE) 
    {
        throw GradeTooLowException();
    }
}

// ==========================================
// CONSTRUCTOR
// ==========================================
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) 
    {
    // Validate both grades
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
    }

// ==========================================
// COPY CONSTRUCTOR
// ==========================================
Form::Form(const Form& other)
    : _name(other._name), _signed(other._signed), 
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) 
    {
    // All attributes copied
    }

// ==========================================
// ASSIGNMENT OPERATOR
// ==========================================
Form& Form::operator=(const Form& other) 
{
    if (this != &other) 
    {
        // NOTE: Can't reassign const members (_name, _gradeToSign, _gradeToExecute)
        // Only copy _signed status
        _signed = other._signed;
    }
    return *this;
}

// ==========================================
// DESTRUCTOR
// ==========================================
Form::~Form() 
{
    // Nothing to clean up
}

// ==========================================
// GETTERS
// ==========================================
const std::string& Form::getName() const 
{
    return _name;
}

bool Form::isSigned() const 
{
    return _signed;
}

int Form::getGradeToSign() const 
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const 
{
    return _gradeToExecute;
}

// ==========================================
// BE SIGNED
// ==========================================
// This is called by a Bureaucrat to sign the form
void Form::beSigned(const Bureaucrat& bureaucrat) {
    // Check if bureaucrat's grade is high enough to sign
    // Remember: grade 1 is HIGHER than grade 150
    // So we need: bureaucrat.getGrade() <= _gradeToSign
    
    if (bureaucrat.getGrade() > _gradeToSign) {
        // Bureaucrat's grade is too low (number too high)
        throw GradeTooLowException();
    }
    
    // If we reach here, bureaucrat can sign
    _signed = true;
}

// ==========================================
// EXCEPTIONS
// ==========================================
const char* Form::GradeTooHighException::what() const throw() 
{
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() 
{
    return "Form grade is too low!";
}

// ==========================================
// OPERATOR OVERLOAD: <<
// ==========================================
std::ostream& operator<<(std::ostream& out, const Form& form) 
{
    out << "Form '" << form.getName() << "': "
        << (form.isSigned() ? "signed" : "not signed")
        << ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute();
    return out;
}