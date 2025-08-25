#include <bits/stdc++.h>

using namespace std;

int s,t,w;
string str;
bool f;

int main()
{
	cin>>s>>t>>w;
	cin>>str;
	for(int k=1; k<=5; k++)
	{
		f=false;
		for(int i=w-1; i>=0; i--)
		{
			if(str[i] < t+97+i-w)
			{
				f=true;
				str[i]++;
				for(int j=i+1; j<=w-1; j++)
				{
					str[j]=str[j-1]+1;
				}
				break;
			}
		}
		if(f=false)
		{
			return 0;
		}
		cout<<str<<endl;
	}
}