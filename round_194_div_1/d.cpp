
 #include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 1000; //

int mas[MAXN][MAXN];
int n, m;

int was[MAXN][MAXN];

bool check(int l)
{
	vector <int> p;
	for (int i = 0; i < n; i++)
	{
		p.clear();
		for (int j = 0; j < m; j++)
		{
			if (mas[i][j] >= l) p.push_back(j);
		}

		for (int j = 0; j < p.size(); j++)
			for (int k = j + 1; k < p.size(); k++ )
			{
				int first = p[j], second = p[k];  
				if (was[ first ] [ second ] == l) return true;
				else was[ first ] [ second ] = l;
			}
	}
	return false;

}
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	     cin >> mas[i][j];

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		was [i][j] = -1;

 	int l = 0, r = 10e9;
	while ( l + 1 < r)
	{
		if (check( (l + r ) /2))
			l = (l + r ) /2;
		else r = (l + r) /2;

	}
	cout << l;
	return 0;
}
