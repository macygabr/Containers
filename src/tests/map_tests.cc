#include <map>

#include "../s21_map/s21_map.h"
#include "gtest/gtest.h"

//________________________________________________Iterators__________________________________________________

// TEST(TestGroupName, Begin) {
//   s21::map<int, char> a;
//   std::map<int, char> b;
//   a[99] = 'N';
//   b[99] = 'N';

//   ASSERT_EQ(a.begin()->first, b.begin()->first);
//   for (int i = 0; i < 10; i++) ASSERT_EQ(a[i], b[i]);
//   ASSERT_EQ(a.begin()->first, b.begin()->first);
// }

TEST(TestGroupName, End) {
  s21::map<int, char> a;
  std::map<int, char> b;
  s21::map<int, char>::iterator it1;
  std::map<int, char>::iterator it2;

  for (int i = 1, j = 50; i < 50; i++, j--) {  // leaks
    std::pair<int, int> x = {i, j};
    ASSERT_EQ(a.insert(x).second, b.insert(x).second);
  }
  for (it1 = a.begin(), it2 = b.begin(); it2 != b.end(); it1++, it2++)
    ASSERT_EQ(a[it1->first], b[it2->first]);

  it1 = a.begin();
  it2 = b.begin();

  cout << a.insert({99, 'N'}).first->first << endl;
  cout << a.insert({99, 'N'}).first->first << " " << a.insert({99, 'N'}).second
       << endl;
  a.printTree(a.root);
  //   it1++;
  //   it2++;
  //   ASSERT_EQ(a[it1->first], b[it2->first]);
  //   it1++;
  //   it2++;
  //   ASSERT_EQ(a[it1->first], b[it2->first]);
  //   it1++;
  //   it2++;
  //   ASSERT_EQ(a[it1->first], b[it2->first]);
  //   --it1;
  //   --it2;
  //   ASSERT_EQ(a[it1->first], b[it2->first]);
  //   --it1;
  //   --it2;
  //   ASSERT_EQ(a[it1->first], b[it2->first]);
  //   --it1;
  //   --it2;
  //   ASSERT_EQ(a[it1->first], b[it2->first]);
  //   it1++;
  //   it2++;
  //   ASSERT_EQ(a[it1->first], b[it2->first]);
  //   ASSERT_EQ(a[(++it1)->first], b[(++it2)->first]);
  //   ASSERT_EQ(a[(++it1)->first], b[(++it2)->first]);
  //   ASSERT_EQ(a[(it1--)->first], b[(it2--)->first]);

  //   ASSERT_EQ(a.end()->first, b.end()->second);
}

// //________________________________________________Capacity__________________________________________________
// TEST(TestGroupName, Capacity) {
//   s21::map<int, std::string> a;
//   std::map<int, std::string> b;
//   ASSERT_EQ(a.empty(), b.empty());
//   a[99] = "Nurlan";
//   b[99] = "The Best";
//   ASSERT_EQ(a.empty(), b.empty());
//   s21::map<int, std::string>::iterator it1 = a.begin();
//   std::map<int, std::string>::iterator it2 = b.begin();
//   a.erase(it1);
//   b.erase(it2);
//   ASSERT_EQ(a.empty(), b.empty());
// }

// TEST(TestGroupName, Size) {
//   s21::map<int, std::string> a;
//   std::map<int, std::string> b;
//   ASSERT_EQ(a.size(), b.size());
//   for (int i = 0; i < 6; i++) {
//     a[99] = "Nurlan";
//     b[99] = "The Best";
//   }
//   ASSERT_EQ(a.size(), b.size());
// }
// //________________________________________________Element_access____________________________________________
// TEST(TestGroupName, operator) {
//   s21::map<int, std::string> a;
//   std::map<int, std::string> b;
//   for (int i = 0; i < 50; i++) {
//     a[99] = "Nurlan";
//     b[99] = "Nurlan";
//   }
//   for (int i = 0; i < 100; i++) ASSERT_EQ(a[i], b[i]);
// }

// TEST(TestGroupName, at) {
//   s21::map<int, std::string> a;
//   std::map<int, std::string> b;
//   s21::map<int, std::string>::iterator it1;
//   std::map<int, std::string>::iterator it2;
//   for (int i = 0; i < 50; i++) {
//     a[i] = "Nurlan";
//     b[i] = "Nurlan";
//   }

//   for (it1 = a.begin(), it2 = b.begin(); it1 != a.end() || it2 != b.end();
//        it1++, it2++) {
//     ASSERT_EQ(a.at(it1->first), b.at(it2->first));
//   }

