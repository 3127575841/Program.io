#include<bits/stdc++.h>
using namespace std;


string s;
char manachar[51000010];
int num,len,m=0;
int p[51000010];
void Get_manachar()
{
	
	num=s.length()*2+1;
	for(int i=0,j=0;i<num;i++)
	{
		manachar[i]=(i&1)==0?'#':s[j++];
	}
}

int manacher()
{
	for(int i=0,c=0,r=0,len;i<num;i++)
	{
		len=r>i?min(p[2*c-i],r-i):1;
		while(i+len<num&&i-len>=0&&manachar[i+len]==manachar[i-len])
		{
			len++;
		}
		if(i+len>r)
		{
			r=i+len;
			c=i;
		}
		m=max(m,len);
		p[i]=len;
	}
	
	return m-1;
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	Get_manachar();
	cout<<manacher();

	
	return 0;
}

