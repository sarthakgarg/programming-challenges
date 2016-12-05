#include<stdio.h>
#include"iostream"
#include<vector>
#include<map>
using namespace std;
int main(){
  map<int, int> m;
  m[1] = 2;
  m.insert(pair<int, int>(1, 3));
  cout << m[1] << "\n";
  return 0;
}
