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

int ans[3001];
vector<int> v[3001];
int dfs_visited[3001];
bool bfs_visited[3001];
bool isCycle[3001];

int dfs(int vtx){
    int k = 5000;
    rep(i, 0, v[vtx].size()){
        int next = v[vtx][i];
        if(dfs_visited[next] == 0){
            dfs_visited[next] = dfs_visited[vtx] + 1;
            k = min(k, dfs(next));
        }else if(dfs_visited[next] != dfs_visited[vtx] - 1){
            k = min(dfs_visited[next], k);
        }
    }

    if(k <= dfs_visited[vtx]) isCycle[vtx] = true;
    return k;
}

int main(){
    fastIO();

    int n;
    cin >> n;

    int cnt[n+1];
    mset(0, cnt);

    queue<pair<int, int>> q;
    
    rep(i, 0, n){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs_visited[1] = 1;
    dfs(1);

    rep1(i, 1, n){
        if(isCycle[i]){
            q.push({i, 0});
            bfs_visited[i] = true;
            break;
        }
    }

    while(!q.empty()){
        int vtx = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        if(!isCycle[vtx]) dist++;

        ans[vtx] = dist;

        rep(i, 0, v[vtx].size()){
            int next = v[vtx][i];
            if(bfs_visited[next]) continue;
            bfs_visited[next] = true;
            q.push({next, dist});
        }
    }

    rep1(i, 1, n){
        cout << ans[i] << ' ';
    }
}