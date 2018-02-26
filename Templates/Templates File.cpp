/*Sieve Function*/
bool sieve[SIZE];
set<long long> s;
void sievep()
{
	/* Please Don't Change The Datatype Of Any Number To int Even If The Max Value Of SIZE is 1e6 */
	long long i,p;
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
/* Prime Factorization Using Sieve */
bool sieve[SIZE];
int factor[SIZE];
void sievep()
{
	long long i,p;
	forp(i,0,SIZE-1)
	factor[i]=i;
	sieve[0]=sieve[1]=1;
	for(i=4;i<SIZE;i=i+2){
		sieve[i]=1;
		factor[i]=2;
	}
	for(i=3;i*i<SIZE;i=i+2){
		if(sieve[i]==0)
		{
			for(long long j=i*i;j<SIZE;j+=i)
			{
				if(factor[j]==j)
				factor[j]=i;
				sieve[j]=1;
			}
		}
	}
	return ;
}
/* Factorial */
long long fact[SIZE];
void f()				// Perfect
{
	fact[0]=1;
	for(long long i=1;i<SIZE;i++){
		fact[i]=fact[i-1]*i;
		fact[i]%=MOD;
	}
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
inline long long expo(long long a,long long b,long long mod)
{
	a%=mod;
    long long res=1LL;
    while (b){
    	if (b % 2){ 	
		//	res = mulmod(res,a,mod);
			res =  (res*a)%mod;
		}
	//	a = mulmod(a,a,mod);
		a = (a*a)%mod;
    	b /= 2;
	}
	return res;
}
/*Division */
inline long long mod_div(long long a,long long b,long long mod)
{
	return (a*expo(b,mod-2,mod))%mod;
}
/* Totient Function Sqrt(N) (3,2) (4,2) (6,2) */
long long totient (long long n) {
    long long result = n;
    for (long long i=2; i*i<=n; ++i){
		if (n % i == 0) {
            while (n % i == 0){
            	n /= i;	
			}
            result -= result / i;
        }
	}
    if (n > 1){
    	result -= result / n;	
	}
    return result;
}
/*Area Of A Triangle*/
inline long double area(long double x1,long double y1,long double x2,long double y2,long double x3,long double y3)
{
    return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}
/*Distance Between Two Points */
inline long double dist(long double x1,long double y1,long double x2, long double y2)
{
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
int LCA(int u, int v) {
	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	for(int i=0; i<LN; i++) if( (diff>>i)&1 ) u = pa[i][u];
	if(u == v) return u;
	for(int i=LN-1; i>=0; i--) if(pa[i][u] != pa[i][v]) {
			u = pa[i][u];
			v = pa[i][v];
		}
	return pa[0][u];
}