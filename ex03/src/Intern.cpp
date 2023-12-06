/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:14:09 by tkuramot          #+#    #+#             */
/*   Updated: 2023/12/05 18:14:09 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/12/05.
//

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &obj) {}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &obj) {
  return *this;
}

Form *Intern::MakeForm(std::string &form_name, std::string &target) {
  const int kNumberOfForms = 3;
  std::string form_names[kNumberOfForms] = {"shrubbery creation", "robotomy request", "presidensial pardon"};
  Form *(*form_templates[kNumberOfForms])(const std::string &) = {
	  &Intern::MakeShrubberyCreationForm,
	  &Intern::MakeRobotomyRequestForm,
	  &Intern::MakePresidentialPardonForm
  };
  for (int i = 0; i < kNumberOfForms; ++i) {
	if (form_name == form_names[i]) {
	  std::cout << "Intern creates " << form_names[i] << std::endl;
	  return (*form_templates[i])(target);
	}
  }
  std::cout << "Intern couldn't create the form, " << form_name << std::endl;
  return NULL;
}

Form *Intern::MakeShrubberyCreationForm(const std::string &target) {
  return new ShrubberyCreationForm(target);
}

Form *Intern::MakeRobotomyRequestForm(const std::string &target) {
  return new RobotomyRequestForm(target);
}

Form *Intern::MakePresidentialPardonForm(const std::string &target) {
  return new PresidentialPardonForm(target);
}