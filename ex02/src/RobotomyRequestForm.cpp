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

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : Form("RobotomyRequestForm", 72, 45) {
  target_ = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj)
    : Form(obj) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
  Form::operator=(obj);
  return *this;
}

void RobotomyRequestForm::Execute(const Bureaucrat &executor) const
    throw(Form::GradeTooLowException, Form::NotSignedYet) {
  Form::IsExecutable(executor);
  std::cout << "Buzzzzz... Whirrrr... Zzzzzz..." << std::endl;
  std::srand(std::time(NULL));
  if (std::rand() % 2) {
    std::cout << target_ << " was successfully robotomized!" << std::endl;
  } else {
    std::cout << "Failed to robotomize " << target_ << "..." << std::endl;
  }
}