#include<bits/stdc++.h>

using namespace std;

int n;
string s;
int f[30];
char c;
bool t;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		f[s[0]-96]++;
	}
	for(int i=1;i<=26;i+)
	{
		if(f[i]>=5)
		{
			c=i+96;
			cout<<c;
			f=true;
		}
	}
	if(!f)
	{
		cout<<"PREDAJA";
	}
	return 0;
}