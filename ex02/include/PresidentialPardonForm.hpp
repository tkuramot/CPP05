/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:08:44 by tkuramot          #+#    #+#             */
/*   Updated: 2023/12/04 23:09:11 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/12/04.
//

#ifndef A_OUT_EX02_PRESIDENTIALPARDONFORM_HPP_
#define A_OUT_EX02_PRESIDENTIALPARDONFORM_HPP_

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 public:
  PresidentialPardonForm(const std::string target);
  PresidentialPardonForm(const PresidentialPardonForm &obj);
  ~PresidentialPardonForm();
  PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);

  void Execute(Bureaucrat const &bureaucrat) const throw(AForm::GradeTooLowException, AForm::NotSignedYet);
};

#endif //A_OUT_EX02_PRESIDENTIALPARDONFORM_HPP_
