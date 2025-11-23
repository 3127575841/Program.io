#include<bits/stdc++.h>
using namespace std;

vector<int>DIV(vector<int>&A,int b)
{
	vector<int>C;
	int r=0;
	for(int i=A.size()-1;i>=0;i--)
	{
		r=r*10+A[i];
		C.push_back(r/b);
		r%=b;
	}
	reverse(C.begin(),C.end());
	while(C.size()>1&&C.back()==0){
		C.pop_back();
	}
	return C;
}
int main()
{
	string a;
	int b;
	cin>>a>>b;
	if(b==0)
	{
		cout<<0;
		return 0;
	}
	vector<int>A;
	for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0') ;
	auto C=DIV(A,b);
	for(int i=C.size()-1;i>=0;i--)
	{
		cout<<C[i];
	}	
	
	return 0;
}
