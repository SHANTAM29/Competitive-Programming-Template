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
vii v[SIZE];
int ans;
bool visit[SIZE];
int cnt[SIZE];
void dfs(int i,int val)
{
	if(val==2){
		cnt[i]++;
		return ;
	}
	visit[i]=true;
	for(int j=0;j<v[i].size();j++){
		if(!visit[v[i][j]]){
			dfs(v[i][j],val+1);
		}
	}
	visit[i]=false;
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
	int i,n,m,x,y,j;
	cin>>n>>m;
	forp(i,1,m){
		cin>>x>>y;
		v[x].pb(y);
	}
	mem(visit,false);
	forp(i,1,n){
		mem(cnt,0);
		dfs(i,0);
		forp(j,1,n){
			ans+=cnt[j]*(cnt[j]-1)/2;
		}
	}
	cout<<ans<<endl;
	return 0;
}
