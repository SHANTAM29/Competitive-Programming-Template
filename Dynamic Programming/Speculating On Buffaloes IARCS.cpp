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
#define SIZE 401

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
int n,k;
int a[SIZE];
int dp[SIZE][SIZE][2];
int func(int i,int cnt,int val)
{
	if(i==n){
		if(cnt>=k)
		return 0;
		if(val){
			return a[i];
		}
		return 0;
	}
	if(dp[i][cnt][val]!=-1)
	return dp[i][cnt][val];
	int ans=INT_MIN;
	if(cnt>=k)
	return 0;
	if(val){
		ans=max(ans,a[i]+func(i+1,cnt+1,0));
		ans=max(ans,func(i+1,cnt,1));
	}
	else{
		ans=max(ans,func(i+1,cnt+1,1)-a[i]);
		ans=max(ans,func(i+1,cnt,0));
	}
	dp[i][cnt][val]=ans;
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
	cin>>n>>k;
	mem(dp,-1);
	int i;
	forp(i,1,n){
		cin>>a[i];
	}
	cout<<func(1,0,0)<<endl;
	return 0;
}
