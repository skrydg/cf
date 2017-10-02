#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if (n==1) cout<<0<<'\n'<<0<<'\n'<<0<<'\n';
	else 
	if (n % 2 ==1){
	for (int i=0;i<n;i++) cout<<i<<' ';
	cout<<'\n';
	for (int i=1;i<n;i++) cout<<i<<' ';
	cout<<0<<'\n';
	int k=1;
	for (int i=0;i<n;i++) 
	{
		cout<<k<<' ';
		k+=2; k=k % n;
	}
	}
	else cout<<-1;
	return 0;
}
