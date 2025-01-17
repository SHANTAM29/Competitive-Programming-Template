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
vector< pair<int,int> > v[SIZE];
int dp[SIZE][SIZE];
int parent[SIZE][SIZE];
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
	int i,j,n,m,k,x,y,w;
	cin>>n>>m>>k;
	forp(i,1,m){
		cin>>x>>y>>w;
		v[x].pb(mp(y,w));
	}
	forp(i,0,SIZE-1)forp(j,0,SIZE-1)dp[i][j]=MOD;
	dp[1][0]=0;
	priority_queue< pair <int, pair<int,int> > > q;
	q.push(mp(0,mp(1,0)));
	while(!q.empty()){
		int len=-(q.top().ff);
		int depth=q.top().ss.ss;
		int curr=q.top().ss.ff;
		q.pop();
		if(len>k)
		continue;
		/*if(len>dp[curr][depth])
		continue;*/
		for(j=0;j<v[curr].size();j++){
			int dest = v[curr][j].ff;
			int val = v[curr][j].ss;
			val += dp[curr][depth];
			if(val > k)continue;
			if(val < dp[dest][depth+1]){
				dp[dest][depth+1]=val;
				parent[dest][depth+1]=curr;
				q.push(mp(-dp[dest][depth+1],mp(dest,depth+1)));
			}
		}
	}
	int ans;
	forn(i,n,1)
	if(dp[n][i]<=k){
		ans=i;
		break;
	}
	cout<<ans+1<<endl;
	vii v;
	v.pb(n);
	i=n;
	while(1){
		if(i==1)
		break;
		i=parent[i][ans];
		v.pb(i);
		ans--;
	}
	reverse(all(v));
	for(i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}
