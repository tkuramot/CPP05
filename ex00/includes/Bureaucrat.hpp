/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 23:40:59 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/29 00:16:48 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/11/28.
//

#ifndef A_OUT_EX00_BUREAUCRAT_HPP_
#define A_OUT_EX00_BUREAUCRAT_HPP_

#include <string>

class Bureaucrat {
 public:
  Bureaucrat(const std::string &name, int grade);
  Bureaucrat(const Bureaucrat &obj);
  ~Bureaucrat();
  const std::string &GetName() const;
  int GetGrade() const;
  void Promote(int grade);
  void Demote(int grade);
 private:
  const std::string kName;
  int grade_;
};

#endif //A_OUT_EX00_BUREAUCRAT_HPP_
