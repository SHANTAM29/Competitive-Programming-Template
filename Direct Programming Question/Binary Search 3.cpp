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
ull a,b,c,d,k;
bool check(int mid){
	ull sum = a*mid*mid*mid + b*mid*mid + c*mid + d;
	if(sum<=k)
	return true;
	return false;
}
int main()
{  	
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	boost;
	//cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d>>k;
		if(d>=k)
		{
			cout<<"0\n";
			continue;
		}
		set<int> s;
		int lo=0,hi=1e6;
		//cout<<hi<<endl;
		while(lo<=hi){
			int mid=lo+hi>>1;
			if(check(mid))
			{
				s.insert(mid);
				lo=mid+1;
			}
			else
			hi=mid-1;
		}
		cout<<*(s.rbegin())<<endl;
	}
	return 0;
}
