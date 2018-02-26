#include<bits/stdc++.h>
 
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define len(s) s.length()
#define forp(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,n)    for(ll i=0;i<n;i++)
#define ren(i,n)    for(ll i=n-1;i>=0;i--)
#define forn(i,a,b) for(int i=a;i>=b;i--)
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
string rev(string s)
{
	char a[len(s)+1];
	int i;
	for( i=0;i<len(s);i++){
		a[i]=s[len(s)-1-i];
	}
	a[i]='\0';
	s=a;
	return s;
}
int dp[6101][6101];
int main()
{  	
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	boost;
	int t,i,j;
	string s,x;
	cin>>t;
	while(t--){
		mem(dp,0);
		cin>>s;
		x=rev(s);
		for(i=0;i<len(s);i++){
			for(j=0;j<len(s);j++){
					if(x[i]!=s[j])
				{
					dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
				}
				else
				{
					dp[i+1][j+1]=dp[i][j]+1;
				}
			}
		}
		cout<<len(s)-dp[len(s)][len(s)]<<endl;
	}
	return 0;
} 
