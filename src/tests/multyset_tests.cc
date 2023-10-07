#include <set>

#include "../s21_set/s21_set.h"
#include "gtest/gtest.h"

//________________________________________________Member_functions__________________________________________________

TEST(TestSetGroup, Initializer_list) {
  s21::set<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::set<int> b = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); it1++, it2++) EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(a.size(), b.size());
}

TEST(TestSetGroup, ConstructorCopy) {
  s21::set<int> a = {1, 3, 4, 5};
  std::set<int> b = {1, 3, 4, 5};
  s21::set<int> a_copy = a;
  std::set<int> b_copy = b;
  EXPECT_EQ(a_copy.size(), b_copy.size());
  auto it1 = a_copy.begin();
  auto it2 = b_copy.begin();
  for (; it1 != a_copy.end(); ++it1, ++it2) EXPECT_TRUE((*it1) == (*it2));

  // a.SimpleprintTree(a.root);
}

TEST(TestSetGroup, ConstructorMoveset) {
  s21::set<int> a = {1, 2, 3, 4, 5, 6};
  std::set<int> b = {1, 2, 3, 4, 5, 6};
  s21::set<int> a_copy = std::move(a);
  std::set<int> b_copy = std::move(b);
  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a_copy.size(), b_copy.size());
  auto it1 = a_copy.begin();
  auto it2 = b_copy.begin();
  for (; it1 != a_copy.end(); ++it1, ++it2) EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(a.size(), b.size());
}

//________________________________________________Iterators__________________________________________________

TEST(TestSetGroup, Begin) {
  s21::set<char> a = {'N', 'U', 'R', 'L', 'A', 'N'};
  std::set<char> b = {'N', 'U', 'R', 'L', 'A', 'N'};
  auto it1 = a.begin();
  auto it2 = b.begin();
  ASSERT_EQ(*it1, *it2);
  for (; it1 != a.end(); it1++, it2++) ASSERT_EQ(*it1, *it2);
  ASSERT_EQ(a.size(), b.size());
}

TEST(TestSetGroup, End) {
  s21::set<int> a;
  std::set<int> b;
  s21::set<int>::iterator it1;
  std::set<int>::iterator it2;

  for (int i = 1; i < 50; i++) {
    auto x = rand() % 100;
    ASSERT_EQ(a.insert(i).second, b.insert(i).second);
  }
  for (it1 = a.begin(), it2 = b.begin(); it2 != b.end(); it1++, it2++)
    ASSERT_EQ(*a.find(*it1), *b.find(*it2));

  it1 = a.begin();
  it2 = b.begin();

  it1++;
  it2++;
  ASSERT_EQ(*it1, *it2);
  it1++;
  it2++;
  ASSERT_EQ(*it1, *it2);
  it1++;
  it2++;
  ASSERT_EQ(*it1, *it2);
  --it1;
  --it2;
  ASSERT_EQ(*it1, *it2);
  --it1;
  --it2;
  ASSERT_EQ(*it1, *it2);
  --it1;
  --it2;
  ASSERT_EQ(*it1, *it2);
  it1++;
  it2++;
  ASSERT_EQ(*it1, *it2);
  ASSERT_EQ(*(++it1), *(++it2));
  ASSERT_EQ(*(++it1), *(++it2));
  ASSERT_EQ(*(it1--), *(it2--));

  // a.SimpleprintTree(a.root);
}

//________________________________________________Capacity__________________________________________________
TEST(TestSetGroup, Capacity) {
  s21::set<std::string> a;
  std::set<std::string> b;
  ASSERT_EQ(a.empty(), b.empty());
  a.insert("Nurlan");
  b.insert("Nurlan");
  ASSERT_EQ(a.empty(), b.empty());
  s21::set<std::string>::iterator it1 = a.begin();
  std::set<std::string>::iterator it2 = b.begin();
  a.erase(it1);
  b.erase(it2);
  ASSERT_EQ(a.empty(), b.empty());
  // a.printTree(a.root);
}

