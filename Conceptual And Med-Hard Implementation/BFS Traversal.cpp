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
#define SIZE 10001

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
vector<int> v[SIZE];
int dist[SIZE];
bool visit[SIZE];
queue<int> q;
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
	int t,n,m,x,y,i;
	cin>>t;
	while(t--){
		cin>>n>>m;
		mem(visit,false);
		forp(i,1,n)
		v[i].clear();
		forp(i,1,m){
			cin>>x>>y;
			v[x].pb(y);
			v[y].pb(x);
		}
		dist[1]=0;
		q.push(1);
		visit[1]=true;
		while(!q.empty()){
			i=q.front();
			q.pop();
			for(int j=0;j<v[i].size();j++){
				if(!visit[v[i][j]]){
					dist[v[i][j]]=dist[i]+1;
					q.push(v[i][j]);
					visit[v[i][j]]=true;
				}
			}
		}
		cout<<dist[n]<<endl;
	}
	return 0;
}
