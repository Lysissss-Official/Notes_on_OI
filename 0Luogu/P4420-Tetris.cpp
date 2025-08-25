#include <bits/stdc++.h>

using namespace std;

int n,m;
int ans[6];
char s[20][20];

int main()
{
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			cin>>s[i][j];
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(i+1<=n && j+1<=m && s[i][j]==s[i][j+1] && s[i][j]==s[i+1][j] && s[i][j]==s[i+1][j+1] && s[i+1][j+1]!='.')ans[1]++;
			
			if(i<=n && j+3<=m && s[i][j]==s[i][j+1] && s[i][j]==s[i][j+2] && s[i][j]==s[i][j+3] && s[i][j+3]!='.')ans[2]++;
			if(i+3<=n && j<=m && s[i][j]==s[i+1][j] && s[i][j]==s[i+2][j] && s[i][j]==s[i+3][j] && s[i+3][j]!='.')ans[2]++;
			
			if(i+1<=n && j+2<=m && s[i][j+1]==s[i][j+2] && s[i][j+1]==s[i+1][j+1] && s[i][j+1]==s[i+1][j] && s[i+1][j]!='.')ans[3]++;
			if(i+2<=n && j+1<=m && s[i][j]==s[i+1][j] && s[i][j]==s[i+1][j+1] && s[i][j]==s[i+2][j+1] && s[i+2][j+1]!='.')ans[3]++;
			
			if(i+1<=n && j+2<=m && s[i][j]==s[i][j+1] && s[i][j]==s[i+1][j+1] && s[i][j]==s[i+1][j+2] && s[i+1][j+2]!='.')ans[4]++;
			if(i+2<=n && j+1<=m && s[i][j+1]==s[i+1][j+1] && s[i][j+1]==s[i+1][j] && s[i][j+1]==s[i+2][j] && s[i+2][j]!='.')ans[4]++;
			
			if(i+1<=n && j+2<=m && s[i+1][j]==s[i+1][j+1] && s[i+1][j]==s[i+1][j+2] && s[i+1][j]==s[i][j+1] && s[i][j+1]!='.')ans[5]++;
			if(i+1<=n && j+2<=m && s[i][j]==s[i][j+1] && s[i][j]==s[i][j+2] && s[i][j]==s[i+1][j+1] && s[i+1][j+1]!='.')ans[5]++;
			if(i+2<=n && j+1<=m && s[i][j]==s[i+1][j] && s[i][j]==s[i+2][j] && s[i][j]==s[i+1][j+1] && s[i+1][j+1]!='.')ans[5]++;
			if(i+2<=n && j+1<=m && s[i][j+1]==s[i+1][j+1] && s[i][j+1]==s[i+2][j+1] && s[i][j+1]==s[i+1][j] && s[i+1][j]!='.')ans[5]++;
		}
	}
	cout<<ans[1]<<endl<<ans[2]<<endl<<ans[3]<<endl<<ans[4]<<endl<<ans[5]<<endl;
	return 0;
}