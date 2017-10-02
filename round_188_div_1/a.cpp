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


bool is(ll a, ll b, ll c){
	return max(a, b) >= c;
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
	ll x, y, m;
	cin >> x >> y >> m;
	if (!is(x, y, m) && max(x, y) <= 0){
		cout << -1;
		return 0;
	}

	if (x < y) swap(x, y);
    ll cnt = 0;
	while (x < m){
		cnt += (x - y) / x + 1;
		//cout << cnt << endl;
		y = ((x - y) / x + 1) * x + y;
		if (x < y)
			swap(x, y);
	}
	cout << cnt;
	return 0;
}
