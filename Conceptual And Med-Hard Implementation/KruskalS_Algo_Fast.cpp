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
int parent[SIZE];
int sz[SIZE];
set< pair<int,pair<int,int> > > edges;
int root(int i)
{
	while(i!=parent[i])
	i=parent[i];
	return i;
}
void merge(int i,int j)
{
	int A=root(i);
	int B=root(j);
	if(sz[A]<sz[B]){
		parent[A]=B;
		sz[B]+=sz[A];
	}
	else{
		parent[B]=A;
		sz[A]+=sz[B];
	}
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
	int i,n,m,x,y,w;
	cin>>n>>m;
	forp(i,1,n){
		parent[i]=i;
		sz[i]=1;
	}
	forp(i,1,m){
		cin>>x>>y>>w;
		edges.insert(mp(w,mp(x,y)));
	}
	int ans=0;
	tr(edges,it){
		pair<int ,pii > temp;
		temp=*it; 
		x=temp.ss.ff;
		y=temp.ss.ss;
		if(root(x)!=root(y)){
			merge(x,y);
			ans+=temp.ff;
		}
	}
	cout<<ans<<endl;
	return 0;
}
