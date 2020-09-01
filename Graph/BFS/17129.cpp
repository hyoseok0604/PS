#include<bits/stdc++.h>

using namespace std;

#define lli long long
#define TC int TC;cin>>TC;while(TC--)
#define fastIO() ios_base::sync_with_stdio(0),cin.tie(0)
#define uMin(a, b) a = min(a, b)
#define uMax(a, b) a = max(a, b)
#define mset(a, arr) memset(arr, a, sizeof(arr))

#define rep(i, a, b) for(int i = (a) ; i < (b) ; i++)
#define rep1(i, a, b) for(int i = (a) ; i <= (b) ; i++)
#define rep2(i, a, b) for(int i = (a) ; i >= (b) ; i--)

#define cout1(a) cout << a << '\n'
#define cout2(a, b) cout << a << ' ' << b << '\n'
#define cout3(a, b, c) cout << a << ' ' << b << ' ' << c << '\n'
#define cout4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

int main(){
    fastIO();

    int n, m;
    cin >> n >> m;

    int y0, x0;

    int arr[n][m];
    rep(i, 0, n){
        rep(j, 0, m){
            char c;
            cin >> c;
            arr[i][j] = c - '0';
            if(arr[i][j] == 2) y0 = i, x0 = j, arr[i][j] = 0;
        }
    }

    int ans = 1e9;
    queue<pair<int, int>> q;
    q.push({y0, x0});

    int dist[n][m];
    mset(-1, dist);

    dist[y0][x0] = 0;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if(arr[y][x] != 0) uMin(ans, dist[y][x]);

        rep(i, 0, 4){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(dist[ny][nx] != -1 || arr[ny][nx] == 1 || ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});
        }
    }

    if(ans == 1e9){
        cout << "NIE";
    }else{
        cout << "TAK\n" << ans;
    }
}