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
int n;
int dp[1<<12][99];
int func(int mask,int k)
{
	if(k<0)
	return 0;
	if(bitc(mask)==1){
		int temp;
		for(int i=0;i<n;i++){
			if((mask>>i)&1){
				temp=n-1-i;
				break;
			}
		}
		if(temp==k)
		return 1;
		return 0;
	}
	if(dp[mask][k]!=-1)
	return dp[mask][k];
	int ans=0;
	int cnt=bitc(mask);
	int x=0;
	for(int i=0;i<n;i++){
		if((mask>>i)&1){
			x++;
			int temp=cnt-x;
			temp=n-1-i-temp;
			mask^=1<<i;
			ans+=func(mask,k-temp);
			mask^=1<<i;
		}
	}
	dp[mask][k]=ans;
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
	int t,k;
	cin>>t;
	while(t--){
		mem(dp,-1);
		cin>>n>>k;
		int mask=(1<<n)-1;
		cout<<func(mask,k)<<endl;
	}
	return 0;
}
