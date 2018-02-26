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

const ll N=999;
using namespace std;
int main()
{  	
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	boost;
	ll n,m,src,count,dest,a,b,x,i;
	pair<ll,ll> dist[101];
	multiset< pair<ll,ll> > s;
	multiset< pair<ll,ll> > ::iterator it;
	cin>>n>>m;
	vector< pair<ll,ll> > arr[n+1];
	rep(i,0,101)
	{
		dist[i].ff=INT_MAX;
		dist[i].ss=i;
	}
	rep(i,1,m)
	{
		cin>>a>>b>>x;
		//x=N-x;
		arr[a].pb(mp(b,x));
		arr[b].pb(mp(a,x));
	}
	cin>>src>>dest>>count;
	dist[src]=mp(0,1);
	s.insert(mp(dist[src].ff,src));
	//printf("hey whatsup\n");
	while(!s.empty())
	{
		it=b(s);
		a=(*(it)).ss;
		s.erase(it);
		for(i=0;i<arr[a].size();i++)
		{
			b=arr[a][i].ff;
			x=arr[a][i].ss;
			if(dist[b].ff>dist[a].ff+x)
			{
				dist[b].ff=dist[a].ff+x;
				dist[b].ss=a;
				s.insert(mp(dist[b].ff,b));
			}
		}
	}
	/*for(i=1;i<=n;i++)
	cout<<dist[i].ff<<" "<<dist[i].ss<<endl;*/
	i=5;
	cout<<i<<" ";
	while(1)
	{
		ll x=dist[i].ss;
		if(x==1)
		break;
		cout<<x<<" ";
		i=x;
	}
	cout<<1<<endl;
	return 0;
}
