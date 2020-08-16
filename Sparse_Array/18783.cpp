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

int p[100001][32];

int main(){
    fastIO();

    int n, m, k;
    cin >> n >> m >> k;

    rep1(i, 1, n) p[i][0] = i;

    while(m--){
        int l, r;
        cin >> l >> r;

        rep(i, 0, (r - l + 1) / 2){
            swap(p[l+i][0], p[r-i][0]);
        }
    }

    rep(k, 1, 32){
        rep1(i, 1, n){
            p[i][k] = p[p[i][k-1]][k-1];
        }
    }

    rep1(i, 1, n){
        int ans = i;
        rep(j, 0, 32){
            if(k & (1 << j)) ans = p[ans][j];
        }
        cout << ans << '\n';
    }
}