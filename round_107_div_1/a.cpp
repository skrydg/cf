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

int main()
{
	//freopen("subsequences.in", "r", stdin);
	//freopen("subsequences.out", "w", stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	ll q;
	ll ans = 1;
	cin >> q;
	int cnt = 0;
	for (ll i = 2; i * i <= q; i++)
	{
		while (q % i == 0)
		{
			if (cnt < 2) ans *= i;
			cnt++, q /= i;
		}
		if (cnt >= 3) break;
	}
	if (q > 1) cnt++;
	if (cnt <= 1)
	{
		cout << 1 << endl << 0;
		return 0;
	}
	if (cnt == 2)
	{
		cout << 2;
		return 0;
	}
	cout << 1 << endl << ans;
	return 0;
	
}
