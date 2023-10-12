
# TARGET = s21_stack.a
# CC = gcc
# CFLAGS = -Wall -Werror -Wextra -std=c++17 -lstdc++
# TEST_FLAGS = -lgtest -pthread
# TEST_TARGET = testing_exe

# all: test

# clean:

# 	rm -rf *.o *.a *.out *.log $(TEST_TARGET)

# test: clean
# 	$(CC) $(CFLAGS) s21_stack/*.cpp $(TEST_FLAGS) -o $(TEST_TARGET)
# 	./$(TEST_TARGET)



CC=g++
CFLAGS= -c  
FILES = s21_map
TEST_FLAGS=-lgtest -pthread
GTEST_FLAG = --gtest_repeat=1
TEST_FUNC= s21_stack/*.cpp
#stack_tests.cc stack_tests.cc stack_tests.cc stack_tests.cc
PATH_TO_FILE = s21_map
cleanMAC = echo check

OS := $(shell uname -s)
ifeq ($(OS), Linux)
	TEST_FLAGS += -lsubunit -lrt -lm
	DOX = echo 'you must install doxygen'
else
	DOX =brew install doxygen
	cleanMAC = bash ../../clear.sh
endif

all: test

installDox:
	$(DOX)

installVal:
	sudo apt-get install libgtest-dev libgmock-dev -y
	sudo apt install g++ -y

dvi: clean
	doxygen Doxyfile
	open html/index.html

clean:
	# rm -rf *.a */*.a *.o */*.o */*.out test report gcov *.gcno *.gcda html
	# $(cleanMAC)

test: 
#	make goclang
	make clean
	 $(CC) $(TEST_FUNC) -o test $(TEST_FLAGS); ./test $(GTEST_FLAG)

clang:
	clang-format -style="{BasedOnStyle: Google}" -n $(PATH_TO_FILE)/*.h $(PATH_TO_FILE)/*.inc

goclang:
	clang-format -style="{BasedOnStyle: Google}" -i */*.h */*.inc */*.cc


valgrind: test
	CK_FORK=no valgrind --tool=memcheck --leak-check=yes --track-origins=yes  -s ./test

check_cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config $(FILES).cc *.h

leaks: clean $(FILES).a test
	leaks -atExit -- ./test

push: clean goclang
	git add .
	git commit -m "$(c)"
	git push

.PHONY: installDox dvi clean $(FILES).a clang goclang test valgrind check_cppcheck push
