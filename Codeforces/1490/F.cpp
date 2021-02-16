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

        sort(a, a + n);

        vector<int> v;
        rep(i, 0, n){
            int cnt = 1;
            while(i + 1 < n && a[i] == a[i+1]) cnt++, i++;
            v.push_back(cnt);
        }

        sort(v.begin(), v.end());

        // v.size 만큼의 유니크한 정수들

        int ans = 1e9;
        int prefix = 0;

        // rep(i, 0, v.size()) cout << v[i] << ' ';
        rep(i, 0, v.size()){
            int k = 1; // v[i]개 있는 숫자들
            int pretmp = 0;
            while(i + 1 < v.size() && v[i] == v[i+1]) pretmp += v[i], i++, k++;
            // prefix 만큼 지움 
            // 지금까지의 정수들 : prefix
            // 구간 1
            int a = prefix;

            // 구간 2
            // pass

            // 구간 3
            int c = n - pretmp - prefix - v[i] - (v.size() - i - 1) * v[i];
            ans = min(ans, a + c);

            // cout4(prefix, pretmp, a, c);

            prefix += pretmp;
            prefix += v[i];
        }

        cout << ans << '\n';
    }
}