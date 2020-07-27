#include<bits/stdc++.h>

using namespace std;

#define lli long long
#define TC int TC;cin>>TC;while(TC--)
#define fastIO() ios_base::sync_with_stdio(0),cin.tie(0)
#define uMin(a, b) a = min(a, b);
#define uMax(a, b) a = max(a, b);
#define mset(a, arr) memset(arr, a, sizeof(arr))

int main(){
    fastIO();

    int n, m;
    cin >> n >> m;

    vector<int> v[m];
    for(int i = 0 ; i < m ; i++){
        int k;
        cin >> k;
        v[i].resize(k);
        for(int j = 0 ; j < k ; j++){
            cin >> v[i][j];
        }
    }
    
    int result[n+1];
    int ans[n+1];
    int r2[n+1];
    for(int i = 1 ; i <= n ; i++){
        cin >> result[i];
        ans[i] = result[i];
        r2[i] = result[i];
    }

    for(int i = m - 1 ; i >= 0 ; i--){
        bool flag = false;
        for(int j = 0 ; j < v[i].size() ; j++){
            if(flag) ans[v[i][j]] = 0, r2[v[i][j]] = 0;
            else if(result[v[i][j]] == 0 || r2[v[i][j]] == 0) flag = true, j = -1;
        }
    }

    for(int i = 0 ; i < m ; i++){
        bool flag = false;
        for(int j = 0 ; j < v[i].size() ; j++){
            if(flag) r2[v[i][j]] = 1;
            else if(r2[v[i][j]] == 1) flag = true, j = -1;
        }
    }

    bool flag = true;
    for(int i = 1 ; i <= n ; i++){
        if(r2[i] != result[i]) flag = false;
    }

    if(flag){
        cout << "YES\n";
        for(int i = 1 ; i <= n ; i++){
            cout << ans[i] << ' ';
        }
    }else cout << "NO\n";
}