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
#include <iostream>

int main() {
  {
	std::cout << "==================Constructor==================" << std::endl;
	{
	  std::cout << "------------------Normal------------------" << std::endl;
	  Bureaucrat b("Bob", 50);
	  std::cout << b << std::endl;
	}
	{
	  std::cout << "------------------Too high grade------------------" << std::endl;
	  try {
		Bureaucrat b("Bob", 0);
	  } catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	  }
	}
	{
	  std::cout << "------------------Too high grade------------------" << std::endl;
	  try {
		Bureaucrat b("Bob", 151);
	  } catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	  }
	}
  }
  {
	std::cout << "==================Copy Constructor==================" << std::endl;
	Bureaucrat b("Bob", 50);
	Bureaucrat b_copy(b);
	std::cout << b << std::endl;
	std::cout << b_copy << std::endl;
  }
  {
	std::cout << "==================Copy Assignment Operator==================" << std::endl;
	Bureaucrat b("Bob", 50);
	Bureaucrat b_assigned("John", 20);
	b_assigned = b;
	std::cout << b << std::endl;
	std::cout << b_assigned << std::endl;
  }
  {
	std::cout << "==================Accessors==================" << std::endl;
	Bureaucrat b("Bob", 50);
	std::cout << b.GetName() << std::endl;
	std::cout << b.GetGrade() << std::endl;
  }
  {
	std::cout << "==================Accessors==================" << std::endl;
	{
	  std::cout << "------------------Normal------------------" << std::endl;
	  Bureaucrat b("Bob", 50);
	  std::cout << b << std::endl;
	  std::cout << "Bureaucrat promoted by 40 grade" << std::endl;
	  b.Promote(40);
	  std::cout << b << std::endl;
	  std::cout << "Bureaucrat demoted by 40 grade" << std::endl;
	  b.Demote(40);
	  std::cout << b << std::endl;
	}
	{
	  std::cout << "------------------Too high grade------------------" << std::endl;
	  try {
		Bureaucrat b("Bob", 50);
		std::cout << b << std::endl;
		std::cout << "Bureaucrat promoted by 50 grade" << std::endl;
		b.Promote(50);
	  } catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	  }
	}
	{
	  std::cout << "------------------Too low grade------------------" << std::endl;
	  try {
		Bureaucrat b("Bob", 50);
		std::cout << b << std::endl;
		std::cout << "Bureaucrat promoted by 101 grade" << std::endl;
		b.Demote(101);
	  } catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	  }
	}
  }
  return 0;
}