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
#define rep(i, a, b) for(int i = a ; i < b ; i++)
#define repR(i, a, b) for(int i = a ; i > b ; i--)

int check(int n){
    if(n < 100) return 1;

    int before = n % 10, after = n / 10 % 10;
    int gap = before - after;
    n /= 100;

    while(n != 0){
        before = after;
        after = n % 10;
        if(gap != before - after) return 0;
        n /= 10;
    }

    return 1;
}

int main(){
    fastIO();

    int n;
    cin >> n;

    int cnt = 0;
    for(int i = 1 ; i <= n ; i++){
        cnt += check(i);
    }

    cout << cnt;
}