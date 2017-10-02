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

const int MAXN = 2101;
const int INF = 1000 * 1000 * 1010;

struct edge{
    int u, v;
    int cap, cost, flow;
    int ind;
    edge(){};
    edge(int u, int v, int cap, int cost, int ind) : u(u), v(v), cap(cap), cost(cost), ind(ind){
        flow = 0;
    };
};
int get_cap(edge &a){
    return (a.cap - a.flow);
}

int ptn[MAXN];
int get_weig(edge &a){
    //cout << a.v << " " << a.u << endl;
    assert(a.cost + ptn[a.u] - ptn[a.v] >= 0);
    return (a.cost + ptn[a.u] - ptn[a.v]);
}


vector <edge> ed;
vector <int> g[MAXN];

void add_edge(int u, int v, int cap, int cost, int ind){
    //cout << u << " " << v << " " << cap << endl;
    g[u].pb(sz(ed));
    ed.pb(edge(u, v, cap, cost, ind));
    g[v].pb(sz(ed));
    ed.pb(edge(v, u, 0, -cost, ind));
}


int n, cnt_v, k;
int di[MAXN], pr[MAXN];
bool was[MAXN];
set <pii> is;

int find_min_path(int s, int t){
    is.clear();
    memset(was, 0, sizeof was);
    fill(di, di + cnt_v, INF);
    
    di[s] = 0;
    pr[s] = -1;
    is.insert({di[s], s});
    while (!is.empty()){
        int v = is.begin() -> se;
        is.erase(is.begin());
        if (was[v]) continue;
        was[v] = 1;
        for (int i = 0; i < sz(g[v]); i++){
            edge *buf = &ed[g[v][i]];
            if (get_cap(*buf) == 0) continue;
            assert(v == buf -> u);
            if (di[buf -> v] > di[buf -> u] + get_weig(*buf)){
                di[buf -> v] = di[buf -> u] + get_weig(*buf);
                pr[buf -> v] = g[v][i];
                is.insert({di[buf -> v], buf -> v});
            }
        }
    }
    if (!was[t]) return 0;
    int buft = t;
    int flow = MAXN;
    while (buft != s){
        //cout << buft << endl;
        edge *buf = &ed[pr[buft]];
        flow = min(flow, get_cap(*buf));
        buft = buf -> u;
    }
    buft = t;
    int ans = 0;
    while (buft != s){
        edge *buf = &ed[pr[buft]];
        edge *_buf = &ed[pr[buft] ^ 1];
        buf -> flow += flow;
        _buf -> flow -= flow;
        ans += flow * (buf -> cost);
        buft = buf -> u;
    }

    for (int i = 0; i < cnt_v; i++){ // relax
        ptn[i] = di[i] + ptn[i];
    }
    
    return ans;
}


pair <pii, pii> inf[MAXN];

int main() {
#ifdef HOME
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));
#else
    //freopen("code.in", "r", stdin);
    //freopen("code.out", "w", stdout);
#endif
    //  ios_base::sync_with_stdio(false);
//    cin.tie(0);

    cin >> n >> k;
    int s = 2 * n, t = 2 * n + 1;
    cnt_v = 2 * n + 2;
    for (int i = 0; i < n; i++){
        cin >> inf[i].fi.fi >> inf[i].fi.se >> inf[i].se.fi;
        inf[i].se.se = i;
    }

    
    sort(inf, inf + n);
    for (int i = 0; i < n; i++){
        add_edge(i, i + n, 1, -inf[i].se.fi, inf[i].se.se);
        add_edge(s, i, MAXN, 0, -1); 
        add_edge(i + n, t, MAXN,  0, -1);
    }
    
    for (int i = 0; i < n; i++){
        if (i != n - 1){
            add_edge(i, i + 1, MAXN, 0, -1);
        }
        int ind = 0, mi = MAXN;
        for (; ind < n; ind++){
            if (inf[i].fi.fi + inf[i].fi.se <= inf[ind].fi.fi){
                mi = ind;
                break;
            }
        }
        if (mi < n){
            add_edge(i + n, mi, 1, 0, -1);
        }
    }
    
    int di[MAXN];
    fill(di, di + cnt_v, INF);
    di[s] = 0;
    for (int it = 0; it < cnt_v; it++){
        for (int j = 0; j < sz(ed); j++){
            edge *buf = &ed[j];
            if (get_cap(*buf) > 0){
                di[buf -> v] = min(di[buf -> v], di[buf -> u] + buf -> cost);
            }
        }
    }
    for (int i = 0; i < cnt_v; i++)
        ptn[i] = di[i];
    
    int cur = 0;
    for (int i = 0; i < k; i++){
        cur += find_min_path(s, t);
    }
    
#ifdef HOME
    cout << cur << endl;
#endif

    
    int ans[MAXN];
    for (auto it: ed){
        if (it.ind != -1 && it.u < it.v){
            ans[it.ind] = (it.cap == 1 && it.flow == 1);
        }
    }
    
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}
