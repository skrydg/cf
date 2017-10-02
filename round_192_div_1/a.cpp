#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n;
	char mas[100][100];
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mas[i][j];
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		bool b = false;
		for (int j = 0; j < n; j++)
			if (mas[i][j] != 'E') b = true; 
		if (!b) flag = true;
	}

	if (!flag)
	{
		for (int i = 0; i < n; i++)
		{
		for (int j = 0; j < n; j++)
			if (mas[i][j] != 'E') 
			{
				cout << i+1 << ' ' << j+1 << '\n';
				break;
			}
		}
		return 0;
	}

	flag = false;

	for (int i = 0; i < n; i++)
	{
		bool b = false;
		for (int j = 0; j < n; j++)
			if (mas[j][i] != 'E') b = true; 
		if (!b) flag = true;
	}


	if (!flag)
	{
		for (int i = 0; i < n; i++)
		{
		for (int j = 0; j < n; j++)
			if (mas[j][i] != 'E') 
			{
				cout << j+1 << ' ' << i+1 << '\n';
				break;
			}
		}
		return 0;
	}

	cout << -1;
	return 0;
}
