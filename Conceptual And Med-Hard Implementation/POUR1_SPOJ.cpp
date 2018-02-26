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
#define SIZE 100001

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
set< pair<int,pii > > s;
pair<int,pii > temp;
map< pii,bool > m;
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
	int t,a,b,c;
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		m.clear();
		s.clear();
		if(c==0 or (c>a and c>b)){
			cout<<"-1\n";
			continue;
		}
		if(c==a or c==b){
			cout<<"1\n";
			continue;
		}
		if(c%__gcd(a,b)!=0){
			cout<<"-1\n";
			continue;
		}
		m[mp(0,0)]=true;
		s.insert(mp(1,mp(a,0)));
		s.insert(mp(1,mp(0,b)));
		while(1){
			temp=*(s.begin());
			s.erase(s.begin());
			if(temp.ss.ff == c or temp.ss.ss == c){
				break;
			}
			if(m[mp(temp.ss.ff,temp.ss.ss)])
			continue;
			m[mp(temp.ss.ff,temp.ss.ss)]=true;
			s.insert(mp(temp.ff+1,mp(0,temp.ss.ss)));
			s.insert(mp(temp.ff+1,mp(temp.ss.ff,0)));
			s.insert(mp(temp.ff+1,mp(temp.ss.ff,b)));
			s.insert(mp(temp.ff+1,mp(a,temp.ss.ss)));
			int x=a-temp.ss.ff;
			s.insert(mp(temp.ff+1,mp(min(a,temp.ss.ff+temp.ss.ss),max(0,temp.ss.ss-x))));
			x=b-temp.ss.ss;
			s.insert(mp(temp.ff+1,mp(max(0,temp.ss.ff-x),min(b,temp.ss.ff+temp.ss.ss))));
		}
		cout<<temp.ff<<endl;
	}
	return 0;
}
