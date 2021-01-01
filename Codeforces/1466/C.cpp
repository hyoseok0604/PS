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

#define cout1(a) cout << a << '\n'
#define cout2(a, b) cout << a << ' ' << b << '\n'
#define cout3(a, b, c) cout << a << ' ' << b << ' ' << c << '\n'
#define cout4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'

int main(){
    fastIO();

    TC{
        string s;
        cin >> s;

        int ans = 0;
        rep(i, 0, s.length()){
            if((i + 1 < s.length() && s[i] == s[i+1])){
                char c = 'a';
                while((i - 1 >= 0 && s[i+2] == c) || (i < s.length() && s[i] == c) || (i + 1 < s.length() && s[i+1] == c) ||
                    (i + 2 < s.length() && s[i+2] == c) || (i + 3 < s.length() && s[i+3] == c)) c++;
                s[i+1] = c;
                ans++;
            }
            if((i + 2 < s.length() && s[i] == s[i+2])){
                char c = 'a';
                while((i < s.length() && s[i] == c) || (i + 1 < s.length() && s[i+1] == c) ||
                    (i + 2 < s.length() && s[i+2] == c) || (i + 3 < s.length() && s[i+3] == c) || (i + 4 < s.length() && s[i+4] == c)) c++;
                s[i+2] = c;
                ans++;
            }
        }
        cout << ans << '\n';
    }
}