#include<bits/stdc++.h>

using namespace std;

#define lli long long
#define TC int TC;cin>>TC;while(TC--)
#define fastIO() ios_base::sync_with_stdio(0),cin.tie(0)
#define uMin(a, b) a = min(a, b);
#define uMax(a, b) a = max(a, b);
#define mset(a, arr) memset(arr, a, sizeof(arr))

uint32_t tree[400000];
int size;

void make_tree(){
    for(int i = size ; i >= 1 ; i--){
        tree[i] = tree[i * 2] | tree[i * 2 + 1];
    }
}

void update(int vtx, uint32_t value){
    vtx += size;
    tree[vtx] = value;

    while(vtx > 1){
        vtx /= 2;
        tree[vtx] = tree[vtx * 2] | tree[vtx * 2 + 1];
    }
}

uint32_t get(int L, int R, int vtx, int nL, int nR){
    if(nL > R || nR < L) return 0;
    if(L <= nL && nR <= R) return tree[vtx];

    int mid = (nL + nR) / 2;
    return get(L, R, vtx * 2, nL, mid) | get(L, R, vtx * 2 + 1, mid + 1, nR);
}

int main(){
    fastIO();

    string s;
    cin >> s;

    int n = s.length();
    int lv = 1;
    while(lv < n){
        size += lv;
        lv *= 2;
    }

    for(int i = 1 ; i <= n ; i++){
        tree[size + i] = 1 << (s[i-1] - 'a');
    }

    make_tree();

    int m;
    cin >> m;
    while(m--){
        int q;
        cin >> q;
        if(q == 1){
            int p;
            char c;
            cin >> p >> c;
            update(p, 1 << (c - 'a'));
        }else{
            int l, r;
            cin >> l >> r;
            cout << __builtin_popcount(get(l, r, 1, 1, size + 1)) << '\n';
        }
    }
}