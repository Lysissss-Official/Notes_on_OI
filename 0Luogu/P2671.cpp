#include<bits/stdc++.h>

using namespace std;

int n,m;
int col[100010], num[100010];
int ans;

int main()
{
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>num[i];
	}
	for(int i=1; i<=n; i++)
	{
		cin>>col[i];
	}
	for(int i=1; i<=n-2; i++)
	{
		for(int j=i+2; j<=n; j=j+2)
		{
			if(col[i]==col[j])
			{
				//cout<<i<<" "<<j<<endl;
				ans=(ans+(num[i]+num[j])*(i+j))%10007;
			}
		}
	}
	cout<<ans;
	return 0;
}