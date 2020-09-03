#include<bits/stdc++.h>

using namespace std;

#define lli long long
#define TC int TC;cin>>TC;while(TC--)
#define fastIO() ios_base::sync_with_stdio(0),cin.tie(0)
#define uMin(a, b) a = min(a, b)
#define uMax(a, b) a = max(a, b)
#define mset(a, arr) memset(arr, a, sizeof(arr))

#define rep(i, a, b) for(int i = (a) ; i < (b) ; i++)
#define rep1(i, a, b) for(int i = (a) ; i <= (b) ; i++)
#define rep2(i, a, b) for(int i = (a) ; i >= (b) ; i--)

#define cout1(a) cout << a << '\n'
#define cout2(a, b) cout << a << ' ' << b << '\n'
#define cout3(a, b, c) cout << a << ' ' << b << ' ' << c << '\n'
#define cout4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'

int main(){
    fastIO();
    
    int n, m;
    cin >> n >> m;

    int s[m];
    mset(0, s);

    rep(i, 0, m){
        int c;
        cin >> c;
        rep(j, 0, c){
            int k;
            cin >> k;
            s[i] |= (1 << (k- 1));
        }
    }

    int ans = 1e9;
    rep(i, 1, (1 << m)){
        int tmp = 0;
        rep(j, 0, m){
            if(i & (1 << j)) tmp |= s[j];
        }
        if(tmp == (1 << n) - 1) uMin(ans, __builtin_popcount(i));
    }

    if(ans == 1e9) cout << -1;
    else cout << ans;
}