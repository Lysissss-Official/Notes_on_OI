#include <bits/stdc++.h>

using namespace std;

double p;
long long t,n10;
long long n[6];

long long gcd(long long x,long long y)
{
	if(!y)
	{
		return x;
	}
	return gcd(y,x%y);
}

int main()
{
	cin>>p;
	if(p==1.00)
	{
		cout<<"1 0 0 0 0"<<endl;
		return 0;
	}
	if(p==2.00)
	{
		cout<<"0 1 0 0 0"<<endl;
		return 0;
	}
	if(p==3.00)
	{
		cout<<"0 0 1 0 0"<<endl;
		return 0;
	}
	if(p==4.00)
	{
		cout<<"0 0 0 1 0"<<endl;
		return 0;
	}
	if(p==5.00)
	{
		cout<<"0 0 0 0 1"<<endl;
		return 0;
	}
	p=p*1e9;
	t=p;
	n10=9;
	while(t%10==0)
	{
		t=t/10;
		n10--;
	}
	n10=pow(10,n10);
	
	n[1]=n10;
	n[2]=t-n[1];
	n[1]-=n[2];
	if(n[2]>n10)
	{
		n[1]=0;
		n[2]=n10;
		n[3]=t-n[2]*2;
		n[2]-=n[3];
		if(n[3]>n10)
		{
			n[2]=0;
			n[3]=n10;
			n[4]=t-n[3]*3;
			n[3]-=n[4];
			if(n[4]>n10)
			{
				n[3]=0;
				n[4]=n10;
				n[5]=t-n[4]*4;
				n[4]-=n[5];
				long long int v=gcd(n[4],n[5]);
				n[4]/=v;
				n[5]/=v;
				cout<<n[1]<<" "<<n[2]<<" "<<n[3]<<" "<<n[4]<<" "<<n[5]<<endl;
				return 0;
			}
			long long int v=gcd(n[3],n[4]);
			n[3]/=v;
			n[4]/=v;
			cout<<n[1]<<" "<<n[2]<<" "<<n[3]<<" "<<n[4]<<" "<<n[5]<<endl;
			return 0;
		}
		long long int v=gcd(n[2],n[3]);
		n[2]/=v;
		n[3]/=v;
		cout<<n[1]<<" "<<n[2]<<" "<<n[3]<<" "<<n[4]<<" "<<n[5]<<endl;
		return 0;
	}
	long long int v=gcd(n[1],n[2]);
	n[1]/=v;
	n[2]/=v;
	cout<<n[1]<<" "<<n[2]<<" "<<n[3]<<" "<<n[4]<<" "<<n[5]<<endl;
	return 0;
}