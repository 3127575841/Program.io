//i指针不回退，j指针来回跑
#include<bits/stdc++.h>
#define N 1000010
using namespace std;
int n,m;
char s[N],p[N];
int next_Array[N];

int main()
{
	cin>>s+1>>p+1; //s[0]和p[0] 不输入从一开始
	m=strlen(s+1),n=strlen(p+1);
	next_Array[1]=0;
	for(int i=2,j=0;i<=n;i++)
	{
		while(j&&p[i]!=p[j+1])
		{
			j=next_Array[j];
		}
		if(p[i]==p[j+1]){
			j+=1;
		}
		next_Array[i]=j;
	}
	//生成next数组
	for(int i=1,j=0;i<=m;i++)
	{
		while(j&&s[i]!=p[j+1])
		{
			j=next_Array[j];
		}	
		if(s[i]==p[j+1])
		{
			j++;
		}
		if(j==n)
		{
			cout<<i-j+1<<endl;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<next_Array[i]<<" ";
	}
	return 0;
}
