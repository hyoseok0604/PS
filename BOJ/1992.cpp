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

char a[64][64];

string solve(int y, int x, int len){
    bool flag = true;
    rep(i, y, y + len){
        rep(j, x, x + len){
            flag &= a[i][j] == a[y][x];
        }
    }

    if(flag) return string({a[y][x]});
    else{
        return "(" + solve(y, x, len / 2)
        + solve(y, x + len / 2, len / 2)
        + solve(y + len / 2, x, len / 2)
        + solve(y + len / 2, x + len / 2, len / 2) + ")";
    }
}

int main(){
    fastIO();

    int n;
    cin >> n;

    rep(i, 0, n){
        rep(j, 0, n){
            cin >> a[i][j];
        }
    }

    cout << solve(0, 0, n);
}