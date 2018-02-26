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
vector<int> v[SIZE];
bool visit[SIZE]={false};
bool vis[SIZE]={false};
bool iscycle=false;
int parent[SIZE];
int cnt;
void dfs(int i)
{
	visit[i]=true;
	for(int j=0;j<v[i].size();j++)
	{
		if(!visit[v[i][j]])
		{
			dfs(v[i][j]);
		}
	}
	return ;
}
void cycle(int i)
{
	vis[i]=true;
	for(int j=0;j<v[i].size();j++){
		if(vis[v[i][j]])
		{
			if(parent[i]!=v[i][j])
			iscycle=true;
		}
		else
		{
			parent[v[i][j]]=i;
			cycle(v[i][j]);
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
	int i,j,n,m,x,y,ans=0;
	cin>>n>>m;
	forp(i,1,m){
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	forp(i,1,n){
		if(!visit[i])
		{
			iscycle=false;
			cycle(i);
			if(!iscycle)
			ans++;
			dfs(i);
		}
	}
	cout<<ans<<endl;
	return 0;
}
