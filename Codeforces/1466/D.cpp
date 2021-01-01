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

        int w[n+1];
        vector<pair<int, int>> wsort;
        rep1(i, 1, n){
            cin >> w[i];
            wsort.push_back({w[i], i});
        }

        sort(wsort.begin(), wsort.end());

        int cnt[n+1];
        mset(-1, cnt);

        rep(i, 0, n-1){
            int a, b;
            cin >> a >> b;
            cnt[a]++;
            cnt[b]++;
        }

        lli ans = 0;
        rep1(i, 1, n) ans += w[i];

        cout << ans << ' ';
        rep2(i, wsort.size()-1, 0){
            rep(j, 0, cnt[wsort[i].second]){
                ans += wsort[i].first;
                cout << ans << ' ';
            }
        }

        cout << '\n';
    }
}