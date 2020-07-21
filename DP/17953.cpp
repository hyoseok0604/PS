#include<bits/stdc++.h>

using namespace std;

#define lli long long
#define TC int TC;cin>>TC;while(TC--)

int arr[10][100001]; // arr[a][b] b 번째 날 a 번째 디저트의 만족도
int dp[100001][10]; // dp[a][b] a 번째 날 b 번째 디저트를 먹었을 경우 최대값

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0 ; i < m ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin >> arr[i][j];
        }
    }

    // dp 초기화
    for(int i = 0 ; i < m ; i++){
        dp[1][i] = arr[i][1];
    }

    // i 번째 날 j 번째 디저트를 먹고 전날 k 번째 디저트를 먹은 경우
    for(int i = 2 ; i <= n ; i++){
        for(int j = 0 ; j < m ; j++){
            for(int k = 0 ; k < m ; k++){
                // 전날 먹은 디저트와 같은 경우 절반의 만족도, 아닐 경우 만족도의 합과 비교
                if(j == k) dp[i][j] = max(dp[i][j], dp[i-1][k] + arr[j][i] / 2);
                else dp[i][j] = max(dp[i][j], dp[i-1][k] + arr[j][i]);
            }
        }
    }

    int ans = 0;
    for(int i = 0 ; i < m ; i++){
        ans = max(ans, dp[n][i]);
    }

    cout << ans;
}