/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 23:41:48 by tkuramot          #+#    #+#             */
/*   Updated: 2023/12/03 02:39:29 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/11/28.
//

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
  //  {
  //	std::cout << "==================Bureaucrat==================" <<
  //std::endl; 	std::cout << "==================Constructor==================" <<
  //std::endl;
  //	{
  //	  std::cout << "------------------Normal------------------" <<
  //std::endl; 	  Bureaucrat b("Bob", 50); 	  std::cout << b << std::endl;
  //	}
  //	{
  //	  std::cout << "------------------Too high grade------------------" <<
  //std::endl; 	  try { 		Bureaucrat b("Bob", 0); 	  } catch
  //(Bureaucrat::GradeTooHighException &e) { 		std::cout << e.what() << std::endl;
  //	  }
  //	}
  //	{
  //	  std::cout << "------------------Too high grade------------------" <<
  //std::endl; 	  try { 		Bureaucrat b("Bob", 151); 	  } catch
  //(Bureaucrat::GradeTooLowException &e) { 		std::cout << e.what() << std::endl;
  //	  }
  //	}
  //  }
  //  {
  //	std::cout << "==================Copy Constructor==================" <<
  //std::endl; 	Bureaucrat b("Bob", 50); 	Bureaucrat b_copy(b); 	std::cout << b <<
  //std::endl; 	std::cout << b_copy << std::endl;
  //  }
  //  {
  //	std::cout << "==================Copy Assignment
  //Operator==================" << std::endl; 	Bureaucrat b("Bob", 50);
  //	Bureaucrat b_assigned("John", 20);
  //	b_assigned = b;
  //	std::cout << b << std::endl;
  //	std::cout << b_assigned << std::endl;
  //  }
  //  {
  //	std::cout << "==================Accessors==================" <<
  //std::endl; 	Bureaucrat b("Bob", 50); 	std::cout << b.GetName() << std::endl;
  //	std::cout << b.GetGrade() << std::endl;
  //  }
  //  {
  //	std::cout << "==================Promote & Demote==================" <<
  //std::endl;
  //	{
  //	  std::cout << "------------------Normal------------------" <<
  //std::endl; 	  Bureaucrat b("Bob", 50); 	  std::cout << b << std::endl; 	  std::cout
  //<< "Bureaucrat promoted by 40 grade" << std::endl; 	  b.Promote(40); 	  std::cout
  //<< b << std::endl; 	  std::cout << "Bureaucrat demoted by 40 grade" <<
  //std::endl; 	  b.Demote(40); 	  std::cout << b << std::endl;
  //	}
  //	{
  //	  std::cout << "------------------Too high grade------------------" <<
  //std::endl; 	  try { 		Bureaucrat b("Bob", 50); 		std::cout << b << std::endl;
  //		std::cout << "Bureaucrat promoted by 50 grade" << std::endl;
  //		b.Promote(50);
  //	  } catch (Bureaucrat::GradeTooHighException &e) {
  //		std::cout << e.what() << std::endl;
  //	  }
  //	}
  //	{
  //	  std::cout << "------------------Too low grade------------------" <<
  //std::endl; 	  try { 		Bureaucrat b("Bob", 50); 		std::cout << b << std::endl;
  //		std::cout << "Bureaucrat promoted by 101 grade" << std::endl;
  //		b.Demote(101);
  //	  } catch (Bureaucrat::GradeTooLowException &e) {
  //		std::cout << e.what() << std::endl;
  //	  }
  //	}
  //	{
  //	  std::cout << "==================SignForm==================" <<
  //std::endl;
  //	  {
  //		std::cout << "------------------Normal------------------" <<
  //std::endl; 		Form f("Construction plan", false, 20, 40); 		Bureaucrat b("Bob",
  //10); 		b.SignForm(f);
  //	  }
  //	  {
  //		std::cout << "------------------Already signed------------------" <<
  //std::endl; 		Form f("Construction plan", false, 20, 40); 		Bureaucrat b("Bob",
  //10); 		b.SignForm(f); 		b.SignForm(f);
  //	  }
  //	  {
  //		std::cout << "------------------Too low grade------------------" <<
  //std::endl; 		Form f("Construction plan", false, 20, 40); 		Bureaucrat b("Bob",
  //50); 		try { 		  b.SignForm(f); 		} catch (Form::GradeTooLowException &e) {
  //		  std::cout << e.what() << std::endl;
  //		}
  //	  }
  //	}
  //  }
  //  {
  //	std::cout << "==================Form==================" << std::endl;
  //	std::cout << "==================Constructor==================" <<
  //std::endl;
  //	{
  //	  std::cout << "------------------Normal------------------" <<
  //std::endl; 	  Form f("Construction plan", false, 20, 40); 	  std::cout << f <<
  //std::endl;
  //	}
  //	{
  //	  std::cout << "------------------Too high grade------------------" <<
  //std::endl; 	  try { 		Form f("Construction plan", false, 0, 40); 	  } catch
  //(Form::GradeTooHighException &e) { 		std::cout << e.what() << std::endl;
  //	  }
  //	  try {
  //		Form f("Construction plan", false, 20, 0);
  //	  } catch (Form::GradeTooHighException &e) {
  //		std::cout << e.what() << std::endl;
  //	  }
  //	}
  //	{
  //	  std::cout << "------------------Too low grade------------------" <<
  //std::endl; 	  try { 		Form f("Construction plan", false, 151, 40); 	  } catch
  //(Form::GradeTooLowException &e) { 		std::cout << e.what() << std::endl;
  //	  }
  //	  try {
  //		Form f("Construction plan", false, 20, 151);
  //	  } catch (Form::GradeTooLowException &e) {
  //		std::cout << e.what() << std::endl;
  //	  }
  //	}
  //	{
  //	  std::cout << "==================Copy Constructor==================" <<
  //std::endl; 	  Form f("Construction plan", false, 20, 40); 	  Form b_copy(f);
  //	  std::cout << f << std::endl;
  //	  std::cout << b_copy << std::endl;
  //	}
  //	{
  //	  std::cout << "==================Copy Assignment
  //Operator==================" << std::endl; 	  Form f("Construction plan", false,
  //20, 40); 	  Form f_assigned("No plan", false, 20, 40); 	  f_assigned = f;
  //	  std::cout << f << std::endl;
  //	  std::cout << f_assigned << std::endl;
  //	}
  //	{
  //	  std::cout << "==================Accessors==================" <<
  //std::endl; 	  Form f("Construction plan", false, 20, 40); 	  std::cout <<
  //f.GetName() << std::endl; 	  std::cout << f.GetRequiredGradeToSign() <<
  //std::endl; 	  std::cout << f.GetRequiredGradeToExecute() << std::endl;
  //	}
  //  }
  {
    std::cout << "==================ShrubberyForm=================="
              << std::endl;
    {
      std::cout << "------------------Normal------------------" << std::endl;
      ShrubberyCreationForm f("home");
      std::cout << f << std::endl;
      Bureaucrat b("Bob", 1);
      b.SignForm(f);
      b.ExecuteForm(f);
    }
    {
      std::cout << "------------------Not signed yet------------------"
                << std::endl;
      ShrubberyCreationForm f("home");
      Bureaucrat b("Bob", 1);
      b.ExecuteForm(f);
    }
    {
      std::cout << "------------------Too low level------------------"
                << std::endl;
      ShrubberyCreationForm f("home");
      Bureaucrat b("Bob", 145);
      b.SignForm(f);
      b.ExecuteForm(f);
    }
  }
  {
    std::cout << "==================RobotomyRequestForm=================="
              << std::endl;
    {
      std::cout << "------------------Normal------------------" << std::endl;
      RobotomyRequestForm f("John");
      std::cout << f << std::endl;
      Bureaucrat b("Bob", 1);
      b.SignForm(f);
      b.ExecuteForm(f);
    }
    {
      std::cout << "------------------Not signed yet------------------"
                << std::endl;
      RobotomyRequestForm f("John");
      Bureaucrat b("Bob", 1);
      b.ExecuteForm(f);
    }
    {
      std::cout << "------------------Too low level------------------"
                << std::endl;
      RobotomyRequestForm f("John");
      Bureaucrat b("Bob", 72);
      b.SignForm(f);
      b.ExecuteForm(f);
    }
  }
  {
    std::cout << "==================PresidentialPardonForm=================="
              << std::endl;
    {
      std::cout << "------------------Normal------------------" << std::endl;
      PresidentialPardonForm f("John");
      std::cout << f << std::endl;
      Bureaucrat b("Bob", 1);
      b.SignForm(f);
      b.ExecuteForm(f);
    }
    {
      std::cout << "------------------Not signed yet------------------"
                << std::endl;
      PresidentialPardonForm f("John");
      Bureaucrat b("Bob", 1);
      b.ExecuteForm(f);
    }
    {
      std::cout << "------------------Too low level------------------"
                << std::endl;
      PresidentialPardonForm f("John");
      Bureaucrat b("Bob", 72);
      b.SignForm(f);
      b.ExecuteForm(f);
    }
  }
  return 0;
}