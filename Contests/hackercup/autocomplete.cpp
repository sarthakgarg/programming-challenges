// trie insert and search facebook hacker cup round 1 uses a trie using a 2d matrix
#include <stdio.h>
#include "iostream"
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include<string.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
#define X first
#define Y second
#define MAXN 1000005
#define MAXALPHA 27
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
int trie[MAXN][MAXALPHA], n, m, x, y, z, valid[MAXN][MAXALPHA], nxt = 1, t;

void add(char str[]){
  int v = 0;
  for(int i = 0; str[i] != '\0'; i++){
    if(valid[v][str[i] - 'a'] == t) v = trie[v][str[i] - 'a'];
    else{
      valid[v][str[i] - 'a'] = t;
      trie[v][str[i] - 'a'] = nxt;
      v = nxt;
      nxt++;
    }
  }
}

int count(char str[]){
  int v = 0, i = 0, ct = 0;
  while(str[i] != '\0'){
    if(valid[v][str[i] - 'a'] == t){
      v = trie[v][str[i] - 'a'];
      ct++;
    }
    else break;
    i++;
  }
  return ct;
}

int main(){
  scanf("%d", &z);
  int ans, ct;
  char str[1000007];
  for(t = 1; t <= z; t++){
    ans = 0;
    nxt = 1;
    scanf("%d", &n);
    while(n--){
      scanf("%s", str);
      ct = count(str);
      if(ct == strlen(str)) ans += ct;
      else ans += (ct + 1);
      add(str);
    }
    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}

