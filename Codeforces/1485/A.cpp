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

    int n, q, k;
    cin >> n >> q >> k;

    lli a[n];
    rep(i, 0, n) cin >> a[i];

    lli ll[n];
    lli rr[n];
    mset(0, ll);
    mset(0, rr);
    rep(i, 0, n){
        if(i > 0) ll[i] += a[i] - a[i-1] - 1;
        if(i < n - 1) rr[i] += a[i+1] - a[i] - 1; 
    }

    lli psuml[n+1];
    lli psumr[n+1];
    mset(0, psuml);
    mset(0, psumr);
    rep(i, 0, n){
        psuml[i+1] = psuml[i] + ll[i];
        psumr[i+1] = psumr[i] + rr[i];
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        cout << psuml[r] - psuml[l] + psumr[r-1] - psumr[l-1] + a[l-1] - 1 + k - a[r-1] << '\n';
    }
}