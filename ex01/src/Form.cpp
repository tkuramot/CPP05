/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:05:04 by tkuramot          #+#    #+#             */
/*   Updated: 2023/12/03 23:10:00 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/11/30.
//

#include "Form.hpp"
#include "Bureaucrat.hpp"

const char *Form::GradeTooHighException::what() const throw() {
  return "Grade must be lower than or equal to 1";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Grade must be higher than or equal to 150";
}

Form::Form(
    const std::string &name, const int required_grade_to_sign,
    const int required_grade_to_execute) throw(Form::GradeTooHighException,
                                               Form::GradeTooLowException)
    : kName(name), is_signed_(false),
      kRequiredGradeToSign(required_grade_to_sign),
      kRequiredGradeToExecute(required_grade_to_execute) {
  if (kRequiredGradeToSign < Bureaucrat::kHighestGrade ||
      kRequiredGradeToExecute < Bureaucrat::kHighestGrade) {
    throw Form::GradeTooHighException();
  }
  if (kRequiredGradeToSign > Bureaucrat::kLowestGrade ||
      kRequiredGradeToExecute > Bureaucrat::kLowestGrade) {
    throw Form::GradeTooLowException();
  }
}

Form::Form(const Form &obj)
    : kName(obj.kName), is_signed_(obj.is_signed_),
      kRequiredGradeToSign(obj.kRequiredGradeToSign),
      kRequiredGradeToExecute(obj.kRequiredGradeToExecute) {}

Form::~Form() {}

Form &Form::operator=(const Form &obj) {
  is_signed_ = obj.is_signed_;
  return *this;
}
const std::string &Form::GetName() const { return kName; }
bool Form::IsSigned() const { return is_signed_; }

int Form::GetRequiredGradeToSign() const
    throw(Form::GradeTooHighException, Form::GradeTooLowException) {
  return kRequiredGradeToSign;
}

int Form::GetRequiredGradeToExecute() const
    throw(Form::GradeTooHighException, Form::GradeTooLowException) {
  return kRequiredGradeToExecute;
}

void Form::BeSigned(Bureaucrat const &bureaucrat) throw(
    Form::GradeTooLowException) {
  if (bureaucrat.GetGrade() > kRequiredGradeToSign) {
    throw Form::GradeTooLowException();
  }
  is_signed_ = true;
}

std::ostream &operator<<(std::ostream &os, Form &form) {
  os << "This form, " << form.GetName() << " requires grade "
     << form.GetRequiredGradeToSign() << " to sign and grade "
     << form.GetRequiredGradeToExecute() << " to execute. This form is "
     << (form.IsSigned() ? "signed." : "not signed.");
  return os;
}