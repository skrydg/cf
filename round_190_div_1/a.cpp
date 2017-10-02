#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
vector < pair <long long, long long> > mas;
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int a,b, x = 0,y = 0;
	cin >> a >> b;
	string s;
	cin >> ws >> s;
	mas.push_back ( make_pair(0, 0) );
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'U') y++;
		if (s[i] == 'D') y--;
		if (s[i] == 'L') x--;
		if (s[i] == 'R') x++;
		mas.push_back(make_pair(x,y));
	}
	if (a == 0 && b == 0)
		{
		   cout << "Yes";
	       return 0;
		}
	for (int i = 0; i < mas.size(); i++)
	{
		long long x1 = a - mas[i].first;
		long long y1 = b - mas[i].second;
		if (x1 == 0 && y1 == 0)
		{
			cout << "Yes";
			  return 0;
		}
		if (x == 0 && x1 != 0) continue;
		if (y == 0 && y1 !=0) continue;		
		if (x == 0 && x1 == 0)
		{
			if (y == 0 && y1 == 0)
			{
			  cout << "Yes";
			  return 0;
			}
			if (abs(y1) % abs(y) == 0 && y1/y > 0)
			{
				cout << "Yes";
			    return 0;
			}
			continue;
		}
		if (y == 0 && y1 == 0)
		{
			if (abs(x1) % abs(x) == 0 && x1/x > 0)
			{
				cout << "Yes";
			    return 0;
			}
			continue;
		}
		if ((abs(x1) % abs(x) == 0) && (abs(y1) % abs(y) == 0) && (x1/x == y1/y) && (x1/x > 0))
           {
			  cout << "Yes";
			  return 0;
		   }
	}
	cout << "No";
	return 0;
}
