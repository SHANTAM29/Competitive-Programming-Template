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
ll dp[21][1<<20];
int n;
int A[21][21];
int expo[21];
bool arr[21];
void f2()
{
	expo[0]=1;
	for(int i=1;i<=20;i++)
	expo[i]=expo[i-1]<<1;
	return;
}
int f()
{
	int ans=0;
	for(int i=n;i>=1;i--){
		ans+=arr[i]*expo[n-i];
	}
	return ans;
}
ll func(int i)
{
	int temp=f();
	if(dp[i][temp]!=-1)
	return dp[i][temp];
	if(i==n)
	{
		ll ans=0;
		for(int j=1;j<=n;j++){
			if(A[i][j]==1 and arr[j]==false)
			ans++;
		}
		dp[i][temp]=ans;
		return ans;
	}
	ll ans=0;
	for(int j=1;j<=n;j++){
		if(A[i][j]==1 and arr[j]==false)
		{
			arr[j]=true;
			ans+=func(i+1);
			arr[j]=false;
		}
	}
	dp[i][temp]=ans;
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
	f2();
	int T,i,j;
	cin>>T;
	while(T--){
		mem(dp,-1);
		cin>>n;
		forp(i,1,n){
			forp(j,1,n){
				cin>>A[i][j];
			}
		}
		ll ans=func(1);
		cout<<ans<<endl;
	}
	return 0;
}
Language: C++
