#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<vector>
#include"Map.h"

int main()
{
  Map N{5};
  N.showMap();
  std::cout << "first part" << std::endl;
  N.findRoute1();
  N.showRoute();
  std::cout << "second part" << std::endl;
  N.findRoute2();
  N.showRoute();
  //std::cout << "third part" << std::endl
  //N.findRoute3();
  return 0;
}
