#include <bits/stdc++.h>

using namespace std;

int n;
int a[200],b[200];

int main()
{
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>b[i];
	}
	for(int i=1; i<=n; i++)
	{
		a[i]=b[i]*i;
		for(int j=i-1; j>=1; j--)
		{
			a[i]=a[i]-a[j];
		}
		cout<<a[i]<<" ";
	}
}