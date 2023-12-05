/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
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

class AForm {
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

  AForm(const std::string &name,
		bool is_signed,
		const int required_grade_to_sign,
		const int required_grade_to_execute) throw(GradeTooHighException, GradeTooLowException);
  AForm(const AForm &obj);
  virtual ~AForm();
  AForm &operator=(const AForm &obj);

  const std::string &GetName() const;
  bool IsSigned() const;
  int GetRequiredGradeToSign() const throw(GradeTooHighException, GradeTooLowException);
  int GetRequiredGradeToExecute() const throw(GradeTooHighException, GradeTooLowException);

  void BeSigned(Bureaucrat const &bureaucrat) throw(AForm::GradeTooLowException);
  void IsExecutable(Bureaucrat const &executor) const throw(AForm::GradeTooLowException, AForm::NotSignedYet);
  virtual void Execute(Bureaucrat const &executor) const throw(std::exception) = 0;
 private:
  const std::string kName;
  bool is_signed_;
  const int kRequiredGradeToSign;
  const int kRequiredGradeToExecute;
 protected:
  std::string target_;
};

std::ostream &operator<<(std::ostream &os, AForm &form);

#endif //A_OUT_EX01_CMAKE_BUILD_DEBUG_FORM_HPP_
