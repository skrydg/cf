#include <iostream>
using namespace std;


int abs(int x){
	if (x>0) return x;
	else return -x;
}
int main()
{
	long long n,mas[300];
	cin>>n;
	long long sum=0,kol=0,min=10000000;
	for (int i=0;i<2*n-1;i++)
	{
		cin>>mas[i];
		sum+=abs(mas[i]);
		if (mas[i]<0) kol++;
		if (min>abs(mas[i])) min=abs(mas[i]);
	}
	if (n % 2==0)
	{
	if (kol % 2 ==0) cout<<sum;
	else cout<<sum-2*min;
	}
	else cout<<sum;
	return 0;
}
