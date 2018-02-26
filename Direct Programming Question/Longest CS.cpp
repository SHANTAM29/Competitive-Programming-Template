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
#define SIZE 100000

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
int dp[5005][5005];
int main()
{  	
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	boost;
	//cin.tie(0);
	string s1,s2;
	int i,j;
	cin>>s1>>s2;
	s1="."+s1;
	s2="."+s2;
	for(i=1;i<len(s1);i++){
		for(j=1;j<len(s2);j++){
			if(s1[i]!=s2[j])
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			else
			dp[i][j]=1+dp[i-1][j-1];
		}
	}
	cout<<dp[len(s1)-1][len(s2)-1];
	return 0;
}
