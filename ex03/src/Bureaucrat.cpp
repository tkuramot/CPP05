/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 23:40:59 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/29 00:37:11 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/11/28.
//

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade must be lower than or equal to 1";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade must be higher than or equal to 150";
}

Bureaucrat::Bureaucrat(const std::string &name,
					   int grade) throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException)
	: kName(name), grade_(grade) {
  if (grade_ < kHighestGrade) {
	throw GradeTooHighException();
  } else if (grade_ > kLowestGrade) {
	throw GradeTooLowException();
  }
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : kName(obj.kName), grade_(obj.grade_) {
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj) {
  grade_ = obj.grade_;
  return *this;
}

const std::string &Bureaucrat::GetName() const {
  return kName;
}

int Bureaucrat::GetGrade() const {
  return grade_;
}

void Bureaucrat::Promote(int grade_diff) throw(Bureaucrat::GradeTooHighException) {
  if (grade_ - grade_diff < kHighestGrade) {
	throw GradeTooHighException();
  }
  grade_ -= grade_diff;
}

void Bureaucrat::Demote(int grade_diff) throw(Bureaucrat::GradeTooLowException) {
  if (grade_ + grade_diff > kLowestGrade) {
	throw GradeTooLowException();
  }
  grade_ += grade_diff;
}

void Bureaucrat::SignForm(Form &form) const {
  if (form.IsSigned()) {
	std::cout << kName << " couldn’t sign " << form.GetName() << " because the form is already signed." << std::endl;
	return;
  }
  try {
	form.BeSigned(*this);
  } catch (Form::GradeTooLowException &e) {
	std::cout << kName << " couldn’t sign " << form.GetName() << " because his grade was too low." << std::endl;
	return;
  }
  std::cout << kName << " signed " << form.GetName() << "." << std::endl;
}

void Bureaucrat::ExecuteForm(Form const &form) {
  try {
	std::cout << kName << " executed " << form.GetName() << "." << std::endl;
	form.Execute(*this);
  } catch (Form::GradeTooLowException &e) {
	std::cout << kName << "'s grade was too low to execute " << form.GetName() << "." << std::endl;
  } catch (Form::NotSignedYet &e) {
	std::cout << kName << " tried to execute " << form.GetName() << ", but it was not signed yet."
			  << std::endl;
  } catch (std::exception &e) {
	std::cout << kName << " couldn't execute " << form.GetName() << "." << std::endl
			  << e.what() << std::endl;
  }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.GetName() << ", bureaucrat grade " << bureaucrat.GetGrade() << ".";
  return os;
}