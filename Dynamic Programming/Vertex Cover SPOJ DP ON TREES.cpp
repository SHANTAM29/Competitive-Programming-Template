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
int parent[SIZE];
vii v[SIZE];
int dp[SIZE][2];
void dfs(int i)
{
	for(int j=0;j<v[i].size();j++){
		if(v[i][j]!=parent[i]){
			parent[v[i][j]]=i;
			dfs(v[i][j]);
		}
	}
}
int func(int i,int val)
{
	if(i!=1){
		if(v[i].size()==1){
			if(val==0)
			return 1;
			return 0;
		}
	}
	if(dp[i][val]!=-1)
	return dp[i][val];
	int ans=1;
	for(int j=0;j<v[i].size();j++){
		if(v[i][j]!=parent[i]){
			ans+=func(v[i][j],1);
		}
	}
	if(val==1){
		int temp=0;
		for(int j=0;j<v[i].size();j++){
			if(v[i][j]!=parent[i]){
				temp+=func(v[i][j],0);
			}
		}
		ans=min(ans,temp);
	}
	dp[i][val]=ans;
	return ans;
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
	mem(dp,-1);
	int i,n,x,y;
	cin>>n;
	forp(i,1,n-1){
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	if(n<=2){
		cout<<n-1<<endl;
		return 0;
	}
	dfs(1);
	cout<<func(1,1)<<endl;
	return 0;
} 
