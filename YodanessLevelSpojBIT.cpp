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
bool sieve[SIZE];
set<ll> s;
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
/* Multiplying 2 Long long Numbers */
inline long long mulmod(long long a,long long b,long long mod)
{
	a %= mod;
	long long res = 0LL;
	while (b){
        if (b % 2){    
            res = (res + a) % mod;
        }
        a = (a * 2) % mod;
        b /= 2;
    }
    return res;
}
/*Function For Calculating Exponent*/
inline long long modulo(long long a,long long b,long long mod)
{
	a%=mod;
    long long res=1LL;
    while (b){
    	if (b % 2){ 	
			res = mulmod(res,a,mod); 
		}
		a = mulmod(a,a,mod);
    	b /= 2;
	}
	return res;
}
bool Miller(ll p,int iteration)
{
    if (p < 2){
        return false;
    }
    if (p != 2 && p % 2==0){
        return false;
    }
    ll s = p - 1;
    while (s % 2 == 0){
        s /= 2;
    }
    for (int i = 0; i < iteration; i++){
        ll a = rand() % (p - 1) + 1, temp = s;
        ll mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0)
        {
            return false;
        }
    }
    return true;
}
ll func(ll n)
{
	if(n==1){
		return 1;
	}
	ll ans=1;
	tr(s,it){
		if((*it)*(*it)*(*it) > n)
		break;
		ll cnt=1;
		while(n%*it==0){
			cnt++;
			n/=*it;
		}
		ans *= cnt;
	}
	if(Miller(n,10)){
		ans *= 2;
	}
	else{
		if(n!=1){
			ll val = sqrt(n);
			if(val*val==n){
				ans *= 3;
			}
			else{
				ans*=4;
			}	
		}
	}
	return ans;
}
int main()
{  	
	boost;
	sievep();
	ll n,i,t;
	cin>>t;
	while(t--){
		cin>>n;
		bool is = false;
		ll ans;
		forp(i,2,64){
			long long temp = pow(n,1.000000000000/i);
			if(modulo(temp,i,LLONG_MAX)==n){
				ll num_div = func(temp);
				if(num_div == i){
					is=true;
					ans=temp;
					break;
				}
			}
			else if(modulo(temp+1,i,LLONG_MAX)==n){
				ll num_div = func(temp+1);
				if(num_div == i){
					is=true;
					ans=temp+1;
					break;
				}
			}
		}
		if(is){
			cout<<ans<<endl;
		}
		else{
			cout<<"-1"<<endl;
		}
	}
	return 0;
}
