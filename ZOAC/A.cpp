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

char k[3][10] = {
    {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
    {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ' '},
    {'z', 'x', 'c', 'v', 'b', 'n', 'm', ' ', ' ', ' '}
};

bool isL(int x, int y){
    if(x == 2) return y <= 3;
    else return y <= 4;
}

bool isL(pair<int, int> p){
    return isL(p.first, p.second);
}

pair<int, int> f(char c){
    rep(i, 0, 3){
        rep(j, 0, 10){
            if(c == k[i][j]) return {i, j};
        }
    }
}

int main(){
    fastIO();

    char l, r;
    cin >> l >> r;
    string s;
    cin >> s;

    pair<int, int> cl = f(l);
    pair<int, int> cr = f(r);

    lli ans = 0;
    rep(i, 0, s.length()){
        pair<int, int> dest = f(s[i]);

        if(isL(dest)){
            ans += abs(cl.first - dest.first);
            ans += abs(cl.second - dest.second);
            ans++;
            cl = dest;
        }else{
            ans += abs(cr.first - dest.first);
            ans += abs(cr.second - dest.second);
            ans++;
            cr = dest;
        }
    }

    cout << ans;
}