
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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pnt;
typedef vector <ll> vll; 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FILE ""
#define POINT -100000000
#define QUERY 1
const int MAXN = 2 * 1000 * 100 + 10;
int ind[MAXN], p[MAXN];
vector <pii> point;

pii que[MAXN];
pair <pii, int> ev[MAXN * 20];
int ans[MAXN];
int cntEv = 0;
int f[MAXN];

int get(int x){
	int ans = 0;
	for (int i = x; i >= 0; i = ((i + 1) & i) - 1)
		ans += f[i];
	return ans;
}
void update(int x){
	for (int i = x; i < MAXN; i |= i + 1)
		f[i]++;
}
int main() {
#ifdef HOME
 	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen(FILE ".in", "r", stdin);
	//freopen(FILE ".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++){
		cin >> p[i];
		ind[p[i]] = i;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j * i <= n; j++){
		    point.pb({ind[i], ind[j * i]});
			ev[cntEv++] = {point.back(), POINT};
		}
	}
	for (int i = 0; i < q; i++){
		cin >> que[i].fi >> que[i].se;
		que[i].fi--, que[i].se--;
		ev[cntEv++] = {{que[i].se, que[i].se}, i + 1};
		ev[cntEv++] = {{que[i].se, que[i].fi - 1}, -i - 1};
		ev[cntEv++] = {{que[i].fi - 1, que[i].se}, -i - 1};
		ev[cntEv++] = {{que[i].fi - 1, que[i].fi - 1}, i + 1};
	}
	sort(ev, ev + cntEv);
	for (int curInd = 0; curInd < cntEv; curInd++){
		pair <pii, int> cur = ev[curInd];
		if (cur.se != POINT){
			int ind = abs(cur.se);
			if (cur.se > 0)
				ans[ind - 1] += get(cur.fi.se);
			else
				ans[ind - 1] -= get(cur.fi.se);
			//	cout << cur.fi.se << " " << ans[ind - 1] << endl;
		} else {
			update(cur.fi.se);
			//	cout << cur.fi.se << endl;
		}
	}
	for (int i = 0; i < q; i++){
		cout << ans[i] << "\n";
	}
    return 0;
}
