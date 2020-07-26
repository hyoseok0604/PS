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
    
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    for(int x = -999 ; x <= 999 ; x++){
        for(int y = -999; y <= 999 ; y++){
            if(a * x + b * y == c && d * x + e * y == f)
                return cout << x << " " << y, 0;
        }
    }
}