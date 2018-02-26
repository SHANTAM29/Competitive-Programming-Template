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
#define MOD 100000007
#define EPSILON 1e-9
#define PI 3.14159265358979323846
#define SIZE 100000

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
bool b[1024];
ll a[1000];
int main()
{  	
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	boost;
	//cin.tie(0);
	ll t,tt,n,mm,i,x;
	//map<ll,ll> m,m2;
	ll m[1024],m2[1024];
	cin>>t;
	forp(tt,1,t){
		//m.clear();
		mem(m,0);
		mem(b,false);
		cin>>n>>mm;
		rep(i,n){
			cin>>a[i];
		}
		rep(i,mm){
			cin>>x;
			b[x]=true;
		}
		m[0]=1;
		rep(i,n){
			//m2.clear();
			mem(m2,0);
			for(int j=0;j<1024;j++){
				m2[j^a[i]]=m[j];
			}
			for(int j=0;j<1025;j++){
				m[j]=(m[j]+m2[j])%MOD;
			}
		}
		ll cnt=0;
		for(i=0;i<1024;i++){
			if(!b[i])
			{
				cnt=(cnt+m[i])%MOD;
			}
		}
		cout<<"Case "<<tt<<": "<<cnt<<endl;
	}
	return 0;
}
