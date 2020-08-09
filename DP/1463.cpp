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

int dp[1000001];

int main(){
    fastIO();

    int n;
    cin >> n;
    
    rep1(i, 0, n) dp[i] = 1e9;
    dp[1] = 0;
    rep1(i, 1, n){
        if(i + 1 <= n) uMin(dp[i+1], dp[i] + 1);
        if(i * 2 <= n) uMin(dp[i*2], dp[i] + 1);
        if(i * 3 <= n) uMin(dp[i*3], dp[i] + 1);
    }
    
    cout << dp[n];
}