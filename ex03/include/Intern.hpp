/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:14:09 by tkuramot          #+#    #+#             */
/*   Updated: 2023/12/05 18:14:39 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/12/05.
//

#ifndef A_OUT_EX03_INTERN_HPP_
#define A_OUT_EX03_INTERN_HPP_

#include "Form.hpp"
#include <string>

class Intern {
public:
  Intern();
  Intern(const Intern &obj);
  ~Intern();
  Intern &operator=(const Intern &obj);

  Form *MakeForm(std::string form_name, std::string target);
  static Form *MakeShrubberyCreationForm(const std::string &target);
  static Form *MakeRobotomyRequestForm(const std::string &target);
  static Form *MakePresidentialPardonForm(const std::string &target);
};

#endif // A_OUT_EX03_INTERN_HPP_
