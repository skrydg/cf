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

const int MAXN = 101;
const int MAXK = 30;
const int INF = 1000 * 1000 * 1010;

int ne[MAXK][MAXN][MAXN], allne[MAXK][MAXN];
int two[MAXK], rtwo[MAXK];
string a, c;
int norm(int a, size_t mod){
	return a % (int)mod;
}

int get(int posa, int posc, int cnt){
	int ans = 0;
	for (int i = 0; i < MAXK; i++){
		if (cnt % 2){
			ans += ne[i][posa][posc];
			if (ans >= INF) return INF;
			posa = norm(posa + ne[i][posa][posc], a.size());
			posc = norm(two[i] + posc, c.size());
		}
		cnt /= 2;
	}
	return ans;
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
	int b, d; cin >> b >> d;
	cin >> a >> c;
	rtwo[0] = two[0] = 1;
	for (int i = 1; i < MAXK; i++) {
		rtwo[i] = rtwo[i - 1] * 2;
		two[i] = norm(two[i - 1] * 2, c.size());	
	}
	for (int i = 0; i < (int)a.size(); i++){
		for (int j = 0; j < (int)c.size(); j++){
			ne[0][i][j] = 0;
			int k = i;
			while (a[k] != c[j]){
				k = norm(k + 1, a.size());
				ne[0][i][j]++;
				if (ne[0][i][j] > (int)a.size()){
					cout << 0;
					return 0;
				}
			}
			k = norm(k + 1, a.size());
			ne[0][i][j]++;
		}
	}
	for (int k = 1; k < MAXK; k++){
		for (int i = 0; i < (int)a.size(); i++){
			for (int j = 0; j < (int)c.size(); j++){
				ne[k][i][j] = ne[k - 1][norm(i + ne[k - 1][i][j], a.size())][norm(j + two[k - 1], c.size())] + ne[k - 1][i][j];
				if (ne[k][i][j] > INF) ne[k][i][j] = INF;
			}
		}
	}
	for (int i = 0; i < (int)a.size(); i++){
		allne[0][i] = get(i, 0, (int)c.size() * d);
	}
	for (int k = 1; k < MAXK; k++)
		for (int i = 0; i < (int)a.size(); i++){
			allne[k][i] = allne[k - 1][i] +
				allne[k - 1][norm(allne[k - 1][i] + i, a.size())];
			if (allne[k][i] >= INF) allne[k][i] = INF;
		}
	int cur = 0;
	int pos = 0,
		len = 0;
	while (1){
		int ind = MAXK - 1;
		while (ind >= 0 && allne[ind][pos] + len > (int)a.size() * b) ind--;
		if (ind < 0) break;
		len += allne[ind][pos];
		pos = norm(pos + allne[ind][pos], a.size());
		cur += rtwo[ind];
	}
	cout << cur;
	return 0;
}
