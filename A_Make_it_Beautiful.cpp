#include<bits/stdc++.h>
using namespace std;
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define ull unsigned long long
#define pi acos(-1)
#define yes "YES" 
#define no "NO"
#define endl "\n"
#define Max INT_MAX
#define Min INT_MIN
#define pow2(n) n&(n-1)
#define lcm(a,b) (a*b)/__gcd(a,b)
#define pii pair<int,int>
#define pll pair<long long ,long long>
#define setpre(n) fixed<<setprecision(n)
#define forn(n) for(int i=0;i<n;i++)
#define asort(v) sort(v.begin(),v.end())
#define dsort(v) sort(v.rbegin(),v.rend())
#define vecinp(v,n) for(int i=0;i<n;i++) cin>>v[i]
#define revs(v) reverse(v.begin(),v.end())
#define mem(a,b) memset(a,b,sizeof(a))
#define test() int t;cin>>t;while(t--)
#define nesloop(n,m) for(int i=0;i<n;i++) for(int j=0;j<m;j++) 
int const N=1e5;
int mod=1e7;
//........................................................................................................
//........................................................................................................
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define multiordered_set tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>
 
bool isprime(int n){
	if (n == 1) return false;
	for (int i=2; i*i<=n;i++)
		if(n%i==0) return false;
	return true;
}
vector<int>sieve(int n){
    vector<bool>prime(n+1,true);
    for(int i=2;i<=sqrt(n);i++){
        if(prime[i])
            for(int j=i*i;j<=n;j+=i) prime[j]=false;     
    }
    prime[0]=prime[1]=false;
    vector<int>primes;
    for(int i=2;i<=n;i++)
        if(prime[i]) primes.push_back(i);
    return primes;
}
vector<int>PF(int n){
    vector<int>primes=sieve(N);
    vector<int>pf;
    int fin=upper_bound(primes.begin(),primes.end(),n)-primes.begin();
    for(int i=0;i<fin;i++){
           if(n==1) break;
        while(n%primes[i]==0){
            pf.push_back(primes[i]); n/=primes[i];
        }
    }
    return pf;
}
ll BinaryMultiply(ll a,ll b){
    ll ans=0;
    while(b){
        if(b&1) ans=(ans+a)%mod; a=(a+a)%mod;
        b>>=1;
    }
    return ans;
}
ll binex(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=BinaryMultiply(ans,a); a = BinaryMultiply(a,a); b>>=1;
    }
    return ans;
}
int digitsum(int n){
    int ans=0;
    while(n) ans+=(n%10),n/=10; return ans;
}
ull summation(ull n){
    ull  sum;  if(n%2) sum=(n+1)/2,sum*=n;
    else sum=n/2,sum*=(n+1);
    return sum;
}
bool perfectSquare(ll n){
    if(n<=1) return true;
    ll l = 1, r = n;
    while(r>=l){
        ll mid = (l+r)/2;
        if(mid>n/mid) r = (mid-1);
        else if(mid*mid == n) return true;
        else l =mid+1;
    }
    return false;
}
bool isValidDirection(int i, int j,int row ,int col) {
    return i>=0 && i<row && j>=0 && j<col;
}
vector<int>alldiv(int n){ // complexity :O(sqrt(n))
    vector<int>div;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            if(n/i==i) div.push_back(i);
            else {
                div.push_back(i);
                div.push_back(n/i);
            }
        }
    }
    return div;
}
bool cmp(pair<int,int>a,pair<int,int>b){
    //increasing order ; true = don't make swap , false = make swap
    if(a.first<b.first ) return true; // increasing
    else if(a.first == b.first) return a.second<b.second; // accending order second value
    else return false;
    // decreasing order
    // if(a.first>b.first ) return true; // decreasing
    // else if(a.first == b.first) return a.second<b.second; // decending order second value
    // else return false;
}
void solve(){
    ll n,m,k; cin>>n;
    vector<int>v(101,0);
    int ans = true;
    for(int i=0;i<n;i++){
        int x ; cin>>x; 
        v[x]++;
        if(v[x] == n) ans = false;
    }
    if(ans){
        int cnt = 0;
        cout<<yes<<endl;
        while(cnt<n){
            for(int i=100;i>0 && cnt<n;i--){
                if(v[i]){
                    cout<<i<<' ';
                    v[i]--;
                    cnt++;
                } 
            }
        }
        cout<<endl;
    }
    else cout<<no<<endl;
}
//*********************************************************************************************//
int main(){
    faster;
    test()
        solve();
return 0;
}