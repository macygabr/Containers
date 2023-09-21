#include <map>

#include "../s21_map.h"
#include "gtest/gtest.h"

TEST(TestGroupName, Iterators1_char) {
  s21::map<int, char> a;
  pair<int, char> a1 = {1, 'N'};
  pair<int, char> a2 = {6, 'u'};
  a.insert(a1);
  std::map<int, char> b;
  pair<int, char> b1 = {1, 'N'};
  pair<int, char> b2 = {6, 'u'};
  b.insert(b1);
  a[2];
  // ASSERT_EQ(a.insert(a1).second, b.insert(b1).second);
  // ASSERT_EQ(a.insert(a2).second, b.insert(b2).second);
  ASSERT_EQ(a[1], b[1]);
  // ASSERT_EQ(a[2], b[2]);
  a.printTree(a.root);
  // ASSERT_EQ(a[6], b[6]);

  // ASSERT_EQ(a.end()->first, b.end()->first); // ?????????
}

// TEST(TestGroupName, Iterators2_string) {
//   s21::map<int, string> a;
//   pair<int, string> a1 = {1, "Nurlan"};
//   pair<int, string> a2 = {2, "The"};
//   a.insert(a1);
//   a.insert(a2);
//   std::map<int, string> b;
//   pair<int, string> b1 = {1, "Nurlan"};
//   pair<int, string> b2 = {2, "The"};
//   b.insert(b1);
//   b.insert(b2);

//   ASSERT_EQ(a[1], b[1]);
//   ASSERT_EQ(a[2], b[2]);
// }

// TEST(TestGroupName, Iterators3) {
//   s21::map<int, string> a;
//   ASSERT_EQ(a.insert(1, "Nurlan").second, true);
//   ASSERT_EQ(a.insert(1, "the Best").second, false);
// }

// TEST(TestGroupName, Insert_or_assign1) {
//   s21::map<int, string> a;
//   a.insert_or_assign(1, "Nurlan");
//   a.insert_or_assign(2, "The");
//   a.insert_or_assign(3, "Best");
//   a.insert_or_assign(3, "Nurlan");
//   // a.printTree(a.root);
//   ASSERT_EQ(a[1], a[3]);
//   // ASSERT_EQ(a.insert_or_assign(1,"Nurlan").second, false);
// }

int main(int argc, char** argv) {
  // b.printTree(b.root);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
