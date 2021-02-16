#include<bits/stdc++.h>

using namespace std;

#define lli long long
#define TC int TC;cin>>TC;while(TC--)
#define fastIO() ios_base::sync_with_stdio(0),cin.tie(0)
#define uMin(a, b) a = min(a, b)
#define uMax(a, b) a = max(a, b)
#define mset(a, arr) memset(arr, a, sizeof(arr))
#define piii pair<lli, pair<lli, lli>>
#define piiii pair<pair<lli, lli>, pair<lli, lli>>
#define ff first
#define ss second

#define rep(i, a, b) for(int i = (a) ; i < (b) ; i++)
#define rep1(i, a, b) for(int i = (a) ; i <= (b) ; i++)
#define rep2(i, a, b) for(int i = (a) ; i >= (b) ; i--)

#define cout1(a) cout << a << '\n'
#define cout2(a, b) cout << a << ' ' << b << '\n'
#define cout3(a, b, c) cout << a << ' ' << b << ' ' << c << '\n'
#define cout4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'

int main(){
    fastIO();
    
    bool prime[30000];
    mset(0, prime);

    vector<int> primes;

    rep(i, 2, 30000){
        if(!prime[i]){
            primes.push_back(i);
            for(int j = 2 ; j * i < 30000 ; j++){
                prime[j * i] = true;
            }
        }
    }

    TC{
        int n;
        cin >> n;

        int bef = 1;
        int ans = 1;
        int cnt = 0;
        rep(i, 0, primes.size()){
            if(primes[i] >= bef + n){
                bef = primes[i];
                ans *= primes[i];
                cnt++;
            }
            if(cnt == 2) break;
        }

        cout << ans << '\n';
    }
}