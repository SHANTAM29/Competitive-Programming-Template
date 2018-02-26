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
#define SIZE 1001

typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
int dp[SIZE][SIZE];
string ans[100001];
int pos[100001];
char ch[100001];
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
	int i,j;
	string s1,s2;
	cin>>s1>>s2;
	for(i=1;i<=len(s2);i++){
		dp[0][i]=i;
	}
	for(i=1;i<=len(s1);i++){
		dp[i][0]=i;
	}
	int k=0;
	for(i=1;i<=len(s1);i++){
		for(j=1;j<=len(s2);j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j]=dp[i-1][j-1];
			}
			else{
				dp[i][j]=1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
			}
		}
	}
	cout<<dp[len(s1)][len(s2)]<<endl;
	i = len(s1);
	j = len(s2);
    while(j >= 1 || i >= 1){
        if(i>0 && j>0 && s1[i-1] == s2[j-1]){
            i--;    j--;
            continue;
        }
        if(i>0 && j>0 && dp[i][j] == dp[i-1][j-1]+1){
            pos[k] = j;
			ch[k] = s2[j-1];
            ans[k]="REPLACE";
            k++;
            i--;    
			j--;
            continue;
        }
        if(j>0 && dp[i][j] == dp[i][j-1]+1){
			pos[k] = j;
			ch[k] = s2[j-1];
            ans[k]="INSERT";
            k++;
			j--;
            continue;
        }
        if(i>0 && dp[i][j] == dp[i-1][j]+1){
			pos[k]=j+1;
            ans[k]="DELETE";
            k++;
            i--;    
            continue;
        }
    }
	for(i=k-1;i>=0;i--){
		cout<<ans[i]<<" ";
		if(ans[i]=="DELETE"){
			cout<<pos[i]<<endl;
		}
		else{
			cout<<pos[i]<<" "<<ch[i]<<endl;
		}
	}
	return 0;
}