//   for (int i = 50; i < 100; i++) {
//     EXPECT_THROW(a.at(i), std::out_of_range);
//     EXPECT_THROW(b.at(i), std::out_of_range);
//   }
//   ASSERT_EQ(a.size(), b.size());
// }

// //________________________________________________Modifiers_________________________________________________
// TEST(TestGroupName, Insert_int_int) {
//   s21::map<int, int> a;
//   std::map<int, int> b;
//   std::pair<int, int> b1 = {99, 0};
//   s21::map<int, int>::iterator it1;
//   std::map<int, int>::iterator it2;

//   for (int i = 1, j = 50; i < 50; i++, j--) {
//     std::pair<int, int> x = {i, j};
//     ASSERT_EQ(a.insert(x).second, b.insert(x).second);
//   }
//   ASSERT_EQ(a.insert(99).second, true);
//   ASSERT_EQ(a.insert(99).second, false);
//   ASSERT_EQ(b.insert(b1).second, true);
//   a[77] = 3;
//   b[77] = 3;

//   for (it1 = a.begin(), it2 = b.begin(); it1 != a.end(); it1++, it2++) {
//     ASSERT_EQ(it1->first, it2->first);
//   }
//   ASSERT_EQ(a.size(), b.size());
//   // a.printTree(a.root);
// }
// TEST(TestGroupName, Insert_int_char) {
//   s21::map<int, char> a;
//   std::map<int, char> b;
//   s21::map<int, char>::iterator it1;
//   std::map<int, char>::iterator it2;

//   for (int i = 0; i < 50; i++) {
//     std::pair<int, char> x = {i, 'N' + i};
//     ASSERT_EQ(a.insert(x).second, b.insert(x).second);
//   }
//   a[77] = 'O';
//   b[77] = 'O';
//   for (it1 = a.begin(), it2 = b.begin(); it1 != a.end(); it1++, it2++) {
//     ASSERT_EQ(it1->first, it2->first);
//   }
//   ASSERT_EQ(a.size(), b.size());
//   // a.printTree(a.root);
// }

// TEST(TestGroupName, Insert_int_string) {
//   s21::map<int, std::string> a;
//   std::map<int, std::string> b;
//   s21::map<int, std::string>::iterator it1;
//   std::map<int, std::string>::iterator it2;

//   for (int i = 0; i < 50; i++) {
//     std::pair<int, std::string> x = {i, std::to_string(i)};
//     ASSERT_EQ(a.insert(x).second, b.insert(x).second);
//   }
//   a[90] = "Nurlan";
//   b[90] = "Nurlan";

//   for (it1 = a.begin(), it2 = b.begin(); it1 != a.end(); it1++, it2++) {
//     ASSERT_EQ(it1->first, it2->first);
//   }
//   ASSERT_EQ(a.size(), b.size());
//   // a.printTree(a.root);
// }

// TEST(TestGroupName, Insert_string_int) {
//   s21::map<std::string, int> a;
//   std::map<std::string, int> b;
//   s21::map<std::string, int>::iterator it1;
//   std::map<std::string, int>::iterator it2;

//   for (int i = 0; i < 50; i++) {
//     std::pair<std::string, int> x = {std::to_string(i), i};
//     ASSERT_EQ(a.insert(x).second, b.insert(x).second);
//   }
//   a["Nurlan"] = 333;
//   b["Nurlan"] = 333;

//   for (it1 = a.begin(), it2 = b.begin(); it1 != a.end(); it1++, it2++) {
//     ASSERT_EQ(it1->first, it2->first);
//   }
//   ASSERT_EQ(a.size(), b.size());
//   // a.printTree(a.root);
// }

// TEST(TestGroupName, Insert_string_char) {
//   s21::map<std::string, char> a;
//   std::map<std::string, char> b;
//   s21::map<std::string, char>::iterator it1;
//   std::map<std::string, char>::iterator it2;

//   for (int i = 0; i < 50; i++) {
//     std::pair<std::string, char> x = {std::to_string(i), i};
//     ASSERT_EQ(a.insert(x).second, b.insert(x).second);
//   }
//   a["Nurlan"] = 'O';
//   b["Nurlan"] = 'O';

//   for (it1 = a.begin(), it2 = b.begin(); it1 != a.end(); it1++, it2++) {
//     ASSERT_EQ(it1->first, it2->first);
//   }
//   ASSERT_EQ(a.size(), b.size());
//   // a.printTree(a.root);
// }

