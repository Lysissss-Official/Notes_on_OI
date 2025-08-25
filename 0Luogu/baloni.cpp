#include<bits/stdc++.h>

using namespace std;

int n;
int h;
int f[1000005];
int ans;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>h;
		if(f[h]<=0)
		{
			ans++;
			f[h-1]++;
		}
		else
		{
			f[h]--;
			f[h-1]++;
		}
	}
	cout<<ans<<endl;
}