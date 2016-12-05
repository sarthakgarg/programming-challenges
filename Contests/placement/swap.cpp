#include<stdio.h>
#include"iostream"
using namespace std;
int main(){
  int a, b;
  cin >> a >> b;
  a ^= b ^= a ^= b;
  cout << a << " " << b << "\n";
  return 0;
}