TEST(TestSetGroup, Size) {
  s21::set<std::string> a;
  std::set<std::string> b;
  ASSERT_EQ(a.size(), b.size());
  for (int i = 0; i < 6; i++) {
    a.insert("Nurlan");
    b.insert("The Best");
  }
  ASSERT_EQ(a.size(), b.size());
}

//________________________________________________Modifiers_________________________________________________

TEST(TestSetGroup, Clear) {
  s21::set<int> a;
  std::set<int> b;
  a.clear();
  b.clear();
  EXPECT_EQ(a.empty(), b.empty());
  a.insert(1);
  b.insert(1);
  EXPECT_EQ(a.empty(), b.empty());
  a.clear();
  b.clear();
  EXPECT_EQ(a.empty(), b.empty());
}

TEST(TestSetGroup, Insert_int) {
  s21::set<int> a;
  std::set<int> b;
  s21::set<int>::iterator it1;
  std::set<int>::iterator it2;

  for (int i = 1; i < 50; i++) {
    int x = rand() % 100;
    ASSERT_EQ(a.insert(x).second, b.insert(x).second);
  }
  ASSERT_EQ(a.insert(99).second, true);
  ASSERT_EQ(a.insert(99).second, false);
  ASSERT_EQ(b.insert(99).second, true);
  ASSERT_EQ(b.insert(99).second, false);

  for (it1 = a.begin(), it2 = b.begin(); it1 != a.end(); it1++, it2++)
    ASSERT_EQ(*it1, *it2);

  ASSERT_EQ(a.size(), b.size());
  // a.printTree(a.root);
}
TEST(TestSetGroup, Insert_char) {
  s21::set<char> a;
  std::set<char> b;
  s21::set<char>::iterator it1;
  std::set<char>::iterator it2;

  for (int i = 0; i < 50; i++) {
    char x = 'N' + i;
    ASSERT_EQ(a.insert(x).second, b.insert(x).second);
  }
  for (it1 = a.begin(), it2 = b.begin(); it1 != a.end(); it1++, it2++)
    ASSERT_EQ(*it1, *it2);

  ASSERT_EQ(a.size(), b.size());
  // a.printTree(a.root);
}

TEST(TestSetGroup, Insert_string) {
  s21::set<std::string> a;
  std::set<std::string> b;
  s21::set<std::string>::iterator it1;
  std::set<std::string>::iterator it2;

  for (int i = 0; i < 50; i++) {
    std::string x = std::to_string(i);
    ASSERT_EQ(a.insert(x).second, b.insert(x).second);
  }

  for (it1 = a.begin(), it2 = b.begin(); it1 != a.end(); it1++, it2++)
    ASSERT_EQ(*it1, *it2);

  ASSERT_EQ(a.size(), b.size());
  // a.printTree(a.root);
}

TEST(TestSetGroup, Insert_pair) {
  s21::set<std::pair<int, int>> a;
  std::set<std::pair<int, int>> b;
  s21::set<std::pair<int, int>>::iterator it1;
  std::set<std::pair<int, int>>::iterator it2;

  for (int i = 0, j = 49; i < 50; i++, j--) {
    std::pair<int, int> x = {i, j};
    ASSERT_EQ(a.insert(x).second, b.insert(x).second);
  }

  for (it1 = a.begin(), it2 = b.begin(); it1 != a.end(); it1++, it2++) {
    ASSERT_EQ((*it1).first, (*it2).first);
    ASSERT_EQ((*it1).second, (*it2).second);
  }
  ASSERT_EQ(a.size(), b.size());
}

namespace s21 {
class my_class {
  using value_type = std::pair<int, int>;

 public:
  value_type val;

  my_class() {
    val.first = 0;
    val.second = 0;
  }
  my_class(int x, int y) {
    val.first = x;
    val.second = y;
  }

  bool operator>(const my_class& it) { return val.first > it.val.first; };
  bool operator<(const my_class& it) { return val.first < it.val.first; };
  bool operator==(const my_class& it) { return val.first == it.val.first; };
};
}  // namespace s21

