#include<bits/stdc++.h>

using namespace std;

#define lli long long
#define TC int TC;cin>>TC;while(TC--)
#define fastIO() ios_base::sync_with_stdio(0),cin.tie(0)
#define uMin(a, b) a = min(a, b);
#define uMax(a, b) a = max(a, b);
#define mset(a, arr) memset(arr, a, sizeof(arr))

int main(){
    fastIO();

    TC{
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        lli a = x2 - x1;
        lli b = y2 - y1;

        cout << 1 + a * b << '\n';
    }
}