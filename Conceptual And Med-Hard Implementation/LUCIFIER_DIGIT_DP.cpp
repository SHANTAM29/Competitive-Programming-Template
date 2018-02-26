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
/*Sieve Function*/
bool sieve[SIZE];
set<int> s;
vector<int> v;
int dp[11][50][50][2];
void sievep()
{
	/* Please Don't Change The Datatype Of Any Number To int Even If The Max Value Of SIZE is 1e6 */
	ll i,p;
	s.insert(2);
	for(i=3;i<SIZE;i=i+2)
	{
		if(sieve[i]==0)
		{
			s.insert(i);
			p=i;
			while(i*p<SIZE*1LL)
			{
				sieve[i*p]=1;
				p=p+2;
			}
		}
	}
	return ;
}
int f(int pos,int sum1,int sum2,bool is)
{
	if(pos==v.size()-1){
		int fans=0;
		for(int i=0;i<=(is?v[pos]:9);i++){
			if(pos%2){
				if(present(s,sum1-sum2-i))
				fans++;
			}
			else{
				if(present(s,sum2-sum1-i))
				fans++;
			}
		}
		return fans;
	}
	if(dp[pos][sum1][sum2][is]!=-1)
	return dp[pos][sum1][sum2][is];
	int fans=0;
	for(int i=0;i<=(is?v[pos]:9);i++){
		if(pos%2){
			fans += f(pos+1,sum1,sum2+i,(is?(i==v[pos]?true:false):is));
		}
		else{
			fans += f(pos+1,sum1+i,sum2,(is?(i==v[pos]?true:false):is));
		}
	}
	dp[pos][sum1][sum2][is]=fans;
	return fans;
}
int func(int x)
{
	v.clear();
	while(x){
		v.pb(x%10);
		x/=10;
	}
	reverse(all(v));
	mem(dp,-1);
	return f(0,0,0,true);
}
bool check(int x)
{
	int val1=0;
	int val2=0;
	bool is=true;
	while(x){
		if(is){
			val1+=x%10;
		}
		else{
			val2+=x%10;
		}
		x/=10;
		is=1-is;
	}
	if(present(s,val2-val1))
	return true;
	return false;
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
	//cout<<"Case #"<<tt<<": ";
	sievep();
	int t,a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(a>b)
		swap(a,b);
		if(!a)
		a++;
		if(!b)
		b++;
		int val1=func(a);
		int val2=func(b);
		val2-=val1;
		if(check(a))
		val2++;
		cout<<val2<<endl;
	}
	return 0;
}
