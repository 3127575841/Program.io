#include<bits/stdc++.h>
using namespace std;

vector<int>e[5];
int n,m,a,b;
unsigned long long ansa,ansb,ans=;
int w[200010];



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		e[a].push_back(b);
	}
	dfs(1);
	return 0;
	
}	
