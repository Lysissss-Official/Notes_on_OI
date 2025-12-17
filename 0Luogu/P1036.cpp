#include<bits/stdc++.h>

using namespace std;

int n,k;
int x[40];
int ans;

bool P_Num(int a)
{
	if(a==2)
	{
		return true;
	}
	if(a%2==0)
	{
		return false;
	}
	for(int i=3; i*i<=a; i=i+2)
	{
		if(a%i==0)
		{
			return false;
		}
	}
	return true;
}

void dfs(int sum, int cnt, int now)
{
	if(cnt==0)
	{
		if(P_Num(sum))
		{
			ans++;
		}
		return;
	}
	for(int i=now; i<=(n-cnt+1); i++)
	{
		dfs(sum+x[i],cnt-1,i+1);
	}
}

int main()
{
	cin>>n>>k;
	for(int i=1; i<=n; i++)
	{
		cin>>x[i];
	}
	dfs(0, k, 1);
	cout<<ans<<endl;
	return 0;
}