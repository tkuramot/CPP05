/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:08:34 by tkuramot          #+#    #+#             */
/*   Updated: 2023/12/04 23:08:34 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/12/04.
//

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &name, bool is_signed)
	: AForm(name,
			is_signed,
			72,
			45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
  AForm::operator=(obj);
  return *this;
}

void RobotomyRequestForm::Execute(const Bureaucrat &executor) const
throw(AForm::GradeTooLowException, AForm::NotSignedYet) {
  AForm::IsExecutable(executor);
  std::cout << "Buzzzzz... Whirrrr... Zzzzzz..." << std::endl;
  std::srand(std::time(NULL));
  if (std::rand() % 2) {
	std::cout << executor.GetName() << " was successfully robotomized!" << std::endl;
  } else {
	std::cout << "Failed to robotomize " << executor.GetName() << "..." << std::endl;
  }
}