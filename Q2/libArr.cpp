#include<iostream>
#include"libArr.h"

int libArr::counter(int n){
  int Arr[n]{};
  int count{0};
    for(int i{0}; i < n ; i++)
    {
      Arr[i] = i+1;
    }
    for(int i{0}; i < n ; i++)
    {
      count += Arr[i];
    }
  return count;
}
