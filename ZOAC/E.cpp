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

    int n;
    cin >> n;

    vector<int> pos(n*2+2);
    pair<int, int> a[n];
    rep(i, 0, n){
        cin >> a[i].first >> a[i].second;
        pos[i * 2] = a[i].first;
        pos[i * 2 + 1] = a[i].second;
    }

    pos[n*2] = 0;
    pos[n*2+1] = 2100000000;

    sort(pos.begin(), pos.end());

    pos.erase(unique(pos.begin(), pos.end()), pos.end());

    int timestamp[pos.size() + 2];
    mset(0, timestamp);

    rep(i, 0, n){
        int s = lower_bound(pos.begin(), pos.end(), a[i].first) - pos.begin();
        int e = lower_bound(pos.begin(), pos.end(), a[i].second) - pos.begin();
        
        timestamp[s]++;
        timestamp[e]--;
    }

    int ans = timestamp[0];
    int anst = 0;
    int anse = -1;
    rep(i, 1, pos.size()){
        timestamp[i] += timestamp[i-1];
        if(timestamp[i] > ans){
            ans = timestamp[i], anst = i;
        }else if(timestamp[i] < ans && anse < anst) anse = i;
    }
    cout << ans << '\n';
    cout << pos[anst] << ' ' << pos[anse];
}