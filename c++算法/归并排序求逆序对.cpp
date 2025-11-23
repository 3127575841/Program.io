#include<bits/stdc++.h>
#define N 1000010
using namespace std;

unsigned long long n,q[N],tmp[N],sum=0;
unsigned long long merge_sort(unsigned long long q[],int l,int r)
{
	if(l>=r) return 0;
	int mid=(l+r)>>1;
	sum=merge_sort(q,l,mid)+merge_sort(q,mid+1,r);
	int k=0,i=l,j=mid+1;
	while(i<=mid&&j<=r){
		if(q[i]<=q[j])
		{
			tmp[k++]=q[i++];
		}
		else
		{
			tmp[k++]=q[j++];
			sum+=mid-i+1;
		}
	}
	while(i<=mid){
		tmp[k++]=q[i++];
	}
	while(j<=r){
		tmp[k++]=q[j++];
	}
	for(int i=l,j=0;i<=r;i++,j++){
		q[i]=tmp[j];
	}
	return sum;
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>q[i];
	}
	merge_sort(q,0,n-1);
	cout<<sum;
	return 0;
} 
