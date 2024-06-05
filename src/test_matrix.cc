#include <gtest/gtest.h>

#include <iostream>

#include "s21_matrix_oop.h"

TEST(Constructor, test_1) {
  S21Matrix A;
  EXPECT_EQ(A.GetCols(), 3);
  EXPECT_EQ(A.GetRows(), 3);
}

TEST(Constructor, test_2) {
  S21Matrix A;
  EXPECT_EQ(A.GetCols(), 3);
  EXPECT_EQ(A.GetRows(), 3);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      EXPECT_DOUBLE_EQ(0, A(i, j));
    }
  }
}

TEST(Constructor, test_3) {
  S21Matrix C(2, 2);
  C(0, 0) = 5.000000;
  C(0, 1) = 4.000000;
  C(1, 0) = 2.000000;
  C(1, 1) = 5.000000;
  S21Matrix A(C);
  EXPECT_EQ(true, C.EqMatrix(A));
}

TEST(Constructor, test_4) {
  S21Matrix C(3, 2);
  S21Matrix A(3, 2);
  C(0, 0) = 5.000000;
  C(0, 1) = 4.000000;
  C(1, 0) = 2.000000;
  C(1, 1) = 5.000000;
  C(2, 0) = 3.000000;
  C(2, 1) = 6.000000;

  A(0, 0) = 5.000000;
  A(0, 1) = 4.000000;
  A(1, 0) = 2.000000;
  A(1, 1) = 5.000000;
  A(2, 0) = 3.000000;
  A(2, 1) = 6.000000;
  S21Matrix B(std::move(C));
  EXPECT_EQ(true, A == B);
}

TEST(Setter, test_5) {
  S21Matrix A(4, 4), B(3, 3);
  A(0, 0) = 15.0;
  A(0, 1) = 12.0;
  A(0, 2) = 1.0;
  A(0, 3) = 7.0;

  A(1, 0) = 15.0;
  A(1, 1) = 12.0;
  A(1, 2) = 1.0;
  A(1, 3) = 7.0;

  A(2, 0) = 15.0;
  A(2, 1) = 12.0;
  A(2, 2) = 1.0;
  A(2, 3) = 7.0;

  A(3, 0) = 15.0;
  A(3, 1) = 12.0;
  A(3, 2) = 1.0;
  A(3, 3) = 7.0;

  A.SetRows(3);
  A.SetCols(3);
  EXPECT_EQ(3, A.GetRows());
  EXPECT_EQ(3, A.GetCols());
  B(0, 0) = 15.0;
  B(0, 1) = 12.0;
  B(0, 2) = 1.0;

  B(1, 0) = 15.0;
  B(1, 1) = 12.0;
  B(1, 2) = 1.0;

  B(2, 0) = 15.0;
  B(2, 1) = 12.0;
  B(2, 2) = 1.0;

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      EXPECT_DOUBLE_EQ(B(i, j), A(i, j));
    }
  }
}

TEST(Setter, test_6) {
  S21Matrix A;
  A.SetRows(5);
  A.SetCols(5);
  EXPECT_EQ(5, A.GetRows());
  EXPECT_EQ(5, A.GetCols());
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      EXPECT_DOUBLE_EQ(0, A(i, j));
    }
  }
}

TEST(Setter, test_7) {
  S21Matrix A;
  EXPECT_ANY_THROW(A.SetRows(-1));
}

TEST(Setter, test_8) {
  S21Matrix A;
  EXPECT_ANY_THROW(A.SetCols(-1));
}

