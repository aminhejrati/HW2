#include<iostream>
#include<vector>
#include"libVec.h"

int libVec::counter(int n){
  int count{0};
  for(int i{0}; i < n ; i++)
    {
      list.push_back(i+1);
    }
  for(int i{0}; i < n ; i++)
    {
      count += list[i];
    }  
  return count; 
}
