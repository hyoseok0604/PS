#include<bits/stdc++.h>

using namespace std;

#define lli long long
#define TC int TC;cin>>TC;while(TC--)
#define fastIO() ios_base::sync_with_stdio(0),cin.tie(0)
#define uMin(a, b) a = min(a, b);
#define uMax(a, b) a = max(a, b);
#define mset(a, arr) memset(arr, a, sizeof(arr))

int a[5];

int main(){
    fastIO();
    string c = "UNIST";
    int N;
    cin >> N;
    while(N--){
        string s;
        cin >> s;
        for(int i = 0 ; i < 5 ; i++){
            if(s[0] != c[i]) continue;
            for(int j = 0 ; j + i < 5 && j < s.length() ; j++){
                if(s[j] == c[j + i]){
                    if(i == 0) a[j + i]++;
                    else{
                        a[i + j] += a[i - 1];
                        a[i + j] %= 1000000007;
                    }
                }else{
                    break;
                }
            }
        }
    }

    cout << a[4];
}