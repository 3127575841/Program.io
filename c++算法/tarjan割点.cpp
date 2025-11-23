#include<bits/stdc++.h>
#define N 20010
using namespace std;
int n,m,a,b;
vector<int>e[N];
int dfn[N],low[N],tot;
bool cnt[N];
int root;
void tarjan(int x)
{
	dfn[x]=low[x]=++tot;
	int child=0;
	for(int y:e[x])
	{
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
			if(low[y]>=dfn[x])
			{
				child++;
				if(x!=root||child>1)
				{
					cnt[x]=true;
				}
			}
		}
		else
		{
			low[x]=min(low[x],dfn[y]);
		}
	}
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	while(m--)
	{
		cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for(root=1;root<=n;root++)
	{
		if(!dfn[root])
		{
			tarjan(root);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt[i])
		{
			ans++;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
	{
		if(cnt[i])
		{
			printf("%d ",i);
		}
	}
	return 0;
}
