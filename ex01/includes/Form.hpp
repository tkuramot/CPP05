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

class Form {
 public:
  class GradeTooHighException : public std::exception {
	virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
	virtual const char *what() const throw();
  };
  Form(const std::string &name,
	   bool is_signed,
	   const int required_grade_to_sign,
	   const int required_grade_to_execute);
  Form(const Form &obj);
  ~Form();
  Form &operator=(const Form &obj);
  const std::string &GetName() const;
  bool IsSigned() const;
  const int GetRequiredGradeToSign() const;
  const int GetRequiredGradeToExecute() const;
 private:
  const std::string kName;
  bool is_signed_;
  const int kRequiredGradeToSign;
  const int kRequiredGradeToExecute;
};

#endif //A_OUT_EX01_CMAKE_BUILD_DEBUG_FORM_HPP_
