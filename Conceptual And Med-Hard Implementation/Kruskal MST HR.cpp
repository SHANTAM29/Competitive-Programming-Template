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
#define SIZE 3001

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
int parent[SIZE];
vector< pair<int,pair<int,int> > > v;
int root(int x)
{
	while(x!=parent[x])
	x=parent[x];
	return x;
}
void merge(int x,int y)
{
	int rx=root(x);
	int ry=root(y);
	parent[rx]=ry;
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
	}
	forp(i,1,m){
		cin>>x>>y>>w;
		v.pb(mp(w,mp(x,y)));
	}
	sort(all(v));
	int ans=0;
	for(int j=0;j<v.size();j++){
		//cout<<v[j].ff<<endl;
		int temp1=v[j].ss.ff;
		int temp2=v[j].ss.ss;
		//cout<<temp1<<" "<<temp2<<" "<<v[j].ff<<endl;
		if(root(temp1)!=root(temp2)){
			ans+=v[j].ff;
			merge(temp1,temp2);
		}
	}
	cout<<ans<<endl;
	return 0;
}
