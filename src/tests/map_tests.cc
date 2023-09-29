#include <map>

#include "../s21_map/s21_map.h"
#include "gtest/gtest.h"

// TEST(TestGroupName, Iterators1_int) {
//   s21::map<int, int> a;
//   std::pair<int, int> a1 = {5, 5};
//   a.insert(a1);
//   a.insert(9);
//   a.insert(7, 7);
//   a.insert(10);
//   a.insert(1);
//   a.insert(8, 8);
//   a.insert(0, 6);
//   std::map<int, int> b;
//   std::pair<int, int> b1 = {5, 5};
//   std::pair<int, int> b2 = {9, 0};
//   std::pair<int, int> b3 = {7, 7};
//   std::pair<int, int> b4 = {10, 0};
//   std::pair<int, int> b5 = {1, 0};
//   std::pair<int, int> b6 = {8, 8};
//   std::pair<int, int> b7 = {0, 6};
//   b.insert(b1);
//   b.insert(b2);
//   b.insert(b3);
//   b.insert(b4);
//   b.insert(b5);
//   b.insert(b6);
//   b.insert(b7);

//   s21::map<int, int>::iterator it1 = a.begin();
//   std::map<int, int>::iterator it2 = b.begin();

//   for (; it1 != a.end() ; it1++) {
//     ASSERT_EQ(it1.node->node_key.first, it2->first);
//     ASSERT_EQ(it1.node->node_key.second, it2->second);
//   }

//   ASSERT_EQ(a.size(), b.size());

//   // a.printTree(a.root);
// }

// TEST(TestGroupName, Iterators1_char) {
//   s21::map<int, char> a;
//   std::pair<int, char> a1 = {1, 'N'};
//   std::pair<int, char> a2 = {6, 'u'};
//   a.insert(a1);
//   std::map<int, char> b;
//   std::pair<int, char> b1 = {1, 'N'};
//   std::pair<int, char> b2 = {6, 'u'};
//   b.insert(b1);
//   a[1];
//   a[2];

//   b[1];
//   b[2];

//   ASSERT_EQ(a.insert(a1).second, b.insert(b1).second);
//   ASSERT_EQ(a.insert(a2).second, b.insert(b2).second);
//   ASSERT_EQ(a[1], b[1]);
//   ASSERT_EQ(a[2], b[2]);
//   ASSERT_EQ(a[6], b[6]);
//   ASSERT_EQ(a.size(), b.size());
//   // a.printTree(a.root);
// }

// TEST(TestGroupName, Iterators2_string) {
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

//   ASSERT_EQ(a[1], b[1]);
//   ASSERT_EQ(a[2], b[2]);
//   ASSERT_EQ(a[3], b[3]);
//   ASSERT_EQ(a.size(), b.size());
//   // a.printTree(a.root);
// }

// TEST(TestGroupName, Iterators3_string) {
//   s21::map<std::string, std::string> a;
//   a["Nurlan"];
//   a["the"];
//   a["best"];

//   ASSERT_EQ(a.insert("Nurlan", "the Best").second, false);
//   ASSERT_EQ(a.insert_or_assign("Nurlan", "the Best").second, true);
//   ASSERT_EQ(a.insert("NeNurlan", "the Best").second, true);

//   // a.printTree(a.root);
// }

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

//   s21::map<int, std::string>::iterator it1 = a.begin();
//   std::map<int, std::string>::iterator it2 = b.begin();

//   for (; it1 != a.end() && it2 != b.end(); it1++, it2++) {
//     ASSERT_EQ(it1.node->node_key.first, it2->first);
//     ASSERT_EQ(it1.node->node_key.second, it2->second);
//   }

//   it1 = a.begin();
//   it2 = b.begin();

//   for (; it1 != a.end() && it2 != b.end(); ++it1, ++it2) {
//     ASSERT_EQ(it1.node->node_key.first, it2->first);
//     ASSERT_EQ(it1.node->node_key.second, it2->second);
//   }
//   ASSERT_EQ(a.size(), b.size());
//   // a.printTree(a.root);
// }

// TEST(TestGroupName, operator_sub_1) {
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

//   s21::map<int, std::string>::iterator it1 = a.end();
//   std::map<int, std::string>::iterator it2 = b.end();

//   it1 = a.end();
//   it2 = b.end();
//   do {
//     --it1;
//     --it2;
//     ASSERT_EQ(it1.node->node_key.first, it2->first);
//   } while (it1 != a.begin() || it2 != b.begin());

//   it1 = a.end();
//   it2 = b.end();
//   do {
//     it1--;
//     it2--;
//     ASSERT_EQ(it1.node->node_key.first, it2->first);
//   } while (it1 != a.begin() || it2 != b.begin());
//   ASSERT_EQ(a.size(), b.size());
//   // a.printTree(a.root);
// }

// TEST(TestGroupName, max_size_1) {
//   s21::map<int, std::string> a;
//   for (int i = 0; i < int(a.max_size()); i++) a.insert(i, "Nurlan");
//   ASSERT_EQ(a.max_size(), 100);
//   EXPECT_THROW(a.insert(100, "Best"), std::length_error);
//   // a.printTree(a.root);
// }

// TEST(TestGroupName, contains_1) {
//   s21::map<int, std::string> a;
//   for (int i = 0; i < 10; i++) a.insert(i, "Nurlan");
//   ASSERT_EQ(a.contains(), true);
//   ASSERT_EQ(a.contains(5), true);
//   ASSERT_EQ(a.contains(-2), false);
//   // a.printTree(a.root);
// }

TEST(TestGroupName, erase_1) {
  s21::map<int, std::string> a;
  std::map<int, std::string> b;
  int s = 0;
  for (int i = 0; i < 4; i++) {
    std::pair<int, std::string> x = {i, "Nurlan"};
    b.insert(x);
    a.insert(x);
    cout << endl;
  }

  // s21::map<int, std::string>::iterator it1= a.begin();
  // std::map<int, std::string>::iterator it2 = b.begin();

  // for(; s<20; s++){
  // cout<<it1.node->node_key.first << " " << it2->first <<endl;
  // cout<<it1.node->node_key.first<<endl;
  // it2 = b.erase(it2);
  // }

  // cout<<it1.node->node_key.first << " " << it2->first <<endl;
  // ASSERT_EQ(a.size(), b.size());
  // ASSERT_EQ(it1.node->node_key.first, it2->first);
  a.printTree(a.root);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
