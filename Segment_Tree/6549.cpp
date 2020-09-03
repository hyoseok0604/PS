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

int tree[400000];
int size;
lli arr[100001];

void build(){
    rep2(i, size, 1){
        lli a = arr[tree[i*2]];
        lli b = arr[tree[i*2+1]];
        tree[i] = min(a, b) == a ? tree[i*2] : tree[i*2+1];
    }
}

int query(int L, int R, int vtx, int nL, int nR){
    if(nL > R || nR < L) return 0;
    if(L <= nL && nR <= R) return tree[vtx];

    int mid = (nL + nR) / 2;

    int q1 = query(L, R, vtx * 2, nL, mid);
    int q2 = query(L, R, vtx * 2 + 1, mid + 1, nR);
    
    return min(arr[q1], arr[q2]) == arr[q1] ? q1 : q2;
}

lli solve(int l, int r){
    if(l > r) return 0;

    int p = query(l, r, 1, 1, size + 1);

    lli ans = arr[p] * (r - l + 1);

    ans = max(ans, solve(l, p - 1));
    ans = max(ans, solve(p + 1, r));

    return ans;
}

int main(){
    fastIO();

    while(1){
        int n;
        cin >> n;

        if(n == 0) break;

        size = 0;
        arr[0] = 1e9+1;

        int lv = 1;
        while(lv < n){
            size += lv;
            lv *= 2;
        }

        rep1(i, 1, n){
            cin >> arr[i];
            tree[size + i] = i;
        }

        build();

        cout << solve(1, n) << '\n';
    }
}