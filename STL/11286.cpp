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

    priority_queue<pair<int, int>> pq;
    
    rep(i, 0, n){
        int q;
        cin >> q;
        if(q == 0){
            if(pq.empty()) cout << "0\n";
            else cout << -pq.top().first * -1 * pq.top().second << '\n', pq.pop();
        }else{
            if(q > 0) pq.push({-q, -1});
            else pq.push({q, 1});
        }
    }
}
