#include <iostream>
#include <vector>
using namespace std;

int main() {
  // Метод reserve() - зарезервировать дополнительную память для массива
  // 1. Объявить массив из 5 элементов типа float
  //   vector<float> A(0);
  // if (A.empty())
  // cout<<"em";
  // else cout << "not em";

  //   // 2. Вывести количество элементов массива и зарезервированное количество
  //   //   cout << A.size() << endl; // 5
  //   //   cout << A.capacity() << endl; // 5

  //   // 3. Зарезервировать дополнительную память для массива
  //   A.reserve(-3);

  //   // 4. Вывести количество элементов массива и зарезервировано место для
  //   // элементов массива
  //   cout << A.size() << endl;      // 5
  //   cout << A.capacity() << endl;  // 12

  std::vector<int> v{1, 2, 3, 4, 5};
  for (int i = 0; i < v.size(); i++) std::cout << v[i] << " ";
  std::cout << "\n";
  std::cout << v.size() << std::endl;
  std::cout << v.capacity() << std::endl;
  vector<int>::iterator it2 = v.end()+1;
  v.erase(it2);
  for (int i = 0; i < v.size(); i++) std::cout << v[i] << " ";
  std::cout << "\n";
  std::cout << v.size() << std::endl;
  std::cout << v.capacity() << std::endl;
}