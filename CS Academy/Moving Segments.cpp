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
#define MID ((l+r)>>1)
#define lc (rt<<1)
#define rc (rt<<1|1)
#define ls lc,l,MID
#define rs rc,MID+1,r
#define st 1,1,n
#define PII pair<int,int>
using namespace std;
LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b >> 1,M) : 1; }
const int N=1e5+1;
const int M=1e9+7;
PII p[N];
int main(){Accel
    int n;
    cin>>n;
    vector<int>A;
    REP(i,n)cin>>p[i].F>>p[i].S,A.PB(p[i].F),A.PB(p[i].S);
    sort(ALL(A));
    int t=A[n];
    LL ans=0;
    REP(i,n)
        if(p[i].F>t||p[i].S<t)ans+=min(abs(p[i].F-t),abs(p[i].S-t));
    cout<<ans<<endl;
}