TEST(Setter, test_9) {
  S21Matrix A(3, 3), B(4, 4);
  A(0, 0) = 15.0;
  A(0, 1) = 12.0;
  A(0, 2) = 1.0;

  A(1, 0) = 15.0;
  A(1, 1) = 12.0;
  A(1, 2) = 1.0;

  A(2, 0) = 15.0;
  A(2, 1) = 12.0;
  A(2, 2) = 1.0;

  A.SetRows(4);
  A.SetCols(4);
  EXPECT_EQ(4, A.GetRows());
  EXPECT_EQ(4, A.GetCols());
  B(0, 0) = 15.0;
  B(0, 1) = 12.0;
  B(0, 2) = 1.0;
  B(0, 3) = 0.0;

  B(1, 0) = 15.0;
  B(1, 1) = 12.0;
  B(1, 2) = 1.0;
  B(1, 3) = 0.0;

  B(2, 0) = 15.0;
  B(2, 1) = 12.0;
  B(2, 2) = 1.0;
  B(2, 3) = 0.0;

  B(3, 0) = 0.0;
  B(3, 1) = 0.0;
  B(3, 2) = 0.0;
  B(3, 3) = 0.0;

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      EXPECT_DOUBLE_EQ(B(i, j), A(i, j));
    }
  }
}

TEST(EqMatrix, test_10) {
  S21Matrix A(3, 3), B(3, 3);
  A(0, 0) = 15.0;
  A(0, 1) = 12.0;
  A(0, 2) = 1.0;

  A(1, 0) = 15.0;
  A(1, 1) = 12.0;
  A(1, 2) = 1.0;

  A(2, 0) = 15.0;
  A(2, 1) = 12.0;
  A(2, 2) = 1.0;

  B(0, 0) = 15.0;
  B(0, 1) = 12.0;
  B(0, 2) = 1.0;

  B(1, 0) = 15.0;
  B(1, 1) = 12.0;
  B(1, 2) = 1.0;

  B(2, 0) = 15.0;
  B(2, 1) = 12.0;
  B(2, 2) = 1.0;

  EXPECT_EQ(true, A.EqMatrix(B));
}

TEST(EqMatrix, test_11) {
  S21Matrix A(3, 3), B(3, 3);
  A(0, 0) = 15.0;
  A(0, 1) = 12.0;
  A(0, 2) = 1.0;

  A(1, 0) = 15.0;
  A(1, 1) = 12.0;
  A(1, 2) = 1.0;

  A(2, 0) = 15.0;
  A(2, 1) = 12.0;
  A(2, 2) = 1.0;

  B(0, 0) = 155.0;
  B(0, 1) = 12.0;
  B(0, 2) = 1.0;

  B(1, 0) = 15.0;
  B(1, 1) = 12.0;
  B(1, 2) = 1.0;

  B(2, 0) = 155.0;
  B(2, 1) = 12.0;
  B(2, 2) = 1.0;

  EXPECT_EQ(false, A.EqMatrix(B));
}

TEST(EqMatrix, test_12) {
  S21Matrix C(3, 2);
  C(0, 0) = 5.000000;
  C(0, 1) = 4.000000;
  C(1, 0) = 2.000000;
  C(1, 1) = 5.000000;
  C(2, 0) = 3.000000;
  C(2, 1) = 6.000000;
  S21Matrix A(2, 2);
  A(0, 0) = 5.000000;
  A(0, 1) = 4.000000;
  A(1, 0) = 2.000000;
  A(1, 1) = 5.000000;
  EXPECT_EQ(false, A.EqMatrix(C));
}

TEST(EqMatrix, test_13) {
  S21Matrix C(2, 2);
  S21Matrix A(3, 3);
  EXPECT_FALSE(A.EqMatrix(C));
}

TEST(SumMatrix, test_14) {
  S21Matrix A(5, 4), B(3, 2);
  EXPECT_ANY_THROW(A.SumMatrix(B));
}

TEST(SumMatrix, test_15) {
  S21Matrix A(3, 3), B(3, 3), C(3, 3), D(3, 3);
  A(0, 0) = 15.0;
  A(0, 1) = 12.0;
  A(0, 2) = 1.0;

  A(1, 0) = 15.0;
  A(1, 1) = 12.0;
  A(1, 2) = 1.0;

  A(2, 0) = 15.0;
  A(2, 1) = 12.0;
  A(2, 2) = 1.0;

  B(0, 0) = 15.0;
  B(0, 1) = 12.0;
  B(0, 2) = 1.0;

  B(1, 0) = 15.0;
  B(1, 1) = 12.0;
  B(1, 2) = 1.0;

  B(2, 0) = 15.0;
  B(2, 1) = 12.0;
  B(2, 2) = 1.0;

  C(0, 0) = 30.0;
  C(0, 1) = 24.0;
  C(0, 2) = 2.0;

  C(1, 0) = 30.0;
  C(1, 1) = 24.0;
  C(1, 2) = 2.0;

  C(2, 0) = 30.0;
  C(2, 1) = 24.0;
  C(2, 2) = 2.0;
  D = A + B;
  A.SumMatrix(B);

  EXPECT_EQ(true, D == C);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      EXPECT_DOUBLE_EQ(C(i, j), A(i, j));
    }
  }
}

