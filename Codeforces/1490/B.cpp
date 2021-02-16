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

        int a[n];
        rep(i, 0, n) cin >> a[i];
        
        int c[3];
        mset(0, c);
        rep(i, 0, n) c[a[i] % 3]++;

        int tar = n / 3;

        lli ans = 1e16;
        rep(i, 0, 3){
            lli tmp = 0;

            int x = c[i%3];
            int y = c[(i+1)%3];
            int z = c[(i+2)%3];

            if(x > tar) tmp += x - tar, y += x - tar, x = tar;
            if(y > tar) tmp += y - tar, z += y - tar, y = tar;
            if(z > tar) tmp += z - tar, x += z - tar, z = tar;
            if(x > tar) tmp += x - tar, y += x - tar, x = tar;
            if(y > tar) tmp += y - tar, z += y - tar, y = tar;

            ans = min(ans, tmp);
        }
        cout << ans << '\n';
    }
}