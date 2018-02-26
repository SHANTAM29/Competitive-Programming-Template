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
#define SIZE 5000001

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
set<ll> s,s2;
bool sieve[SIZE];
void sievep()
{
	/* Please Don't Change The Datatype Of Any Number To int Even If The Max Value Of SIZE is 1e6 */
	ll i,p;
	s2.insert(2);
	for(i=3;i<SIZE;i=i+2)
	{
		if(sieve[i]==0)
		{
			s2.insert(i);
			p=i;
			while(i*p<SIZE*1LL)
			{
				sieve[i*p]=1;
				p=p+2;
			}
		}
	}
	return ;
}
int lca(int x,int y)
{
	s.clear();
	while(x!=1){
		s.insert(x);
		x/=2;
	}
	s.insert(1);
	while(y!=1){
		if(present(s,y))
		return y;
		y/=2;
	}
	return 1;
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
	sievep();
	int t,x,y;
	cin>>t;
	while(t--){
		cin>>x>>y;
		int temp=lca(x,y);
		ll ans=0;
		while(x!=temp){
			if(present(s2,x))
			ans-=x;
			else
			ans+=x;
			x/=2;
		}
		//cout<<temp<<endl;
		if(present(s2,temp))
		ans-=temp;
		else
		ans+=temp;
		while(y!=temp){
			if(present(s2,y))
			ans-=y;
			else
			ans+=y;
			y/=2;
		}
		cout<<ans<<endl;
	}
	return 0;
}
