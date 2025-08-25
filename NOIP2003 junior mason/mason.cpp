#include<bits/stdc++.h>

using namespace std;

int p;
int pow2[1000];

int main()
{
	freopen("mason.in","r",stdin);
	freopen("mason.out","w",stdout);
	cin>>p;
	cout<<int(log(2)/log(10)*p)+1<<endl;
	pow2[1]=1;
	for(int j=1;j<=p;j++)
	{
		for(int i=1;i<=501;i++)
		{
			pow2[i]*=2;
			if(pow2[i-1]>=10)
			{
				pow2[i-1]-=10;
				pow2[i]++;
			}
		}
	}
	pow2[1]--;
	for(int i=1;i<=501;i++)
	{
		if(pow2[i-1]>=10)
		{
			pow2[i-1]-=10;
			pow2[i]++;
		}
	}
	for(int i=500;i>=1;i--)
	{
		cout<<pow2[i];
	}
}