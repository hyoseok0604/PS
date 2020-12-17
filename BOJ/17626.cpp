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

int dp[50000];

int main(){
    fastIO();

    vector<int> m(230);
    rep(i, 1, m.size()){
        m[i] = i * i;
    }

    rep(i, 1, m.size()){
        dp[m[i]] = 1;
    }

    rep(i, 0, 3){
        rep(j, 1, 50000){
            if(dp[j] != 0){
                rep(k, 0, 230){
                    if(j + m[k] > 50000) continue;
                    if(dp[j + m[k]] == 0) dp[j + m[k]] = dp[j] + 1;
                    dp[j + m[k]] = min(dp[j + m[k]], dp[j] + 1);
                }
            }
        }
    }

    int n;
    cin >> n;

    cout << dp[n];
}