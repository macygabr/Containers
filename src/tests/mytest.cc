#include <map>

#include "../s21_map/s21_map.h"
#include "gtest/gtest.h"


TEST(TestGroupName, Iterators1_char) {
  // s21::map<int, char> a;
  // std::pair<int, char> a1 = {1, 'N'};
  // std::pair<int, char> a2 = {6, 'u'};
  // a.insert(a1);
  // std::map<int, char> b;
  // std::pair<int, char> b1 = {1, 'N'};
  // std::pair<int, char> b2 = {6, 'u'};
  // b.insert(b1);
  // a[2];
  // a[3];
  // a[4];

  // ASSERT_EQ(a.insert(a1).second, b.insert(b1).second);
  // ASSERT_EQ(a.insert(a2).second, b.insert(b2).second);
  // ASSERT_EQ(a[1], b[1]);
  // ASSERT_EQ(a[2], b[2]);
  // ASSERT_EQ(a[6], b[6]);

  // a.printTree(a.root);
  // ASSERT_EQ(a.end()->first, b.end()->first); // ?????????
}

// TEST(TestGroupName, Iterators2_string) {
//   s21::map<int, std::string> a;
//   std::pair<int, std::string> a1 = {1, "Nurlan"};
//   std::pair<int, std::string> a2 = {2, "The"};
//   a.insert(a1);
//   a.insert(a2);
//   std::map<int, std::string> b;
//   std::pair<int, std::string> b1 = {1, "Nurlan"};
//   std::pair<int, std::string> b2 = {2, "The"};
//   b.insert(b1);
//   b.insert(b2);

//   ASSERT_EQ(a[1], b[1]);
//   ASSERT_EQ(a[2], b[2]);
// }

TEST(TestGroupName, Iterators3_string) {
  s21::map<std::string, std::string> a;

  a.insert("Nurlan", "the Best");
//   a["Nurlan"];
//   a["the"];
//   a["best"];

//   ASSERT_EQ(a.insert("Nurlan", "the Best").second, false);
//   ASSERT_EQ(a.insert("NeNurlan", "the Best").second, true);
  // a.printTree(a.root);
}

// TEST(TestGroupName, Insert_or_assign1) {
//   s21::map<int, std::string> a;
//   a.insert_or_assign(1, "Nurlan");
//   a.insert_or_assign(2, "The");
//   a.insert_or_assign(3, "Best");
//   a.insert_or_assign(3, "Nurlan");
//   ASSERT_EQ(a[1], a[3]);
//   ASSERT_EQ(a.insert_or_assign(1, "Nurlan").second, true);
//   // a.printTree(a.root);
// }

// TEST(TestGroupName, operator_plus_1) {
//   s21::map<int, std::string> a;
//   std::pair<int, std::string> a1 = {1, "Nurlan"};
//   std::pair<int, std::string> a2 = {2, "The"};
//   std::pair<int, std::string> a3 = {3, "Best"};
//   a.insert(a1);
//   a.insert(a2);
//   a.insert(a3);
//   std::map<int, std::string> b;
//   std::pair<int, std::string> b1 = {1, "Nurlan"};
//   std::pair<int, std::string> b2 = {2, "The"};
//   std::pair<int, std::string> b3 = {3, "Best"};
//   b.insert(b1);
//   b.insert(b2);
//   b.insert(b3);
//   // s21::map <int, std::string> :: iterator it1;
//   // std::map <int, std::string> :: iterator it2;
//   // it1 = a.begin();
//   // it2 = b.begin();

  
//   //  for (; it1 != b.end() || it2 != b.end(); it1++,it2++) 
//   {
//         // std::cout <<"Ключ " << it1->first << ", значение " << it1->second << std::endl;
//     }
//   // a.printTree(a.root);
// }

int main(int argc, char** argv) {
  // b.printTree(b.root);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
