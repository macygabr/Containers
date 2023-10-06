<<<<<<< HEAD
CC=g++
CFLAGS= -c  
FILES = s21_map
TEST_FLAGS=-lgtest  -pthread
TEST_FUNC= map_tests.cc
# TEST_FUNC= main.cc set_tests.cc
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
	rm -rf *.a */*.a *.o */*.o */*.out */test report gcov *.gcno *.gcda html
	$(cleanMAC)

# $(FILES).a:
# 	cd $(PATH_TO_FILE); $(CC) $(CFLAGS) $(FILES).; ar rcs $(FILES).a $(FILES).o; rm *.o 

# test: $(FILES).a
# 	cd $(PATH_TO_FILE); $(CC) $(TEST_FUNC) $(FILES).a -o test $(TEST_FLAGS)
# 	./$(PATH_TO_FILE)/test
# 	make clean
test: 
#	make goclang
	make clean
	cd tests; $(CC) $(TEST_FUNC) -o test $(TEST_FLAGS); ./test

clang:
	clang-format -style="{BasedOnStyle: Google}" -n $(PATH_TO_FILE)/*.h $(PATH_TO_FILE)/*.inc

goclang:
	clang-format -style="{BasedOnStyle: Google}" -i */*.h */*.inc */*.cc


valgrind: test
	CK_FORK=no valgrind --tool=memcheck --leak-check=yes --track-origins=yes  -s ./tests/test

check_cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config $(FILES).cc *.h

leaks: clean $(FILES).a
	$(CC) $(TEST_FUNC) $(FILES).a -o test $(TEST_FLAGS)
	leaks -atExit -- ./test

push: clean goclang
	git add .
	git commit -m "$(c)"
	git push

.PHONY: installDox dvi clean $(FILES).a clang goclang test valgrind check_cppcheck push
=======

TARGET = s21_vector.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c++20 -lstdc++
TEST_FLAGS = -lgtest -pthread
TEST_TARGET = testing_exe

all: test

clean:

	rm -rf *.o *.a *.out *.log $(TEST_TARGET)

test: clean
	$(CC) $(CFLAGS) s21_list/*.cpp $(TEST_FLAGS) -o $(TEST_TARGET)
	./$(TEST_TARGET)



>>>>>>> roddstat
