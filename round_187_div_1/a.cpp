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
const int MAXN = 1000 * 1000;
ll a[MAXN];
int main() {
#ifdef HOME
 	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen(FILE ".in", "r", stdin);
	//freopen(FILE ".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	int n; ll k; cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	ll lasum = 0,
		cnt = 1,
		realn = n;
	for (int i = 0; i < n; i++){
		if ((ld)lasum - (ld)(realn - cnt) * a[i] * (cnt - 1) < (ld)k){
			cout << i + 1 << "\n";
			realn--;
		} else {
			lasum += a[i] * (cnt - 1);
			cnt++;
		}
	}
	return 0;
}
