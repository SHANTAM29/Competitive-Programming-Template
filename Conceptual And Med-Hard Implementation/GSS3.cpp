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
#define SIZE 50001

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
struct Node{
	int pref;
	int suff;
	int ans;
	int sum;
};
Node tree[4*SIZE];
int a[SIZE];
Node merge(Node A, Node B)
{
	Node C;
	C.sum=A.sum+B.sum;
	C.pref=max(A.pref,A.sum+B.pref);
	C.suff=max(B.suff,A.suff+B.sum);
	C.ans=max(max(C.sum,A.suff+B.pref),max(B.ans,A.ans));
	return C;
}
void build(int node,int s,int e)
{
	if(s==e){
		tree[node].ans=tree[node].sum=tree[node].pref=tree[node].suff=a[s];
		//cout<<node<<"->"<<tree[node].ans<<" "<<tree[node].pref<<" "<<tree[node].suff<<" "<<tree[node].sum<<endl;
	}
	else{
		int mid=(s+e)>>1;
		build(2*node,s,mid);
		build(2*node+1,mid+1,e);
		tree[node]=merge(tree[2*node],tree[2*node+1]);
		//cout<<node<<"->"<<tree[node].ans<<" "<<tree[node].pref<<" "<<tree[node].suff<<" "<<tree[node].sum<<endl;
	}
}
void update(int node,int s,int e,int idx,int val)
{
	if(s==e){
		a[s]=val;
		tree[node].ans=tree[node].sum=tree[node].pref=tree[node].suff=a[s];
		return ;
	}
	int mid=(s+e)/2;
	if(idx<=mid){
		update(2*node,s,mid,idx,val);
	}
	else{
		update(2*node+1,mid+1,e,idx,val);
	}
	tree[node]=merge(tree[2*node],tree[2*node+1]);
}
Node query(int node,int s,int e,int l,int r)
{
	if(s>=l and e<=r)
	return tree[node];
	int mid=(s+e)>>1;
	if(r<=mid){
		return query(2*node,s,mid,l,r);
	}
	if(l>mid){
		return query(2*node+1,mid+1,e,l,r);
	}
	Node val1=query(2*node,s,mid,l,mid);
	Node val2=query(2*node+1,mid+1,e,mid+1,r);
	Node C=merge(val1,val2);
	return C;
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
	int i,n,q,l,r;
	scanf("%d",&n);
	forp(i,1,n){
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	scanf("%d",&q);
	while(q--){
		int type;
		scanf("%d",&type);
		if(type==0){
			scanf("%d %d",&l,&r);
			update(1,1,n,l,r);
		}
		else{
			scanf("%d %d",&l,&r);
			Node C = query(1,1,n,l,r);
			printf("%d\n",C.ans);	
		}
	}
	return 0;
}