TEST(SubMatrix, test_16) {
  S21Matrix A(5, 4), B(3, 2);
  EXPECT_ANY_THROW(A.SubMatrix(B));
}

TEST(SubMatrix, test_17) {
  S21Matrix A(3, 3), B(3, 3), C(3, 3), D(3, 3);
  A(0, 0) = 15.0;
  A(0, 1) = 12.0;
  A(0, 2) = 1.0;

  A(1, 0) = 15.0;
  A(1, 1) = 12.0;
  A(1, 2) = 1.0;

  A(2, 0) = 15.0;
  A(2, 1) = 12.0;
  A(2, 2) = 1.0;

  B(0, 0) = 15.0;
  B(0, 1) = 12.0;
  B(0, 2) = 1.0;

  B(1, 0) = 15.0;
  B(1, 1) = 12.0;
  B(1, 2) = 1.0;

  B(2, 0) = 15.0;
  B(2, 1) = 12.0;
  B(2, 2) = 1.0;

  C(0, 0) = 0.0;
  C(0, 1) = 0.0;
  C(0, 2) = 0.0;

  C(1, 0) = 0.0;
  C(1, 1) = 0.0;
  C(1, 2) = 0.0;

  C(2, 0) = 0.0;
  C(2, 1) = 0.0;
  C(2, 2) = 0.0;
  D = A - B;
  A.SubMatrix(B);
  EXPECT_EQ(true, D == C);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      EXPECT_DOUBLE_EQ(C(i, j), A(i, j));
    }
  }
}

TEST(MulNumber, test_18) {
  S21Matrix A(3, 3), B(3, 3);
  A(0, 0) = 15.0;
  A(0, 1) = 12.0;
  A(0, 2) = 1.0;

  A(1, 0) = 15.0;
  A(1, 1) = 12.0;
  A(1, 2) = 1.0;

  A(2, 0) = 15.0;
  A(2, 1) = 12.0;
  A(2, 2) = 1.0;

  double num = 10;
  A.MulNumber(num);
  B(0, 0) = 150.0;
  B(0, 1) = 120.0;
  B(0, 2) = 10.0;

  B(1, 0) = 150.0;
  B(1, 1) = 120.0;
  B(1, 2) = 10.0;

  B(2, 0) = 150.0;
  B(2, 1) = 120.0;
  B(2, 2) = 10.0;

  EXPECT_EQ(true, A.EqMatrix(B));
}

TEST(MulNumber, test_19) {
  S21Matrix C(3, 2), B(3, 2), D(3, 2);
  C(0, 0) = 5.000000;
  C(0, 1) = 4.000000;
  C(1, 0) = 2.000000;
  C(1, 1) = 5.000000;
  C(2, 0) = 3.000000;
  C(2, 1) = 6.000000;
  S21Matrix result(3, 2);
  result(0, 0) = 15.000000;
  result(0, 1) = 12.000000;
  result(1, 0) = 6.000000;
  result(1, 1) = 15.000000;
  result(2, 0) = 9.000000;
  result(2, 1) = 18.000000;
  B = C * 3.0;
  D = 3.0 * C;
  C *= 3.0;
  EXPECT_EQ(true, B == result);
  EXPECT_EQ(true, D == result);
  EXPECT_EQ(true, C == result);
}

