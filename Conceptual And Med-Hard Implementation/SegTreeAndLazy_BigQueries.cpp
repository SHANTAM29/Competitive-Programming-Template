#include<bits/stdc++.h>
 
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define len(s) s.length()
#define forp(i,a,b) for( i=a;i<=b;i++)
#define FOR(tt,a,b) for(int tt=a;tt<=b;tt++)
#define rep(i,n)    for( i=0;i<n;i++)
#define ren(i,n)    for( i=n-1;i>=0;i--)
#define forn(i,a,b) for( i=a;i>=b;i--)
#define all(v) v.begin(),v.end()
#define b(v) v.begin()
#define e(v) v.end()
#define mem(n,m) memset(n,m,sizeof(n))
#define lb lower_bound
#define ub upper_bound
#define pii pair<int,int>
#define pll pair<long long,long long>
#define vii vector<int>
#define vll vector<long long>
#define gl(cin,s)  getline(cin,s);
#define bitc(n) __builtin_popcountll(n)
#define present(s,x) (s.find(x) != s.end()) 
#define cpresent(s,x) (find(all(s),x) != s.end()) 
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
 
#define boost ios_base::sync_with_stdio(0)
#define MOD 1000000007
#define EPSILON 1e-9
#define PI 3.14159265358979323846
#define SIZE 100001
 
typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
 
ll a[SIZE];
pll pref[SIZE],tree[6*SIZE],lazyx[SIZE*6];
pair< ll , pair<ll,ll> > lazyy[SIZE*6];
 
ll expo2(ll x){
	ll ans=0;
	while(x>0 and x%2==0){
		x/=2;
		ans++;
	}
	return ans;
}
 
ll expo5(ll x){
	ll ans=0;
	while(x>0 and x%5==0){
		x/=5;
		ans++;
	}
	return ans;
}
 
void func(){
	pref[0]=mp(0LL,0LL);
	for(ll i=1;i<SIZE;i++){
		pref[i].ff = pref[i-1].ff + expo2(i);
		pref[i].ss = pref[i-1].ss + expo5(i);
	}
}
 
void build(ll node,ll s,ll e)
{
	if(s==e){
		lazyx[node]=mp(0LL,0LL);
		lazyy[node]=mp(0LL,mp(0LL,0LL));
		tree[node]=mp(expo2(a[s]),expo5(a[s]));
	}
	else{
		ll mid = (s+e)>>1;
		build(2*node,s,mid);
		build(2*node+1,mid+1,e);
		tree[node].ff = tree[2*node].ff + tree[2*node+1].ff;
		tree[node].ss = tree[2*node].ss + tree[2*node+1].ss;
		lazyx[node]=mp(0LL,0LL);
		lazyy[node]=mp(0LL,mp(0LL,0LL));
	}
}
 
void upd1(ll node,ll s,ll e,ll l,ll r,pll val)
{
	ll mid = (s+e)>>1;
	if((lazyy[node].ff != 0)){
		tree[node].ff = (lazyy[node].ss.ff)*(e-s+1) + pref[lazyy[node].ff + e-s].ff - pref[lazyy[node].ff-1].ff;
		tree[node].ss = (lazyy[node].ss.ss)*(e-s+1) + pref[lazyy[node].ff + e-s].ss - pref[lazyy[node].ff-1].ss;
		if(s!=e){
			lazyx[2*node] = lazyx[2*node+1] = mp(0LL,0LL);
			lazyy[2*node] = mp(lazyy[node].ff,mp(lazyy[node].ss.ff,lazyy[node].ss.ss));
			lazyy[2*node+1] = mp(lazyy[node].ff + mid + 1 - s,mp(lazyy[node].ss.ff,lazyy[node].ss.ss));	
		}
	}
	if((lazyx[node].ff != 0) or (lazyx[node].ss != 0)){
		tree[node].ff += lazyx[node].ff*(e-s+1);
		tree[node].ss += lazyx[node].ss*(e-s+1);
		if(s!=e){
			lazyx[2*node].ff += lazyx[node].ff;
			lazyx[2*node].ss += lazyx[node].ss;
			lazyx[2*node+1].ss += lazyx[node].ss;
			lazyx[2*node+1].ff += lazyx[node].ff; 	
		}
	}
	lazyx[node]=mp(0LL,0LL);
	lazyy[node]=mp(0LL,mp(0LL,0LL));
	if(e<l or s>r)
	return ;
	if(s >= l and e <= r){
        tree[node].ff += (e-s+1)*(val.ff);
        tree[node].ss += (e-s+1)*(val.ss);
        if(s!=e){
        	lazyx[node*2].ff += (val.ff);
        	lazyx[2*node].ss += (val.ss);
        	lazyx[node*2+1].ff += (val.ff);
        	lazyx[2*node+1].ss += (val.ss);	
		}
        return;
    }
    upd1(2*node,s,mid,l,r,val);
    upd1(2*node+1,mid+1,e,l,r,val);
    tree[node].ff = tree[2*node].ff + tree[2*node+1].ff;
	tree[node].ss = tree[2*node].ss + tree[2*node+1].ss;
}
 
