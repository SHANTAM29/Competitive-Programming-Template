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
#define MOD 100000000
#define EPSILON 1e-9
#define PI 3.14159265358979323846
#define SIZE 100001

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
ll dp[201][201][11][11];
int n1,n2,k1,k2;
ll func(int i,int cnt1,int cnt2,int temp1,int temp2)
{
	//cout<<i<<" "<<cnt1<<" "<<cnt2<<" "<<temp1<<" "<<temp2<<endl;
	if(i==n1+n2)
	{
		if(cnt1==k1){
			if(temp1==n1 and temp2+1==n2)
			return 1;
			return 0;
		}
		else if(cnt2==k2){
			if(temp1+1==n1 and temp2==n2)
			return 1;
			return 0;
		}
		else{
			int ans=0;
			if(temp1+1==n1 and temp2==n2)
			ans++;
			if(temp1==n1 and temp2+1==n2)
			ans++;
			//cout<<ans<<endl;
			return ans;
		}
	}
	if(dp[temp1][temp2][cnt1][cnt2]!=-1)
	return dp[temp1][temp2][cnt1][cnt2];
	if(cnt1==k1){
		ll ans=func(i+1,0,1,temp1,temp2+1);
		dp[temp1][temp2][cnt1][cnt2]=ans;
		return ans;
	}
	else if(cnt2==k2){
		ll ans=func(i+1,1,0,temp1+1,temp2);
		dp[temp1][temp2][cnt1][cnt2]=ans;
		return ans;
	}
	else{
		ll ans1=func(i+1,cnt1+1,0,temp1+1,temp2);
		ll ans2=func(i+1,0,cnt2+1,temp1,temp2+1);
		dp[temp1][temp2][cnt1][cnt2]=(ans1+ans2)%MOD;
		return dp[temp1][temp2][cnt1][cnt2];
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
	cin>>n1>>n2>>k1>>k2;
	mem(dp,-1);
	ll ans=func(1,0,0,0,0);
	cout<<ans<<endl;
	return 0;
}
