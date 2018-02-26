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
#define SIZE 501

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
int cost[SIZE];
int weight[SIZE],n;
int dp[SIZE][10000];
int func(int i,int f)
{
	if(f<0)
	return 9999999;
	if(i==n){
		if(f%weight[i]==0){
			int temp=f/weight[i];
			return temp*cost[i];
		}
		else{
			return 9999999;
		}
	}
	if(dp[i][f]!=-1)
	return dp[i][f];
	int ans=9999999;
	for(int j=0;j<=f/weight[i];j++){
		int temp=j*cost[i]+func(i+1,f-weight[i]*j);
		ans=min(ans,temp);
	}
	dp[i][f]=ans;
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
	int t,e,f,i;
	cin>>t;
	while(t--){
		cin>>e>>f;
		cin>>n;
		forp(i,1,n){
			cin>>cost[i]>>weight[i];
		}
		if(e>f){
			cout<<"This is impossible.\n";
		}
		else if(e==f){
			cout<<"The minimum amount of money in the piggy-bank is 0.\n";
		}
		else{
			f-=e;
			mem(dp,-1);
			int ans=func(1,f);
			if(ans>=9999999){
				cout<<"This is impossible.\n";
			}
			else{
				cout<<"The minimum amount of money in the piggy-bank is "<<ans<<".\n";
			}
		}
	}
	return 0;
}
