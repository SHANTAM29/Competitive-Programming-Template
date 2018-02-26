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
	ll n,m,T,t,i,a,b,x;
	ll dist[10000];
	ll value[10000];
	pair<ldo,ll> ans[10000];
	multiset< pair<ll,ll> > s;
	cin>>t;
	while(t--){
		cin>>n>>m>>T;
		vector< pair<ll,ll> > arr[n];
		rep(i,0,n-1)
		dist[i]=INT_MAX;
		dist[0]=0;
		rep(i,0,m-1){
			cin>>a>>b>>x;
			arr[a].pb(mp(b,x));
			arr[b].pb(mp(a,x));
		}
		rep(i,1,n-1){
			cin>>value[i];
		}
		value[0]=0;
		s.insert(mp(0,0));
		while(!s.empty()){
			b=(*(s.begin())).ss;
			s.erase(s.begin());
			for(i=0;i<arr[b].size();i++){
				a=arr[b][i].ff;
				x=arr[b][i].ss;
				if(dist[a]>dist[b]+x)
				{
					dist[a]=dist[b]+x;
					s.insert(mp(dist[a],a));
				}
			}
		}
		ans[0].ff=0;
		ans[0].ss=0;
		rep(i,1,n-1){
			ans[i].ff=(ldo)value[i]/(2*dist[i]);
			ans[i].ss=i;
		}
		sort(ans+1,ans+n);
		/*rep(i,0,n-1)
		cout<<ans[i].ss<<" "<<ans[i].ff<<endl;*/
		ll cnt=0,out=0;
		i=n-1;
		while(i>=1){
			out+=value[ans[i].ss];
			cnt+=2*dist[ans[i].ss];
			if(cnt==T)
			break;
			else if(cnt>T)
			{
				out-=value[ans[i].ss];
				cnt-=2*dist[ans[i].ss];
			}
			i--;
		}
		cout<<out<<endl;
	}
	return 0;
}
