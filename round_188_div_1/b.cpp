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

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<short, short> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pnt;
typedef vector <ll> vll; 
#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define FILE ""
#define open 0
#define close 1
const int INF = 1000 * 1000 * 1000 + 5;
const int MOD = 1000 * 1000 * 1000 + 7;
const ld EPS = 1e-9;

const int MAXK = 3000;

short p[MAXK * 2][MAXK * 2];
pii o[MAXK * MAXK * 3];

bool in_range(int l, int s, int r){
	return (l <= s) && (s < r);
}

pii disp[4] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
  //freopen(FILE ".in", "r", stdin);
  //freopen(FILE ".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    short n;
	cin >> n;
	p[MAXK][MAXK] = n;
	int l = 0, r = 0;
	o[r++] = {MAXK, MAXK};
	while (l < r){
		pii cur = o[l++];
	    short pl = p[cur.fi][cur.se] / 4;
		if (pl){
			p[cur.fi][cur.se] %= 4;
			for (int i = 0; i < 4; i++){
				pii ne = {cur.fi + disp[i].fi, cur.se + disp[i].se};
				p[ne.fi][ne.se] += pl;
				if (p[ne.fi][ne.se] >= 4) o[r++] = ne;
			}
		}
	}
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++){
		int a, b;
		cin >> a >> b;
		a += MAXK;
		b += MAXK;
		if (in_range(0, a, 2 * MAXK) &&
			in_range(0, b, 2 * MAXK)){
			cout << p[a][b] << '\n';
		} else {
			cout << 0 << "\n";
		}
	}
	return 0;
}
