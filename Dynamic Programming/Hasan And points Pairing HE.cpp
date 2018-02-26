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
double x[17],y[17];
double dp[1<<16];
bool is[1<<16];
int n;
double dist(int i,int j)
{
	return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
double func(int mask)
{
	if(bitc(mask)==2){
		int temp[2],k=0;
		for(int i=1;i<=2*n;i++){
			if((mask>>(i-1))&1){
				temp[k]=i;
				k++;
			}
		}
		return dist(temp[0],temp[1]);
	}
	if(is[mask])
	return dp[mask];
	double ans=1e7;
	for(int i=1;i<=2*n;i++){
		for(int j=i+1;j<=2*n;j++){
			if((mask>>(i-1))&1){
				if((mask>>(j-1))&1){
					mask=mask^(1<<(i-1));
					mask=mask^(1<<(j-1));
					ans=min(ans,dist(i,j)+func(mask));
					mask=mask^(1<<(i-1));
					mask=mask^(1<<(j-1));
				}
			}
		}
	}
	is[mask]=true;
	dp[mask]=ans;
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
	cin>>n;
	forp(i,1,2*n){
		cin>>x[i]>>y[i];
	}
	int mask=(1<<(2*n))-1;
	cout<<fixed<<setprecision(6)<<func(mask)<<endl;
	return 0;
}
