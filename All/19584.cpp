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

int main(){
    fastIO();

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> pos(n);
    rep(i, 0, n){
        int x, y;
        cin >> x >> y;
        pos[i] = {y, i+1};
    }

    sort(pos.begin(), pos.end());

    int comp[n+1];
    int b = -1e9 - 1;
    int p = -1;
    rep(i, 0, n){
        if(pos[i].first != b) p++, b = pos[i].first;
        comp[pos[i].second] = p;
    }

    lli arr[p+2];
    mset(0, arr);
    rep(i, 0, m){
        int u, v, c;
        cin >> u >> v >> c;

        u = comp[u];
        v = comp[v];

        if(u > v) swap(u, v);

        arr[u] += c;
        arr[v+1] -= c;
    }

    lli ans = arr[0];
    rep(i, 1, p+1){
        ans = max(ans, arr[i] += arr[i-1]);
    }

    cout << ans;
}