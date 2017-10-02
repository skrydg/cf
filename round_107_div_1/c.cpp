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
#define ld long double
#define pld pair <ld, ld>
#define pll pair <ll, ll>
#define fi first
#define pii pair <int, int>
#define se second
#define mp make_pair

const int MAXN = 300 * 1000;
ll x[MAXN], a[MAXN], b[MAXN], cnt_p[MAXN];
ld p[MAXN];
ld sum[MAXN];

struct vertex
{
	ld ma, l, r, all;
	vertex(){};
	vertex(ld ma, ld l, ld r, ld all) : ma(ma), l(l), r(r), all(all) {};
};
ld max(ld a, ld b)
{
	return (a > b) ? a : b;
}
class tree
{
public:
	vector <vertex> t;
	int len;
	vertex up( vertex a, vertex b)
		{
			return vertex(max(a.ma, max(b.ma, a.r + b.l)),
						  max(a.l, a.all + b.l),
						  max(b.r, b.all + a.r),
						  a.all + b.all);
		}
	void build(int n, ld *sum)
		{
			for (len = 1; len < n; len *= 2);
		    t.resize(2 * len);
			for (int i = 0; i < n; i++)
				t[i + len].all = sum[i],
				    t[i + len].ma = t[i + len].l = t[i + len].r = max(0.0, sum[i]);
			for (int i = len - 1; i > 0; i--)
				t[i] = up(t[2 * i], t[2 * i + 1]);
		}
	vertex ma(int tl, int tr, int v, int l, int r)
		{
			if (tl > tr)
				return vertex(0, 0, 0, 0);
			if (tl == l && tr == r)
				return t[v];
			int s = (l + r) / 2;
			return up(ma(tl, min(s, tr), 2 * v, l, s),
					  ma(max(tl, s + 1), tr, 2 * v + 1, s + 1, r));
		}
};
tree t;
int main()
{
	//freopen("subsequences.in", "r", stdin);
	//freopen("subsequences.out", "w", stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n, m, c;
	cin >> n >>  m >> c;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	for (int i = 0; i < n - 1; i++)
		cin >> p[i], p[i] /= 100;
	for (int i = 0; i < m; i++)
		cin >> a[i] >> b[i], a[i]--, b[i]--;
	
	for (int i = 0; i < n - 1; i++)
	{
		sum[i] = (ld)(x[i + 1] - x[i]) / 2.0 - p[i] * c;
	}
	t.build(n - 1, sum);
    ld ans = 0;
	for (int i = 0; i < m; i++)
	{
		int len = t.len;
		ans += (ld)t.ma(a[i] + len, b[i] - 1 + len, 1, len, len * 2 - 1).ma;
	}
	cout.setf(ios::fixed);
	cout.precision(20);
	cout << ans;
	return 0;
	
}
