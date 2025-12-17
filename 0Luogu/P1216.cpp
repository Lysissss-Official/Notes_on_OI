#include<bits/stdc++.h>

using namespace std;

int r;
int tri[2000][2000];
int f[2000][2000];

int main()
{
	cin>>r;
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=i;j++)
		{
			cin>>tri[i][j];
		}
	}
	for(int i=1;i<=r;i++)
	{
		f[r][i]=tri[r][i];
	}
	for(int i=r-1;i>=1;i--)
	{
		for(int j=1;j<=i;j++)
		{
			f[i][j]=max(f[i+1][j],f[i+1][j+1])+tri[i][j];
		}
	}
	cout<<f[1][1]<<endl;
}