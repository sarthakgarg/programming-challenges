// Includes
#include"iostream"
#include<queue>
#include<map>
#include<string.h>
#include<vector>
#include<stack>
#include<stdio.h>
#include<math.h>
#include<set>
#include<algorithm>
#define N 105
#define M 150000
#define mod 10000007
#define X first
#define Y second 
#define INF 1000000007
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPP(i, a, b) for(int i = a; i < b; i++)
#define foreach(gg, itit) for(auto itit = gg.begin(); itit != gg.end(); itit++)
using namespace std;
// End Includes

// I have written the Non IoC code only for the case of computing the dynamic minimum queries

template <class T>
class DynamicRangeMinimum(){
public:
    vector<T> t, leaf;
    int n;
    
    DynamicRangeMinimum(vector<T> input){
        leaf = input;
        n = leaf.size();
        t = vector<T>(4 * n);
        Build(1, 0, n - 1);
    }
    
    T merge(T a, T b){
        return min(a, b);
    }
    
    void Build(int v, int tl, int tr){
        if(tl == tr){
            t[v] = leaf[tl];
            return;
        }
        int mid = (tl + tr) / 2;
        Build(2 * v, tl, mid);
        Build(2 * v + 1, mid + 1, tr);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
        return;
    }
    
    T Query(int v, int tl, int tr, int l, int r){
        if(l == tl && r == tr) return t[v];
        int mid = (tl + tr) / 2;
        if(l > min(r, mid)) return Query(2 * v + 1, mid + 1, tr, max(mid + 1, l), r);
        else if(max(mid + 1, l) > r) return Query(2 * v, tl, mid, l, min(r, mid));
        else return merge(Query(2 * v, tl, mid, l, min(r, mid)), Query(2 * v + 1, mid + 1, tr, max(mid + 1, l), r));
    }
    
    void Update(int v, int tl, int tr, int x, T newval){
        if(tl == tr){
            t[v] = newval;
            return;
        }
        int mid = (tl + tr) / 2;
        if(x <= mid) Update(2 * v, tl, mid, x, newval);
        else Update(2 * v + 1, mid + 1, tr, x, newval);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }   
};


class DynamicRangeGCD(){
public:
    vector<int> t, leaf;
    int n;
    
    DynamicRangeGCD(vector<int> input){
        leaf = input;
        n = leaf.size();
        t = vector<int>(4 * n);
        Build(1, 0, n - 1);
    }
    
    int merge(int a, int b){
        if(b == 0) return a;
        else return merge(b, a % b);
    }
    
    void Build(int v, int tl, int tr){
        if(tl == tr){
            t[v] = leaf[tl];
            return;
        }
        int mid = (tl + tr) / 2;
        Build(2 * v, tl, mid);
        Build(2 * v + 1, mid + 1, tr);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
        return;
    }
    
    int Query(int v, int tl, int tr, int l, int r){
        if(l == tl && r == tr) return t[v];
        int mid = (tl + tr) / 2;
        if(l > min(r, mid)) return Query(2 * v + 1, mid + 1, tr, max(mid + 1, l), r);
        else if(max(mid + 1, l) > r) return Query(2 * v, tl, mid, l, min(r, mid));
        else return merge(Query(2 * v, tl, mid, l, min(r, mid)), Query(2 * v + 1, mid + 1, tr, max(mid + 1, l), r));
    }
    
    void Update(int v, int tl, int tr, int x, int newval){
        if(tl == tr){
            t[v] = newval;
            return;
        }
        int mid = (tl + tr) / 2;
        if(x <= mid) Update(2 * v, tl, mid, x, newval);
        else Update(2 * v + 1, mid + 1, tr, x, newval);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }   
};

class DynamicRangeXOR(){
public:
    vector<int> t, leaf;
    int n;
    
    DynamicRangeXOR(vector<int> input){
        leaf = input;
        n = leaf.size();
        t = vector<int>(4 * n);
        Build(1, 0, n - 1);
    }
    
    int merge(int a, int b){
        return a ^ b;
    }
    
    void Build(int v, int tl, int tr){
        if(tl == tr){
            t[v] = leaf[tl];
            return;
        }
        int mid = (tl + tr) / 2;
        Build(2 * v, tl, mid);
        Build(2 * v + 1, mid + 1, tr);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
        return;
    }
    
    int Query(int v, int tl, int tr, int l, int r){
        if(l == tl && r == tr) return t[v];
        int mid = (tl + tr) / 2;
        if(l > min(r, mid)) return Query(2 * v + 1, mid + 1, tr, max(mid + 1, l), r);
        else if(max(mid + 1, l) > r) return Query(2 * v, tl, mid, l, min(r, mid));
        else return merge(Query(2 * v, tl, mid, l, min(r, mid)), Query(2 * v + 1, mid + 1, tr, max(mid + 1, l), r));
    }
    
