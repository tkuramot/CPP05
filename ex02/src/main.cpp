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