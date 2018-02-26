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
set< vector<int> > s;
vii v;
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
	int i,n,t,sum;
	int a[12];
	cin>>t;
	while(t--){
		cin>>n;
		forp(i,0,n-1){
			cin>>a[i];
		}
		cin>>sum;
		s.clear();
		int mask=(1<<n)-1;
		for(int j=0;j<=mask;j++){
			int val=0;
			v.clear();
			for(i=0;i<n;i++){
				if((j>>i)&1){
					val+=a[i];
					v.pb(a[i]);
				}
			}
			if(val==sum){
				sort(all(v));
				s.insert(v);
			}
		}
		if(s.size()==0){
			cout<<"Empty\n";
		}
		else{
			//cout<<s.size()<<endl;
			tr(s,it){
				cout<<"(";
				for(int k=0;k<(*it).size();k++){
					cout<<(*it)[k];
					if(k<(*it).size()-1)
					cout<<" ";
				}
				cout<<")";
			}
			cout<<endl;
		}
	}
	return 0;
}
