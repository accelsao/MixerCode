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
const int N=1e6+1;
const int M=1e9+9;
const double eps=1e-6;

const double PI(acos(-1.0));
//for(int mask=i;mask>0;mask=(mask-1)&i)
//int a[25]= { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
//__gcd, atan2(y,x)=y/x , __int128
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//log() = ln() , log(x)/log(y)=log(y)-base-x
//INT_MAX 127,INT_MIN 128
//int dw[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//int dw[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
//cout<<fixed<<setprecision(12)<<ans<<endl;
//__builtin_popcount(mask)
//LL pw(LL a,LL b){LL t=1;for(;b;b>>=1,a=a*a%M)b&1?t=t*a%M:0;return t;}

LL pw(LL a,LL b){
	LL t=1;
	while(b){
		if(b&1)
			t=t*a%M;
		a=a*a%M;
		b>>=1;
	}
	return t;
}

LL n,a,b,k;
int main(){Accel
	cin>>n>>a>>b>>k;
	
	LL a1=pw(a,n);
	LL r=b*pw(a,M-2)%M,r2=1;
	LL ans=0;
	string s;
	cin>>s;
	for(auto x:s){
		
		if(x=='+'){
			ans=(ans+a1)%M;
		}
		else{
			ans=(ans-a1+M)%M;
		}
		a1=(a1*r)%M;
		r2=(r2*r)%M;
	}
	r=r2;
	
	
	
	a1=ans;
	LL tm=(n+1)/k;
	if(r==1){
		cout<<a1*tm%M<<endl;
		return 0;
	}
	LL P=(pw(r,tm)-1+M)%M;
	P=P*a1%M;
	r=(r-1+M)%M;
	P=P*pw(r,M-2)%M;
	
	cout<<P<<endl;
}
