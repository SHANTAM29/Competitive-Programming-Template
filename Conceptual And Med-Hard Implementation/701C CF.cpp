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
set<char> s;
int cnt[100];
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
	string str;
	int l;
	cin>>l;
	cin>>str;
	for(int i=0;i<len(str);i++){
		s.insert(str[i]);
	}
	if(s.size()==1){
		cout<<"1\n";
		return 0;
	}
	int total=s.size();
	//cout<<total<<endl;
	s.clear();
	int i=1,j=0;
	int val=1;
	cnt[str[0]-'A']++;
	int ans=INT_MAX;
	while(i<len(str)){
		if(cnt[str[i]-'A']){
			cnt[str[i]-'A']++;
		}
		else{
			cnt[str[i]-'A']++;
			val++;
		}
		if(val==total){
			//cout<<i<<" "<<j<<endl;
			ans=min(ans,i-j+1);
			while(j<i){
				if(cnt[str[j]-'A']==1){
					ans=min(ans,i-j+1);
					cnt[str[j]-'A']=0;
					val--;
					j++;
					break;
				}
				cnt[str[j]-'A']--;
				j++;
			}
		}
		i++;
	}
	cout<<ans<<endl;
	return 0;
}
