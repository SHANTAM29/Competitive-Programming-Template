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
ll r[SIZE];
ll c[SIZE];
bool is1[SIZE];
bool is2[SIZE];
ll fans[SIZE];
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
	ll i,n,m,x,y;
	cin>>n>>m;
	forp(i,1,n){
		r[i]=n;
		c[i]=n;
	}
	ll ans=n*n*1LL;
	ll val1=0;
	ll val2=0;
	forp(i,1,m){
		cin>>x>>y;
		if(is1[x] and is2[y]){
			fans[i]=ans;
		}
		else if(is1[x]){
			ans-=(c[y]-val1);
			fans[i]=ans;
			is2[y]=true;
			val2++;
		}
		else if(is2[y]){
			ans-=(r[x]-val2);
			val1++;
			fans[i]=ans;
			is1[x]=true;
		}
		else{
			ans-=(r[x]+c[y]-val1-val2)-1;
			//cout<<ans<<endl;
			fans[i]=ans;
			is1[x]=true;
			is2[y]=true;
			val1++;
			val2++;
		}
		if(ans<=0)
		break;
	}
	forp(i,1,m){
		cout<<fans[i]<<" ";
	}
	return 0;
}
