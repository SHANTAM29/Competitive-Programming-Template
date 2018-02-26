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
struct node{
	node* alphabets[26];
	int ans;
	node()
	{
		ans=0;
		for(int i=0;i<26;i++){
			alphabets[i]=NULL;
		}	
	} 
}*root = new node();			
void insert(node* temp,string s,int w)
{
	if(len(s)==1){
		if(temp->alphabets[s[0]-'a']==NULL){
			temp->alphabets[s[0]-'a']= new node;
		}
		temp->alphabets[s[0]-'a']->ans=max(temp->alphabets[s[0]-'a']->ans,w);
		return ;
	}
	else{
		string t = s.substr(1,s.length()-1);
		if(temp->alphabets[s[0]-'a']==NULL){
			temp->alphabets[s[0]-'a']=new node;
		}
		temp->alphabets[s[0]-'a']->ans=max(temp->alphabets[s[0]-'a']->ans,w);
		insert(temp->alphabets[s[0]-'a'],t,w);
	}
}
int search(node* temp,string s)
{
	if(len(s)==1){
		if(temp->alphabets[s[0]-'a']==NULL){
			return -1;
		}
		return temp->alphabets[s[0]-'a']->ans;
	}
	else{
		string t = s.substr(1,s.length()-1);
		if(temp->alphabets[s[0]-'a']==NULL){
			return -1;
		}
		return search(temp->alphabets[s[0]-'a'],t);
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
	//cout<<"Case #"<<tt<<": ";
	int n,q,i,w;
	string s;
	cin>>n>>q;
	forp(i,1,n){
		cin>>s>>w;
		insert(root,s,w);
		/*if(root->alphabets[s[0]-'a']==NULL){
			cout<<"Hey\n";
		}
		else{
			cout<<root->alphabets[s[0]-'a']<<endl;
		}*/
	}
	while(q--){
		cin>>s;
		cout<<search(root,s)<<endl;
	}
	return 0;
}
