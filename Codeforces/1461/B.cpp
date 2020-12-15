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

int dy[3] = {1, 1, 1};
int dx[3] = {-1, 0, 1};

int main(){
    fastIO();

    TC{
        int n, m;
        cin >> n >> m;

        bool a[n][m];
        mset(0, a);

        rep(i, 0, n){
            rep(j, 0, m){
                char c;
                cin >> c;
                a[i][j] = c == '*';
            }
        }

        int ans[n][m];
        mset(0, ans);
        rep2(i, n-1, 0){
            rep(j, 0, m){
                if(!a[i][j]) continue;
                ans[i][j]++;
                int tmp = 0;
                int mn = 1e9;
                rep(k, 0, 3){
                    int ny = i + dy[k];
                    int nx = j + dx[k];

                    if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                    if(a[ny][nx]) tmp++, mn = min(ans[ny][nx], mn);
                }
                if(tmp == 3) ans[i][j] += mn;
            }
        }

        int k = 0;
        rep(i, 0, n){
            rep(j, 0, m){
                k += ans[i][j];
            }
        }

        cout << k << '\n';
    }
}