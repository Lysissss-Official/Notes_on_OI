#include<bits/stdc++.h>

using namespace std;

double a,b,c,d;

int main()
{
	cin>>a>>b>>c>>d;
	for(double i=-100.00; i<=100.00; i=i+0.001)
	{
		if(i>0)return 0;
		cout<<i<<" "<<a*i*i*i+b*i*i+c*i+d<<endl;
		if(a*i*i*i+b*i*i+c*i+d==0.00)
		{
			printf("%.2f\n",i);
		}
	}
	return 0;
}