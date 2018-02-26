#include<bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(i=a;i<=b;i++)
#define ren(i,a,b) for(i=a;i>=b;i--)
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
#define SIZE 100001

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
int main()
{  	
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	boost;
	ll n,k,a,b,i,j,t;
	ll arr[505][505];
	vector< pair<ll,ll> > v;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		rep(i,0,n-1)
		{
			cin>>a>>b;
			v.pb(mp(a,b));
		}
		sort(all(v));
		rep(i,0,n-1)
		{
			arr[i][0]=0;
		}
		rep(i,1,k)
		{
			if(i>=v[0].ff)
			arr[0][i]=v[0].ss;
			else
			arr[0][i]=0;
		}
		for(i=1;i<n;i++)
		{
			for(j=1;j<=k;j++)
			{
				arr[i][j]=arr[i-1][j];
				if(j>=v[i].ff)
				{
					arr[i][j]=max(arr[i][j],v[i].ss+arr[i-1][j-v[i].ff]);
				}
			}
		}
		ll ans=0,temp=0;
		for(i=0;i<=k;i++)
		{
			if(ans<arr[n-1][i])
			{
				ans=arr[n-1][i];
				temp=i;
			}
		}
		cout<<temp<<" "<<ans<<endl;
		v.clear();
	}
	return 0;
}
