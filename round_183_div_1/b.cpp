#include <iostream>
using namespace std;

int main()
{
	long long n,m,x,y,a,b,n1,m1,n11,m11,x1,y1,x2,y2,a1,b1,per;
	cin>>n>>m>>x>>y>>a>>b;
	a1=a;b1=b;
	while (a1!=0)
	{
	    b1=b1 % a1;
		if (b1<a1) { per=b1;b1=a1;a1=per;}
	}
	a=a/b1;b=b/b1;
	n1=n-n%a;
	m1=m-m%b;
	if (n1/a*b<=m) m1=n1/a*b;
	else n1=m1/b*a;
	if (n1 % 2==1) n11=(n1/2+n1%2);
	else n11=n1-(n1/2+n1%2);
	if (m1 % 2==1)
	m11=(m1/2+m1%2);
	else m11=m1-(m1/2+m1%2);
	x1=x-n11;y1=y-m11;
	x2=x1+n1; y2=y1+m1;
	if (x1<0) {x2-=x1; x1=0;}
	if (y1<0) {y2-=y1; y1=0;}
	if (x2>n) { x1-=x2-n; x2=n;}
	if (y2>m) { y1-=y2-m; y2=m;}
	cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2;
	return 0;
}
