/*
〔2003〕NOI Day2 T1：逃学的小孩 
题目描述详见：https://www.luogu.com.cn/problem/P4408
解题思路详见：https://github.com/Lysissss-Official/Notes_on_OI 

Code by -Lysissss.
-------------------
v0 (2025-8-24): 完成源码
*/

#include<bits/stdc++.h>

using namespace std;

vector<long long> v[2][300000];
int n,m,maxn,x,y,z;
long long d[3][300000],maxd,max2d;
bool f[3][300000];

void dfs(int num,int times,long long len)
{
	for(int i=0;i<v[0][num].size();i++)
	{
		if(!f[times][v[0][num][i]])
		{
			f[times][v[0][num][i]]=true;
			d[times][v[0][num][i]]=len+v[1][num][i];
			dfs(v[0][num][i],times,len+v[1][num][i]);
		}
	}
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n-1;i++)
	{
		cin>>x>>y>>z;
		v[0][x].push_back(y);
		v[1][x].push_back(z);
		v[0][y].push_back(x);
		v[1][y].push_back(z);
	}
	
	f[0][1]=true;
	d[0][1]=0;
	dfs(1,0,0);
	maxn=1;
	for(int i=2;i<=n;i++)
	{
		if(d[0][maxn]<d[0][i])
		{
			maxn=i;
		}
	}
	
	f[1][maxn]=true;
	d[1][maxn]=0;
	dfs(maxn,1,0);
	maxd=d[1][1];
	maxn=1;
	for(int i=2;i<=n;i++)
	{
		if(d[1][maxn]<d[1][i])
		{
			maxn=i;
			maxd=d[1][i];
		}
	}
	
	f[2][maxn]=true;
	d[2][maxn]=0;
	dfs(maxn,2,0);
	max2d=0;
	for(int i=1;i<=n;i++)
	{
		if(d[2][i]<d[1][i])
		{
			if(d[2][i]+maxd>max2d)
			{
				maxn=i;
				max2d=d[2][i]+maxd;
			}
		}
		else
		{
			if(d[1][i]+maxd>max2d)
			{
				maxn=i;
				max2d=d[1][i]+maxd;
			}
		}
		//if(d[1][i]<d[1][maxn])
		//{
		//	if(d[1][i]+d[2][i]>max2d)
		//	{
		//		maxn=i;
		//		max2d=d[1][i]+d[2][i];
		//	}
		//}
		//else
		//{
		//	if(d[2][i]+maxd>max2d)
		//	{
		//		maxn=i;
		//		max2d=d[2][i]+maxd;
		//	}
		//}
	}
	cout<<max2d;
} 
