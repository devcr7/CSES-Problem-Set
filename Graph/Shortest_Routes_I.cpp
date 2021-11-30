#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pi (3.141592653589)
#define mod 1000000007
#define int long long
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 
int n, m;
vector<pair<int, int>>v[100001];
int vis[100001];
int d[100001];
 
int32_t main(){
fast
// Fuck Ratings, I'm in Love with Experience.
// Once a Charas, Always a CHARAS.
 
 
int t=1;
//cin>>t;
while(t--){
    cin>>n>>m;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
    rep(i, m){
    	int x, y, z;cin>>x>>y>>z;
    	v[x].pb({y, z});
	}
	q.push({0, 1});
	rep(i, 100001)d[i]=1000000000LL * m + 1LL;
	rep(i, 100001)vis[i]=0;
	d[1]=0;
	while(!q.empty()){
		auto a=q.top();
		q.pop();
		int c=a.ss, dis=a.ff;
		if(vis[c])continue;
		vis[c]=1;
		for(auto i: v[c]){
			if(d[c]+i.ss<d[i.ff]){
				d[i.ff]=d[c]+i.ss;
				q.push({d[i.ff], i.ff});
			}
		}
	}
	rep(i, n)cout<<d[i+1]<<" ";
}
return 0;
}