/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:05:04 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/30 17:12:36 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/11/30.
//

#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw() {
  return "Grade must be lower than or equal to 1";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Grade must be higher than or equal to 150";
}

Form::Form(const std::string &name,
		   bool is_signed,
		   const int required_grade_to_sign,
		   const int required_grade_to_execute)
	: kName(name),
	  is_signed_(is_signed),
	  kRequiredGradeToSign(required_grade_to_sign),
	  kRequiredGradeToExecute(required_grade_to_execute) {
}

Form::Form(const Form &obj)
	: kName(obj.kName),
	  is_signed_(obj.is_signed_),
	  kRequiredGradeToSign(obj.kRequiredGradeToSign),
	  kRequiredGradeToExecute(obj.kRequiredGradeToExecute) {
}

Form::~Form() {
}

Form &Form::operator=(const Form &obj) {
  is_signed_ = obj.is_signed_;
  return *this;
}
const std::string &Form::GetName() const {
  return kName;
}
bool Form::IsSigned() const {
  return is_signed_;
}
const int Form::GetRequiredGradeToSign() const {
  return kRequiredGradeToSign;
}
const int Form::GetRequiredGradeToExecute() const {
  return kRequiredGradeToExecute;
}
