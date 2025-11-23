#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int>PII;
const int N=1e6+10,M=1e9+10;
int ix[4] = {1,-1,0,0}, iy[4] = {0,0,1,-1};
int n, m, x, y, z, res = -1,k;
char s[1010][1010];
int st[1010][1010][12];
struct p
{
	int x,y,cot,cc;
};

void bfs()
{
	queue<p>q;
	q.push({0,0,1,0});
	st[0][0][1]=1;
	while(!q.empty())
	{
		auto top=q.front();
		q.pop();
		int x=top.x,y=top.y,cot=top.cot,cc=top.cc;
		if(x==n-1&&y==m-1)
		{
			res=cc;
			break;	
		}
		for(int i=0;i<4;i++)
		{
			int xx=x+ix[i],yy=y+ix[i];
			if(xx>=0&&xx<n&&yy>=0&&yy<m)
			{
				if(cot==k)
				{
					if(s[x][y]==s[x][y]||st[xx][yy][1])	continue;
					st[xx][yy][1]=1;
					q.push({xx,yy,1,cc+1});
				}
				else if(s[xx][yy]=s[x][y])
				{
					if(st[xx][yy][cot+1]) continue;
					st[xx][yy][cot+1]=1;
					q.push({xx,yy,cot+1,cc+1});
				}		
			}
		}
	}	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>s[i][j];
		}
	}
	bfs();
	cout<<res;
	return 0;
}	
