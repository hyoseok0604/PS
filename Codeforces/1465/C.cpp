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

int xy[100005];
bool visited[100005];

int dfs(int vtx){
    visited[vtx] = true;
    if(!visited[xy[vtx]] && xy[vtx] != 0) return dfs(xy[vtx]) + 1;
    return 1;
}

int main(){
    fastIO();

    TC{
        mset(0, xy);
        mset(0, visited);
        
        int n, m;
        cin >> n >> m;

        rep(i, 0, m){
            int x, y;
            cin >> x >> y;

            if(x == y) continue;

            xy[x] = y;
        }

        int ans = 0;
        rep1(i, 1, n){
            if(xy[i] == 0 || visited[i]) continue;

            int cnt = 0;
            int now = i;
            while(xy[now] != 0 && !visited[now]){
                visited[now] = true;
                now = xy[now];
                cnt++;
            }
            ans += cnt;
            if(now == i) ans++;
        }
        cout << ans << '\n';
    }
}