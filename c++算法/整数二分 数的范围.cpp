#include<bits/stdc++.h>
#define N 100100
using namespace std;
int m,n,a[N];
int main()
{
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
	}
	while(n--)
	{
		int x;
		cin>>x;
		int n1=lower_bound(a,a+n,x)-a;
		int n2=upper_bound(a,a+n,x)-a;
		if(a[n1]!=x)
		{
			cout<<"-1"<<" "<<"-1"<<endl;
			continue;
		}
		cout<<n1<<" "<<n2-1<<endl;
	}
	return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e5+4;
//int n,p;
//int a[N];
//int main()
//{
//	cin>>n>>p;
//	for(int i=0;i<n;i++)
//	{
//		cin>>a[i];
//	}
//	while(p--)
//	{
//		int x;
//		cin>>x;
//		int n1 = lower_bound(a,a+n,x)-a;
//		int n2 = upper_bound(a,a+n,x)-a;
//		if(a[n1]!=x) {
//			cout<<"-1"<<" "<<"-1"<<endl;
//			continue;
//		}
//		cout<<n1<<" "<<n2-1<<endl;
//		
//	}
//	
//	
//	return 0;
//}
