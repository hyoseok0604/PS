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
#define print(a) cout << (a)
#define println(a) cout << (a) << '\n'

int main(){
    fastIO();

    string s;
    cin >> s;

    string ans = "";

    bool java = false;
    bool cpp = false;
    bool err = false;

    if(s[0] < 'a' || s[0] > 'z') err = true;

    for(int i = 1 ; i < s.length() ; i++){
        if(s[i] == '_'){
            if(s[i-1] == '_' || i == s.length() - 1) err = true;
            cpp = true;
        }
        if(s[i] >= 'A' && s[i] <= 'Z') java = true;
    }

    if(err || (java && cpp)){
        return cout << "Error!", 0;
    }

    if(java){
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] >= 'A' && s[i] <= 'Z') cout << '_' << (char)(s[i] - 'A' + 'a');
            else cout << s[i];
        }
    }else if(!cpp){
        cout << s;
    }else{
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '_') cout << (char)(s[++i] - 'a' + 'A');
            else cout << s[i];
        }
    }
}