TEST(TestSetGroup, Insert_my_class) {
  s21::set<s21::my_class> a;
  s21::set<s21::my_class>::iterator it1;

  for (int i = 0, j = 49; i < 50; i++, j--) {
    s21::my_class a1(i, j);
    s21::my_class x = a1;
    ASSERT_EQ(a.insert(x).second, true);
  }
  int i = 0, j = 49;
  for (it1 = a.begin(); it1 != a.end(); it1++, i++, j--) {
    ASSERT_EQ((*it1).val.first, i);
    ASSERT_EQ((*it1).val.second, j);
  }
  ASSERT_EQ(a.size(), 50);
}

TEST(TestSetGroup, Erase_1) {
  s21::set<int> a;
  std::set<int> b;
  s21::set<int>::iterator it1;
  std::set<int>::iterator it2;
  s21::set<int>::iterator save_it1;
  std::set<int>::iterator save_it2;

  for (int i = 0; i < 50; i++) {
    int x = rand() % 100;
    ASSERT_EQ(a.insert(x).second, b.insert(x).second);
  }

  int i = 0;
  for (it1 = a.begin(), it2 = b.begin(); it1 != a.end(); i++) {
    it1 = a.erase(it1);
    it2 = b.erase(it2);
    ASSERT_EQ(a.size(), b.size());
    save_it1 = it1;
    save_it2 = it2;
    for (it1 = a.begin(), it2 = b.begin(); it1 != a.end(); it1++, it2++)
      ASSERT_EQ(*it1, *it2);

    it1 = save_it1;
    it2 = save_it2;
  }
  // a.printTree(a.root);
}

TEST(TestSetGroup, Erase_2) {
  s21::set<int> a;
  std::set<int> b;
  s21::set<int>::iterator it1;
  std::set<int>::iterator it2;

  for (int i = 0; i < 50; i++) {
    int x = i;
    ASSERT_EQ(a.insert(x).second, b.insert(x).second);
  }

  for (it1 = a.begin(), it2 = b.begin(); it1 != a.end(); it1++, it2++)
    ASSERT_EQ(*it1, *it2);

  int i = 0;
  for (it1 = a.begin(), it2 = b.begin(); i < 10; i++, it1++, it2++)
    ;

  for (int j = 0; j < 10; j++) {
    it1 = a.erase(it1);
    it2 = b.erase(it2);
  }

  for (it1 = a.begin(), it2 = b.begin(); it1 != a.end(); it1++, it2++)
    ASSERT_EQ(*it1, *it2);
  // a.printTree(a.root);
  // a.SimpleprintTree(a.root);
}

TEST(TestSetGroup, Swap) {
  s21::set<double> a1;
  s21::set<double> a2;
  std::set<double> b1;
  std::set<double> b2;
  s21::set<double>::iterator it1;
  std::set<double>::iterator it2;

  for (int i = 0, j = 49; i < 50; i++, j--) {
    double x = j / 10.;
    ASSERT_EQ(a1.insert(x).second, b1.insert(x).second);
  }
  for (int i = 0, j = 49; i < 50; i++, j--) {
    double x = j << 1;
    ASSERT_EQ(a2.insert(x).second, b2.insert(x).second);
  }

  for (it1 = a1.begin(), it2 = b1.begin(); it1 != a1.end(); it1++, it2++)
    ASSERT_EQ(*it1, *it2);

  a1.swap(a2);
  b1.swap(b2);

  for (it1 = a1.begin(), it2 = b1.begin(); it1 != a1.end(); it1++, it2++)
    ASSERT_EQ(*it1, *it2);
  for (it1 = a2.begin(), it2 = b2.begin(); it1 != a2.end(); it1++, it2++)
    ASSERT_EQ(*it1, *it2);

  ASSERT_EQ(a1.size(), b1.size());
  ASSERT_EQ(a2.size(), b2.size());
  // a1.printTree(a1.root);
}

