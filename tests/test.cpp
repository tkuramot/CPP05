/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:16:08 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/29 11:16:08 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by k.t. on 2023/11/29.
//

#include <gtest/gtest.h>
#include "Bureaucrat.hpp"

class BureaucratTest : public ::testing::Test {
 protected:
  Bureaucrat *bureaucrat;

  void SetUp() override {
	bureaucrat = new Bureaucrat("John Doe", 50);
  }

  void TearDown() override {
	delete bureaucrat;
  }
};

// コンストラクタのテスト
TEST_F(BureaucratTest, ConstructorNormalCondition) {
EXPECT_EQ("John Doe", bureaucrat->GetName());
EXPECT_EQ(50, bureaucrat->GetGrade());
}

TEST_F(BureaucratTest, ConstructorHighGradeException) {
EXPECT_THROW(Bureaucrat("John Doe", 0), Bureaucrat::GradeTooHighException);
}

TEST_F(BureaucratTest, ConstructorLowGradeException) {
EXPECT_THROW(Bureaucrat("John Doe", 151), Bureaucrat::GradeTooLowException);
}

// コピー構築子のテスト
TEST_F(BureaucratTest, CopyConstructor) {
Bureaucrat copy = *bureaucrat;
EXPECT_EQ(copy.GetName(), bureaucrat->GetName());
EXPECT_EQ(copy.GetGrade(), bureaucrat->GetGrade());
}

// 代入演算子のテスト
TEST_F(BureaucratTest, AssignmentOperator) {
Bureaucrat another("Jane Doe", 75);
another = *bureaucrat;
EXPECT_EQ(another.GetName(), bureaucrat->GetName());
EXPECT_EQ(another.GetGrade(), bureaucrat->GetGrade());
}

// 昇進・降進のテスト（境界値分析）
TEST_F(BureaucratTest, PromoteToHighestGrade) {
bureaucrat->Promote(49); // 50から最高グレードへ
EXPECT_EQ(bureaucrat->GetGrade(), 1);
}

TEST_F(BureaucratTest, DemoteToLowestGrade) {
bureaucrat->Demote(100); // 50から最低グレードへ
EXPECT_EQ(bureaucrat->GetGrade(), 150);
}

// 昇進・降進の異常系テスト
TEST_F(BureaucratTest, PromoteBeyondHighestGrade) {
EXPECT_THROW(bureaucrat->Promote(51), Bureaucrat::GradeTooHighException);
}

TEST_F(BureaucratTest, DemoteBeyondLowestGrade) {
EXPECT_THROW(bureaucrat->Demote(101), Bureaucrat::GradeTooLowException);
}

// その他必要なテストをここに追加…
