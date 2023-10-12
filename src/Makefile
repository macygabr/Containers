CC=g++
FILES = s21_map
TEST_FLAGS=-lgtest -pthread -lgtest_main -lstdc++ -lm
GTEST_FLAG = --gtest_repeat=1 --gtest_shuffle
TEST_FUNC=  map_tests.cc vector_tests.cc list_tests.cc queue_tests.cc stack_tests.cc array_tests.cc  set_tests.cc multiset_tests.cc   
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

test: 
	make clean
	cd tests; $(CC) $(TEST_FUNC) -o test $(TEST_FLAGS); ./test $(GTEST_FLAG)

clang:
	clang-format -style="{BasedOnStyle: Google}" -n $(PATH_TO_FILE)/*.h $(PATH_TO_FILE)/*.inc

goclang:
	clang-format -style="{BasedOnStyle: Google}" -i */*.h */*.inc */*.cc


valgrind: test
	CK_FORK=no valgrind --tool=memcheck --leak-check=yes --track-origins=yes  -s ./tests/test

check_cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config $(FILES).cc *.h

leaks: clean $(FILES).a test
	leaks -atExit -- ./tests/test

push: clean goclang
	git add .
	git commit -m "$(c)"
	git push

gcov_report: clean
#	g++ -std=c++17 -g -Wall -Werror -Wextra  --coverage $(SOURCE) ./tests/*.cc -o $(TEST_FILE_COV) $(TESTFLAGS)
#	./$(TEST_FILE_COV)
#	lcov -t "$(TEST_FILE_COV)" -o $(TEST_FILE_COV).info -c -d . --no-external  
#	genhtml -o report $(TEST_FILE_COV).info
	g++ -std=c++17 -g --coverage ./tests/map_tests.cc -o greport $(TEST_FLAGS)
	./greport
	lcov -t "greport" -o greport.info -c -d . --no-external
#	genhtml -o report fizzbuzz.info
	

.PHONY: installDox dvi clean $(FILES).a clang goclang test valgrind check_cppcheck push


#CC = g++ -std=c++17 -g
#CPPFLAGS = -Wall -Werror -Wextra
#GCOVFLAGS = --coverage
#CLEAN	= rm -rf
#
#OS := $(shell uname)
#ifeq ($(OS),Darwin)
#	LEAKS = CK_FORK=no leaks --atExit --
#	TESTFLAGS = -lgtest -lgtest_main -lm -lstdc++
#else
#	LEAKS = valgrind --leak-check=full --track-origins=yes -s
#	TESTFLAGS = -lgtest -lgtest_main -lm -lstdc++ -lpthread
#endif
#
#NAME = s21_containers
#
#SRC_DIR	= ./array/* ./list/* ./queue/* ./stack/* ./vector/* ./map/* ./set/* ./multiset/*
#
#TEST_FILE	= $(NAME)_test
#TEST_FILE_COV	= $(TEST_FILE)_cov
#TEST_DIR				= ./tests
#TEST_SOURCE_FILE		= *.cc
#TEST = $(TEST_DIR)/$(TEST_SOURCE_FILE)
#
#all: clean test
#
#clean:
#	$(CLEAN) $(TEST_FILE) $(TEST_FILE_FOR_LEAKS) $(TEST_FILE_COV) .clang-format
#	$(CLEAN) *.o *.a *.gcno *.gcda *.info *.out *.gch *.dSYM report
#	$(CLEAN) report*
#
#$(TEST_FILE): $(SOURCE) $(TEST)
#	$(CC) $(CPPFLAGS) $(SOURCE) $(TEST) -o $(TEST_FILE) $(TESTFLAGS)
#
#test: $(TEST_FILE)
#	./$(TEST_FILE)
#
#report/index.html: $(SOURCE) $(TEST)
#	$(CC) $(CPPFLAGS) $(GCOVFLAGS) $(SOURCE) $(TEST) -o $(TEST_FILE_COV) $(TESTFLAGS)
#	./$(TEST_FILE_COV)
#	lcov -t "$(TEST_FILE_COV)" -o $(TEST_FILE_COV).info -c -d . --no-external  
#	genhtml -o report $(TEST_FILE_COV).info
#
#gcov_report: report/index.html
#	open report/index.html
#
#open_report:
#	-$(OPEN) report/index.html
#
#check: leaks style
#
#clang:
#	clang-format -i --style=Google */*.cc */*.h *.h
#
#style:
#	clang-format -n --style=Google */*.cc */*.h *.h
#
#cppcheck:
#	cppcheck --std=c++17 --enable=all --language=c++ --suppress=missingIncludeSystem $(TEST) $(SOURCE)
#
#leaks: $(TEST_FILE)
#	$(LEAKS) ./$(TEST_FILE)
#
#.PHONY: all clean test gcov_report style cppcheck leaks check