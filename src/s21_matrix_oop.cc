#include "s21_matrix_oop.h"

#include <cmath>

// Базовый конструктор, инициализирующий матрицу некоторой заранее заданной
// размерностью
S21Matrix::S21Matrix() : rows_(3), cols_(3) { InitMatrix(); }

//Параметризированный конструктор с количеством строк и столбцов
S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  InitMatrix();
}

//Конструктор копирования, содержит ссылку на копируемый объект
S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  InitMatrix();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

//Конструктор переноса (В качестве параметра содержит двойную ссылку на
//перемещаемый объект)
S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.matrix_ = NULL;
  /// noexcept - для оптимизации при использовании стандартных контейнеров
}

//Деструктор
S21Matrix::~S21Matrix() {
  if (matrix_) {
    for (int i = 0; i < rows_; ++i) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    rows_ = 0;
    cols_ = 0;
  }
}

// accessor
int S21Matrix::GetRows() const { return rows_; }
int S21Matrix::GetCols() const { return cols_; }

// mutator
void S21Matrix::SetRows(int rows) {
  if (rows < 1) {
    throw std::out_of_range("Incorrect size");
  }
  int new_row = 0;
  S21Matrix temp_matrix(rows, cols_);
  if (rows >= rows_) {
    new_row = rows_;
  } else {
    new_row = rows;
  }
  for (int i = 0; i < new_row; ++i) {
    for (int j = 0; j < cols_; ++j) {
      temp_matrix.matrix_[i][j] = matrix_[i][j];
    }
  }
  *this = temp_matrix;
}

void S21Matrix::SetCols(const int cols) {
  int cols_new = 0;
  if (cols < 1) {
    throw std::out_of_range("Incorrect size");
  }
  S21Matrix temp_matrix(rows_, cols);
  if (cols >= cols_) {
    cols_new = cols_;
  } else {
    cols_new = cols;
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_new; ++j) {
      temp_matrix.matrix_[i][j] = matrix_[i][j];
    }
  }
  *this = temp_matrix;
}

void S21Matrix::InitMatrix() {
  if ((rows_ < 1) || (cols_ < 1)) {
    throw std::out_of_range("Incorrect input");
  }
  matrix_ = new double*[rows_]();
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_]();
  }
}

bool S21Matrix::EqMatrix(const S21Matrix& other) const noexcept {
  if (rows_ != other.rows_ || cols_ != other.cols_) return false;
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      if (std::abs(matrix_[i][j] - other.matrix_[i][j]) > 1e-07) {
        return false;
      }
    }
  }
  return true;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range("Different sizes");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range("Different sizes");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = matrix_[i][j] * num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::out_of_range("Incorrect matrix sizes");
  }
  S21Matrix mul_res(rows_, other.cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < other.cols_; ++j) {
      for (int x = 0; x < cols_; ++x) {
        mul_res.matrix_[i][j] += matrix_[i][x] * other.matrix_[x][j];
      }
    }
  }
  *this = mul_res;
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix trans_res(cols_, rows_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      trans_res.matrix_[j][i] = matrix_[i][j];
    }
  }
  return trans_res;
}

S21Matrix S21Matrix::S21Minor(int row_m, int col_m) {
  S21Matrix minor_matrix(rows_ - 1, cols_ - 1);
  for (int x = 0, i = 0; i < rows_; ++i) {
    if (i != row_m) {
      for (int y = 0, j = 0; j < cols_; ++j)
        if (j != col_m) minor_matrix.matrix_[x][y++] = matrix_[i][j];
      x++;
    }
  }
  return minor_matrix;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_ || rows_ < 2) {
    throw std::out_of_range("Incorrect matrix sizes");
  }
  S21Matrix CC_matrix(rows_, cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      S21Matrix temp_matrix(rows_ - 1, cols_ - 1);
      temp_matrix = S21Minor(i, j);
      double det = temp_matrix.Determinant();
      CC_matrix.matrix_[i][j] = det * std::pow(-1, i + j);
    }
  }
  return CC_matrix;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw std::out_of_range("Incorrect matrix sizes");
  }
  double det = 0;
  if (rows_ == 1 && cols_ == 1) {
    det = matrix_[0][0];
  } else {
    for (int j = 0; j < cols_; ++j) {
      S21Matrix matrix_minor(rows_ - 1, cols_ - 1);
      matrix_minor = S21Minor(0, j);
      det += std::pow(-1, j) * matrix_[0][j] * matrix_minor.Determinant();
    }
  }
  return det;
}
S21Matrix S21Matrix::InverseMatrix() {
  if (cols_ != rows_) {
    throw std::out_of_range("Incorrect matrix");
  }
  double det = Determinant();
  if (det == 0.000000) {
    throw std::out_of_range("Calculation error");
  }
  S21Matrix inverse_matrix(rows_, cols_);
  if (rows_ == 1) {
    inverse_matrix.matrix_[0][0] = std::pow(matrix_[0][0], -1);
  } else {
    inverse_matrix = CalcComplements().Transpose() * (1 / det);
  }
  return inverse_matrix;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

S21Matrix operator*(const double num, const S21Matrix& other) {
  S21Matrix result = other;
  result.MulNumber(num);
  return result;
}

S21Matrix operator*(const S21Matrix& other, const double num) {
  S21Matrix result = other;
  result.MulNumber(num);
  return result;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

bool S21Matrix::operator==(const S21Matrix& other) { return EqMatrix(other); }

//Присвоение матрице значений другой матрицы
S21Matrix S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    S21Matrix temp_matrix(other);
    this->~S21Matrix();
    this->rows_ = temp_matrix.rows_;
    this->cols_ = temp_matrix.cols_;
    this->matrix_ = temp_matrix.matrix_;
    temp_matrix.matrix_ = nullptr;
  }
  return *this;
}

// //Индексация по элементам матрицы (строка, колонка)
double& S21Matrix::operator()(const int i, const int j) const {
  if ((i >= rows_) || (j >= cols_) || (i < 0) || (j < 0)) {
    throw std::out_of_range("Incorrect matrix");
  }
  return matrix_[i][j];
}

double& S21Matrix::operator()(int i, int j) {
  if ((i >= rows_) || (j >= cols_) || (i < 0) || (j < 0)) {
    throw std::out_of_range("Incorrect matrix");
  }
  return matrix_[i][j];
}