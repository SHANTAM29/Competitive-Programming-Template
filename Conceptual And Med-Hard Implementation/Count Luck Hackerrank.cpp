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
#define SIZE 102

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
char a[SIZE][SIZE];
pii s,e;
bool is;
vector< pii > v;
bool visit[SIZE][SIZE];
void dfs(int i,int j)
{
	visit[i][j]=true;
	if(e==mp(i,j)){
		is=true;
		return ;
	}
	if(a[i+1][j]!='X' and visit[i+1][j]==false){
		dfs(i+1,j);
		if(is){
			v.pb(mp(i+1,j));
			return ;
		}
	}
	if(a[i-1][j]!='X' and visit[i-1][j]==false){
		dfs(i-1,j);
		if(is){
			v.pb(mp(i-1,j));
			return ;
		}
	}
	if(a[i][j+1]!='X' and visit[i][j+1]==false){
		dfs(i,j+1);
		if(is){
			v.pb(mp(i,j+1));
			return ;
		}
	}
	if(a[i][j-1]!='X' and visit[i][j-1]==false){
		dfs(i,j-1);
		if(is){
			v.pb(mp(i,j-1));
			return ;
		}
	}
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
	int i,j,n,m,t,k;
	cin>>t;
	while(t--){
		mem(a,'X');
		cin>>n>>m;
		forp(i,1,n){
			forp(j,1,m){
				cin>>a[i][j];
				if(a[i][j]=='*')
				e=mp(i,j);
				if(a[i][j]=='M')
				s=mp(i,j);
			}
		}
		cin>>k;
		is=false;
		v.clear();
		mem(visit,false);
		dfs(s.ff,s.ss);
		int ans=0;
		v.pb(s);
		v.erase(v.begin());
		for(i=0;i<v.size();i++){
			int temp=0;
			//cout<<v[i].ff<<" "<<v[i].ss<<endl;
			if(a[v[i].ff+1][v[i].ss]!='X')
			temp++;
			if(a[v[i].ff-1][v[i].ss]!='X')
			temp++;
			if(a[v[i].ff][v[i].ss+1]!='X')
			temp++;
			if(a[v[i].ff][v[i].ss-1]!='X')
			temp++;
			if(i==v.size()-1){
				if(temp>1)
				ans++;
			}
			else{
				if(temp>2)
				ans++;
			}
		}
		if(ans==k){
			cout<<"Impressed\n";
		}
		else{
			cout<<"Oops!\n";
		}
	}
	return 0;
}
