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
vector<int> v;
vector<int> num;
long long dp[20][2][2][9][7][16];
bool check(int val,int nine,int mask,int seven)
{
	if(mask&1){
		if(nine%3==0)
		return false;
	}
	if((mask>>2)&1){
		if(seven==0)
		return false;
	}
	if((mask>>3)&1){
		if(nine==0)
		return false;
	}
	return true;
}
long long f(int pos,bool is,bool zero,int nine,int seven,int mask)
{
	if(pos==v.size()-1){
		int ans=0;
		for(int i=0;i<num.size();i++){
			if(num[i]==0 or num[i]==5)
			continue;
			if(is){
				if(num[i]<=v[pos]){
					ans += check(num[i],(nine*10+num[i])%9,mask|(1<<(i-1)),(seven*10+num[i])%7);
				}
			}
			else{
				ans += check(num[i],(nine*10+num[i])%9,mask|(1<<(i-1)),(seven*10+num[i])%7);
			}
		}
		return ans;
	}
	if(dp[pos][is][zero][nine][seven][mask]!=-1)
	return dp[pos][is][zero][nine][seven][mask];
	long long fans=0;
	for(int i=(zero?1:0);i<num.size();i++){
		if(is){
			if(num[i]>v[pos])
			continue;
		}
		if(num[i]){
			fans += f(pos+1,(is?(num[i]==v[pos]?true:false):false),true,(nine*10+num[i])%9,(seven*10+num[i])%7,mask|(1<<(i-1)));
		}
		else{
			fans += f(pos+1,(is?(num[i]==v[pos]?true:false):false),false,0,0,0);
		}
	}
	dp[pos][is][zero][nine][seven][mask]=fans;
	return fans;
}
long long func(long long x)
{
	v.clear();
	while(x){
		v.pb(x%10);
		x/=10;
	}
	reverse(all(v));
	mem(dp,-1);
	return f(0,true,false,0,0,0);
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
	num.pb(0);num.pb(3);num.pb(5);num.pb(7);num.pb(9);
	int Q=1;
	long long A,B,K;
	cin>>Q;
	while(Q--){
		cin>>A>>B>>K;
		long long val1 = A==1?0:func(A-1);
		long long val2 = func(B);
		if(K>val2-val1){
			cout<<"-1\n";
		}
		else{
			K+=val1;
			long long lo = A;
			long long hi = B;
			while(lo<hi){
				long long mid = (lo+hi)>>1;
				if(func(mid)<K){
					lo=mid+1;
				}
				else{
					hi=mid;
				}
			}
			cout<<lo<<endl;
		}
	}
	return 0;
} 
