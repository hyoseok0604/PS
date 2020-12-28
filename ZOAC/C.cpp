#include<bits/stdc++.h>

using namespace std;

#define lli long long int
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

    int n, k, q, m;
    cin >> n >> k >> q >> m;

    int ans[n+3];
    mset(0, ans);

    int s[k];
    rep(i, 0, k){
        int t;
        cin >> t;
        ans[t] = -1;
    }

    int a[q];
    rep(i, 0, q){
        int t;
        cin >> t;
        if(ans[t] != -1) ans[t] = 1;
    }

    rep(i, 2, n+3){
        if(ans[i] != 1) continue;
        for(int k = 1 ; k * i <= n + 2 ; k++){
            if(ans[k * i] == -1) continue;
            else ans[k * i] = 1;
        }
    }

    int psum[n+4];
    mset(0, psum);
    rep(i, 1, n+3){
        psum[i] = psum[i-1] + (ans[i] == 1);
    }

    while(m--){
        int s, e;
        cin >> s >> e;
        cout << e - s + 1 - psum[e] + psum[s-1] << '\n';
    }
}