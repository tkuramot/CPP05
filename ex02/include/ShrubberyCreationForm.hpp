//
// Created by k.t. on 2023/12/04.
//

#ifndef A_OUT_EX02_SHRUBBERYCREATIONFORM_HPP_
#define A_OUT_EX02_SHRUBBERYCREATIONFORM_HPP_

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 public:
  ShrubberyCreationForm(const std::string &name);
  ShrubberyCreationForm(const ShrubberyCreationForm &obj);
  ~ShrubberyCreationForm();
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);

  void Execute(Bureaucrat const &executor) const
  throw(AForm::GradeTooLowException, AForm::NotSignedYet, std::ios_base::failure);
};

#endif //A_OUT_EX02_SHRUBBERYCREATIONFORM_HPP_
