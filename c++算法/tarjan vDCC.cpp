#include<bits/stdc++.h>
#define N 10010
using namespace std;
int n,m,a,b,dfn[N],low[N],stk[N],top,tot,root,cnt,num,id[N];
bool cut[N];
vector<int>e[N],ne[N],dcc[N];
void tarjan(int x)
{
	dfn[x]=low[x]=++tot;
	stk[++top]=x;
	if(x==root&&!e[x].size())
	{
		dcc[++cnt].push_back(x);
		return;
	}
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
					cut[x]=true;
				}
				int z;
				cnt++;
				printf("vDCC");
				do{
					z=stk[top--];
					dcc[cnt].push_back(z);
					printf("%d ",z);
				}while(z!=y);
				dcc[cnt].push_back(x);
				printf("%d\n",x);
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
	num=cnt;
	for(int i=1;i<n;i++)
	{
		if(cut[i])
		{
			id[i]+=num;
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		for(int j=0;j<dcc[i].size();j++){
			int x=dcc[i][j];
			if(cut[x])
			{
				ne[i].push_back(id[x]);
				ne[id[x]].push_back(i);
			}
		}
	}	
	return 0;
}
