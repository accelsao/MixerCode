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
const int M=1e9+7;
const double eps=1e-6;
typedef complex<double>C;
const double PI(acos(-1.0));
//for(int mask=i;mask>0;mask=(mask-1)&i)
//size() use int
//__gcd, atan2(y,x)=y/x , __int128
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//log() = ln() , log(x)/log(y)=log(y)-base-x
//watch out LL
//INT_MAX 127,INT_MIN 128
int n;
vector<int>g[N];
vector<int>f[N];
int dis[N],r[N],tot,vis[N];
void dfs(int u,int d=0,int R=0){
	dis[u]=d;
	r[u]+=R;
	vis[u]=1;
	for(auto v:g[u]){
		if(!vis[v])dfs(v,d+1,R);
	}
	for(auto v:f[u]){
		if(!vis[v]){
			dfs(v,d+1,R+1);
			tot++;
		}
	}
}
int main(){Accel
	cin>>n;
	REP(i,n-1){
		int u,v;cin>>u>>v;
		g[u].PB(v);
		f[v].PB(u);
	}
	dfs(1);
	vector<int>ans;
	int k=tot;
	//cout<<k<<endl;
	FOR(i,1,n){
		int tmp=tot-r[i]*2+dis[i];
		if(tmp<k){
			k=tmp;
			ans.clear();
			ans.PB(i);
		}
		else if(tmp==k)ans.PB(i);
	}
	cout<<k<<endl;
	for(auto x:ans)cout<<x<<" ";
}
