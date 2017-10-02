#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <math.h>
#include <deque>
#include <set>
using namespace std;

#define ll long long
#define pll pair <ll, ll>
#define ld long double
#define pld pair <ld, ld>
#define pii pair <ll, ll>
#define m_p make_pair
 struct line 
 {
	 ll k, b;
	 int idn;
	 line(){};
	 line(ll _k, ll _b, int _idn)
	 {
		 k = _k;
		 b = _b;
		 idn = _idn;
	 }
 };

 vector <ll> a, b;
 vector <ll> dp;
 vector < pair <ld, line> > ch;

 ld Intersetion(line fi, line se)
 {
	 return (se.b - fi.b + 0.0) / (fi.k - se.k);
 }

 void Add(int ind)
 {
	 while (!ch.empty() && 
		 Intersetion(line(b[ind], dp[ind], ind), ch.back().second) <= 
		 ch.back().first )
		 ch.pop_back();
	 if (!ch.empty())
		 ch.push_back(m_p(Intersetion(line(b[ind], dp[ind], ind), ch.back().second), 
						line(b[ind], dp[ind], ind)));
	 else
		 ch.push_back(m_p(1, line(b[0], dp[0], 0)));
 }
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	dp.resize(n);
	dp[0] = 0;
	int ind_mi = 0;
	for (int i = 1; i < n; i++)
	{
		Add(i - 1);
		ind_mi = min(ind_mi, int( ch.size() ) );
		for (;ind_mi < ch.size() && a[i] > ch[ind_mi].first; ind_mi++);
		ind_mi--;
		int j = ch[ind_mi].second.idn;
		dp[i] = dp[j] + a[i] * b[j]; 
	}
	cout << dp[n - 1];
	return 0;

}
