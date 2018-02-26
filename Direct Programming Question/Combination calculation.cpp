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
ll fact[1001];
void fac()
{
	int i;
	fact[0]=fact[1]=1;
	forp(i,2,1000){
		fact[i]=(fact[i-1]*i)%MOD;
	}
	return ;
}
inline long long mod_pow(long long x,long long y)
{
	long long res = 1;
	while(y)
	{
		if(y&1) 
		{
			res = (res*x)%MOD;
		}
		x = (x*x)%MOD;
		y >>= 1;
	}
	return res%MOD;
}

inline long long mod_div(long long a,long long b)
{
	ll ans = (a*mod_pow(b,MOD-2))%MOD; 
	return ans;
}
inline long long mul(long long a,long long b)
{
	return (a*b)%MOD;
}
int main()
{  	
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	boost;
	//cin.tie(0);
	fac();
	ll i,t,n;
	cin>>t;
	while(t--){
		cin>>n;
		forp(i,0,n){
			ll temp;
			temp=mod_div(fact[n],(fact[n-i]*fact[i])%MOD);
			cout<<temp<<" ";
		}
		cout<<endl;
	}
	return 0;
}
