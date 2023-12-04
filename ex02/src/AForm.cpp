/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
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

#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char *AForm::GradeTooHighException::what() const throw() {
  return "Grade must be lower than or equal to 1";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade must be higher than or equal to 150";
}

AForm::AForm(const std::string &name,
			 bool is_signed,
			 const int required_grade_to_sign,
			 const int required_grade_to_execute) throw(AForm::GradeTooHighException, AForm::GradeTooLowException)
	: kName(name),
	  is_signed_(is_signed),
	  kRequiredGradeToSign(required_grade_to_sign),
	  kRequiredGradeToExecute(required_grade_to_execute) {
  if (kRequiredGradeToSign < Bureaucrat::kHighestGrade || kRequiredGradeToExecute < Bureaucrat::kHighestGrade) {
	throw AForm::GradeTooHighException();
  }
  if (kRequiredGradeToSign > Bureaucrat::kLowestGrade || kRequiredGradeToExecute > Bureaucrat::kLowestGrade) {
	throw AForm::GradeTooLowException();
  }
}

AForm::AForm(const AForm &obj)
	: kName(obj.kName),
	  is_signed_(obj.is_signed_),
	  kRequiredGradeToSign(obj.kRequiredGradeToSign),
	  kRequiredGradeToExecute(obj.kRequiredGradeToExecute) {
}

AForm::~AForm() {
}

AForm &AForm::operator=(const AForm &obj) {
  is_signed_ = obj.is_signed_;
  return *this;
}
const std::string &AForm::GetName() const {
  return kName;
}
bool AForm::IsSigned() const {
  return is_signed_;
}

const int AForm::GetRequiredGradeToSign() const throw(AForm::GradeTooHighException, AForm::GradeTooLowException) {
  return kRequiredGradeToSign;
}

const int AForm::GetRequiredGradeToExecute() const throw(AForm::GradeTooHighException, AForm::GradeTooLowException) {
  return kRequiredGradeToExecute;
}

void AForm::BeSigned(const Bureaucrat &bureaucrat) throw(AForm::GradeTooLowException) {
  if (bureaucrat.GetGrade() > kRequiredGradeToSign) {
	throw AForm::GradeTooLowException();
  }
  is_signed_ = true;
}

std::ostream &operator<<(std::ostream &os, AForm &form) {
  os << "AForm title is " << form.GetName() << " which requires grade " << form.GetRequiredGradeToSign()
	 << " to sign and grade " << form.GetRequiredGradeToExecute() << " to execute. This form is "
	 << (form.IsSigned() ? "signed." : "not signed.");
  return os;
}