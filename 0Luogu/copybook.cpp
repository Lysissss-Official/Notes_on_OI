#include<bits/stdc++.h>

using namespace std;

int m,k;
int b[1000];
int p;
int mid;

bool c(int a)
{
	int n=1,tmp=0;
	for(int i=1;i<=m;i++)
	{
		tmp+=b[i];
		if(tmp>a)
		{
			tmp=b[i];
			n++;
			if(n>k)
			{
				return false;
			}
		}
	}
	return true;
}

void t2(int l,int r)
{
	mid=(l+r)/2;
	if(l>=r)
	{
		return;
	}
	if(c(mid))
	{
		r=mid;
		//cout<<"a\t"<<mid<<"\t";
	}
	else
	{
		l=mid+1;
		//cout<<"b\t"<<mid<<"\t";
	}
	//cout<<l<<"\t"<<r<<endl;
	t2(l,r);
}

int main()
{
	cin>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
		p=p+b[i];
	}
	t2(1,p);
	int s[1000],e[1000];
	int j=1;
	e[j]=m;
	int tmp=b[m];
	for(int i=m-1;i>=1;i--)
	{
		tmp+=b[i];
		//cout<<tmp<<endl;
		if(tmp>mid)
		{
			s[j]=i+1;
			j++;
			e[j]=i;
			tmp=b[i];
		}
	}
	s[j]=1;
	for(int i=j;i>=1;i--)
	{
		cout<<s[i]<<" "<<e[i]<<endl;
	}
	return 0;
}