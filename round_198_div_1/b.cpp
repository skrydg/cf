#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

const int MAXN = 100000;
const int INF = 1000000;
long long a[MAXN];
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector <int> d;
	d.resize(n + 1);
    d[0] = -INF;
    for (int i=1; i<=n; ++i)
	    d[i] = INF;
 
for (int i=0; i<n; i++) {
	int j = int (upper_bound (d.begin(), d.end(), a[i]) - d.begin());
	if (d[j-1] < a[i] && a[i] < d[j])
		d[j] = a[i];
     }
    int ans;
	for (int i = 1; i <= n; i++)
		if (d[i] != INF) ans = i;
	cout << ans;
    return 0;
}
