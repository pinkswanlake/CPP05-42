/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmafrid <asmafrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 09:58:50 by asmafrid          #+#    #+#             */
/*   Updated: 2026/01/29 08:43:15 by asmafrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

void printHeader(const std::string& title) {
    std::cout << "\n========== " << title << " ==========\n" << std::endl;
}

int main()  
{
    printHeader("TEST 1: Valid Bureaucrat Creation");
    try {
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;
        
        Bureaucrat alice("Alice", 1);
        std::cout << alice << std::endl;
        
        Bureaucrat charlie("Charlie", 150);
        std::cout << charlie << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    printHeader("TEST 2: Grade Too High (0)");
    try 
        {
        Bureaucrat invalid("Invalid", 0);
        std::cout << invalid << std::endl;
        } 
        catch (std::exception& e) 
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

    printHeader("TEST 3: Grade Too Low (151)");
    try {
        Bureaucrat invalid("Invalid", 151);
        std::cout << invalid << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    printHeader("TEST 4: Incrementing Grade");
    try {
        Bureaucrat john("John", 5);
        std::cout << "Before: " << john << std::endl;
        
        john.incrementGrade();
        std::cout << "After increment: " << john << std::endl;
        
        john.incrementGrade();
        std::cout << "After second increment: " << john << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    printHeader("TEST 5: Decrementing Grade");
    try {
        Bureaucrat sarah("Sarah", 148);
        std::cout << "Before: " << sarah << std::endl;
        
        sarah.decrementGrade();
        std::cout << "After decrement: " << sarah << std::endl;
        
        sarah.decrementGrade();
        std::cout << "After second decrement: " << sarah << std::endl;
    } 
    catch (std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    printHeader("TEST 6: Increment Beyond Highest Grade");
    
        try 
    {
        Bureaucrat top("Top", 1);
        std::cout << "Current: " << top << std::endl;
        std::cout << "Attempting to increment grade 1..." << std::endl;
        top.incrementGrade();  // Should throw exception
        std::cout << "After increment: " << top << std::endl;  // Should not reach here
    }
        catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    printHeader("TEST 7: Decrement Beyond Lowest Grade");
    try 
    {
        Bureaucrat bottom("Bottom", 150);
        std::cout << "Current: " << bottom << std::endl;
        std::cout << "Attempting to decrement grade 150..." << std::endl;
        bottom.decrementGrade();  // Should throw exception
        std::cout << "After decrement: " << bottom << std::endl;  // Should not reach here
    }
    catch (std::exception& e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    printHeader("TEST 8: Copy Constructor");
    try {
        Bureaucrat original("Original", 42);
        std::cout << "Original: " << original << std::endl;
        
        Bureaucrat copy(original);
        std::cout << "Copy: " << copy << std::endl;
        
        // Modify copy
        copy.incrementGrade();
        std::cout << "After modifying copy:" << std::endl;
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
    } 
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    printHeader("TEST 9: Assignment Operator");
    try 
    {
        Bureaucrat a("A", 100);
        Bureaucrat b("B", 50);
        
        std::cout << "Before assignment:" << std::endl;
        std::cout << "A: " << a << std::endl;
        std::cout << "B: " << b << std::endl;
        
        a = b;  // Assignment
        
        std::cout << "\nAfter assignment (a = b):" << std::endl;
        std::cout << "A: " << a << std::endl;
        std::cout << "B: " << b << std::endl;
        std::cout << "Note: A keeps its original name (const)" << std::endl;
    } 
    catch (std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    printHeader("TEST 10: Multiple Increments");
    try {
        Bureaucrat climber("Climber", 10);
        std::cout << "Starting: " << climber << std::endl;
        
        for (int i = 0; i < 5; i++) 
        {
            climber.incrementGrade();
            std::cout << "After increment " << (i + 1) << ": " << climber << std::endl;
        }
    } 
    catch (std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== ALL TESTS COMPLETED ==========\n" << std::endl;
    return 0;
}