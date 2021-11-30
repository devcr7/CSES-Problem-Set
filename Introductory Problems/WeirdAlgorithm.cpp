#include <bits/stdc++.h>
using namespace std;
#define fo(i,n)         for(int i=0;i<n;i++)
#define fod(i,n)        for(int i=n-1;i>=0;i--)
#define For(i,a,b)      for(int i=a;i<=b;i++)
#define all(x)          x.begin(),x.end()
#define SET(x)          memset(x,-1,sizeof(x))
#define clr(x)          memset(x,0,sizeof(x))
#define pie             3.1415926535897932384626
#define pb(i)           push_back(i)
#define mp              make_pair
#define sf(n)           scanf("%d",&n)
#define sfll(n)         scanf("%lld",&n)
#define sf2(a,b)        scanf("%d %d",&a,&b)
#define sf3(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define pf(n)           printf("%d\n",n)
#define pfll(n)         printf("%lld\n",n)
#define pf2(a,b)        printf("%d %d\n",a,b)
#define pf3(a,b,c)      printf("%d %d %d\n",a,b,c)
#define vi              vector<int>
#define vs              vector<string>
#define pii             pair<int,int>
#define vpii            vector<pair<int,int>>
#define vvi             vector<vi>
#define ll              long long int
#define vll             vector<ll>
#define mod             1000000007
#define tc(t)           int t; sf(t); while(t--)
#define sfarr(a,n)      int a[n]; fo(i,n) sf(a[i])
int main(){
    ll n;
    sfll(n);
    while(n!=1){
        cout<<n<<" ";
        if(n%2)
        n=n*3+1;
        else n/=2;
    }
    cout<<n;
}
