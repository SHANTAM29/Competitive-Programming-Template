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
ll dp[SIZE][2];
ll pref[SIZE];
ll n,a[SIZE];
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
	ll t,i,j;
	cin>>t;
	while(t--){
		cin>>n;
		mem(dp,-1);
		forp(i,1,n){
			cin>>a[i];
		}
		forp(i,1,n){
			pref[i]=pref[i-1]+a[i];
			//cout<<pref[i]<<endl;
		}
		if(n<=3)
		{
			ll ans=0;
			forp(i,1,n)
			ans+=a[i];
			cout<<ans<<endl;
			continue;
		}
		dp[n][0]=a[n];
		dp[n-1][0]=a[n]+a[n-1];
		dp[n-2][0]=a[n]+a[n-1]+a[n-2];
		dp[n][1]=dp[n-1][1]=dp[n-2][1]=0;
		forn(i,n-3,1){
			forp(j,0,1){
				if(j)
				{
					ll temp;
					temp=a[i]+(pref[n]-pref[i])-dp[i+1][0];
					temp=max(temp,a[i]+a[i+1]+(pref[n]-pref[i+1])-dp[i+2][0]);
					temp=max(temp,a[i]+a[i+1]+a[i+2]+(pref[n]-pref[i+2])-dp[i+3][0]);
					dp[i][j]=pref[n]-pref[i-1]-temp;
				}
				else
				{
					ll temp;
					temp=a[i]+dp[i+1][1];
					temp=max(temp,a[i]+a[i+1]+dp[i+2][1]);
					temp=max(temp,a[i]+a[i+1]+a[i+2]+dp[i+3][1]);
					dp[i][j]=temp;
				}
			}
		}
		//forp(i,1,n)
		//cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
		cout<<dp[1][0]<<endl;
	}
	return 0;
}
