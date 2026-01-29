/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmafrid <asmafrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:37:58 by asmafrid          #+#    #+#             */
/*   Updated: 2026/01/20 13:54:13 by asmafrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

// Forward declaration (we'll use Bureaucrat but it's defined elsewhere)
class Bureaucrat;

class Form {
private:
    // ==========================================
    // PRIVATE ATTRIBUTES
    // ==========================================
    const std::string _name;        // Form name (constant)
    bool _signed;                   // Is it signed? (starts false)
    const int _gradeToSign;         // Grade required to sign (1-150)
    const int _gradeToExecute;      // Grade required to execute (1-150)

    // Helper to validate grades
    void validateGrade(int grade);

public:
    // ==========================================
    // ORTHODOX CANONICAL FORM
    // ==========================================
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    // ==========================================
    // GETTERS
    // ==========================================
    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // ==========================================
    // MEMBER FUNCTIONS
    // ==========================================
    
    // Sign the form (called by Bureaucrat)
    // Checks if bureaucrat's grade is high enough
    void beSigned(const Bureaucrat& bureaucrat);

    // ==========================================
    // EXCEPTION CLASSES
    // ==========================================
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    // Constants
    static const int HIGHEST_GRADE = 1;
    static const int LOWEST_GRADE = 150;
};

// Overload << operator
std::ostream& operator<<(std::ostream& out, const Form& form);

#endif