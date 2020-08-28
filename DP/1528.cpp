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

pair<int, int> dp[1000001];

pair<int, int> INF = {1e9, 1e9};

int main(){
    fastIO();
    
    vector<int> v;
    rep1(i, 1, 777777){
        int t = i;
        bool flag = true;
        while(t > 0){
            flag &= t % 10 == 4 || t % 10 == 7;
            t /= 10;
        }
        if(flag) v.push_back(i);
    }

    rep1(i, 0, 1000000){
        dp[i] = INF;
    }

    rep(i, 0, v.size()){
        dp[v[i]] = {1, v[i]};
    }

    int n;
    cin >> n;

    rep1(i, 0, n){
        if(dp[i] == INF) continue;
        else{
            rep(j, 0, v.size()){
                if(i + v[j] > 1000000) break;

                dp[i + v[j]] = min(dp[i + v[j]], {dp[i].first + 1, v[j]});
            }
        }
    }

    if(dp[n] == INF) return cout << -1, 0;

    while(n != 0){
        cout << dp[n].second << ' ';
        n -= dp[n].second;
    }
}