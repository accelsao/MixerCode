# Problem Statement
Give N ,a ,b  
N vertexs and you need to construct a graph that there are a components and b in its complement  
# Input
<a href="https://www.codecogs.com/eqnedit.php?latex=n,a,b(1\leq&space;n&space;\leq&space;10^{3}&space;,&space;1\leq&space;a,b&space;\leq&space;n)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?n,a,b(1\leq&space;n&space;\leq&space;10^{3}&space;,&space;1\leq&space;a,b&space;\leq&space;n)" title="n,a,b(1\leq n \leq 10^{3} , 1\leq a,b \leq n)" /></a>  
# Solution
Consider the case when a=b=1 ;  
only when n=2 or n=3 there is no answer  
otherwise for n=1 there is no edge in the graph  
and for n>=4 we can have edge 1 ~ 2,2 ~ 3..n-1~n  that satisfy the conditions  

Then when a!=1 and b!=1 there is no answer ,too  
because when a is not 1 ,it means there is a-1 vertex are isolated , in complement the isolated point will connect to every vertex  
thereforce, components is one in complement graph  

if b>1  ,we connect 1~b-1 make them complete graph  
if a>1  ,we make n-(a-1) complete graph, a-1 isolated
# Code
```cpp
#include <bits/stdc++.h>
#define LL long long
#define Accel ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define Re(a,b) memset(a,b,sizeof a)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ALL(X) (X).begin(), (X).end()
#define FOR(I, A, B) for (int I = (A); I <= (B); I++)
#define REP(I, N) for (int I = 0; I < (N); I++)
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define SZ(a) ((int)a.size())
//#pragma GCC optimize(2)
using namespace std;
//const double eps=1e-6;
//typedef complex<double>C;
//const double PI(acos(-1.0));
//for(int mask=i;mask>0;mask=(mask-1)&i)
//int a[25]= { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
//__gcd, atan2(y,x)=y/x , __int128
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){int s=0;while(x){s+=BIT[x];x-=x&-x;}return s;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a,LL b){LL t=1;for(;b;b>>=1,a=a*a%M)b&1?t=t*a%M:0;return t;}
//log() = ln() , log(x)/log(y)=log(y)-base-x
//INT_MAX 127,INT_MIN 128
//int dw[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//int dw[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
//cout<<fixed<<setprecision(12)<<ans<<endl;
//__builtin_popcount(mask)
//isalnum() decimal digit or an uppercase or lowercase letter
const int N=1e3+10;
const LL inf=1e18;
int p[N][N];
int n,a,b;
int main(){Accel
	cin>>n>>a>>b;

	if(a==1&&b==1){
		if(n==2||n==3)cout<<"NO\n";
		else{
			cout<<"YES\n";
			FOR(i,1,n){
				FOR(j,1,n)
					if(j==i+1||i==j+1)
						cout<<1;
					else cout<<0;
				cout<<endl;
			}
		}
		return 0;
	}
	if(b>1){
		b--;
		for(int i=1;i<=b;i++){
			for(int j=i+1;j<=n;j++){
				p[i][j]=p[j][i]=1;
			}
		}
		if(a>1){
			cout<<"NO\n";
			
		}
		else{
			cout<<"YES\n";
			FOR(i,1,n){
				FOR(j,1,n)
					cout<<p[i][j];
				cout<<endl;
			}
		}
	}
	else if(a>1){
		a--;
		a=n-a;
		for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				p[i][j]=p[j][i]=1;
			}
		}
		if(b>1){
			cout<<"NO\n";
			
		}
		else{
			cout<<"YES\n";
			FOR(i,1,n){
				FOR(j,1,n)
					cout<<p[i][j];
				cout<<endl;
			}
		}
	}
	
}
```

