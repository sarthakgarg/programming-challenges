#include<stdio.h>
#include<list>
#include"iostream"
using namespace std;
int main(){
  list<int> p;
  p.push_front(2);
  auto it = p.begin();
  p.push_front(1);
  cout << *it << "\n";
  return 0;
}
