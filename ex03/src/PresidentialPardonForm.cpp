/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:08:44 by tkuramot          #+#    #+#             */
/*   Updated: 2023/12/04 23:08:44 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/12/04.
//

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: Form("PresidentialPardonForm",
		   false,
		   25,
		   5) {
  target_ = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : Form(obj) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
  Form::operator=(obj);
  return *this;
}

void PresidentialPardonForm::Execute(const Bureaucrat &bureaucrat) const
throw(Form::GradeTooLowException, Form::NotSignedYet) {
  Form::IsExecutable(bureaucrat);
  std::cout << "Zaphod Beeblebrox pardoned " << target_ << std::endl;
}