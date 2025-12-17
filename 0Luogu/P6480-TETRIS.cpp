#include <bits/stdc++.h>

using namespace std;

int a[200];
int n,m;
int ans;

int main()
{
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		ans=n;
		for(int i=1; i<=n-3; i++)
		{
			if(a[i]==a[i+1] && a[i+1]==a[i+2] && a[i+1]==a[i+3])
			{
				ans++;
			}
		}
	}
	else if(m==2)
	{
		for(int i=1; i<=n-1; i++)
		{
			if(a[i]==a[i+1])
			{
				ans++;
			}
		}
	}
	else if(m==3)
	{
		for(int i=1; i<=n-2; i++)
		{
			if(a[i]==a[i+1] && a[i]==a[i+2]-1)
			{
				ans++;
			}
		}
		for(int i=1; i<=n-1; i++)
		{
			if(a[i]==a[i+1]+1)
			{
				ans++;
			}
		}
	}
	else if(m==4)
	{
		for(int i=1; i<=n-2; i++)
		{
			if(a[i+1]==a[i+2] && a[i]==a[i+2]+1)
			{
				ans++;
			}
		}
		for(int i=1; i<=n-1; i++)
		{
			if(a[i]==a[i+1]-1)
			{
				ans++;
			}
		}
	}
	else if(m==5)
	{
		for(int i=1; i<=n-2; i++)
		{
			if(a[i]==a[i+1] && a[i+1]==a[i+2])
			{
				ans++;
			}
		}
		for(int i=1; i<=n-2; i++)
		{
			if(a[i]==a[i+2] && a[i]==a[i+1]+1)
			{
				ans++;
			}
		}
		for(int i=1; i<=n-1; i++)
		{
			if(a[i]==a[i+1]+1)
			{
				ans++;
			}
		}
		for(int i=1; i<=n-1; i++)
		{
			if(a[i]==a[i+1]-1)
			{
				ans++;
			}
		}
	}
	else if(m==6)
	{
		for(int i=1; i<=n-2; i++)
		{
			if(a[i]==a[i+1] && a[i+1]==a[i+2])
			{
				ans++;
			}
		}
		for(int i=1; i<=n-2; i++)
		{
			if(a[i+1]==a[i+2] && a[i]==a[i+2]-1)
			{
				ans++;
			}
		}
		for(int i=1; i<=n-1; i++)
		{
			if(a[i]==a[i+1]+2)
			{
				ans++;
			}
		}
		for(int i=1; i<=n-1; i++)
		{
			if(a[i]==a[i+1])
			{
				ans++;
			}
		}
	}
	else if(m==7)
	{
		for(int i=1; i<=n-2; i++)
		{
			if(a[i]==a[i+1] && a[i+1]==a[i+2])
			{
				ans++;
			}
		}
		for(int i=1; i<=n-2; i++)
		{
			if(a[i]==a[i+1] && a[i]==a[i+2]+1)
			{
				ans++;
			}
		}
		for(int i=1; i<=n-1; i++)
		{
			if(a[i]==a[i+1]-2)
			{
				ans++;
			}
		}
		for(int i=1; i<=n-1; i++)
		{
			if(a[i]==a[i+1])
			{
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}