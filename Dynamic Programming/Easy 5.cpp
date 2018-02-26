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
int a[SIZE][4],n;
int dp[SIZE][4];
int func(int i,int arr[])
{
	int k=0;
	for(int j=1;j<=3;j++)
	if(arr[j]==1)
	k=j;
	//cout<<i<<" "<<k<<endl;
	if(i==n)
	{
		int val=INT_MAX;
		for(int j=1;j<=3;j++){
			if(j!=k)
			val=min(val,a[i][j]);
		}
		return val;
	}
	if(dp[i][k]!=-1)
	return dp[i][k];
	int ans=INT_MAX;
	int val;
	for(int j=1;j<=3;j++){
		if(j!=k)
		{
			for(int idx=1;idx<=3;idx++)
			{
				if(idx!=j)
				arr[idx]=0;
				else
				arr[idx]=1;
			}
			val=a[i][j]+func(i+1,arr);
			for(int idx=1;idx<=3;idx++)
			{
				if(idx!=k)
				arr[idx]=0;
				else
				arr[idx]=1;
			}
			ans=min(ans,val);
		}
	}
	dp[i][k]=ans;
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
	int t,i,j,b[4];
	cin>>t;
	while(t--){
		cin>>n;
	//	mem(b,0);
	//	forp(i,0,3)
	//	cout<<b[i]<<" ";
		forp(i,0,3)
		b[i]=0;
		forp(i,0,SIZE-1){
			forp(j,0,3)
			dp[i][j]=-1;
		}
		forp(i,1,n){
			forp(j,1,3){
				cin>>a[i][j];
			}
		}
		int ans=func(1,b);
		cout<<ans<<endl;
	}
	return 0;
}
