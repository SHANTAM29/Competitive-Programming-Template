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
ll tree[4*SIZE];
void build(ll node,ll s,ll e)
{
	if(s==e){
		tree[node]=a[s];
	}
	else{
		ll mid=(s+e)/2;
		build(2*node,s,mid);
		build(2*node+1,mid+1,e);
		tree[node]=tree[2*node]+tree[2*node+1];
	}
}
void update(ll node,ll s,ll e,ll l,ll r)
{
	if(s>=l and e<=r){
		if(tree[node]==e-s+1)
		return ;
	}
	if(s==e){
		a[s]=sqrt(a[s]);
		tree[node]=a[s];
		return ;
	}
	ll mid=(s+e)/2;
	if(r<=mid){
		update(2*node,s,mid,l,r);
	}
	else if(l>mid){
		update(2*node+1,mid+1,e,l,r);
	}
	else{
		update(2*node,s,mid,l,mid);
		update(2*node+1,mid+1,e,mid+1,r);
	}
	tree[node]=tree[2*node]+tree[2*node+1];
}
ll query(ll node,ll s,ll e,ll l,ll r)
{
	if(s>=l and e<=r)
	return tree[node];
	ll mid=(s+e)/2;
	if(r<=mid){
		return query(2*node,s,mid,l,r);
	}
	if(l>mid){
		return query(2*node+1,mid+1,e,l,r);
	}
	ll val1=query(2*node,s,mid,l,mid);
	ll val2=query(2*node+1,mid+1,e,mid+1,r);
	return val1+val2;
}
int main()
{
	ll i,n,m;
	ll tt=0;
	while(scanf("%lld",&n) != EOF){
		tt++;
		forp(i,1,n){
			scanf("%lld",&a[i]);
		}
		build(1,1,n);
		scanf("%lld",&m);
		ll type,l,r;
		printf("Case #%lld:\n",tt);
		while(m--){
			scanf("%lld %lld %lld",&type,&l,&r);
			if(l > r)
			swap(l,r);
			if(type==0){
				update(1,1,n,l,r);
			}
			else{
				ll ans=query(1,1,n,l,r);
				printf("%lld\n",ans);
			}
		}
		printf("\n");
	}
	return 0;
}
