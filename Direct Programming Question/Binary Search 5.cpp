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

ll a[SIZE],b[SIZE],c[SIZE];
ll n,l;
ull w;
bool check(ll mid)
{
	ull sum=0;
	ll i;
	ldo temp=1e18;
	forp(i,1,n){
		if(mid>=c[i])
		{
			if(mid>=ceil(temp/b[i]))
			return true;
		}
	}
	forp(i,1,n){
		if(mid>=c[i])
		sum+=a[i];
		if(sum>=w)
		return true;
	}
	forp(i,1,n){
		if(mid>=c[i])
		sum+=b[i]*mid;
		if(sum>=w)
		return true;
	}
	return false;
}
int main()
{  	
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	boost;
	//cin.tie(0);
	ll sum=0,i;
	cin>>n>>w>>l;
	forp(i,1,n){
		cin>>a[i]>>b[i];
		if(a[i]>=l)
		sum+=a[i];
	}
	if(sum>=w){
		cout<<"0\n";
		return 0;
	}
	forp(i,1,n){
		ll temp=ceil((ldo)(max(0LL,l-a[i]))/b[i]);
		c[i]=temp;
	}
	set<ll> s;
	ll lo=1,hi=1e18;
	while(lo<=hi){
		ll mid=lo+hi>>1;
		if(check(mid))
		{
			s.insert(mid);
			hi=mid-1;
		}
		else
		lo=mid+1;
	} 
	cout<<*(s.begin())<<endl;
	return 0;
}
