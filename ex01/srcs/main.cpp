/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 23:41:48 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/29 12:28:47 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/11/28.
//

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
  Bureaucrat b("Bob", 50);
  b.Demote(100);
  std::cout << b << std::endl;
  Form f("none", false, 50, 80);
  return 0;
}