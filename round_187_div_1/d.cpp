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
#include <bitset>

using namespace std;
typedef unsigned long long ull;
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
#define FILE "stable"

const ll INF = (ll)1000 * 1000 * 1000 * 1000 * 1000;
const int MAXN = 1000 * 1000;
ll x[MAXN], y[MAXN];
pll allx[MAXN];
ll pma[MAXN], pmi[MAXN], sma[MAXN], smi[MAXN];
int n;

bool check(ll d){
	int r = 0;
	for (int l = 0; l < n; l++){
		while (r < n && allx[r].fi - allx[l].fi <= 2 * d) r++;
	    ll dy = max(pma[l], sma[r]) - min(pmi[l], smi[r]);
		if (dy <= 2 * d) return 1;
	}
	return 0;
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
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
	    ll bufx = x[i] + y[i],
			bufy = x[i] - y[i];
		x[i] = 2 * bufx; y[i] = 2 * bufy;
		//cout << x[i] << " " << y[i] << endl;
		allx[i] = {x[i], i};
	}
	sort(allx, allx + n);
	pmi[0] = INF,
		pma[0] = -INF;
	for (int i = 0; i < n; i++)
		pmi[i + 1] = min(pmi[i], y[allx[i].se]),
			pma[i + 1] = max(pma[i], y[allx[i].se]);

	smi[n] = INF,
		sma[n] = -INF;
	for (int i = n - 1; i >= 0; i--)
		smi[i] = min(smi[i + 1], y[allx[i].se]),
			sma[i] = max(sma[i + 1], y[allx[i].se]);
	
	ll l = -1, r = INF;
	while (l + 1 < r){
		ll s = (l + r) / 2;
		if (check(s)) r = s;
		else l = s; 
	}
	cout.setf(ios::fixed);
	cout.precision(20);
	cout << (ld)r / 2;
	return 0;
}
