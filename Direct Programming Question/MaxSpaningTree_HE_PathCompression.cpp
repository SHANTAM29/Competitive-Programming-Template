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
#define SIZE 5001

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
int parent[SIZE];
set< pair<int,pair<int,int> > > edges;
set< pair<int,pair<int,int> > > :: iterator it;
int root(int i)
{
	while(i!=parent[i])
	{
		parent[i]=parent[parent[i]];
		i=parent[i];
	}
	return i;
}
void merge(int i,int j)
{
	int A=root(i);
	int B=root(j);
	parent[A]=B;
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
	int n,m,t,x,y,w,i;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		edges.clear();
		forp(i,1,n){
			parent[i]=i;
			//sz[i]=1;
		}
		forp(i,1,m){
			scanf("%d %d %d",&x,&y,&w);
			edges.insert(mp(-w,mp(x,y)));
		}
		int ans=0;
		while(edges.size()){
			it=edges.begin();
			pair<int, pair<int,int> > temp=*it;
			edges.erase(it);
			if(root(temp.ss.ff)!=root(temp.ss.ss)){
				merge(temp.ss.ss,temp.ss.ff);
				ans+= -temp.ff;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
