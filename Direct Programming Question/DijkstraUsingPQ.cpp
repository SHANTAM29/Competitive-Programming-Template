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

priority_queue< pii,vector<pii>,cmp > pq;
ll dist[SIZE];
int parent[SIZE];
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
	int i,n,m,s,e,w;
	cin>>n>>m;
	vector< pii > v[n+1];
	forp(i,1,m){
		cin>>s>>e>>w;
		v[s].pb(mp(e,w));
		v[e].pb(mp(s,w));
	}
	forp(i,1,n){
		dist[i]=1e17;
	}
	dist[1]=0;
	pq.push(mp(0,1));
	while(!pq.empty()){
		int x=pq.top().ss;
		pq.pop();
		for(int j=0;j<v[x].size();j++){
			int x1=v[x][j].ff;
			ll x2=v[x][j].ss;
			if(dist[x1]>dist[x]+x2){
				dist[x1]=dist[x]+x2;
				parent[x1]=x;
				pq.push(mp(dist[x1],x1));
			}
		}
	}
	if(dist[n]==1e17){
		cout<<"-1\n";
	}
	else{
		vector<int> ans;
		int temp=n;
		while(temp!=1){
			ans.pb(temp);
			temp=parent[temp];
		}
		ans.pb(1);
		for(int idx=ans.size()-1;idx>=0;idx--){
			cout<<ans[idx]<<" ";
		}
	}
	return 0;
}
