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

    vector<pair<int, int>> pos(n+1);
    rep1(i, 1, n) cin >> pos[i].first >> pos[i].second; // x, y

    vector<int> ypos(n);
    rep(i, 0, n) ypos[i] = pos[i+1].second;

    sort(ypos.begin(), ypos.end()); // n log n
    ypos.erase(unique(ypos.begin(), ypos.end()), ypos.end()); // n

    int comp[n+1];
    rep1(i, 1, n) comp[i] = lower_bound(ypos.begin(), ypos.end(), pos[i].second) - ypos.begin(); // n log n

    lli arr[ypos.size()+1];
    mset(0, arr);
    rep(i, 0, m){ // m
        int u, v, c;
        cin >> u >> v >> c;

        u = comp[u];
        v = comp[v];

        if(u > v) swap(u, v);

        arr[u] += c;
        arr[v+1] -= c;
    }

    rep(i, 1, ypos.size()){
        arr[i] = arr[i] + arr[i-1];
    }

    lli ans = 0;
    rep(i, 0, ypos.size()){
        uMax(ans, arr[i]);
    }

    cout << ans;
}