#include<bits/stdc++.h>
using namespace std;
int n,t;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a=n/2,b=n+a;
		if(a+b==2*n&&(a^b)==(a+b)/2)
		{
			cout<<a<<" "<<b<<endl;
		}
		else puts("-1");
	}
	return 0;
}