// TEST(TestGroupName, Insert_string_string) {
//   s21::map<std::string, std::string> a;
//   std::map<std::string, std::string> b;
//   s21::map<std::string, std::string>::iterator it1;
//   std::map<std::string, std::string>::iterator it2;

//   for (int i = 0; i < 50; i++) {
//     std::pair<std::string, std::string> x = {std::to_string(i),
//                                              std::to_string(i)};
//     ASSERT_EQ(a.insert(x).second, b.insert(x).second);
//   }
//   a["Nurlan"] = "The Best";
//   b["Nurlan"] = "The Best";

//   for (it1 = a.begin(), it2 = b.begin(); it1 != a.end(); it1++, it2++) {
//     ASSERT_EQ(it1->first, it2->first);
//   }
//   ASSERT_EQ(a.size(), b.size());
//   // a.printTree(a.root);
// }

// TEST(TestGroupName, Insert_or_assign_int_string) {
//   s21::map<int, std::string> a;
//   std::map<int, std::string> b;
//   s21::map<int, std::string>::iterator it1;
//   std::map<int, std::string>::iterator it2;

//   for (int i = 0, j = 49; i < 50; i++, j--) {
//     std::pair<int, std::string> a1 = {i, std::to_string(i)};
//     std::pair<int, std::string> b1 = {j, std::to_string(j)};
//     ASSERT_EQ(a.insert(a1).second, b.insert(b1).second);
//   }
//   a[99] = "The Best";
//   b[99] = "The Best";

//   for (int i = 49; i >= 0; i--) a.insert_or_assign(i, std::to_string(i));

//   for (it1 = a.begin(), it2 = b.begin(); it1 != a.end(); it1++, it2++) {
//     ASSERT_EQ(it1->first, it2->first);
//   }
//   ASSERT_EQ(a.size(), b.size());
//   // a.printTree(a.root);
// }

// TEST(TestGroupName, Insert_pair) {
//   s21::map<std::pair<int, int>, std::pair<int, int>> a;
//   std::map<std::pair<int, int>, std::pair<int, int>> b;
//   s21::map<std::pair<int, int>, std::pair<int, int>>::iterator it1;
//   std::map<std::pair<int, int>, std::pair<int, int>>::iterator it2;

//   for (int i = 0, j = 49; i < 50; i++, j--) {
//     std::pair<std::pair<int, int>, std::pair<int, int>> x = {{i, j}, {j, i}};
//     ASSERT_EQ(a.insert(x).second, b.insert(x).second);
//   }

//   for (it1 = a.begin(), it2 = b.begin(); it1 != a.end(); it1++, it2++) {
//     ASSERT_EQ(it1->first.first, it2->first.first);
//     ASSERT_EQ(it1->first.second, it2->first.second);
//     ASSERT_EQ(it1->second.first, it2->second.first);
//     ASSERT_EQ(it1->second.second, it2->second.second);
//   }
//   ASSERT_EQ(a.size(), b.size());
// }

// namespace s21 {
// class my_class {
//   using value_type = std::pair<int, int>;

//  public:
//   value_type val;

//   my_class() {
//     val.first = 0;
//     val.second = 0;
//   }
//   my_class(int x, int y) {
//     val.first = x;
//     val.second = y;
//   }

//   bool operator>(const my_class& it) { return val.first > it.val.first; };
//   bool operator<(const my_class& it) { return val.first < it.val.first; };
//   bool operator==(const my_class& it) { return val.first == it.val.first; };
// };
// }  // namespace s21

// TEST(TestGroupName, Insert_my_class) {
//   s21::map<s21::my_class, s21::my_class> a;
//   s21::map<s21::my_class, s21::my_class>::iterator it1;

//   for (int i = 0, j = 49; i < 50; i++, j--) {
//     s21::my_class a1(i, j);
//     s21::my_class a2(j, i);
//     std::pair<s21::my_class, s21::my_class> x = {a1, a2};
//     ASSERT_EQ(a.insert(x).second, true);
//   }

//   for (it1 = a.begin(); it1 != a.end(); it1++) {
//     ASSERT_EQ(it1->first.val.first, it1->second.val.second);
//     ASSERT_EQ(it1->first.val.second, it1->second.val.first);
//   }
//   ASSERT_EQ(a.size(), 50);
// }

// TEST(TestGroupName, Erase) {
//   s21::map<int, std::string> a;
//   std::map<int, std::string> b;
//   s21::map<int, std::string>::iterator it1;
//   std::map<int, std::string>::iterator it2;

