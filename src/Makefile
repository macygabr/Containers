
TARGET = s21_vector.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c++20 -lstdc++
TEST_FLAGS = -lgtest -pthread
TEST_TARGET = testing_exe

all: test

clean:

	rm -rf *.o *.a *.out *.log $(TEST_TARGET)

test: clean
	$(CC) $(CFLAGS) s21_vector/*.cpp $(TEST_FLAGS) -o $(TEST_TARGET)
	./$(TEST_TARGET)