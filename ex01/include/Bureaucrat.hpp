/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 23:40:59 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/29 00:48:41 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/11/28.
//

#ifndef A_OUT_EX00_BUREAUCRAT_HPP_
#define A_OUT_EX00_BUREAUCRAT_HPP_

#include <string>

class Form;

class Bureaucrat {
 public:
  class GradeTooHighException : public std::exception {
   public:
	virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
	virtual const char *what() const throw();
  };

  Bureaucrat(const std::string &name, int grade) throw(GradeTooHighException, GradeTooLowException);
  Bureaucrat(const Bureaucrat &obj);
  ~Bureaucrat();
  Bureaucrat &operator=(const Bureaucrat &obj);

  const std::string &GetName() const;
  int GetGrade() const;
  void Promote(int grade_diff) throw(GradeTooHighException);
  void Demote(int grade_diff) throw(GradeTooLowException);
  void SignForm(Form &form) const;

  static const int kHighestGrade = 1;
  static const int kLowestGrade = 150;
 private:
  const std::string kName;
  int grade_;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif //A_OUT_EX00_BUREAUCRAT_HPP_
