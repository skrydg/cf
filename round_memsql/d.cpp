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


const int MAXN = 300 * 1010;
const int MAXK = 3010;

int ind[MAXK][MAXK * 2];
int r, c, n;
int pr[2 * MAXN], rang[2 * MAXN];
int in_range(int l, int s, int r){
    return (l <= s && s < r);
}

int get_pr(int v){
    if (v == pr[v]) return v;
    return (pr[v] = get_pr(pr[v]));
}

int merge(int a, int b){
    a = get_pr(a);
    b = get_pr(b);
    if (a == b){
        return a;
    }
    if (rang[a] > rang[b]) swap(a, b);
    rang[b] += rang[a];
    pr[a] = b;
    return b;
}

int merge_all(int r1, int c1){
    vector <int> cur;
    for (int dr = -1; dr <= 1; dr++)
        for (int dc = -1; dc <= 1; dc++){
            if (in_range(0, r1 + dr, r) && 
                ind[r1 + dr][(c1 + dc + 2 * c) % (2 * c)] != -1){
                int buf = get_pr(ind[r1 + dr][(c1 + dc + 2 * c) % (2 * c)]);
                cur.pb(buf);
            }
        }
    assert(cur.size() > 0);
    int buf = cur[0];
    for (int i: cur){
        buf = merge(buf, i);
    }
    return buf;
}


int col[2 * MAXN];
int ind_col = 0;
int check(int r1, int c1){
    vector <int> cur;
    for (int dr = -1; dr <= 1; dr++)
        for (int dc = -1; dc <= 1; dc++){
            if (in_range(0, r1 + dr, r) &&
                ind[r1 + dr][(c1 + dc + 2 * c) % (2 * c)] != -1){
                int buf = get_pr(ind[r1 + dr][(c1 + dc + 2 * c) % (2 * c)]);
                cur.pb(buf);
            }
        }
    sort(cur.begin(), cur.end());
    cur.resize(distance(cur.begin(), unique(cur.begin(), cur.end())));
    for (int ind: cur){
        if (col[ind] == ind_col) return 0;
        col[ind] = ind_col;
    }
    return 1;
}


int main() {
#ifdef HOME
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));
#else
    //freopen("code.in", "r", stdin);
    //freopen("code.out", "w", stdout);
#endif
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    cin >> r >> c >> n;
    if (c == 1){
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < 2 * n; i++){
        pr[i] = i;
        rang[i] = 1;
    }
    int ans = 0;
    memset(ind, -1, sizeof ind);
    for (int i = 0; i < n; i++){
        int r1, c1;
        cin >> r1 >> c1;
        r1--; c1--;
        ind_col++; // memset
        assert(check(r1, c1));
        if (check(r1, c1 + c)){
            //cout << r1 + 1 << " " << c1 + 1 << endl;
            ans++;
            ind[r1][c1] = i;
            ind[r1][c1 + c] = i + n;
            merge_all(r1, c1);
            merge_all(r1, c1 + c);
        }
    }
    cout << ans << endl;
    return 0;
}
