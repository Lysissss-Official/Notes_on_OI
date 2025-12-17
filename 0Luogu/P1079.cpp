#include<bits/stdc++.h>

using namespace std;

string k,c,ans;

void Comp(char a, char b)
{
	char w;
	int f=false;
	if(a>'Z')
	{
		a=a-32;
	}
	if(b>'Z')
	{
		b=b-32;
		f=true;
	}
	w=b-a+65;
	//cout<<a<<">"<<b<<"="<<(int)w<<endl;
	if(w<'A')
	{
		w=w+26;
	}
	if(f)
	{
		w=w+32;
	}
	ans+=w;
	return;
}

int main()
{
	cin>>k;
	cin>>c;
	int j=0;
	for(int i=0; i<c.size(); i++)
	{
		if(j>=k.size())
		{
			j=0;
		}
		Comp(k[j], c[i]);
		j++;
	}
	cout<<ans;
	return 0;
}