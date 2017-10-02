#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <set>
#include <map>
#include <bitset>
#include <time.h>
using namespace std;

typedef vector <int> vi;

#define ll long long
#define pb push_back
#define ld double
#define pld pair <ld, ld>
#define pll pair <ll, ll>
#define fi first
#define pii pair <int, int>
#define se second
#define mp make_pair

int mod = (int)1e9 + 7;
int main()
{
	//freopen("subsequences.in", "r", stdin);
	//freopen("subsequences.out", "w", stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n, k, m;
	cin >> n >> m >> k;
	if (n >= k + 1 && k > 1)
	{
		if (k % 2 == 0)
			cout << m;
		else
			cout << m * m;
		return 0;
	}
	if (n < k || k == 1)
	{
		ll ans = 1;
		for (int i = 0; i < n; i++)
			ans = (ans * m) % mod;
		cout << ans;
		return 0;
	}
	ll ans = 1;
	for (int i = 0; i < (n + 1) / 2; i++)
		ans = (ans * m) % mod;
	cout << ans;

	return 0;
	
}
