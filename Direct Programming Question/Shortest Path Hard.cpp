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
struct cmp
{
    bool operator()(const pair<int , int> &a , const pair<int , int> &b){
        return a.first > b.first;
    }
};
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
	int n,t,i;
	string str1,str2;
	cin>>t;
	while(t--){
		cin>>n;
		vector< pair<int,int> > v[n+1];
		map<string,int> m;
		forp(i,1,n){
			cin>>str1;
			m[str1]=i;
			int edges,j;
			cin>>edges;
			forp(j,1,edges){
				int y,w;
				cin>>y>>w;
				v[i].pb(mp(y,w));
			}
		}
		int q;
		cin>>q;
		while(q--){
			cin>>str1>>str2;
			priority_queue< pair<int,int> ,vector<pii> ,cmp > s;
			int dist[n+1];
			fill(dist+1,dist+1+n,INT_MAX);
			int src,dest;
			src=m[str1];
			dest=m[str2];
			dist[src]=0;
			s.push(mp(0,src));
			while(!s.empty()){
				int x=s.top().ss;
				s.pop();
				if(x==dest){
					cout<<dist[dest]<<endl;
					break;
				}
				for(int j=0;j<v[x].size();j++){
					int x1=v[x][j].ff;
					int x2=v[x][j].ss;
					if(dist[x1] > dist[x]+x2){
						dist[x1]=dist[x]+x2;
						s.push(mp(dist[x1],x1));
					}
				}
			}
		}
	}
	return 0;
}
