class Solution {
public:
    #define ll long long
    const int mod= 1e9+7;
    ll power(ll m,ll n){
        if(n==0)
            return 1;
        else if(n&1)
            return (m%mod)*power(((m%mod)*(m%mod))%mod,(n-1)/2)%mod;
        else
            return power(((m%mod)*(m%mod))%mod,n/2)%mod;
    }
    int minNonZeroProduct(int p) {
        if(p==1)
            return p;
        ll k=0;
        ll d=1;
        for(int i=0;i<p;i++){
            k= (k+d);
            d=(d*2);
        }
        ll ans= 1;
        ll q= ((k-3)/2+1);
        ans = ((k%mod)*power(k-1,q));
        return ans%mod;
    }
};