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
	rm -rf *.a */*.a *.o */*.o */*.out */test report gcov *.gcno *.gcda tests/*.gcno tests/*.gcda html gcov_report tests/*.info
	# $(cleanMAC)

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

gcov_report: 
# clean
#	g++ -std=c++17 -g -Wall -Werror -Wextra  --coverage $(SOURCE) ./tests/*.cc -o $(TEST_FILE_COV) $(TESTFLAGS)
#	./$(TEST_FILE_COV)
#	lcov -t "$(TEST_FILE_COV)" -o $(TEST_FILE_COV).info -c -d . --no-external  
#	genhtml -o report $(TEST_FILE_COV).info
	cd tests; $(CC) -std=c++17 -g --coverage $(TEST_FUNC) -o ../gcov_report  $(TEST_FLAGS)
	cd ..
	./gcov_report 
	lcov -t "stest" -o s21_test.info -c -d ./ --no-external --ignore-errors mismatch
	genhtml -o report s21_test.info
	open ./report/index.html

# g++ -std=c++17 -g --coverage ./tests/map_tests.cc -o greport $(TEST_FLAGS)
# ./greport
# lcov -t "greport" -o greport.info -c -d . --no-external --ignore-errors mismatch
# genhtml -o report fizzbuzz.info
# ./report.html
	

.PHONY: installDox dvi clean $(FILES).a clang goclang test valgrind check_cppcheck push gcov_report
