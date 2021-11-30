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
struct node
{
	ll v=0;;
	// use more variables if you want more information
	// these default values should be identity_element
	node(){}
	node(ll val){
		v=val;
	}
	void merge(const node &l,const node &r){ // store the thing you wanna query
		
		v=l.v+r.v;
		// if we wanted the maximum, then we would do
		// like v = max(l.v,r.v)
	}
};

// example: add on a range: identity transformation = 0
// old += new

// if old is identity which is 0, then 0 + new which new

struct update
{
	ll v = 0; // 4
	// use more variables if you want more information
	// these default values should be identity_transformation
	update(){}
	update(int val){
		v = val; // 5
	}
	// combine the current my_update with the other my_update (see keynotes)
	void combine(update &other,const int32_t &tl,const int32_t &tr){
		v += other.v; // 6
		
		// you can be sure that the "other" is newer than current
		
	}
	// store the correct information in the my_node x
	void apply(node &x,const int32_t &tl,const int32_t &tr){
		
		// no change in freq
		x.v+=(tr-tl+1)*v; 
		
	}
};

// template<typename node,typename update>
struct segtree{
	int len;
	vector<node> t;
	vector<update> u;
	vector<bool> lazy;
	node identity_element;
	update identity_transformation;
	segtree(int l){
		len = l;
		t.resize(4 * len);
		u.resize(4 * len);
		lazy.resize(4 * len);
		identity_element = node();
		identity_transformation = update();
	}	
	void pushdown(const int32_t &v, const int32_t &tl, const int32_t &tr){
		if(!lazy[v]) return;
		int32_t tm = (tl + tr) >> 1;
		apply(v<<1,tl,tm,u[v]);
		apply(v<<1|1,tm+1,tr,u[v]);
		u[v] = identity_transformation;
		lazy[v] = 0;
	}	
	void apply(const int32_t &v, const int32_t &tl, const int32_t &tr, update upd){
		if(tl != tr){
			lazy[v] = 1;
			u[v].combine(upd,tl,tr);
		}
		upd.apply(t[v],tl,tr);
	}
	template<typename T>
	void build(const T &arr,const int32_t &v, const int32_t &tl, const int32_t &tr){
		if(tl == tr){
			t[v] = arr[tl];
			return;
		}
		int32_t tm = (tl + tr) >> 1;
		build(arr,v<<1,tl,tm);
		build(arr,v<<1|1,tm+1,tr);
		t[v].merge(t[v<<1],t[v<<1|1]);
	}
	node query(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r){
		if(l > tr || r < tl){
			return identity_element;
		}
		if(tl >= l && tr <= r){
			return t[v];
		}
		pushdown(v,tl,tr);
		int32_t tm = (tl + tr) >> 1;
		node a = query(v<<1,tl,tm,l,r),b = query(v<<1|1,tm+1,tr,l,r),ans;
		ans.merge(a,b);
		return ans;
    }
	// rupd = range update
	void rupd(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r,const update &upd){
		if(l > tr || r < tl){
			return;
		}
		if(tl >= l && tr <= r){
			apply(v,tl,tr,upd);
			return;
		}
		pushdown(v,tl,tr);
		int32_t tm = (tl + tr) >> 1;
		rupd(v<<1,tl,tm,l,r,upd);
		rupd(v<<1|1,tm+1,tr,l,r,upd);
		t[v].merge(t[v<<1],t[v<<1|1]);
	}
	public:
	template<typename T>
	void build(const T &arr){
		build(arr,1,0,len-1);
	}
	node query(const int32_t &l,const int32_t &r){
		return query(1,0,len-1,l,r);
	}
	void rupd(const int32_t &l,const int32_t &r,const update &upd){
		rupd(1,0,len-1,l,r,upd);
	}
};
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin>>n>>q;
    sfv(a,n);
    segtree s(n);
    s.build(a);
    cin.ignore();
    while(q--){
        string st; getline(cin,st);
        if(st.length()==7){
            int x=st[2]-49,y=st[4]-49,z=st[6]-48;
            s.rupd(x,y,z);
        }
        else{
            int k=st[2]-49;
            cout<<s.query(k,k).v<<"\n";
        }
    }
return 0;
}

