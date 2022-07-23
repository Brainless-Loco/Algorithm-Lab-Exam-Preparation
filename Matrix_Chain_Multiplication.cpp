#include<bits/stdc++.h>
using namespace std;

#define inf INT_MAX
#define ll long long

long int D[41]={100,50,10,15,25,20,40,30,20,50,100,15,20,25,45,75,65,5,25,25,20,5,5,20,25,15,35,40,100,20};
long int M[21][21],S[21][21];

void MatChainMult(ll n)
{
	ll i,j,k,l,q;

	for(l=2;l<=n;l++){
		for(i=1;i<=(n-l+1);i++){
			j=i+l-1;
			for(k=i;k<j;k++){
				q=M[i][k]+M[k+1][j]+D[i-1]*D[k]*D[j];
				if(q<M[i][j]){
					M[i][j]=q;
					S[i][j]=k;
				}
			}
		}
	}
}

void SplitPrint(int i, int j)
{
	if(i==j) cout<<"A"<<i;
	else{
		cout<<"(";
		SplitPrint(i,S[i][j]);
		SplitPrint(S[i][j]+1,j);
		cout<<")";
	}
}


int main()
{
	ll i,j,n;
	ll ans;
	cout<<"Enter the no. of matrices: ";
	cin>>n;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j) M[i][j]=0;
			else M[i][j]=inf;

			S[i][j]=0;
		}
	}

	MatChainMult(n);
    cout<<endl<<"Minimum no. of multiplications = "<<M[1][n]<<endl;
	SplitPrint(1,n);
	return 0;
}


///Brainless Loco