void upd2(ll node,ll s,ll e,ll l,ll r,pll val)
{
	ll mid=(s+e)>>1;
	if((lazyy[node].ff != 0)){
		tree[node].ff = (lazyy[node].ss.ff)*(e-s+1) + pref[lazyy[node].ff + e-s].ff - pref[lazyy[node].ff-1].ff;
		tree[node].ss = (lazyy[node].ss.ss)*(e-s+1) + pref[lazyy[node].ff + e-s].ss - pref[lazyy[node].ff-1].ss;
		if(s!=e){
			lazyx[2*node] = lazyx[2*node+1] = mp(0LL,0LL);
			lazyy[2*node] = mp(lazyy[node].ff,mp(lazyy[node].ss.ff,lazyy[node].ss.ss));
			lazyy[2*node+1] = mp(lazyy[node].ff + mid + 1 - s,mp(lazyy[node].ss.ff,lazyy[node].ss.ss));	
		}
	}
	if((lazyx[node].ff != 0) or (lazyx[node].ss != 0)){
		tree[node].ff += lazyx[node].ff*(e-s+1);
		tree[node].ss += lazyx[node].ss*(e-s+1);
		if(s!=e){
			lazyx[2*node].ff += lazyx[node].ff;
			lazyx[2*node].ss += lazyx[node].ss;
			lazyx[2*node+1].ss += lazyx[node].ss;
			lazyx[2*node+1].ff += lazyx[node].ff; 	
		}
	}
	lazyx[node]=mp(0LL,0LL);
	lazyy[node]=mp(0LL,mp(0LL,0LL));
	if(e<l or s>r){								//This is Perfect
		return ;
	}
	if(s>=l and e<=r){				// This is Perfect
		tree[node].ff=(val.ff)*(e-s+1) + pref[e-l+1].ff - pref[s-l].ff;
		tree[node].ss=(val.ss)*(e-s+1) + pref[e-l+1].ss - pref[s-l].ss;
		if(s!=e){
			lazyx[2*node]=lazyx[2*node+1]=mp(0LL,0LL);
			lazyy[2*node] = mp((s-l+1),mp(val.ff,val.ss));		
			lazyy[2*node+1] = mp((mid+1-l+1),mp(val.ff,val.ss));	
		}	
		return ;
	}
	upd2(2*node,s,mid,l,r,val);
	upd2(2*node+1,mid+1,e,l,r,val);
	tree[node].ff = tree[2*node].ff + tree[2*node+1].ff;
	tree[node].ss = tree[2*node].ss + tree[2*node+1].ss;
}
 
pll query(ll node,ll s,ll e,ll l, ll r)
{
	if(s > r or e < l)
	return mp(0LL,0LL);
	ll mid = (s+e)>>1;
	if(lazyy[node].ff != 0){
		tree[node].ff = (lazyy[node].ss.ff)*(e-s+1) + pref[lazyy[node].ff + e-s].ff - pref[lazyy[node].ff-1].ff;
		tree[node].ss = (lazyy[node].ss.ss)*(e-s+1) + pref[lazyy[node].ff + e-s].ss - pref[lazyy[node].ff-1].ss;
		if(s!=e){
			lazyx[2*node] = lazyx[2*node+1] = mp(0LL,0LL);
			lazyy[2*node] = mp(lazyy[node].ff,mp(lazyy[node].ss.ff,lazyy[node].ss.ss));
			lazyy[2*node+1] = mp(lazyy[node].ff + mid + 1 - s,mp(lazyy[node].ss.ff,lazyy[node].ss.ss));	
		}
	}
	if((lazyx[node].ff != 0) or (lazyx[node].ss != 0)){
		tree[node].ff += lazyx[node].ff*(e-s+1);
		tree[node].ss += lazyx[node].ss*(e-s+1);
		if(s!=e){
			lazyx[2*node].ff += lazyx[node].ff;
			lazyx[2*node].ss += lazyx[node].ss;
			lazyx[2*node+1].ss += lazyx[node].ss;
			lazyx[2*node+1].ff += lazyx[node].ff;	
		} 
	}
	lazyx[node]=mp(0LL,0LL);
	lazyy[node]=mp(0LL,mp(0LL,0LL));
    if(s >= l and e <= r)
    return tree[node];
    pll p1 = query(node*2, s, mid, l, r);
    pll p2 = query(node*2 + 1, mid + 1, e, l, r);
    return mp(p1.ff+p2.ff,p1.ss+p2.ss);
}
 
int main()
{
	boost;
	func();
	ll t,n,m,i;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld",&n,&m);
		forp(i,1,n){
			scanf("%lld",&a[i]);
		}
		build(1,1,n);
		ll FANS=0;
		while(m--){
			ll type,l,r,x,y;
			scanf("%lld",&type);
			if(type==1){
				scanf("%lld %lld %lld",&l,&r,&x);
				upd1(1,1,n,l,r,mp(expo2(x),expo5(x)));
			}
			else if(type==2){
				scanf("%lld %lld %lld",&l,&r,&y);
				upd2(1,1,n,l,r,mp(expo2(y),expo5(y)));
			}
			else{
				scanf("%lld %lld",&l,&r);
				pll ans = query(1,1,n,l,r);
				FANS += min(ans.ff,ans.ss);
			}
		}
		printf("%lld\n",FANS);
	}
	return 0;
}  
