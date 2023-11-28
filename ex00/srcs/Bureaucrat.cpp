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

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Bureaucrat grade must be lower than or equal to 1";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Bureaucrat grade must be higher than or equal to 150";
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : kName(name) {
  if (grade_ < kHighestGrade) {
	throw GradeTooHighException();
  }
  if (grade_ > kLowestGrade) {
	throw GradeTooLowException();
  }
  grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : kName(obj.kName) {
  if (grade_ < kHighestGrade) {
	throw GradeTooHighException();
  }
  if (grade_ > kLowestGrade) {
	throw GradeTooLowException();
  }
  grade_ = obj.grade_;
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj) {
  if (grade_ < kHighestGrade) {
	throw GradeTooHighException();
  }
  if (grade_ > kLowestGrade) {
	throw GradeTooLowException();
  }
  grade_ = obj.grade_;
}

const std::string &Bureaucrat::GetName() const {
  return kName;
}

int Bureaucrat::GetGrade() const {
  return grade_;
}

void Bureaucrat::Promote(int grade_diff) {
  if (grade_ - grade_diff < kHighestGrade) {
	throw GradeTooHighException();
  }
  grade_ = grade_diff;
}

void Bureaucrat::Demote(int grade_diff) {
  if (grade_ + grade_diff > kLowestGrade) {
	throw GradeTooLowException();
  }
  grade_ = grade_diff;
}