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
string s;
int dp[30][300];
int func(int i,int sum)
{
	if(i>len(s)-1)
	return 1;
	if(i==len(s)-1){
		if(s[i]-'0'>=sum)
		return 1;
		return 0;
	}
	if(dp[i][sum]!=-1)
	return dp[i][sum];
	int temp=0;
	int ans=0;
	for(int k=i;k<len(s);k++){
		temp+=s[k]-'0';
		if(temp>=sum)
		ans+=func(k+1,temp);
	}
	dp[i][sum]=ans;
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
	for(int tt=1;;tt++){
		mem(dp,-1);
		cin>>s;
		if(s=="bye")
		break;
		cout<<tt<<". ";
		s="."+s;
		int ans=func(1,0);
		cout<<ans<<endl;
	}
	return 0;
} 
