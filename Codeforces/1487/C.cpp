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

int ans[101][101];

int score[101];

void f1(int n){
    rep(i, 0, n){
        rep(j, i + 1, n){
            ans[i][j] = ((i + j) % 2) ? 1 : -1;
        }
    }
}

void f2(int n){
    rep(i, 0, n){
        rep(j, i + 1, n){
            if(i == j - 1 && i % 2 == 0) continue;
            ans[i][j] = ((i + j) % 2) ? 1 : -1;
        }
    }
}

int main(){
    fastIO();
    
    TC{
        int n;
        cin >> n;

        mset(0, ans);
        
        if(n % 2 == 1){
            f1(n);
        }else{
            f2(n);
        }

        rep(i, 0, n){
            rep(j, i + 1, n){
                cout << ans[i][j] << ' ';
                if(ans[i][j] == 1) score[i] += 3;
                if(ans[i][j] == 0) score[i]++, score[j]++;
                if(ans[i][j] == -1) score[j] += 3;
            }
        }

        // cout << '\n';
        // rep(i, 0, n) cout << score[i] << ' ';
        cout << '\n';

    }
}