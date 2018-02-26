#include<bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define len(s) s.length()
#define forp(i,a,b) for( i=a;i<=b;i++)
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
#define SIZE 200001

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;

int a[SIZE],segtree[SIZE];

void build(int node,int start,int end)
{
	if(start==end)
	{
		segtree[node]=a[start];
	}
	else
	{
		int mid=(start+end)/2;
		build(node*2,start,mid);
		build(node*2+1,mid+1,end);
		segtree[node]=min(segtree[node*2],segtree[node*2+1]);
	}
	return ;
}

void update(int node,int start,int end,int idx,int val)
{
	if(start==end)
	{
		segtree[node]=val;
		a[idx]=val;
	}
	else
	{
		int mid=(start+end)/2;
		if(start<=mid and idx<=mid)
		{
			update(2*node,start,mid,idx,val);
		}
		else
		{
			update(2*node+1,mid+1,end,idx,val);
		}
		segtree[node]=min(segtree[2*node],segtree[2*node+1]);
	}
	return ;
}
int query(int node,int start,int end,int l,int r)
{
	if(r<start or l>end)
	{
		return INT_MAX;
	}
	if(l<=start and r>=end)
	{
		return segtree[node];
	}
	int mid=(start+end)/2;
	int p1=query(node*2,start,mid,l,r);
	int p2=query(node*2+1,mid+1,end,l,r);
	return min(p1,p2);
}
int main()
{  	
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	boost;
	//cin.tie(0);
	int i,n,q,x,y;
	char ch;
	cin>>n;
	forp(i,1,n){
		cin>>a[i];
	}
	build(1,1,n);
	cin>>q;
	while(q--){
		cin>>ch;
		if(ch=='u')
		{
			cin>>x>>y;
			update(1,1,n,x,y);
		}
		else
		{
			cin>>x>>y;
			cout<<query(1,1,n,x,y)<<endl;
		}
	}
	return 0;
}
