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
#define SIZE 1000001
 
typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
pair< pair<ll,ll> , pair<string,ll> > a[SIZE];
string CST = "00000000000000000000";
bool is;
int n;
string f1(ll x)
{
	string temp = CST;
	ll i=0;
	while(x){
		ll num = x%10;
		temp[i] = (char)('0'+num);
		i++;
		x/=10;
	}
	return temp;
}
ll f3(string s)
{
	ll ans=0;
	for(ll i=0;i<len(s);i++){
		ans *= 10;
		ans += s[i]-'0';
	}
	return ans;
}
vll fans[100000];
void f2(ll idx)
{
	ll i,k;
	ll srt = 5*(idx-1);
	ll ed = 5*(idx) - 1;
	forp(i,0,99999){
		fans[i].clear();
	}
	forp(i,1,n){
		string temp = a[i].ss.ff;
		if(ed < len(temp)){
			string ss="";
			forp(k,srt,ed){
				ss += temp[k];
			}
			reverse(all(ss));
			ll val = f3(ss);
			a[i].ff.ff = val;
			fans[val].pb(i);
			if(val!=0){
				is = true;
			}
		}
	}
}
void f4()
{
	ll i,j;
	ll k=1;
	forp(i,0,99999){
		if(fans[i].size()){
			forp(j,0,fans[i].size()-1){
				printf("%lld ",a[fans[i][j]].ss.ss);
				a[fans[i][j]].ff.ss = k;
				k++;
			}
		}
	}
}
int main()
{  	
	boost;
	ll i,x;
	scanf("%lld",&n);
	forp(i,1,n){
		scanf("%lld",&x);
		string s =  f1(x);
		a[i] = mp(mp(0LL,i),mp(s,x));
	}
	ll idx=1;
	while(1){
		is = false;
		f2(idx);
		idx++;
		if(is==false)
		break;
		f4();
		/*forp(i,1,n){
			printf("%lld ",a[i].ss.ss);
			a[i].ff.ss = i;
		}*/
		printf("\n");
	}
	return 0;
}
