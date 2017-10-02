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
#define open 0
#define close 1
const int INF = 1000 * 1000 * 1000 + 5;
const int MOD = 1000 * 1000 * 1000 + 7;
const ld EPS = 1e-9;

const int MAXN = 1000;


bool was[MAXN];
vector <pair <pii, int> > ans;
ll a[MAXN], b[MAXN];
int n, ma, e;


vector <pii> ed;
vector <int> g[MAXN];
bool lwas[MAXN];
ll suma[MAXN], sumb[MAXN];

void find(int v, int pr){
	lwas[v] = 1;
	was[v] = 1;
	suma[v] = a[v];
	sumb[v] = b[v];
	if (pr != -1){
		ed.pb({v, pr});
	}
	for (int ne: g[v]){
		if (!lwas[ne]){
			find(ne, v);
			suma[v] += suma[ne];
			sumb[v] += sumb[ne];
		}
	}
}

bool findAns(int v){
	memset(lwas, 0, sizeof lwas);

	set <pair <ll, int> > is;
	ed.clear();
	is.clear();
	find(v, -1);
	if (sumb[v] != suma[v]){
		return 0;
	}
	for (int i = 0; i < (int)ed.size(); i++){
		int v = ed[i].fi;
		if (sumb[v] != suma[v]){
			is.insert({suma[v] - sumb[v], i});
			//cout << v << " " << ed[i].se << " " << sumb[v] - suma[v] << endl;
		}
	}
	//	return 1;
	while (!is.empty()){
		auto it = is.begin();
		
	    ll w = it -> fi;
		int v = ed[it -> se].fi,
			ne = ed[it -> se].se;
		ll curw = 0;
		while (curw == 0){
			curw = w;
			curw = max(min(curw, a[v]), a[v] - ma);
			curw = max(min(curw, ma - a[ne]), -a[ne]);
			it++;
			if (it == is.end())
				break;
			if (curw == 0){
				w = it -> fi; 
				v = ed[it -> se].fi,
					ne = ed[it -> se].se;
			}
		}
		
		it--;
		w = it -> fi;
		v = ed[it -> se].fi,
			ne = ed[it -> se].se;

		a[v] -= curw;
		a[ne] += curw;
		ans.pb({{v, ne}, curw});
		if (w == curw){
			is.erase(it);
			//	cout << 'a';
		} else {
			pair <ll, int> buf = *it;
			is.erase(it);
			buf.fi -= curw;
			is.insert(buf);
		}	
	}
	return 1;
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
	cin >> n >> ma >> e;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	
	for (int i = 0; i < e; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
    memset(was, 0, sizeof was);
	for (int i = 0; i < n; i++){
		if (!was[i]){
			if (!findAns(i)){
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << ans.size() << endl;
	for (pair <pii, int> i: ans){
		if (i.se < 0){
			swap(i.fi.fi, i.fi.se);
			i.se *= -1;
		}
		cout << i.fi.fi + 1 << " " << i.fi.se + 1 << " " << i.se << '\n';
	}
	return 0;
}
