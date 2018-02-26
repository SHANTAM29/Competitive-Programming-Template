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
#define SIZE 2001

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
bool visit[SIZE];
bool is;
vector<int> v[SIZE];
int grp[SIZE];
void dfs(int i,int temp)
{
	visit[i]=true;
	grp[i]=temp;
	for(int j=0;j<v[i].size();j++){
		if(!visit[v[i][j]])
		{
			if(temp==1)
			dfs(v[i][j],2);
			else
			dfs(v[i][j],1);
		}
		else
		{
			if(temp==grp[v[i][j]])
			is=false;
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
	int i,t,x,y,n,m;
	cin>>t;
	for(int tc=1;tc<=t;tc++){
		is=true;
		mem(visit,false);
		mem(grp,0);
		for(i=0;i<SIZE;i++)
		v[i].clear();
		cin>>n>>m;
		forp(i,1,m){
			cin>>x>>y;
			v[x].pb(y);
			v[y].pb(x);
		}
		forp(i,1,n){
			if(!visit[i])
			{
				dfs(i,1);
			}
		}
		cout<<"Scenario #"<<tc<<":\n";
		is ? cout<<"No suspicious bugs found!\n" : cout<<"Suspicious bugs found!\n";
	}
	return 0;
}
