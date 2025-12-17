#include<bits/stdc++.h>

using namespace std;

int n;
string s[200];
string tem;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		tem="";
		for(int j=s[i].size()-1;j>=0;j--)
		{
			tem+=s[i][j];
		}
		for(int j=i;j<=n;j++)
		{
			if(tem==s[j])
			{
				cout<<tem.size()<<" "<<tem[tem.size()/2]<<endl;
				return 0;
			}
		}
	}
}