TEST(MulMatrix, test_20) {
  S21Matrix A(3, 3), B(3, 2), C(3, 2);
  A(0, 0) = 15.0;
  A(0, 1) = 12.0;
  A(0, 2) = 1.0;
  A(1, 0) = 15.0;
  A(1, 1) = 12.0;
  A(1, 2) = 1.0;
  A(2, 0) = 15.0;
  A(2, 1) = 12.0;
  A(2, 2) = 1.0;

  B(0, 0) = 36.0;
  B(0, 1) = -12.0;
  B(1, 0) = 7.0;
  B(1, 1) = 1.1110;
  B(2, 0) = 2.0;
  B(2, 1) = -99.0;
  S21Matrix result(3, 2);
  result(0, 0) = 626.000000;
  result(0, 1) = -265.668;
  result(1, 0) = 626.000000;
  result(1, 1) = -265.668;
  result(2, 0) = 626.000000;
  result(2, 1) = -265.668;
  C = A * B;
  A.MulMatrix(B);
  EXPECT_EQ(true, A == result);
  EXPECT_EQ(true, C == result);
}

TEST(MulMatrix, test_21) {
  S21Matrix A(2, 2), B(3, 4);
  EXPECT_ANY_THROW(A.MulMatrix(B));
}

TEST(Transpose, test_22) {
  S21Matrix A(2, 3), B(3, 2), C(3, 2);
  A(0, 0) = 5.000000;
  A(0, 1) = 4.000000;
  A(0, 2) = 3.000000;
  A(1, 0) = 1.000000;
  A(1, 1) = 7.000000;
  A(1, 2) = 8.000000;

  B(0, 0) = 5.0;
  B(0, 1) = 1.0;
  B(1, 0) = 4.0;
  B(1, 1) = 7.0;
  B(2, 0) = 3.0;
  B(2, 1) = 8.0;
  C = A.Transpose();
  EXPECT_EQ(true, B == C);
}

TEST(Determinant, test_23) {
  S21Matrix A(5, 6);
  EXPECT_ANY_THROW(A.Determinant());
}

TEST(Determinant, test_24) {
  S21Matrix A(3, 3);
  double num = 0;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      A(i, j) = num;
      num += 1;
    }
  }
  double det = A.Determinant();
  EXPECT_EQ(0, det);
}

TEST(Determinant, test_25) {
  S21Matrix A(3, 3);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(0, 2) = 3.0;
  A(1, 0) = 0.0;
  A(1, 1) = 4.0;
  A(1, 2) = 2.0;
  A(2, 0) = 5.0;
  A(2, 1) = 2.0;
  A(2, 2) = 1.0;
  double det = A.Determinant();
  EXPECT_EQ(-40, det);
}

TEST(CalcComplements, test_26) {
  S21Matrix A(4, 3);
  EXPECT_ANY_THROW(A.CalcComplements());
}

TEST(CalcComplements, test_27) {
  S21Matrix A(1, 1);
  EXPECT_ANY_THROW(A.CalcComplements());
}

TEST(CalcComplements, test_28) {
  S21Matrix A(3, 3), B(3, 3), C(3, 3);
  A(0, 0) = 9.0;
  A(0, 1) = 2.0;
  A(0, 2) = 3.0;
  A(1, 0) = 7.0;
  A(1, 1) = 4.0;
  A(1, 2) = 8.0;
  A(2, 0) = 1.0;
  A(2, 1) = 5.0;
  A(2, 2) = 1.0;

  C(0, 0) = -36.0;
  C(0, 1) = 1.0;
  C(0, 2) = 31.0;
  C(1, 0) = 13.0;
  C(1, 1) = 6.0;
  C(1, 2) = -43.0;
  C(2, 0) = 4.0;
  C(2, 1) = -51.0;
  C(2, 2) = 22.0;

  B = A.CalcComplements();
  EXPECT_EQ(true, B == C);
}

TEST(InverseMatrix, test_29) {
  S21Matrix A(2, 4);
  EXPECT_ANY_THROW(A.InverseMatrix());
}

TEST(InverseMatrix, test_30) {
  S21Matrix A(3, 3);
  double num = 0;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      A(i, j) = num;
      num += 1;
    }
  }
  EXPECT_ANY_THROW(A.InverseMatrix());
}

