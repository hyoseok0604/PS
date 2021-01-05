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

int main(){
    fastIO();

    TC{
        int n;
        cin >> n;

        pair<int, int> h[n];
        pair<int, int> w[n];
        rep(i, 0, n){
            int th, tw;
            cin >> th >> tw;
            if(th > tw) swap(th, tw);
            h[i] = {th, i};
            w[i] = {tw, i};
        }

        sort(h, h + n);

        int ans[n];
        mset(-1, ans);

        pair<int, int> mnws[n];
        int bh = -1;
        int cur = -1;

        rep(i, 0, n){
            int idx = h[i].second;
            int hv = h[i].first;
            int wv = w[idx].first;

            if(bh != hv) mnws[++cur] = {1000000001, 1000000001}, bh = hv;
            mnws[cur] = min(mnws[cur], {wv, idx+1});
        }

        rep(i, 1, cur){
            mnws[i] = min(mnws[i], mnws[i-1]);
        }

        bh = -1;
        cur = -2;
        rep(i, 0, n){
            int idx = h[i].second;
            int hv = h[i].first;
            int wv = w[idx].first;

            if(bh != hv) cur++, bh = hv;

            if(cur == -1) continue;

            if(wv > mnws[cur].first) ans[idx] = mnws[cur].second;
        }

        rep(i, 0, n){
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}