TEST(TestSetGroup, Merge) {
  s21::set<double> a1;
  s21::set<double> a2;
  s21::set<double>::iterator it1;
  for (int i = 0; i <= 10; i++) {
    a1.insert(i).second;
  }
  for (int i = 5; i <= 15; i++) {
    a2.insert(i).second;
  }

  a1.merge(a2);
  int i = 0;
  for (it1 = a1.begin(); i <= 10; i++, it1++) ASSERT_EQ(*it1, i);
  i = 11;
  for (int i = 11; i <= 15; i++, it1++) ASSERT_EQ(*it1, i);
  i = 5;
  it1 = a2.begin();
  for (int i = 5; i <= 10; i++, it1++) ASSERT_EQ(*it1, i);
  ASSERT_EQ(a2.size(), 6);

  // a1.SimpleprintTree(a1.root);
  // a2.printTree(a2.root);
}
//________________________________________________Lookup____________________________________________________
TEST(TestSetGroup, Contains) {
  s21::set<std::string> a;
  std::set<std::string> b;
  s21::set<std::string>::iterator it1;

  for (int i = 0; i < 50; i++) {
    std::string x = std::to_string(i);
    ASSERT_EQ(a.insert(x).second, b.insert(x).second);
  }

  for (int i = 0; i < 50; i++) ASSERT_EQ(a.contains(std::to_string(i)), true);
  for (int i = 50; i < 100; i++)
    ASSERT_EQ(a.contains(std::to_string(i)), false);
}

//________________________________________________Iterators_________________________________________________
TEST(TestSetGroup, operator_plus) {
  s21::set<char> a;
  std::set<char> b;
  s21::set<char>::iterator it1;
  std::set<char>::iterator it2;

  for (int i = 0; i < 50; i++) {
    char x = i;
    ASSERT_EQ(a.insert(x).second, b.insert(x).second);
  }

  for (it1 = a.begin(), it2 = b.begin(); it1 != a.end(); it1++, it2++)
    ASSERT_EQ(*it1, *it2);

  for (it1 = a.begin(), it2 = b.begin(); it1 != a.end(); ++it1, ++it2)
    ASSERT_EQ(*it1, *it2);
}

TEST(TestSetGroup, operator_sub) {
  s21::set<int> a;
  std::set<int> b;
  s21::set<int>::iterator it1;
  std::set<int>::iterator it2;

  for (int i = 0; i < 10; i++) {
    int x = i;
    ASSERT_EQ(a.insert(x).second, b.insert(x).second);
  }

  it1 = a.end();
  it2 = b.end();
  do {
    it1--;
    it2--;
    ASSERT_EQ(*it1, *it2);

  } while (it1 != a.begin() && it2 != b.begin());

  it1 = a.end();
  it2 = b.end();
  do {
    --it1;
    --it2;
    ASSERT_EQ(*it1, *it2);

  } while (it1 != a.begin() || it2 != b.begin());
  ASSERT_EQ(a.size(), b.size());
  // a.printTree(a.root);
}

TEST(TestSetGroup, operator_equal) {
  s21::set<std::string> a;
  std::set<std::string> b;
  a.insert("Nurlan");
  b.insert("Nurlan");
  s21::set<std::string>::iterator it11 = a.begin();
  s21::set<std::string>::iterator it12 = a.begin();
  std::set<std::string>::iterator it21 = b.end();
  std::set<std::string>::iterator it22 = b.end();
  ASSERT_EQ(it11 != it11, it21 != it21);
  ASSERT_EQ(it11 == it11, it21 == it21);
  ASSERT_EQ(it11 != it12, it21 != it22);
  ASSERT_EQ(it11 == it12, it21 == it22);
}

TEST(TestSetGroup, operator_Arrow) {
  s21::set<char> a;
  std::set<char> b;
  s21::set<char>::iterator it1;
  std::set<char>::iterator it2;
  EXPECT_THROW(*it1, std::exception);
  for (int i = 0; i < 26; i++) {
    char x = 'a' + i;
    ASSERT_EQ(a.insert(x).second, b.insert(x).second);
  }

  for (it1 = a.begin(), it2 = b.begin(); it1 != a.end(); ++it1, ++it2)
    ASSERT_EQ(*it1, *it2);
  // a.printTree(a.root);
}
