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
#include "Form.hpp"
#include <iostream>

int main() {
  {
    std::cout << "==================Bureaucrat==================" << std::endl;
    {
      std::cout << "==================SignForm==================" << std::endl;
      {
        std::cout << "------------------Normal------------------" << std::endl;
        Form f("Construction plan", 20, 40);
        Bureaucrat b("Bob", 10);
        b.SignForm(f);
      }
      {
        std::cout << "------------------Already signed------------------"
                  << std::endl;
        Form f("Construction plan", 20, 40);
        Bureaucrat b("Bob", 10);
        b.SignForm(f);
        b.SignForm(f);
      }
      {
        std::cout << "------------------Too low grade------------------"
                  << std::endl;
        Form f("Construction plan", 20, 40);
        Bureaucrat b("Bob", 50);
        try {
          b.SignForm(f);
        } catch (Form::GradeTooLowException &e) {
          std::cout << e.what() << std::endl;
        }
      }
    }
  }
  {
    std::cout << "==================Form==================" << std::endl;
    std::cout << "==================Constructor==================" << std::endl;
    {
      std::cout << "------------------Normal------------------" << std::endl;
      Form f("Construction plan", 20, 40);
      std::cout << f << std::endl;
    }
    {
      std::cout << "------------------Too high grade------------------"
                << std::endl;
      try {
        Form f("Construction plan", 0, 40);
      } catch (Form::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
      }
      try {
        Form f("Construction plan", 20, 0);
      } catch (Form::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
      }
    }
    {
      std::cout << "------------------Too low grade------------------"
                << std::endl;
      try {
        Form f("Construction plan", 151, 40);
      } catch (Form::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
      }
      try {
        Form f("Construction plan", 20, 151);
      } catch (Form::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
      }
    }
    {
      std::cout << "==================Copy Constructor=================="
                << std::endl;
      Form f("Construction plan", 20, 40);
      Form b_copy(f);
      std::cout << f << std::endl;
      std::cout << b_copy << std::endl;
    }
    {
      std::cout
          << "==================Copy Assignment Operator=================="
          << std::endl;
      Form f("Construction plan", 20, 40);
      Form f_assigned("No plan", 20, 40);
      f_assigned = f;
      std::cout << f << std::endl;
      std::cout << f_assigned << std::endl;
    }
    {
      std::cout << "==================Accessors==================" << std::endl;
      Form f("Construction plan", 20, 40);
      std::cout << f.GetName() << std::endl;
      std::cout << f.GetRequiredGradeToSign() << std::endl;
      std::cout << f.GetRequiredGradeToExecute() << std::endl;
    }
  }
  return 0;
}