#include<bits/stdc++.h>

using namespace std;

#define lli long long
#define TC int TC;cin>>TC;while(TC--)
#define fastIO() ios_base::sync_with_stdio(0),cin.tie(0)
#define uMin(a, b) a = min(a, b);
#define uMax(a, b) a = max(a, b);
#define mset(a, arr) memset(arr, a, sizeof(arr))

uint64_t dp[51][25*49+1];

int main(){
    int N, K;
    cin >> N >> K;

    dp[2][0] = 3;
    dp[2][1] = 2;
    
    for(int i = 3 ; i <= N ; i++){
        for(int j = 0 ; dp[i-1][j] != 0 ; j++){
            int c = __builtin_popcountll(dp[i-1][j]);
            dp[i][j] = dp[i][j] == 0 ? (dp[i-1][j] << 1) + 1 : dp[i][j];
            dp[i][j+c] = dp[i][j+c] == 0 ? dp[i-1][j] << 1 : dp[i][j+c];
        }
    }

    if(dp[N][K] == 0ULL) cout << -1;
    else{
        for(int i = N - 1 ; i >= 0 ; i--){
            if((1LL << i) & dp[N][K]) cout << 'A';
            else cout << 'B';
        }
    }
}