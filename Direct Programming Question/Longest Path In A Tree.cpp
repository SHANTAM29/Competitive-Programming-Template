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
#define pll pair<long,long>
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

bool visit[SIZE]={false};
int dist[SIZE];
vector<int> v[SIZE];

void dfs(int i,int cnt)
{
	visit[i]=true;
	dist[i]=cnt;
	for(int j=0;j<v[i].size();j++){
		if(!visit[v[i][j]])
		{
			dfs(v[i][j],cnt+1);
		}
	}
	return ;
}
int main()
{  	
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	boost;
	//cin.tie(0);
	int n,i,j,ans,a,b;
	cin>>n;
	forp(i,1,n-1){
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1,0);
	ans=0;
	j=1;
	forp(i,1,n){
		if(dist[i]>ans)
		{
			ans=dist[i];
			j=i;
		}
	}
//	cout<<ans<<" "<<j<<endl;
	mem(visit,false);
	mem(dist,0);
	dfs(j,0);
	ans=0;
	forp(i,1,n)
	ans=max(ans,dist[i]);
	cout<<ans<<endl;
	return 0;
}
