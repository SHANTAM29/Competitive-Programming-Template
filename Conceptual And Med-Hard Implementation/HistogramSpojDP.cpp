#include<bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define len(s) s.length()
#define forp(i,a,b) for( i=a;i<=b;i++)
#define FOR(tt,a,b) for(int tt=a;tt<=b;tt++)
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
#define SIZE 16

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
int a[SIZE],n;
pair<int,ll> dp[SIZE][1<<15];
int FANS1,FANS2;
pair<int,ll> func(int last,int mask)
{
	if(mask==0)
	return mp(a[last],1LL);
	if(dp[last][mask]!=mp(-1,-1LL))
	return dp[last][mask];
	pair<int,ll> ans=mp(0,0LL),val;	
	for(int i=1;i<=n;i++){
		if((mask>>(i-1))&1){
			mask ^= (1<<(i-1));
			val = func(i,mask);
			val.ff += abs(a[i]-a[last]);
			if(val.ff > ans.ff){
				ans = val;
			}
			else if(val.ff == ans.ff){
				ans.ss += val.ss;
			}
			mask ^= (1<<(i-1));
		}
	}
	dp[last][mask]=ans;
	return ans;
}
/*ll func(int per,int mask)
{
	if(mask==0){
		if(per)
	}
}*/
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
	//cout<<"Case #"<<tt<<": ";
	int i;
	while(1){
		cin>>n;
		if(!n)
		break;
		forp(i,1,n){
			cin>>a[i];
		}
		int mask = (1<<n)-1;
		for(i=0;i<16;i++){
			for(int j=0;j<(1<<15);j++){
				dp[i][j]=mp(-1,-1LL);
			}
		}
		pair<int,ll> FANS1=func(0,mask);
		cout<<FANS1.ff+2*n<<" "<<FANS1.ss<<endl;
	}
	return 0;
}
