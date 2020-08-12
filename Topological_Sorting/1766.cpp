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

    int n, m;
    cin >> n >> m;

    int in[n+1];
    mset(0, in);
    vector<int> v[n+1];

    while(m--){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        in[b]++;
    }

    priority_queue<int> pq;
    rep1(i, 1, n){
        if(!in[i]) pq.push(-i);
    }

    while(!pq.empty()){
        int vtx = -pq.top();
        pq.pop();

        cout << vtx << ' ';

        rep(i, 0, v[vtx].size()){
            int next = v[vtx][i];
            if(--in[next] == 0) pq.push(-next);
        }
    }
}