#include <iostream>

int get_change(int m) {
  //write your code here
  int num_of_coin = 0;
  while(m > 0)
  {
    if(m >= 10) {m -= 10;}
    else if(m >= 5) {m -= 5;}
    else
    {
      m -= 1;
    } 
    num_of_coin ++; 
  }  
  return num_of_coin;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
