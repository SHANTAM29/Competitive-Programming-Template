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
#define SIZE 4001

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
int a[3];
int dp[SIZE];
int func(int n)
{
	if(n==0)
	return 1;
	if(n<a[0])
	return 0;
	if(dp[n]!=-1)
	return dp[n];
	if(n>=a[0] and n<a[1]){
		int x=func(n-a[0]);
		if(x==0)
		{
		    dp[n]=0;
		    return 0;
		}
		dp[n]=1+x;
		return 1+x;
	}
	else if(n>=a[1] and n<a[2]){
		int x=func(n-a[0]);
		int y=func(n-a[1]);
		if(x==0 and y==0)
		{
		    dp[n]=0;
		    return 0;
		}
		dp[n]=1+max(x,y);
		return 1+max(x,y);
	}
	else{
		int x=func(n-a[0]);
		int y=func(n-a[1]);
		int z=func(n-a[2]);
		if(x==0 and y==0 and z==0)
		{
		    dp[n]=0;
		    return 0;
		}
		dp[n]=1+max(x,max(y,z));
		return 1+max(x,max(y,z));
	}
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
	int i,n,t;
	cin>>t;
	while(t--){
	    mem(dp,-1);
		cin>>n;
		cin>>a[0]>>a[1]>>a[2];
		sort(a,a+3);
		cout<<func(n)-1<<endl;
	}
	return 0;
}