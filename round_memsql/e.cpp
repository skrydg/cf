#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <list>
#include <iterator>
#include <functional>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <ctime>
#include <cassert>
#include <unordered_set>
#include <bitset>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef pair<short, short> pss;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pset set <pll>*

#define sz(a) ((int)(a.size()))


const int MAXN = 1000 * 1000;

vector <int> g[2 * MAXN];


int col[MAXN], was[MAXN];
int val[MAXN], ne[MAXN];
int n;

void add_edge(int x, int y){
    g[x].pb(y);
    g[y].pb(x);
    //cout << x << " " << y << endl;
}
void find_val(int v, int _val){
    if (was[v]) return;
    was[v] = 1;
    val[v] = _val;
    if (v < 2 * n){
        find_val(v + 2 * n, 1 - _val);
    } else {
        find_val(v - 2 * n, 1 - _val);
    }
    for (auto u: g[v]){
        find_val(u, _val);
    }
}

void dfs(int v, int _col){
    if (was[v]) return;
    was[v] = 1;
    col[v] = _col;
    for (auto u: g[v]){
        dfs(u, _col);
    }
}



int rang[MAXN], pr[MAXN];

int get_pr(int v){
    if (v == pr[v]) return v;
    return (pr[v] = get_pr(pr[v]));
}

void merge(int a, int b){
    a = get_pr(a);
    b = get_pr(b);
    if (a != b){
        if (rang[a] > rang[b]) swap(a, b);
        rang[a] += rang[b];
        pr[b] = a;
    }
}
int main() {
#ifdef HOME
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));
#else
    //freopen("code.in", "r", stdin);
    //freopen("code.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        add_edge(2 * i, 2 * i + 1 + 2 * n);
        add_edge(2 * i + 1, 2 * i + 2 * n);
        int x = i,
            y = i + n;
        add_edge(x, y + 2 * n);
        add_edge(y, x + 2 * n);
    }
    int _col = 0;
    memset(was, 0, sizeof was);
    for (int i = 0; i < 4 * n; i++){
        if (!was[i])
            dfs(i, _col++);
    }
    
    for (int i = 0; i < 2 * n; i++){
        if (col[i] == col[i + 2 * n]){
            cout << "-1\n";
            return 0;
        }
    }
//    for (int i = 0; i < 4 * n; i++){
//        cout << col[i] << " ";
//    }
//    return 0;
    memset(val, -1, sizeof val);
    memset(was, 0, sizeof was);
    find_val(0, 0);
    if (was[2 * n - 1] && val[2 * n - 1] != 0){
        cout << -1 << endl;
        return 0;
    }
    
    find_val(2 * n - 1, 0);
    for (int i = 0; i < 4 * n; i++){
        if (!was[i]){
            find_val(i, 0);
        }
    }
//    for (int i = 0; i < 2 * n; i++)
//        cout << val[i] << " ";
//    return 0;
    for (int i = 0; i < 2 * n; i++){
        if (val[i] == 1){
            ne[i / 2] = i % n;
        }
    }
    assert(n % 2 == 0);
    memset(was, 0, sizeof was);
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (!was[i]){
            cnt++;
            int cur = i;
            while (!was[cur]){
                was[cur] = 1;
                col[cur] = cnt;
                cur = ne[cur];
            }
        }
    }
    for (int i = 0; i < cnt; i++){
        pr[i] = i;
        rang[i] = 1;
    }
    for (int i = 0; i < n / 2; i++){
        if (get_pr(col[i]) != get_pr(col[i + n / 2])){
            swap(ne[i], ne[i + n / 2]);
            merge(col[i], col[i + n / 2]);
        }
    }
    int cur = 0;
    for (int i = 0; i < n; i++){
        cout << cur << " ";
        cur = ne[cur];
    }
    cout << cur << " ";
    return 0;
}
