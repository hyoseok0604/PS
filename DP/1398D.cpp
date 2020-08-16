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

vector<int> R(200);
vector<int> G(200);
vector<int> B(200);

int cr, cg, cb;

int ans = 0;

lli a[201][201][201];

lli f(int r, int g, int b){
    if((r == cr && g == cg) || (r == cr && b == cb) || (g == cg && b == cb)){
        return 0;
    }
    
    if(a[r][g][b] != -1) return a[r][g][b];

    lli res = 0;
    if(r != cr && g != cg) uMax(res, R[r] * G[g] + f(r + 1, g + 1, b));
    if(r != cr && b != cb) uMax(res, B[b] * R[r] + f(r + 1, g, b + 1));
    if(g != cg && b != cb) uMax(res, G[g] * B[b] + f(r, g + 1, b + 1));

    return a[r][g][b] = res;
}

int main(){
    fastIO();

    cin >> cr >> cg >> cb;

    rep(i, 0, cr){
        cin >> R[i];
    }
    rep(i, 0, cg){
        cin >> G[i];
    }
    rep(i, 0, cb){
        cin >> B[i];
    }

    mset(-1, a);

    sort(R.begin(), R.end(), greater<int>());
    sort(G.begin(), G.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    cout << f(0, 0, 0);
}