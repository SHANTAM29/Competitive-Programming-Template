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
ll a[15001];
ll dp[15001];
ll func(ll x)
{
	//cout<<x<<endl;
	ll ans=0;
	ll val=521000371;
	//cout<<val<<endl;
	for(ll i=1;i<=(x/100000000000);i++){
		ans+=val;
		ans%=MOD;
	}
	x=x%100000000000;
	//cout<<x<<endl;
	ans=(ans+dp[15000]*x)%MOD;
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
	a[2]=1;
	for(int i=3;i<=15000;i++){
		a[i]=(a[i-1]+a[i-2])%10000;
	}
	/*for(int i=0;i<10;i++){
		cout<<a[i]<<" ";
	}*/
	for(int i=1;i<=15000;i++){
		dp[i]=dp[i-1]+a[i];
		dp[i]%=MOD;
	}
	//cout<<dp[15000]<<endl;
	/*for(int i=0;i<10;i++){
		cout<<dp[i]<<" ";
	}*/
	ll t;
	ll l,r;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld",&l,&r);
		l--;
		ll ans=func(r/15000);
		//cout<<ans<<endl;
		ans=(ans+dp[r%15000])%MOD;
		ll temp=func(l/15000);
		//cout<<temp<<endl;
		temp=(temp+dp[l%15000])%MOD;
		ans-=temp;
		if(ans<0)
		ans+=MOD;
		printf("%lld\n",ans);
	}
	return 0;
}
