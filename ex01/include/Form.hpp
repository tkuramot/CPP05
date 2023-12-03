/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
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

#ifndef A_OUT_EX01_CMAKE_BUILD_DEBUG_FORM_HPP_
#define A_OUT_EX01_CMAKE_BUILD_DEBUG_FORM_HPP_

#include <iostream>

class Bureaucrat;

class Form {
 public:
  class GradeTooHighException : public std::exception {
   public:
	virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
	virtual const char *what() const throw();
  };
  Form(const std::string &name,
	   bool is_signed,
	   const int required_grade_to_sign,
	   const int required_grade_to_execute) throw(GradeTooHighException, GradeTooLowException);
  Form(const Form &obj);
  ~Form();
  Form &operator=(const Form &obj);
  const std::string &GetName() const;
  bool IsSigned() const;
  const int GetRequiredGradeToSign() const throw(GradeTooHighException, GradeTooLowException);
  const int GetRequiredGradeToExecute() const throw(GradeTooHighException, GradeTooLowException);
  void BeSigned(const Bureaucrat &bureaucrat) throw(Form::GradeTooLowException);
 private:
  const std::string kName;
  bool is_signed_;
  const int kRequiredGradeToSign;
  const int kRequiredGradeToExecute;
};

std::ostream &operator<<(std::ostream &os, Form &form);

#endif //A_OUT_EX01_CMAKE_BUILD_DEBUG_FORM_HPP_
