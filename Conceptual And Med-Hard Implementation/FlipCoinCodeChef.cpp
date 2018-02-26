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
int tree[4*SIZE];
int lazy[4*SIZE];
void update(int node,int s,int e,int l,int r)
{
	int mid = (s+e)>>1;
	if(lazy[node]!=0){
		tree[node] = e-s+1-tree[node];
		if(s!=e){
			lazy[2*node]=(lazy[2*node]+1)%2;
			lazy[2*node+1]=(lazy[2*node+1]+1)%2;	
		}
	}
	lazy[node]=0;
	if(e<l or s>r)
	return ;
	if(s>=l and e<=r){
		tree[node] = e-s+1-tree[node];
		if(s!=e){
			lazy[2*node]=(lazy[2*node]+1)%2;
			lazy[2*node+1]=(lazy[2*node+1]+1)%2;	
		}
		return ;
	}
	update(2*node,s,mid,l,r);
	update(2*node+1,mid+1,e,l,r);
	tree[node]=tree[2*node]+tree[2*node+1];
}
int query(int node,int s,int e,int l,int r)
{
	int mid = (s+e)>>1;
	if(lazy[node]!=0){
		tree[node] = e-s+1-tree[node];
		if(s!=e){
			lazy[2*node]=(lazy[2*node]+1)%2;
			lazy[2*node+1]=(lazy[2*node+1]+1)%2;	
		}
	}
	lazy[node]=0;
	if(e<l or s>r)
	return 0;
	if(s>=l and e<=r){
		return tree[node];
	}
	int V1=query(2*node,s,mid,l,r);
	int V2=query(2*node+1,mid+1,e,l,r);
	return V1+V2;
}
int main()
{  	
	/* #ifndef ONLINE_JUDGE
	freopen(fi, "r", stdin);
	#endif */
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//cin.ignore();
	//cin.clear();
	boost;
	//cin.tie(0);
	//cout<<"Case #"<<tt<<": ";
	int n,q,type,x,y;
	cin>>n>>q;
	while(q--){
		cin>>type>>x>>y;
		x++;
		y++;
		if(type==0){
			update(1,1,n,x,y);
		}
		else{
			int fans = query(1,1,n,x,y);
			cout<<fans<<endl;
		}
	}
	return 0;
}   
