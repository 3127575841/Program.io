#include<bits/stdc++.h>
#define N 10010
using namespace std;
int n,m,a,b;
vector<int>e[N];
int dfn[N],low[N],tot;
stack<int>stk;
int scc[N],cnt,top;
int din[N],dout[N];
bool instk[N]={false};

void tarjan(int x)
{
	dfn[x]=low[x]=++tot;
	instk[x]=true;
	stk.push(x);
	for(int y:e[x])
	{
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(instk[y]){
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
			instk[y]=false;
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
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		while(cin>>a,a){
			e[i].push_back(a);
		}
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i])
		{
			tarjan(i);
		}
	}
	for(int x=1;x<=n;x++){
		for(int y:e[x]){
			if(scc[x]!=scc[y])
			{
				din[scc[y]]++;
				dout[scc[x]]++;
			}
		}
	}
	int a=0,b=0;
	for(int i=1;i<=cnt;i++){
		if(!din[i]) a++;
		if(!dout[i]) b++;
	}
	cout<<a<<endl;
	if(cnt==1) cout<<0;
	else cout<<max(a,b);
	return 0;
}
