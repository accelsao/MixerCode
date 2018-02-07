//求K條邊的最短路徑

//DP倍增Floyd
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
using namespace std;
const int N=2e5+1;
const int M=1e9+7;
const double eps=1e-6;
typedef complex<double>C;
const double PI(acos(-1.0));
//size() use int
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//log() = ln()
//watch out LL
int K,m,s,t;
map<int,int>mp;
int f[201][201][25],dp[201][2];
int main(){Accel
    cin>>K>>m>>s>>t;
    Re(f,127/3);
    Re(dp,127/2);
    REP(i,m){
        int d,u,v;
        cin>>d>>u>>v;
        if(!mp[u])mp[u]=mp.size();
        if(!mp[v])mp[v]=mp.size();
        u=mp[u],v=mp[v];
        f[u][v][0]=f[v][u][0]=d;
    }
    int n=mp.size();
    FOR(x,1,log2(K)) 
        FOR(k,1,n)
            FOR(i,1,n)
                FOR(j,1,n)
                    f[i][j][x]=min(f[i][j][x],f[i][k][x-1]+f[k][j][x-1]);
    int b=0,fa=0;
    dp[mp[s]][b]=0;
    while(K){
        if(K&1){
            b^=1;
            FOR(i,1,n){
                dp[i][b]=2e9;
                FOR(j,1,n)
                    dp[i][b]=min(dp[i][b],dp[j][b^1]+f[i][j][fa]);
            }
        }
        fa++;
        K>>=1;
    }
    cout<<dp[mp[t]][b]<<endl;
}

//Floyd 矩陣乘法
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
using namespace std;
const int N=2e5+1;
const int M=1e9+7;
const double eps=1e-6;
typedef complex<double>C;
const double PI(acos(-1.0));
//size() use int
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//log() = ln()
//watch out LL
int K,m,s,t,n;
map<int,int>mp;
int f[201][201];
struct mat{
	int s[101][101];
	mat(){
		FOR(i,1,n)FOR(j,1,n)s[i][j]=1e9;
		//Re(s,0x3f);
	}
	mat operator*(mat &x){
		mat tmp;
		FOR(k,1,n)
			FOR(i,1,n)
				FOR(j,1,n)
					tmp.s[i][j]=min(tmp.s[i][j],s[i][k]+x.s[k][j]);
		return tmp;
	}
};
int main(){Accel
	cin>>K>>m>>s>>t;
	REP(i,m){
		int d,u,v;
		cin>>d>>u>>v;
		if(!mp[u])mp[u]=mp.size();
		if(!mp[v])mp[v]=mp.size();
		u=mp[u],v=mp[v];
		f[u][v]=f[v][u]=d;
	}
	n=mp.size();
	mat S,T;
	FOR(i,1,n)
		FOR(j,1,n)
			if(f[i][j])	
				S.s[i][j]=T.s[i][j]=f[i][j];
	K--;
	while(K){
		if(K&1)
			S=S*T;
		T=T*T;
		K>>=1;
	}
	cout<<S.s[mp[s]][mp[t]]<<endl;
}
