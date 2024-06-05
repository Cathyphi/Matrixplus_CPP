#ifndef CPP1_S21MATRIXPLUS_1_SRC_S21_MATRIX_OOP_H
#define CPP1_S21MATRIXPLUS_1_SRC_S21_MATRIX_OOP_H
#include <cmath>
#include <iostream>

class S21Matrix {
 public:
  // constructors and destructor
  S21Matrix();  // Базовый конструктор, инициализирующий матрицу некоторой
                // заранее заданной размерностью
  S21Matrix(int rows, int cols);  //Параметризированный конструктор с
                                  //количеством строк и столбцов
  S21Matrix(const S21Matrix& other);  //Конструктор копирования, содержит ссылку
                                      //на копируемый объект
  S21Matrix(S21Matrix&& other) noexcept;  //Конструктор переноса (В качестве
                                          //параметра содержит двойную ссылку на
                                          //перемещаемый объект)
  ~S21Matrix();  // Destructor

  // getters ans setters
  int GetRows() const;
  int GetCols() const;
  void SetRows(int rows);
  void SetCols(const int cols);

  // public methods
  void SumMatrix(const S21Matrix& other);
  bool EqMatrix(const S21Matrix& other) const noexcept;
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);

  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // operators overloads
  S21Matrix operator+(const S21Matrix& other);  //Сложение двух матриц
  S21Matrix operator-(
      const S21Matrix& other);  //Вычитание одной матрицы из другой
  S21Matrix operator*(const S21Matrix& other);  //Умножение матриц
  friend S21Matrix operator*(
      const double num, const S21Matrix& other);  //умножение числа на матрицу
  friend S21Matrix operator*(const S21Matrix& other,
                             const double num);  //умножение матрицы на число
  bool operator==(
      const S21Matrix& other);  //Проверка на равенство матриц (EqMatrix)
  S21Matrix operator=(
      const S21Matrix& other);  //Присвоение матрице значений другой матрицы
  S21Matrix& operator+=(
      const S21Matrix& other);  //Присвоение сложения (SumMatrix)
  S21Matrix& operator-=(
      const S21Matrix& other);  //Присвоение разности (SubMatrix)
  S21Matrix& operator*=(
      const S21Matrix& other);  //Присвоение умножения (MulMatrix)
  S21Matrix& operator*=(const double num);  //Присвоение умножения (MulNumber)
  double& operator()(const int i, const int j)
      const;  //Индексация по элементам матрицы (строка, колонка)
  double& operator()(int i, int j);

 private:
  int rows_, cols_;
  double** matrix_;
  void InitMatrix();
  S21Matrix S21Minor(int row_m, int col_m);
};

#endif  // CPP1_S21MATRIXPLUS_1_SRC_S21_MATRIX_OOP_H