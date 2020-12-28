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

int main(){
    fastIO();

    lli n, k;
    cin >> n >> k;

    lli s = 1;
    lli e = n / 2 + 1;

    lli ans = -1;

    while(s <= e){
        lli mid = (s + e) / 2;

        lli sum = mid * (2 * (n + 1) + (mid - 1) * (-2)) / 2;

        if(sum == k){
            ans = mid;
            break;
        }else if(sum < k){
            s = mid + 1;
        }else if(sum > k){
            e = mid - 1;
        }
    }

    if(ans != -1) cout << "YES";
    else cout << "NO";
}