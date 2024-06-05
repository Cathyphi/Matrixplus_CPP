CC = gcc -Wall -Werror -Wextra -std=c++17

all: s21_matrix_oop.a

s21_matrix_oop.a:
	$(CC) -c s21_matrix_oop.cc -o s21_matrix_oop.o -lstdc++
	ar rcs s21_matrix_oop.a *.o
	ranlib s21_matrix_oop.a

clean:
	rm -rf *.o *.a *.out *.info report test.dSYM *.gcno test

test: clean
	$(CC) test_matrix.cc s21_matrix_oop.cc -lgtest -o test -lstdc++
	./test

gcov_report: test
	$(CC) --coverage s21_matrix_oop.cc -c -lstdc++
	$(CC) test_matrix.cc -c -lstdc++
	$(CC) --coverage *.o -lgtest -o test -lstdc++
	./test
	lcov -t "my_test" -c -d ./ --output-file ./test.info
	genhtml -o report test.info
	rm -rf *.gcda *.gch *.gcno *.out *.o *.out
	open report/index.html

style:
	clang-format -n *.cc *.h

leaks: test
	leaks -atExit -- ./test