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

int main(){
    fastIO();

    int n;
    cin >> n;

    vector<int> v[n+1];
    int in[n+1];
    int time[n+1];
    int mxTime[n+1];
    mset(0, in);
    mset(0, mxTime);

    rep1(i, 1, n){
        int m;
        cin >> time[i] >> m;
        rep(j, 0, m){
            int k;
            cin >> k;
            v[k].push_back(i);
            in[i]++;
        }
    }

    queue<int> q;
    rep1(i, 1, n){
        if(in[i] == 0) q.push(i), mxTime[i] = time[i];
    }

    int ans = 0;

    while(!q.empty()){
        int vtx = q.front();
        q.pop();

        uMax(ans, mxTime[vtx]);

        rep(i, 0, v[vtx].size()){
            int next = v[vtx][i];
            uMax(mxTime[next], mxTime[vtx] + time[next]);
            if(--in[next] == 0){
                q.push(next);
            }
        }
    }

    cout << ans;
}