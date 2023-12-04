/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
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
#include "AForm.hpp"

const char *AForm::GradeTooHighException::what() const throw() {
  return "Grade must be lower than or equal to 1";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade must be higher than or equal to 150";
}

const char *AForm::NotSignedYet::what() const throw() {
  return "This form is not signed";
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

int AForm::GetRequiredGradeToSign() const throw(AForm::GradeTooHighException, AForm::GradeTooLowException) {
  return kRequiredGradeToSign;
}

int AForm::GetRequiredGradeToExecute() const throw(AForm::GradeTooHighException, AForm::GradeTooLowException) {
  return kRequiredGradeToExecute;
}

void AForm::IsExecutable(Bureaucrat const &executor) const throw(AForm::GradeTooLowException, AForm::NotSignedYet) {
  if (!is_signed_) {
	throw AForm::NotSignedYet();
  }
  if (executor.GetGrade() > kRequiredGradeToExecute) {
	throw AForm::GradeTooLowException();
  }
}

void AForm::BeSigned(Bureaucrat const &bureaucrat) throw(AForm::GradeTooLowException) {
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