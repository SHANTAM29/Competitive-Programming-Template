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
#define SIZE 500001
 
typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
map<int,int> m;
int a[SIZE];
int dp[SIZE];
vector<int> v;
int expo[SIZE];
void func()
{
	expo[0]=1;
	for(int i=1;i<SIZE;i++){
		expo[i]=expo[i-1]*2;
		expo[i]%=MOD;
		//cout<<expo[i]<<" ";
	}
	return ;
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
	func();
	int i,n,q;
	cin>>n>>q;
	forp(i,1,n){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	m[0]=1;
	forp(i,1,n){
		m[a[i]]+=expo[i-1];
		m[a[i]]%=MOD;
	}
	tr(m,it){
		v.pb(it->ff);
		//cout<<it->ff<<" "<<it->ss<<endl;
	}
	/*for(i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}*/
	dp[0]=1;
	for(i=1;i<v.size();i++){
		dp[i]=dp[i-1]+m[v[i]];
		dp[i]%=MOD;
	}
	while(q--){
		char ch;
		int x;
		cin>>ch>>x;
		if(ch=='='){
			cout<<m[x]<<endl;
		}
		else if(ch=='<'){
			int temp=lb(all(v),x)-v.begin();
			if(temp==v.size() or v[temp]>=x)
			temp--;
			cout<<dp[temp]<<endl;
		}
		else{
			int temp=ub(all(v),x)-v.begin();
			int ans=dp[v.size()-1]-dp[temp-1];
			if(ans<0)
			ans+=MOD;
			cout<<ans<<endl;
		}
	}
	return 0;
}
