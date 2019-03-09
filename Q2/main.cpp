#include<iostream>
#include<vector>
#include <chrono>
#include"libVec.h"
#include"libArr.h"


int main()
{
  auto start1{std::chrono::high_resolution_clock::now()};  
  libVec s{};
  std::cout << s.counter(10000) << std::endl;
  auto stop1{std::chrono::high_resolution_clock::now()};
  auto duration1{stop1 - start1};
  auto start2{std::chrono::high_resolution_clock::now()};
  libArr a{};
  std::cout << a.counter(10000) <<std::endl;
  auto stop2{std::chrono::high_resolution_clock::now()};  
  auto duration2{stop2 - start1};   
  std::cout << duration1.count() << ","  << duration2.count() << std::endl;
  return 0;
}
