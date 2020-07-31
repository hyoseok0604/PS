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
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0 ; i < n ; i++){
            cin >> arr[i];
        }

        sort(arr, arr + n);

        int ans = 1;
        for(int i = 0 ; i < n ; i++){
            if(arr[i] <= i + 1) ans = i + 2;
        }
        cout << ans << '\n';
    }
}