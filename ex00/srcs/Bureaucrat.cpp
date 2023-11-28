/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 23:40:59 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/28 23:48:46 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/11/28.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : kName(name) {
  grade_ = grade;
}

Bureaucrat::~Bureaucrat() {
}

const std::string &Bureaucrat::GetName() const {
  return kName;
}

int Bureaucrat::GetGrade() const {
  return grade_;
}