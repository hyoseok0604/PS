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

        // 1, 2, 3, 4, 5, 6, 7, 8, 9
        // 19, 29, 39, 49, 59, 69, 79, 89
        // 189, 289, 389, 489, 589, 689, 789, 1789

        if(n > 45){
            cout << -1 << '\n';
            continue;
        }
        int k = 9;
        while(n != 0){
            if(n < k){
                cout << n;
                n = 0;
            }else{
                n -= k;
                k--;
            }
        }

        rep1(i, k+1, 9) cout << i;
        cout << '\n';
    }
}