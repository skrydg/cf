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
const int MAXN = 101;
int g[MAXN][MAXN];
int x[MAXN], y[MAXN];
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
	int n, d;
	cin >> n >> d;
	for (int i = 1; i < n - 1; i++){
		int a;
		cin >> a;
		for (int j = 0; j < n; j++){
			if (i != j)
				g[j][i] = a;
		}
	}
	for (int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			g[i][j] -= d * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++){
				g[j][k] = max(g[j][k], g[j][i] + g[i][k]);
			}
	cout << -g[0][n - 1];
    return 0;
}
