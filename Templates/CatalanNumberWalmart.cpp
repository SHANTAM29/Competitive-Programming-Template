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
#define SIZE 2001

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
ll catalan[SIZE];
ll pref[SIZE];
ll C[4001][4001];
/*Function For Calculating Exponent*/
inline long long expo(long long a,long long b,long long mod){
    long long res=1LL;
    while (b)
	{
    	if (b % 2){ 	
			res = (res * a) % mod; 
		}
		a = (a * a) % mod;
    	b =b>>1;
	}
	return res;
}
/*Division */
inline long long mod_div(long long a,long long b,long long mod)
{
	return (a*expo(b,mod-2,mod))%mod;
}
void f1()
{
	C[0][0]=1;
	C[1][0]=C[1][1]=1;
	int i,j;
	forp(i,2,4000){
		forp(j,0,i){
			if(j==0){
				C[i][j]=1;
			}
			else{
				C[i][j]=C[i-1][j] + C[i-1][j-1];
				C[i][j] %= MOD;
			}
		}
	}
}
void f2()
{
	pref[0]=0;
	pref[1]=1;
	int i;
	forp(i,2,SIZE-1){
		pref[i]=pref[i-1]+catalan[i];
        pref[i]%=MOD;
	}
}
void func()
{
	f1();
	catalan[1]=1;
	int i;
	forp(i,2,SIZE-1){
		catalan[i] = mod_div(C[2*i][i],i+1,MOD);
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
	//cout<<"Case #"<<tt<<": ";
	func();
	int n,t;
	cin>>t;
	while(t--){
		cin>>n;
        if(n==0){
            cout<<"0\n";
        }
        else{
            cout<<pref[n/2]<<endl;   
        }
	}
	return 0;
}
