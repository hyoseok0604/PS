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

    lli x[n+1], p[n+1];
    rep1(i, 1, n) cin >> x[i] >> p[i]; // 입력

    lli psp[n+1];
    psp[0] = 0;
    rep1(i, 1, n) psp[i] = psp[i-1] + p[i]; // 부분합

    lli gap[n+1];
    rep1(i, 1, n) gap[i] = psp[i-1] - x[i]; // 가지고 있던 돈 - i 번째 대회 참가 조건

    lli smxgap[n+1], pmxgap[n+1];
    smxgap[n] = gap[n];
    pmxgap[1] = gap[1];
    rep1(i, 2, n) pmxgap[i] = max(pmxgap[i-1], gap[i]); // 1 ~ i 까지 구간 max
    rep2(i, n-1, 1) smxgap[i] = max(smxgap[i+1], gap[i]); // i ~ n까지 구간 max

    bool flag = false;
    rep1(i, 1, n){ // i번째 대회를 제거했다고 가정
        bool f = true; // true 가능, false 불가능
        if(i > 1){
            if(pmxgap[i-1] > 0) f &= false;
        }

        if(i < n){
            if(smxgap[i+1] - p[i] > 0) f &= false;
        }

        flag |= f;
    }

    if(flag) cout << "Kkeo-eok";
    else cout << "Zzz";
}