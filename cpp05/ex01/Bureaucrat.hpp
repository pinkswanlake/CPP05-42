/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmafrid <asmafrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:31:15 by asmafrid          #+#    #+#             */
/*   Updated: 2026/01/29 08:45:24 by asmafrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>

  class Form;

  class Bureaucrat
    {
        private:
                const std::string _name;
                int  _grade;

                void validateGrade(int grade);
        
        public:
                Bureaucrat(const std::string& name, int grade);
                Bureaucrat(const Bureaucrat& other);
                Bureaucrat& operator=(const Bureaucrat& other);  
                ~Bureaucrat();

        const std::string& getName() const;
        int getGrade() const;

        
        void incrementGrade();
        void decrementGrade();
        void signForm(Form&, form);
        
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            virtual const char* what() const throw();
        }; 
        
            static const int HIGHEST_GRADE;
            static const int LOWEST_GRADE;
    };
    
    std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif