#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<vector>
//#include<algorithm>
#include"Map.h"

Map::Map(int n){
  srand(time(NULL)); // make map whith random number
  for(int i{} ; i < n ; i++)
    {
      for(int j{} ; j < n ; j++)
	{
	  submap.push_back(rand() % 101);
	  subroute.push_back('-');
	}
      map.push_back(submap);
      submap.clear();
      route.push_back(subroute);
      subroute.clear();
    }
  N = n;
}

void Map::showMap(){
  for(int i{}; i < N ; i++)
    {
    for(int j{}; j < N ; j++)
      std::cout << std::setw(5) << map[i][j];
    std::cout << " " << std::endl; 
    }
}

void Map::findRoute1(){
  for(int i{} ; i < N ; i++)
      for(int j{} ; j < N ; j++)
	route[i][j] = '-';
  int i{ 0 };
  int j{ 0 };
  int right{ abs(map[0][1] - map[0][0]) };
  int down{ abs(map[1][0] - map[0][0]) };
  route[i][j] = '*';
  d = 0;
  flag = true;
  while(flag)
    {
      if(i == (N-1))
	{
	  right = abs(map[i][j + 1] - map[i][j]);
	  d += right;
	  j++;
	}
      else if(j == (N-1))
	{
	  down = abs(map[i + 1][j] - map[i][j]);
	  d += down;
	  i++;
	}
      else
	{
	  right = abs(map[i][j + 1] - map[i][j]);
	  down = abs(map[i + 1][j] - map[i][j]);
	  if(right > down)
	    {
	      d += down;
	      i++;
	    }
	  else
	    {
	      d += right;
	      j++;
	    }
	}
      route[i][j] = '*' ;
      if(i == (N-1) && j == (N-1))
	flag = false;
    }
  std::cout << "Distance: " << d << std::endl;
}

void Map::findRoute2(){
  for(int x{} ; x < N ; x++)
      for(int y{} ; y < N ; y++)
	route[x][y] = '-';
   int i{ 0 };
   int j{ 0 };
   int right{ abs(map[0][1] - map[0][0]) };
   int down{ abs(map[1][0] - map[0][0]) };
   int diameter{ abs(map[1][1] - map[0][0]) };
   route[i][j] = '*';
   d = 0;
   flag = true;
   while(flag)
    {
      if(i == (N-1))
	{
	  right = abs(map[i][j + 1] - map[i][j]);
	  d += right;
	  j++;
	}
      else if(j == (N-1))
	{
	  down = abs(map[i + 1][j] - map[i][j]);
	  d += down;
	  i++;
	}
      else
	{
	  right = abs(map[i][j + 1] - map[i][j]);
	  down = abs(map[i + 1][j] - map[i][j]);
	  diameter = abs(map[i + 1][j + 1] - map[i][j]);
	  if((right > diameter) && (down > diameter))
	    {
	      d += diameter;
	      i++;
	      j++;
	    }
	  else if(down > right)
	    {
	      d += right;
	      j++;
	    }
	  else
	    {
	      d += down;
	      i++;
	    }
	}
      route[i][j] = '*' ;
      if(i == (N-1) && j == (N-1))
	flag = false;
    }
  std::cout << "Distance: " << d << std::endl;
}
/*void Map::findRoute3(){
  int i{0}; //x of map
  int j{0}; //y of map
  int d{0}; //distance
  //number of permutation that we need
  int N_p{fact(2*N-2)/(fact(N-1)*fact(N-1))};
  for(int x{} ; x < N ; x++)
      for(int y{} ; y < N ; y++)
	route[i][j] = '-';
  std::vector<char> per{};
  std::vector<int> dis{};
  for(int x{} ; x < N-1 ;x++)
    {
      per.push_back('r');
    }
  for(int x{} ; x < N-1 ;x++)
    {
      per.push_back('d');
    }
  for(int x{}; x < N_p ; x++)
    {
      for(char y : per)
	{
	  if(y == 'r')
	    d += abs(map[i][j + 1] - map[i][j]);
	  if(y == 'd')
	    d += abs(map[i + 1][j] - map[i][j]);
	}
      dis.push_back(d);
      d = 0; 
      std::next_permutation(per.begin(), per.end());
      for(char w : per)
	std::cout << w << " " ;
      std::cout << "" << std::endl;
    }
  for(int w : dis)
    std::cout << w <<std::endl;
    }*/

void Map::showRoute(){
  for(int i{}; i < N ; i++)
    {
    for(int j{}; j < N ; j++)
      std::cout << std::setw(5) << route[i][j];
    std::cout << " " << std::endl; 
    }
}

int Map::fact(int n){
  int f=1;
  for(int i=1;i<=n;i++)
    f *= i;
  return f;
}
