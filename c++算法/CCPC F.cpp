#include<bits/stdc++.h>
using namespace std;
int k=0;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int x,y,z;
		cin>>x>>y>>z;
		if(x+y<z){
			cout<<-1<<endl;
			continue;
		}
		int a=x+y-z;
		for(int i=max(x,z)+1;i<=a;i++){
			if(a%i ==0){
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}
