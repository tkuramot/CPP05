/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:08:20 by tkuramot          #+#    #+#             */
/*   Updated: 2023/12/05 00:02:15 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/12/04.
//

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name,
											 bool is_signed) : AForm(name,
																	 is_signed,
																	 145,
																	 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
  AForm::operator=(obj);
  return *this;
}

void ShrubberyCreationForm::Execute(Bureaucrat const &executor) const
throw(AForm::GradeTooLowException, AForm::NotSignedYet) {
  AForm::IsExecutable(executor);
  std::ofstream shrubbery_file(executor.GetName() + "_shrubbery");
  shrubbery_file.exceptions(std::ofstream::badbit | std::ofstream::failbit);
  shrubbery_file << "      ccee88oo" << std::endl
				 << "   C8O8O8Q8PoOb o8oo" << std::endl
				 << "dOB69QO8PdUOpugoO9bD" << std::endl
				 << "CgggbU8OU qOp qOdoUOdcb" << std::endl
				 << "      6OuU  /p u gcoUodpP" << std::endl
				 << "      8boU O U lpoUugoOc" << std::endl
				 << "     qggUgUg /gUocUodcUo" << std::endl
				 << "      8oooooo    8ooooo" << std::endl;
  shrubbery_file.close();
}
