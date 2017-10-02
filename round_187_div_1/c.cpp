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

const int MAXN = 1000 * 1010;
const int mod = 1000 * 1000 * 1000 + 7;
int a[MAXN];
int f[MAXN];
int la[MAXN], sum[MAXN];
ll dp[MAXN];

int get(int x){
	int ans = 0;
	for (int i = x; i >= 0; i = ((i + 1) & i) - 1){
		ans += f[i];
		if (ans >= mod) ans -= mod;
	}
	return ans;
}
void add(int x, int val){
	for (int i = x; i < MAXN; i |= i + 1){
		f[i] += val;
		if (f[i] >= mod) f[i] -= mod;
	}
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
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < MAXN; i++) la[i] = -1;
	int ans = 0;
	add(0, 1);
	for (int i = 0; i < n; i++){
		int buf = dp[a[i]];
		dp[a[i]] = ((ll)get(a[i]) * a[i]) % mod;
		ans = (ans + dp[a[i]] - buf + mod) % mod;
		add(a[i], ((int)dp[a[i]] - buf + mod) % mod);
		//cout << dp[a[i]];
	}
	cout << ans;
	return 0;
}
