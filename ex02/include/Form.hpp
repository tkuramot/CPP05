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
  class NotSignedYet : public std::exception {
   public:
	virtual const char *what() const throw();
  };

  Form(const std::string &name,
	   bool is_signed,
	   const int required_grade_to_sign,
	   const int required_grade_to_execute) throw(GradeTooHighException, GradeTooLowException);
  Form(const Form &obj);
  virtual ~Form();
  Form &operator=(const Form &obj);

  const std::string &GetName() const;
  bool IsSigned() const;
  int GetRequiredGradeToSign() const throw(GradeTooHighException, GradeTooLowException);
  int GetRequiredGradeToExecute() const throw(GradeTooHighException, GradeTooLowException);

  void BeSigned(Bureaucrat const &bureaucrat) throw(Form::GradeTooLowException);
  void IsExecutable(Bureaucrat const &executor) const throw(Form::GradeTooLowException, Form::NotSignedYet);
  virtual void Execute(Bureaucrat const &executor) const throw(std::exception) = 0;
 private:
  const std::string kName;
  bool is_signed_;
  const int kRequiredGradeToSign;
  const int kRequiredGradeToExecute;
 protected:
  std::string target_;
};

std::ostream &operator<<(std::ostream &os, Form &form);

#endif //A_OUT_EX01_CMAKE_BUILD_DEBUG_FORM_HPP_
