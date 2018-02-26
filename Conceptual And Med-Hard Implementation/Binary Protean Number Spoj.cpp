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
ll f[91];
ll sum[91];
ll g[91];
void f2()
{
	for(int i=1;i<=90;i++)
	sum[i]=sum[i-1]+f[i];
}
void func()
{
	f[1]=1;
	f[2]=1;
	f[3]=2;
	g[0]=1;
	g[1]=2;
	for(int i=4;i<=90;i++){
		f[i]=f[i-1]+f[i-2];
		g[i-2]=f[i];
	}
	f2();
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
	func();
	//cout<<f[90]<<endl;
	int t;
	string s;
	cin>>t;
	for(int tt=1;tt<=t;tt++){
		cin>>s;
		cout<<"Case "<<tt<<": ";
		if(len(s)==1){
			cout<<"1\n";
		}
		else if(len(s)==2){
			cout<<"2\n";
		}
		else{
			int temp=len(s);
			ll ans=sum[temp-1];
			ll val=0;
			for(int i=2;i<len(s);i++){
				if(s[i]=='1'){
					val+=g[len(s)-1-i];
				}
			}
			cout<<ans+val+1<<endl;
		}
	}
	return 0;
} 
