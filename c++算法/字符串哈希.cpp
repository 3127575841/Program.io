//将字符串转换为P进制数字，比较数字来比较字符串
#include<bits/stdc++.h>
#define P 131  //P通常取131或13331，m与P互质来防止hash值一样（哈希碰撞）
using namespace std;
unsigned long long  n;
unsigned long long num[20005];
unsigned long long sum[20005];
unsigned long long calc(string a)
{
	int cnt=a.size();
	num[0]=(int)a[0];
	for(int i=1;i<cnt;i++){
		num[i]=num[i-1]*P+a[i];
	}
	return num[cnt-1];
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
	{	
		string s;
		cin>>s;
		s;
		sum[i]=calc(s);
	}
	sort(sum+1,sum+n+1);
	int res=0;
	for(int i=1;i<=n;i++){
		if(sum[i]!=sum[i-1])
		{
			res++;
		}
	}
	cout<<res;
	return 0;

}



