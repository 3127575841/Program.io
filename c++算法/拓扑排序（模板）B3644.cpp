#include<bits/stdc++.h>
using namespace std;
vector<int>e[105];
int inputpoint[105];
int n;
queue<int>q;
queue<int>p;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		int to;
		cin>>to;
		while(to!=0){
			e[i].push_back(to);
			inputpoint[to]++;
			cin>>to;
		}
	}
	for(int i=1;i<=n;i++){
		if(inputpoint[i]==0) 
		{
			q.push(i);
		}
	}
	while(q.size()){
		int x=q.front();	
		p.push(x);
		q.pop();
		for(auto ed:e[x]){
			if(--inputpoint[ed]==0)
			{
				q.push(ed);		
			}
		}
	}	
	if(p.size()!=n)
	{
		cout<<-1;
	}else{
		while(p.size())
		{
			cout<<p.front()<<" ";
			p.pop();
		}
	}
	return 0;
}
