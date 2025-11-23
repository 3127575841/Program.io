#include<iostream>
using namespace std;
int const N=1010; 
int a[N][N],b[N][N],x; 
int main(){ 
	int n,m,c;
	cin>>n>>m; 
	c=1; 
	for(int i=1;i<=n;i++){ 
		for(int j=1;j<=n+1;j++){
			a[i][j]=0;
			b[i][j]=0;
		}
	}
	while(m--)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		for(int i=x1;i<=x2;i++)
		{
			b[i][y1]+=1;
			b[i][y2+1]-=1;
		}
	}
	
	for(int i=1;i<=n;i++){ 
		for(int j=1;j<=n+1;j++){
			x+=b[i][j];
			a[i][j]=x;
		}
	}
	
	for(int i=1;i<=n;i++){ 
		for(int j=1;j<=n;j++){
			printf("%d ",a[i][j]); 
		}printf("\n"); 
	}
	return 0; 
}