    void Update(int v, int tl, int tr, int x, int newval){
        if(tl == tr){
            t[v] = newval;
            return;
        }
        int mid = (tl + tr) / 2;
        if(x <= mid) Update(2 * v, tl, mid, x, newval);
        else Update(2 * v + 1, mid + 1, tr, x, newval);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }   
};

template <class T>
class Sort(){
public:
    vector<pair<T, int> t, leaf;
    int n;
    T top;
    DynamicRangeXOR(vector<int> input){
        int idx = 0;
        tp = input[0];
        for(T x : input){
            leaf.push_back(pair<T, int>(x, idx++));
            top = max(top, x);
        }
        n = leaf.size();
        t = vector<pair<T, int>(4 * n);
        Build(1, 0, n - 1);
    }
    
    pair<T, int> merge(pair<T, int> a, pair<T, int> b){
        return min(a, b);
    }
    
    void Build(int v, int tl, int tr){
        if(tl == tr){
            t[v] = leaf[tl];
            return;
        }
        int mid = (tl + tr) / 2;
        Build(2 * v, tl, mid);
        Build(2 * v + 1, mid + 1, tr);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
        return;
    }
    
    pair<T, int> Query(int v, int tl, int tr, int l, int r){
        if(l == tl && r == tr) return t[v];
        int mid = (tl + tr) / 2;
        if(l > min(r, mid)) return Query(2 * v + 1, mid + 1, tr, max(mid + 1, l), r);
        else if(max(mid + 1, l) > r) return Query(2 * v, tl, mid, l, min(r, mid));
        else return merge(Query(2 * v, tl, mid, l, min(r, mid)), Query(2 * v + 1, mid + 1, tr, max(mid + 1, l), r));
    }
    
    void Update(int v, int tl, int tr, int x, T newval){
        if(tl == tr){
            t[v] = newval;
            return;
        }
        int mid = (tl + tr) / 2;
        if(x <= mid) Update(2 * v, tl, mid, x, newval);
        else Update(2 * v + 1, mid + 1, tr, x, newval);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }
    
    vector<T> sort(){
        vector<T> ret(0);
        for(int i = 0; i < n; i++){
            int mnidx = Query(1, 0, n - 1, 0, n - 1).second;
            ret.push_back(leaf[mnidx].first);
            Update(1, 0, n - 1, mnidx, pair<T, int>(tp, n));
        }
        return ret;
    }
};

int main(){
    //use case for sorting
    vector<string> v;
    v.push_back("ramsey");
    v.push_back("jason");
    v.push_back("brad");
    v.push_back("nicole");
    v.push_back("mary");
    v.push_back("amber");
    Sort<string> f(v);
    f.process();
    vector<string> result = f.sort();
    for(string x : result) cout << x << " ";
    cout << "\n";
    
    // Use case for range minimum query
    /*vector<int> v;
    v.push_back(3);
    v.push_back(5);
    v.push_back(2);
    v.push_back(2);
    v.push_back(1);
    v.push_back(0);
    DynamicRangeMinimum<int> q(v);
    q.process();
    cout << q.query(0, 2) << "\n";
    cout << q.query(0, 4) << "\n";
    cout << q.query(1, 3) << "\n";
    cout << q.query(2, 4) << "\n";
    cout << q.query(1, 1) << "\n";*/
    
    //use case for range XOR queries
    /*vector<int> v;
    v.push_back(3);
    v.push_back(5);
    v.push_back(2);
    v.push_back(2);
    v.push_back(1);
    v.push_back(0);
    DynamicRangeXOR q(v);
    q.process();
    cout << q.query(0, 2) << "\n";
    cout << q.query(0, 4) << "\n";
    cout << q.query(1, 3) << "\n";
    cout << q.query(2, 4) << "\n";
    cout << q.query(1, 1) << "\n";*/
    
    //use case for range gcd queries
    /*vector<int> v;
    v.push_back(12);
    v.push_back(18);
    v.push_back(6);
    v.push_back(24);
    v.push_back(8);
    v.push_back(1);
    DynamicRangeGCD q(v);
    q.process();
    cout << q.query(0, 2) << "\n";
    cout << q.query(0, 4) << "\n";
    cout << q.query(1, 3) << "\n";
    cout << q.query(2, 4) << "\n";
    cout << q.query(1, 1) << "\n";*/
    return 0;
}