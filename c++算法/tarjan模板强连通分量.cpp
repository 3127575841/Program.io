#include<bits/stdc++.h>
#define N 100010
using namespace std;
int n,m,a,b;
vector<int>e[N];
int dfn[N],low[N],tot;
stack<int>stk;
int scc[N],siz[N],cnt;

void tarjan(int x)
{
	dfn[x]=low[x]=++tot;
	stk.push(x);
	for(int y:e[x])
	{
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(!scc[y]){
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(dfn[x]==low[x])
	{
		int y;
		++cnt;
		do{
			y=stk.top();
			stk.pop();
			scc[y]=cnt;
			++siz[cnt];
			if(y==x)
			{
				break;
			}
		}while(y!=x);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		e[a].push_back(b);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i])
		{
			tarjan(i);
		}
	}
	int ans=0;
	for(int i=1;i<=cnt;i++){
		if(siz[i]>1)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
