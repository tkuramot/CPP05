/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 23:24:03 by tkuramot          #+#    #+#             */
/*   Updated: 2023/12/04 23:46:30 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/11/30.
//

#include "Bureaucrat.hpp"
#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw() {
  return "Grade must be lower than or equal to 1";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Grade must be higher than or equal to 150";
}

const char *Form::NotSignedYet::what() const throw() {
  return "This form is not signed";
}

Form::Form(const std::string &name,
		   bool is_signed,
		   const int required_grade_to_sign,
		   const int required_grade_to_execute) throw(Form::GradeTooHighException, Form::GradeTooLowException)
	: kName(name),
	  is_signed_(is_signed),
	  kRequiredGradeToSign(required_grade_to_sign),
	  kRequiredGradeToExecute(required_grade_to_execute) {
  if (kRequiredGradeToSign < Bureaucrat::kHighestGrade || kRequiredGradeToExecute < Bureaucrat::kHighestGrade) {
	throw Form::GradeTooHighException();
  }
  if (kRequiredGradeToSign > Bureaucrat::kLowestGrade || kRequiredGradeToExecute > Bureaucrat::kLowestGrade) {
	throw Form::GradeTooLowException();
  }
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

int Form::GetRequiredGradeToSign() const throw(Form::GradeTooHighException, Form::GradeTooLowException) {
  return kRequiredGradeToSign;
}

int Form::GetRequiredGradeToExecute() const throw(Form::GradeTooHighException, Form::GradeTooLowException) {
  return kRequiredGradeToExecute;
}

void Form::IsExecutable(Bureaucrat const &executor) const throw(Form::GradeTooLowException, Form::NotSignedYet) {
  if (!is_signed_) {
	throw Form::NotSignedYet();
  }
  if (executor.GetGrade() > kRequiredGradeToExecute) {
	throw Form::GradeTooLowException();
  }
}

void Form::BeSigned(Bureaucrat const &bureaucrat) throw(Form::GradeTooLowException) {
  if (bureaucrat.GetGrade() > kRequiredGradeToSign) {
	throw Form::GradeTooLowException();
  }
  is_signed_ = true;
}

std::ostream &operator<<(std::ostream &os, Form &form) {
  os << "This form, " << form.GetName() << " requires grade " << form.GetRequiredGradeToSign()
	 << " to sign and grade " << form.GetRequiredGradeToExecute() << " to execute. This form is "
	 << (form.IsSigned() ? "signed." : "not signed.");
  return os;
}