#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>

using namespace std;


int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int k,n;
	cin>>n>>k;
	if (k>=(n*(n-1)/2)) cout<<"no solution";
	else 
	{
		int last=0;
		cout<<1<<' '<<1<<'\n';
		for (int i=2;i<=n;i++)
		{
			cout<<i<<' '<<last+n+i<<'\n'; 
			last=last+n+i;
		}

	}



	return 0;
}
