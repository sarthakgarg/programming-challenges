#include<stdio.h>
#include"iostream"
#include<map>
#include<list>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, ii> iiii;
class LFUCache{
  int sz;
  int mx;
  int tim;
  map<ii, ii> l;
  map<int, map<ii, ii>::iterator> m;
public:
  LFUCache(int capacity) {
    sz = 0;
    tim = 0;
    mx = capacity;
    l.clear();
    m.clear();
  }
  int get(int key) {
    tim++;
    if(m.find(key) != m.end()){
      auto p = m[key];
      auto temp = *p;
      l.erase(p);
      auto x = l.insert(iiii(ii(temp.X.X + 1, tim), temp.Y));
      m[key] = x.X;
      return temp.Y.Y;
    }
    else return -1;
  }
  void set(int key, int value) {
    tim++;
    if(m.find(key) != m.end()){
      auto p = m[key];
      auto temp = *p;
      l.erase(p);
      auto x = l.insert(iiii(ii(temp.X.X + 1, tim), ii(temp.Y.X, value)));
      m[key] = x.X;
    }
    else{
      if(mx == 0){
        return;
      }
      if(sz == mx){
        sz--;
        int u = (l.begin()->Y).X;
        m.erase(u);
        l.erase(l.begin());
      }
      sz++;
      auto temp = iiii(ii(1, tim), ii(key, value));
      auto x = l.insert(temp);
      m[key] = x.X;
    }
  }
};
int main(){
  return 0;
}
