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
// int parent[1000001];
// int ranker[1000001];
vector<bool> vis(1000001,0);
vector<int> g[1000001];
// void dfs(int node){
//     vis[node]=1;
//     for(int child:g[node]){
//         if(!vis[child])
//         dfs(child);
//     }
// }
void graph(vector<int> g[],int e,bool t){
    fo(i,e){
        int u,v; cin>>u>>v;
        g[u].pb(v);
        if(!t)
        g[v].pb(u);
    }
}
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
vi emp(1000001);
int dfs(int node){
    vis[node]=1;
    int cur=1;
    for(int child:g[node]){
        if(!vis[child]){
            cur+=dfs(child);
        }
    }
    emp[node]=cur;
    return cur;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    sfarr(a,n);
    int c=2;
    fo(i,n-1){
        g[a[i]].pb(c);
        g[c].pb(a[i]);
        c++;
    }
    dfs(1);
    For(i,1,n) cout<<emp[i]-1<<" ";
return 0;
}

