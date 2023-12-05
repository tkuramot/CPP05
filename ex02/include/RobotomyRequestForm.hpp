/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:08:34 by tkuramot          #+#    #+#             */
/*   Updated: 2023/12/05 13:26:01 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/12/04.
//

#ifndef A_OUT_EX02_ROBOTOMYREQUESTFORM_HPP_
#define A_OUT_EX02_ROBOTOMYREQUESTFORM_HPP_

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 public:
  RobotomyRequestForm(const std::string &name, bool is_signed);
  RobotomyRequestForm(const RobotomyRequestForm &obj);
  ~RobotomyRequestForm();
  RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);

  void Execute(Bureaucrat const &executor) const throw(AForm::GradeTooLowException, AForm::NotSignedYet);
};

#endif //A_OUT_EX02_ROBOTOMYREQUESTFORM_HPP_
