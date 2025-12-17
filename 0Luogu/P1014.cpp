#include<bits/stdc++.h>

using namespace std;

int n,m;
int cnt=0;

int main()
{
	cin>>n;
	for(int i=1;;i++)
	{
		cnt=cnt+i;
		if(cnt>=n)
		{
			cnt=cnt-i;
			cnt=n-cnt;
			m=i+1;
			break;
		}
	}
	cout<<m-cnt<<"/"<<cnt<<endl;
	return 0;
}