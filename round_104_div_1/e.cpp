#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;

const int MAXN = 1000000; //
int n,m, len;
struct v
{
	int nul, one, up, down;
	int flag;
};
v der[MAXN * 4];

void UP(int v) // children --> parent
{
	der[v].one = der[2*v].one + der[2*v + 1].one;
	der[v].nul = der[2*v].nul + der[2*v + 1].nul;
	der[v].up = max( der[2*v]. nul + der[2*v + 1]. up, der[2*v].up + der[2*v + 1].one);
	der[v].down = max (der[2*v]. one + der[2*v + 1].down, der[2*v]. down + der[2*v + 1]. nul);
	der[v].flag = 0;
}
void update(int v)
{
	der[v].flag = 1 - der[v].flag;
	swap(der[v].one,der[v].nul);
	swap(der[v].up,der[v].down);

}
void push(int v)
{
	der[v].flag = 0;
	update(2*v);
	update(2*v + 1);
}
void Update(int l, int r, int v,int L,int R)
{
	if (l == L && r == R)
	{
		update(v);
	}
	else
	{
		if (der[v].flag) push(v);
		int s = ( L + R ) / 2;
		if ( s < l ) Update(l, r, 2*v + 1, s + 1, R);
		else
		{
			if ( s >= r) Update(l, r, 2*v, L, s);
			else
			{
				Update(l, s, 2*v, L, s);
				Update(s+1, r, 2*v + 1, s+1, R);
			}
		}
		UP(v);
	}

}
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n >> m;
	for (len = 1; len < n; len *=2);
	for (int i = 0; i < n; i++)
	{
		char x;
		cin >> x;
		//der[i + len].nul = 0;
		//der[i + len].one = 0;
		der[i + len].up = 1;
		der[i + len].down = 1;
		//der[i + len].flag = 0;
	    if (x == '4')  der[i + len].nul ++;
		else der[ i + len ]. one ++;
	}

/*	for (int i = n; i < 2*len; i++)
	{
		der[i + len].nul = 0;
		der[i + len].one = 0;
		der[i + len].up = 0;
		der[i + len].down = 0;
		der[i + len].flag = 0;
	}
	*/
	for (int i = len - 1; i > 0; i--)
		UP(i);
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> ws >> s;
		if (s == "count")
		{
			cout << der[1].up << endl;
		}
		else
		{
			int l,r;
			cin >> l >> r;
			Update(l + len - 1, r + len - 1, 1, len, len * 2 - 1);
		}
	}
	return 0;
}
