#include<bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(i=a;i<=b;i++)

#define boost ios_base::sync_with_stdio(0)
#define SIZE 100001

typedef long long  ll;
typedef unsigned long long ull;
using namespace std;
ll dist[SIZE];
multiset< pair < ll,ll > > s;
int main()
{  	
	boost;
	ll t,n,m,i,a,b,x,src,K,X;
	cin>>t;
	while(t--)
	{
		cin>>n>>K>>X>>m>>src;
		bool hogaya = false;
		vector< pair<ll,ll> > arr[n+1];
        rep(i,0,n)
        dist[i]=1e18;
		rep(i,1,m)
		{
			cin>>a>>b>>x;
			arr[a].pb(mp(b,x));
			arr[b].pb(mp(a,x));
		}
		dist[src]=0;
		s.insert(mp(dist[src],src));
		while(!s.empty())
		{
			b=(*(s.begin())).second;
			if(!hogaya and b<=K){
				hogaya = true;
				for(int IDX=1;IDX<=K;IDX++){
					if(IDX==b)
					continue;
					if(dist[IDX] > dist[b]+X){
						dist[IDX]=dist[b]+X;
						s.insert(mp(dist[IDX],IDX));
					}
				}
			}
			s.erase(s.begin());
			for(i=0;i<arr[b].size();i++)
			{
				a=arr[b][i].first;
				x=arr[b][i].second;
				if(dist[a]>dist[b]+x)
				{
					dist[a]=dist[b]+x;
					s.insert(mp(dist[a],a));
				}
			}
		}
		for(i=1;i<=n;i++){
			cout<<dist[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
