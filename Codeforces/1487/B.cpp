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
        int n, k;
        cin >> n >> k;

        if(n % 2 == 0){
            cout << ((k - 1) % n) + 1 << '\n';
        }else{
            int q = (k - 1) / n % (n / 2);
            int r = (k - 1) % n;

            int s = (1 + (q * 2));

            int t = 0;
            if(r >= n / 2 - q) t++;
            if(r >= n - q - 1) t++;

            r += t;

            cout << (s + r - 1) % n + 1 << '\n';
        }
        
    }
}