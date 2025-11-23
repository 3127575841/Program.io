#include<bits/stdc++.h>
using namespace std;

bool is[10000005]={false};
long long cc[10000005];
long long cnt=0;
long long re=0;
long long ans=0;
int main()
{
	is[1]=true;
	for(int i=2;i<=10000005;i++)
	{
		if(is[i]==false)
		{
			cc[++cnt]=i;
		}
		for(int j=1;j<=cnt;j++)
		{
			if(i*cc[j]>10000005){
				break;
			}
			is[i*cc[j]]=true;
			if(i%cc[j]==0) break;
		}
	}
	cout<<cnt<<endl;
	cout<<cc[cnt]<<endl;
//	long long re=0;
//	for(long long p=1;p<=cnt;p++)
//	{
//		if(cc[p]*cc[p]>23333333333333)
//		{
//			break;		
//		}
//		for(long long q=p+1;q<=cnt;q++)
//		{
//			if(cc[p]*cc[p]*cc[q]*cc[q]<233)
//			{
//				continue;
//			}
//			if(cc[p]*cc[p]*cc[q]*cc[q]>23333333333333)
//			{
//				break;		
//			}
//			re++;
//		}
//	}
//	cout<<re;
	for(long long i=1;i<cnt;i++){
		long long pp = cc[i]*cc[i];
		if(pp * pp >23333333333333) break;//一点小优化
		for(long long j=i+1;j<=cnt;j++){
			long long qq = cc[j]*cc[j];
			if(pp*qq>23333333333333) break;
			if(pp*qq<2333) continue;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}


//#include<iostream>
//using namespace std;
//bool a[10000010] = { 1,1 };//同上问一样i=0,i=1的时候都不是质数 ，所以直接标记，数组大小你看着设定，同上文一样太大考虑vector
//int b[10000010];//存质数 
//long long n;
//int main()
//{
//	int cnt = 0;
//	cin >> n;//看你要查的范围是多大啦。
//	for (int i = 2; i <= n; i++)
//	{
//		if (a[i] == 0)    b[++cnt] = i;
//		for (int j = 1; j <= cnt; j++)
//		{
//			if (i * b[j] > n)break;// 如果超出给出的范围，那么就退出循环 
//			a[i * b[j]] = 1;//素数的倍数不是素数，进行标记。
//			if (i % b[j] == 0)break;//超级关键的只标记一次
//		}
//	}
//	cout<<cnt;
//	return 0;	
//}
