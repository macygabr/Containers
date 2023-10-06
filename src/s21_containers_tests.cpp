#include <gtest/gtest.h>

#include "s21_list/list_tests.cpp"
// #include "s21_map_tests.cpp"
#include "s21_queue/queue_tests.cpp"
// #include "s21_set_tests.cpp"
// #include "s21_stack_tests.cpp"
#include "s21_vector/vector_tests.cpp"

int main(int argc, char **argv) {
#ifdef __APPLE__
  free(__cxxabiv1::__cxa_get_globals());
#endif   
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
