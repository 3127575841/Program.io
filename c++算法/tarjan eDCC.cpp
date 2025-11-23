#include<bits/stdc++.h>
#define N 5010
#define M 20010
using namespace std;
int n,m,x,y,sum=0,head[N],idx=1;
struct E
{
	int to,ne;
}e[M];
int dfn[N],low[N],tim,dcc[N],cnt,bri[M],du[N];
stack<int>s;
void add(int x,int y)
{
	e[++idx].to=y;
	e[idx].ne=head[x];
	head[x]=idx;
}
void tarjan(int x,int ine)
{
	dfn[x]=low[x]=++tim;
	s.push(x);
	for(int i=head[x];i;i=e[i].ne)
	{
		int y=e[i].to;
		if(!dfn[y])
		{
			tarjan(y,i);
			low[x]=min(low[x],low[y]);
			if(dfn[x]<low[y])
			{
				bri[i]=bri[i^1]=1;
			}
		}
		else if(i!=(ine^1))
		{
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(dfn[x]==low[x])
	{
		++cnt;
		while(1)
		{
			int y=s.top();
			s.pop();
			dcc[y]=cnt;
			if(x==y) break;
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
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	tarjan(1,0);
	for(int i=2;i<=idx;i++)
	{
		if(bri[i])
		{
			du[dcc[e[i].to]]++;
		}
	}
	for(int i=0;i<=idx;i++)
	{
		if(du[i]==1)
		{
			sum++;
		}
	}
	printf("%d\n",(sum+1)/2);
	return 0;
}


//
//
//// Tarjan eDCC缩点 O(n)
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//#include <stack>
//using namespace std;
//
//const int N=5010,M=20010;
//int n,m,x,y,sum=0;
//int head[N],idx=1; //2,3开始配对
//struct E{int to,ne;}e[M];
//int dfn[N],low[N],tim,dcc[N],cnt,bri[M],du[N];
//stack<int> s;
//
//void add(int x,int y){
//	e[++idx].to=y;e[idx].ne=head[x];head[x]=idx;
//}
//void tarjan(int x,int ine){
//	dfn[x]=low[x]=++tim; s.push(x);
//	for(int i=head[x];i;i=e[i].ne){
//		int y=e[i].to;
//		if(!dfn[y]){ //若y尚未访问
//			tarjan(y,i);
//			low[x]=min(low[x],low[y]);
//			if(dfn[x]<low[y])
//				bri[i]=bri[i^1]=1; //桥
//		}
//		else if(i!=(ine^1)) //不是反边
//			low[x]=min(low[x],dfn[y]);
//	}
//	if(dfn[x]==low[x]){
//		++cnt;
//		while(1){
//			int y=s.top();s.pop();
//			dcc[y]=cnt; //eDCC
//			if(y==x)break;
//		}
//	}
//}
//int main(){
//	cin>>n>>m;
//	while(m--){
//		cin>>x>>y; add(x,y),add(y,x);
//	}
//	tarjan(1,0);
//	for(int i=2;i<=idx;i++)
//		if(bri[i]) du[dcc[e[i].to]]++; //度数
//	for(int i=1;i<=cnt;i++)
//		if(du[i]==1) sum++; //叶节点数
//	printf("%d\n",(sum+1)/2);
//	return 0;
//}