//   for (int i = 0; i < 50; i++) {
//     std::pair<int, std::string> x = {i, std::to_string(i)};
//     ASSERT_EQ(a.insert(x).second, b.insert(x).second);
//   }
//   a[99] = "The Best";
//   b[99] = "The Best";

//   int i = 0;
//   for (it1 = a.begin(), it2 = b.begin(); i < 10; i++) {
//     a.erase(it1++);
//     b.erase(it2++);
//   }

//   for (it1 = a.begin(), it2 = b.begin(); it1 != a.end(); it1++, it2++)
//     ASSERT_EQ(it1->first, it2->first);

//   for (; i < 10; i++, it1++, it2++)
//     ;

//   for (; i < 10; i++) {
//     a.erase(it1);
//     b.erase(it2);
//     it1++;
//     it2++;
//   }

//   for (it1 = a.begin(), it2 = b.begin(); it1 != a.end(); it1++, it2++)
//     ASSERT_EQ(it1->first, it2->first);

//   ASSERT_EQ(a.size(), b.size());
//   // a.printTree(a.root);
// }

// TEST(TestGroupName, Swap) {
//   s21::map<int, double> a1;
//   s21::map<int, double> a2;
//   std::map<int, double> b1;
//   std::map<int, double> b2;
//   s21::map<int, double>::iterator it1;
//   std::map<int, double>::iterator it2;

//   for (int i = 0, j = 49; i < 50; i++, j--) {
//     std::pair<int, double> x = {i, j / 10.};
//     ASSERT_EQ(a1.insert(x).second, b1.insert(x).second);
//   }
//   for (int i = 0, j = 49; i < 50; i++, j--) {
//     std::pair<int, double> x = {i, j << 1};
//     ASSERT_EQ(a2.insert(x).second, b2.insert(x).second);
//   }

//   for (it1 = a1.begin(), it2 = b1.begin(); it1 != a1.end(); it1++, it2++)
//     ASSERT_EQ(it1->first, it2->first);

//   a1.swap(a2);
//   b1.swap(b2);

//   for (it1 = a1.begin(), it2 = b1.begin(); it1 != a1.end(); it1++, it2++)
//     ASSERT_EQ(it1->first, it2->first);
//   for (it1 = a2.begin(), it2 = b2.begin(); it1 != a2.end(); it1++, it2++)
//     ASSERT_EQ(it1->first, it2->first);

//   ASSERT_EQ(a1.size(), b1.size());
//   ASSERT_EQ(a2.size(), b2.size());
//   // a1.printTree(a1.root);
// }

TEST(TestGroupName, Merge) {
  // s21::map<int, double> a1;
  // s21::map<int, double> a2;
  // std::map<int, double> b1;
  // s21::map<int, double>::iterator it1;
  // std::map<int, double>::iterator it2;
  // for (int i = 0; i <= 50; i++) {
  //   std::pair<int, double> x = {i, 1 / 10.};
  //   a1.insert(x).second;
  // }
  // for (int i = 40; i <= 80; i++) {
  //   std::pair<int, double> x = {i, 10.};
  //   a2.insert(x).second;
  // }
  // it1 = a1.begin();
  // // for(it1 = a1.begin(); it1 != a1.end(); it1++) {
  // a1.erase(it1);
  // it1++;
  // a1.erase(it1);
  // it1++;
  // }
  //   it1++;
  //   a1.erase(it1);
  //   // cout<<it1->first<<endl;
  //   it1++;
  //   a1.erase(it1);

  // a1.merge(a2);
  // for (int i = 0; i <= 50; i++) {
  //   ASSERT_EQ(a1[i], 1 / 10.);
  // }
  // for (int i = 51; i < 80; i++) {
  //   ASSERT_EQ(a1[i], 10);
  // }
  // ASSERT_EQ(a1.size(), b1.size());
  // ASSERT_EQ(a2.size(), b2.size());
  // b1.merge(b1);
  // for (it1 = a1.begin(), it2 = b1.begin(); it1 != a1.end(); it1++, it2++)
  //   ASSERT_EQ(it1->first, it2->first);

  // for (it1 = a2.begin(), it2 = b2.begin(); it1 != a2.end(); it1++, it2++)
  //   ASSERT_EQ(it1->first, it2->first);

  // ASSERT_EQ(a1.size(), 80);
  // ASSERT_EQ(a2.size(), 30);
  // a1.printTree(a1.root);
}
// //________________________________________________Lookup____________________________________________________
// TEST(TestGroupName, Contains) {
//   s21::map<int, std::string> a;
//   std::map<int, std::string> b;
//   s21::map<int, std::string>::iterator it1;

