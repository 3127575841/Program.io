#include<bits/stdc++.h>
using namespace std;
bool vis[100005]={false};
bool visited[100005]={false};
long long n,x,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(vis[i])
		{
			if(visited[x])
			{
				ans++;
			}else{
				visited[x]=true;
				ans-=2;
			}
		}
		else
		{
			vis[i]=true;
			ans++;
		}
	}
	
	cout<<ans;
	return 0;
}
