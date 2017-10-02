
 #include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

const int MAXN = 100000;
long long mas[MAXN];
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	cin >> n;
	for (int i = 0;i < n; i ++)
		cin >> mas[i];
	sort(mas, mas + n);
	long long ans = 0;
	long long q = n - 1;
	long long sum = 0;
	for (int i = n -1; i >= 0; i --)
	{
		ans += q * mas[i];
		q-=2;
		sum+=mas[i];
	}
	ans*=2;
	ans+=sum;
	int n1 = n;
	for (int i = 2; i <= n;)
	{
		if (n1 % i == 0 && ans % i == 0)
		{
			n1 = n1 / i;
			ans = ans / i;
		}
		else i++;
	}
	cout << ans << ' ' << n1;
	return 0;
}