TEST(InverseMatrix, test_31) {
  S21Matrix A(1, 1), B(1, 1);
  A(0, 0) = 15;
  B = A.InverseMatrix();
  EXPECT_DOUBLE_EQ(0.066666666666666666, B(0, 0));
}

TEST(InverseMatrix, test_32) {
  S21Matrix A(3, 3), B(3, 3), C(3, 3);
  A(0, 0) = 9.0;
  A(0, 1) = 2.0;
  A(0, 2) = 3.0;
  A(1, 0) = 7.0;
  A(1, 1) = 4.0;
  A(1, 2) = 8.0;
  A(2, 0) = 1.0;
  A(2, 1) = 5.0;
  A(2, 2) = 1.0;
  B = A.InverseMatrix();
  C(0, 0) = 0.1572052402;
  C(0, 1) = -0.056768559;
  C(0, 2) = -0.0174672489;
  C(1, 0) = -0.0043668122;
  C(1, 1) = -0.0262008734;
  C(1, 2) = 0.2227074236;
  C(2, 0) = -0.135371179;
  C(2, 1) = 0.1877729258;
  C(2, 2) = -0.096069869;
  EXPECT_DOUBLE_EQ(true, B == C);
}
TEST(Operator, test_33) {
  S21Matrix A(2, 2);
  A(0, 0) = 2023.000000;
  A(0, 1) = 2023.000000;
  A(1, 0) = 2023.000000;
  A(1, 1) = 2023.000000;
  S21Matrix B(2, 2);
  B(0, 0) = 23.000000;
  B(0, 1) = 23.000000;
  B(1, 0) = 23.000000;
  B(1, 1) = 23.000000;
  S21Matrix C(2, 2);
  C(0, 0) = 2046.000000;
  C(0, 1) = 2046.000000;
  C(1, 0) = 2046.000000;
  C(1, 1) = 2046.000000;
  A += B;
  EXPECT_EQ(true, A == C);
}
TEST(Operator, test_34) {
  S21Matrix A(2, 2);
  A(0, 0) = 2023.000000;
  A(0, 1) = 2023.000000;
  A(1, 0) = 2023.000000;
  A(1, 1) = 2023.000000;
  S21Matrix B(2, 2);
  B(0, 0) = 23.000000;
  B(0, 1) = 23.000000;
  B(1, 0) = 23.000000;
  B(1, 1) = 23.000000;
  S21Matrix C(2, 2);
  C(0, 0) = 2000.000000;
  C(0, 1) = 2000.000000;
  C(1, 0) = 2000.000000;
  C(1, 1) = 2000.000000;
  A -= B;
  EXPECT_EQ(true, A == C);
}
TEST(Operator, test_35) {
  S21Matrix A(2, 2);
  A(0, 0) = 2023.000000;
  A(0, 1) = 2023.000000;
  A(1, 0) = 2023.000000;
  A(1, 1) = 2023.000000;
  S21Matrix B(2, 2);
  B(0, 0) = 23.000000;
  B(0, 1) = 23.000000;
  B(1, 0) = 23.000000;
  B(1, 1) = 23.000000;
  S21Matrix C(2, 2);
  C(0, 0) = 93058.000000;
  C(0, 1) = 93058.000000;
  C(1, 0) = 93058.000000;
  C(1, 1) = 93058.000000;
  A *= B;
  EXPECT_EQ(true, A == C);
}

TEST(Operators, test_36) {
  S21Matrix a(3, 3);
  EXPECT_ANY_THROW(a(4, 4));
}

TEST(Operators, test_37) {
  const S21Matrix a(3, 3);
  EXPECT_ANY_THROW(a(4, 4));
}
TEST(Operators_const, test_38) {
  const S21Matrix C(2, 2);
  C(0, 0) = 5.000000;
  C(0, 1) = 4.000000;
  C(1, 0) = 2.000000;
  C(1, 1) = 5.000000;
  S21Matrix A(C);
  EXPECT_EQ(true, C.EqMatrix(A));
}

TEST(Errors, test_39) { EXPECT_ANY_THROW(S21Matrix A(-1, -1)); }

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
