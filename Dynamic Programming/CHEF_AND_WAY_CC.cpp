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
#define SIZE 100001

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
int A[SIZE];
double B[SIZE];
double dp[SIZE];
int N,K;
int from[SIZE];
pair<double,int> tree[4*SIZE];
void build(int node,int s,int e)
{
	if(s==e){
		tree[node] = mp(DBL_MAX,-1);
	}
	else{
		int mid = (s+e)>>1;
		build(2*node,s,mid);
		build(2*node+1,mid+1,e);
		tree[node] = mp(DBL_MAX,-1);
	}
}
void upd(int node,int s,int e,int idx,double val)
{
	if(idx < s or idx > e)
	return ;
	if(s==e){
		tree[node] = mp(val,s);
		return ;
	}
	int mid = (s+e)>>1;
	if(idx <= mid){
		upd(2*node,s,mid,idx,val);
	}
	else{
		upd(2*node+1,mid+1,e,idx,val);
	}
	if(tree[2*node].ff < tree[2*node+1].ff){
		tree[node] = tree[2*node];
	}
	else{
		tree[node] = tree[2*node+1];
	}
}
pair<double,int> query(int node,int s,int e,int l,int r)
{
	if(r < s or l > e)
	return mp(DBL_MAX,-1);
	if(s >= l and e <= r)
	return tree[node];
	int mid = (s+e)>>1;
	pair<double,int> A1 = query(2*node,s,mid,l,r);
	pair<double,int> A2 = query(2*node+1,mid+1,e,l,r);
	if(A1.ff < A2.ff)
	return A1;
	return A2;
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
	//cout<<"Case "<<tt<<": ";
	int i;
	cin>>N>>K;
	forp(i,1,N){
		cin>>A[i];
		B[i] = log2(A[i]);
	}
	build(1,1,N);
	dp[1] = B[1];
	upd(1,1,N,1,dp[1]);
	forp(i,2,N){
		pair<double,int> temp = query(1,1,N,max(1,i-K),i-1);
		dp[i] = temp.ff + B[i];
		from[i] = temp.ss;
		upd(1,1,N,i,dp[i]);
	}
	long long fans = 1;
	int curr = N;
	while(curr != 1){
		fans = (fans*A[curr])%MOD;
		curr = from[curr];
	}
	fans = (fans*A[1])%MOD;
	cout<<fans<<endl;
	return 0;
}