//   for (int i = 0; i < 50; i++) {
//     std::pair<int, std::string> x = {i, std::to_string(i)};
//     ASSERT_EQ(a.insert(x).second, b.insert(x).second);
//   }

//   for (int i = 0; i < 50; i++) ASSERT_EQ(a.contains(i), true);
//   for (int i = 50; i < 100; i++) ASSERT_EQ(a.contains(i), false);
// }

// //________________________________________________Iterators_________________________________________________
// TEST(TestGroupName, operator_plus) {
//   s21::map<int, char> a;
//   std::map<int, char> b;
//   s21::map<int, char>::iterator it1;
//   std::map<int, char>::iterator it2;

//   for (int i = 0; i < 50; i++) {
//     std::pair<int, char> x = {i, i};
//     ASSERT_EQ(a.insert(x).second, b.insert(x).second);
//   }

//   for (it1 = a.begin(), it2 = b.begin(); it1 != a.end(); it1++, it2++)
//     ASSERT_EQ(it1->first, it2->first);

//   for (it1 = a.begin(), it2 = b.begin(); it1 != a.end(); ++it1, ++it2)
//     ASSERT_EQ(it1->first, it2->first);
// }

// TEST(TestGroupName, operator_sub) {
//   s21::map<int, int> a;
//   std::map<int, int> b;
//   s21::map<int, int>::iterator it1;
//   std::map<int, int>::iterator it2;

//   for (int i = 0; i < 10; i++) {
//     std::pair<int, int> x = {i, i};
//     ASSERT_EQ(a.insert(x).second, b.insert(x).second);
//   }

//   it1 = a.end();
//   it2 = b.end();
//   do {
//     it1--;
//     it2--;
//     ASSERT_EQ(it1->first, it2->first);

//   } while (it1 != a.begin() && it2 != b.begin());

//   it1 = a.end();
//   it2 = b.end();
//   do {
//     --it1;
//     --it2;
//     ASSERT_EQ(it1->first, it2->first);

//   } while (it1 != a.begin() || it2 != b.begin());
//   ASSERT_EQ(a.size(), b.size());
//   // a.printTree(a.root);
// }

// TEST(TestGroupName, operator_equal) {
//   s21::map<std::string, std::string> a;
//   std::map<std::string, std::string> b;
//   a["Nurlan"] = "The Best";
//   b["Nurlan"] = "The Best";
//   s21::map<std::string, std::string>::iterator it11 = a.begin();
//   s21::map<std::string, std::string>::iterator it12 = a.begin();
//   std::map<std::string, std::string>::iterator it21 = b.end();
//   std::map<std::string, std::string>::iterator it22 = b.end();
//   ASSERT_EQ(it11 != it11, it21 != it21);
//   ASSERT_EQ(it11 == it11, it21 == it21);
//   ASSERT_EQ(it11 != it12, it21 != it22);
//   ASSERT_EQ(it11 == it12, it21 == it22);
// }

// TEST(TestGroupName, operator_Arrow) {
//   s21::map<char, char> a;
//   std::map<char, char> b;
//   s21::map<char, char>::iterator it1;
//   std::map<char, char>::iterator it2;
//   EXPECT_THROW(it1->first, std::exception);

//   for (int i = 0; i < 26; i++) {
//     std::pair<char, char> x = {'a' + i, 'a' + i};
//     ASSERT_EQ(a.insert(x).second, b.insert(x).second);
//   }

//   for (it1 = a.begin(), it2 = b.begin(); it1 != a.end(); ++it1, ++it2)
//     ASSERT_EQ(it1->first, it2->first);
//   // a.printTree(a.root);
// }

// TEST(TestGroupName, Dereferencing_operator) {
//   s21::map<char, char> a;
//   std::map<char, char> b;
//   s21::map<char, char>::iterator it1;
//   std::map<char, char>::iterator it2;

//   for (int i = 0; i < 26; i++) {
//     std::pair<char, char> x = {'a' + i, 'a' + i};
//     ASSERT_EQ(a.insert(x).second, b.insert(x).second);
//   }

//   for (it1 = a.begin(), it2 = b.begin(); it1 != a.end(); ++it1, ++it2)
//     ASSERT_EQ((*it1).first, (*it2).first);
//   // a.printTree(a.root);
// }

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
