#include<stdio.h>
#include"iostream"
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<complex>
#include<map>
#include<vector>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>
#include<deque>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define	foreach( gg,itit )	for( auto itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define sz(a) int((a).size())
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
const int mod = 1e9 + 7;
int x, y, z, p, q, r, n, m, alpha[27], grid[27][27];
char ch, str[1004], str1[1004];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n;
	REP(i, n){
		cin >> str;
		REP(j, 26) alpha[j] = 0;
		x = 0;
		y = 0;
		for(int j = 0; str[j] != '\0'; j++){
			if(alpha[str[j] - 'a'] == 0){
				y++;
				alpha[str[j] - 'a'] = 1;
			}
			x++;
		}
		if(y == 1) grid[str[0] - 'a'][str[0] - 'a'] += x;
		else if(y == 2) {
			REPP(j, 1, x){
				if(str[j] != str[0]) ch = str[j];
			}
			grid[str[0] - 'a'][ch - 'a'] += x;
			grid[ch - 'a'][str[0] - 'a'] += x;
		}
	}
	REP(i, 26) REP(j, 26) if(i != j) p = max(p, grid[i][i] + grid[i][j] + grid[j][j]); 
	cout << p << "\n";
	return 0;
}