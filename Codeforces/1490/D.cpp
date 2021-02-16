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

int a[101];
int pos[101];
int d[101];

void f(int l, int r, int k){
    int mx = 0;
    if(r < l) return;
    rep1(i, l, r){
        mx = max(mx, a[i]);
    }

    d[pos[mx]] = k;

    f(l, pos[mx]-1, k + 1), f(pos[mx]+1, r, k + 1);
}

int main(){
    fastIO();

    TC{
        int n;
        cin >> n;

        rep(i, 0, n) cin >> a[i];

        rep(i, 0, n) pos[a[i]] = i;

        f(0, n-1, 0);

        rep(i, 0, n) cout << d[i] << ' ';
        cout << '\n';
    }
}