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

    bool broken[10];
    mset(0, broken);

    rep(i, 0, m){
        int k;
        cin >> k;
        broken[k] = true;
    }

    int ans = 1e9;
    rep1(i, 0, 1000000){
        if(i == 100) ans = min(abs(n - i), ans);
        bool flag = false;
        int tmp = i;
        int cnt = 0;
        if(tmp == 0){
            cnt = 1;
            if(broken[0] == true) continue;
        }
        while(tmp > 0){
            flag |= broken[tmp%10];
            tmp /= 10;
            cnt++;
        }

        if(!flag){
            ans = min(ans, abs(n - i) + cnt);
        }
    }

    cout << ans;
}