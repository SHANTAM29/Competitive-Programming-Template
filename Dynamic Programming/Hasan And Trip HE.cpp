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
#define SIZE 3001
 
typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
ldo dp[SIZE][SIZE];
bool is[SIZE][SIZE];
int n;
ldo x[SIZE];
ldo y[SIZE];
ldo f[SIZE];
ldo dist(int i,int j)
{
	return sqrt((x[i]-x[j])*(x[i]-x[j])*1.0000 + 1.0000*(y[i]-y[j])*(y[i]-y[j]));
}
ldo func(int i,int j)
{
	if(i==n){
		return f[i]-dist(i,j);
	}
	if(is[i][j])
	return dp[i][j];
	ldo ans;
	ans=f[i]+func(i+1,i)-dist(i,j);
	ans=max(ans,func(i+1,j));
	is[i][j]=true;
	dp[i][j]=ans;
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
	int i;
	cin>>n;
	forp(i,1,n){
		cin>>x[i]>>y[i]>>f[i];
	}
	ldo ans=f[1];
	if(n==1){
		cout<<fixed<<setprecision(6)<<ans<<endl;
	}
	else{
		cout<<fixed<<setprecision(6)<<ans+func(2,1)<<endl;
	}
	return 0;
}
