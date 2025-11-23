#include<bits/stdc++.h>
using namespace std;


string a;
string b;
int z[20000010],m,n,e[20000010];
void Zarray(const string& s)
{
	z[0]=s.length();
	for(int i=1,c=1,r=1,len;i<s.length();i++)
	{
		len=r>i?min(r-i,z[i-c]):0;
		while(i+len<s.length()&&s[i+len]==s[len])
		{
			len++;	
		}
		if(i+len>r)
		{
			r=i+len;
			c=i;
		}
		z[i]=len;
	}
}

void Earray(const string& a,const string& b)
{
	n=a.length();
	m=b.length();
	for(int i=0,c=0,r=0,len;i<n;i++)
	{
		len=r>i?min(r-i,z[i-c]):0;
		while(i+len<n&&len<m&&a[len+i]==b[len])
		{
			len++;
		}
		if(i+len>r)
		{
			r=i+len;
			c=i;
		}
		e[i]=len;		
	}	
}
long long eor(int *arr,int num)
{
	long long ans=0;
	for(int i=0;i<num;i++)
	{
		ans^=(long long)(i+1)*(arr[i]+1);
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b;
	Zarray(b);
	Earray(a,b);
	cout<<eor(z,b.length())<<endl;
	cout<<eor(e,a.length());
	
	return 0;
}
