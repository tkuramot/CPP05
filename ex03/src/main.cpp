/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 23:41:48 by tkuramot          #+#    #+#             */
/*   Updated: 2023/12/03 02:39:29 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/11/28.
//

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
  {
    std::cout << "==================Intern==================" << std::endl;
    Intern someRandomIntern;

    Form *scf = someRandomIntern.MakeForm("shrubbery creation", "home");
    std::cout << *scf << std::endl;
    delete scf;

    Form *rrf = someRandomIntern.MakeForm("robotomy request", "John");
    std::cout << *rrf << std::endl;
    delete rrf;

    Form *ppf = someRandomIntern.MakeForm("presidential pardon", "John");
    std::cout << *ppf << std::endl;
    delete ppf;

    Form *none = someRandomIntern.MakeForm("none", "none");
    std::cout << none << std::endl;
  }
  return 0;
}