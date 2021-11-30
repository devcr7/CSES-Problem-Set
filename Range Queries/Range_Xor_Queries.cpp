#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define fo(i,n)         for(int i=0;i<n;i++)
#define fod(i,n)        for(int i=n-1;i>=0;i--)
#define For(i,a,b)      for(int i=a;i<=b;i++)
#define all(x)          x.begin(),x.end()
#define SET(x)          memset(x,-1,sizeof(x))
#define si              set<int>
#define pb(i)           emplace_back(i)
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
int f[1000001];
int prime[1000001];
void sieve(){
    prime[0]=prime[1]=0;
    For(i,2,1000000) prime[i]=1;
    for(int i=2;i*i<=1000000;i++){
        if(prime[i]){
            for(ll j=i*i;j<=1000000;j+=i)
            prime[j]=0;
        }
    }
}
int power(int a,int b){
    int r=1;
    while(b){
        if(b&1){
            r=(r*1ll*a)%mod;
            b--;
        }
        else{
            a=(a*1ll*a)%mod;
            b>>=1;
        }
    }
    return r;
}
void factorial(){
    f[0]=f[1]=1;
    For(i,2,1000000) f[i]=(f[i-1]*1ll*i)%mod;
}
int nCr(int a,int b){
     factorial();
     int r=f[a]; 
     r=(r*1ll*power(f[b],mod-2))%mod;
     r=(r*1ll*power(f[a-b],mod-2))%mod;
     return r;
}
vi z_algo(string s){
    ll n=s.length(),l=0,r=0;
    vi z(n);
    For(i,1,n-1){
        if(i<=r) z[i]=min(r-i+1,z[i-l]);
        while(z[i]+i<n && s[z[i]]==s[i+z[i]]) z[i]++;
        if(i+z[i]-1>r) l=i,r=i+z[i]-1;
    }
    return z;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,q; cin>>n>>q;
    sfarr(a,n);
    int l=sqrt(n+.0)+1;
    ll mn=0;
    vi v(l);
    fo(i,n) v[i/l]^=a[i];
    while(q--){
        int x,y; cin>>x>>y;
        x-=1,y-=1;
        ll m=0;
        for(int i=x;i<=y;){
            if(i%l==0 && i+l-1<=y)
            m^=v[i/l],i+=l;
            else m^=a[i],i++;
        }
        cout<<m<<"\n";
    }
return 0;
}
