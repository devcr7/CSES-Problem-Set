#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define fo(i,n)         for(int i=0;i<n;i++)
#define fod(i,n)        for(int i=n-1;i>=0;i--)
#define For(i,a,b)      for(int i=a;i<=b;i++)
#define all(x)          x.begin(),x.end()
#define SET(x,v)        memset(x,v,sizeof(x))
#define si              set<int>
#define pb(i)           push_back(i)
#define sll             set<long long>
#define vs              vector<string>
#define yes             cout<<"YES\n"
#define no              cout<<"NO\n"
#define vpii            vector<pair<int,int>>
#define ll              long long int
#define vi              vector<ll>
#define mod             1000000007
#define tc(t)           int t; cin>>t; while(t--)
#define sfm(a,m,n)      ll a[m][n]; fo(i,m) fo(j,n) cin>>a[i][j]
#define sfarr(a,n)      ll a[n]; fo(i,n) cin>>a[i]
#define sfv(v,n)        vi v(n); for(ll &i:v) cin>>i
// int f[1000001];
// int prime[1000001];
// void sieve(){
//     prime[0]=prime[1]=0;
//     For(i,2,1000000) prime[i]=1;
//     for(int i=2;i*i<=1000000;i++){
//         if(prime[i]){
//             for(ll j=i*i;j<=1000000;j+=i)
//             prime[j]=0;
//         }
//     }
// }
// int power(int a,int b){
//     int r=1;
//     while(b){
//         if(b&1){
//             r=(r*1ll*a)%mod;
//             b--;
//         }
//         else{
//             a=(a*1ll*a)%mod;
//             b>>=1;
//         }
//     }
//     return r;
// }
// void factorial(){
//     f[0]=f[1]=1;
//     For(i,2,1000000) f[i]=(f[i-1]*1ll*i)%mod;
// }
// int nCr(int a,int b){
//     if(b>a) return 0;
//      factorial();
//      int r=f[a]; 
//      r=(r*1ll*power(f[b],mod-2))%mod;
//      r=(r*1ll*power(f[a-b],mod-2))%mod;
//      return r;
// }
// vi z_algo(string s){
//     ll n=s.length(),l=0,r=0;
//     vi z(n);
//     For(i,1,n-1){
//         if(i<=r) z[i]=min(r-i+1,z[i-l]);
//         while(z[i]+i<n && s[z[i]]==s[i+z[i]]) z[i]++;
//         if(i+z[i]-1>r) l=i,r=i+z[i]-1;
//     }
//     return z;
// }
// int parent[1000001];
// int ranker[1000001];
// int findpar(int node){
//     if(node==parent[node])
//     return node;
//     return parent[node]=findpar(parent[node]);
// }
// void connect(int u,int v){
//     u=findpar(u);
//     v=findpar(v);
//     if(u==v) return;
//     if(ranker[u]<ranker[v])
//     parent[u]=v;
//     else if(ranker[u]>ranker[v])
//     parent[v]=u;
//     else{
//         parent[v]=u;
//         ranker[u]++;
//     }
// }
vector<bool> vis(1000001,0);
vector<int> g[1000001];
vector<int> col(1000001,0);
void graph(vector<int> g[],int e,bool t){
    fo(i,e){
        int u,v; cin>>u>>v;
        g[u].pb(v);
        if(!t)
        g[v].pb(u);
    }
}
bool dfs(int node,int par,int c){
    vis[node]=1;
    col[node]=c;
    for(int child:g[node]){
        if(child==par) continue;
        if(col[child]==0)
        if(!dfs(child,node,(col[node]^3)))
        return 0;
        if(col[child]==col[node])
        return 0;
    }
    return 1;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin>>n>>m;
    graph(g,m,0);
    bool check=1;
    For(i,1,n){
        if(!vis[i]){
            if(!dfs(i,-1,1)){
                check=0;
                cout<<"IMPOSSIBLE";
                break;
            }
        }
    }
    if(check)
    For(i,1,n) cout<<col[i]<<" ";
return 0;
}

