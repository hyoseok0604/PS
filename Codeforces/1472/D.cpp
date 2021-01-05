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
        int n;
        cin >> n;

        int a[n];
        rep(i, 0, n) cin >> a[i];

        vector<int> even; // 짝
        vector<int> odd; // 홀
        rep(i, 0, n){
            if(a[i] % 2 == 0) even.push_back(a[i]);
            else odd.push_back(a[i]);
        }

        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());

        lli s1 = 0, s2 = 0;
        int p1 = even.size();
        int p2 = odd.size();
        p1--;
        p2--;
        rep(i, 0, n){
            if(p1 == -1){
                if(i % 2 == 0){

                }else{
                    s2 += odd[p2];
                }
                p2--;
            }else if(p2 == -1){
                if(i % 2 == 0){
                    s1 += even[p1];
                }else{

                }
                p1--;
            }else{
                if(i % 2 == 0){
                    if(even[p1] > odd[p2]){
                        s1 += even[p1];
                        p1--;
                    }else{
                        p2--;
                    }
                }else{
                    if(odd[p2] > even[p1]){
                        s2 += odd[p2];
                        p2--;
                    }else{
                        p1--;
                    }
                }
            }
        }

        if(s1 == s2) cout << "Tie\n";
        else if(s1 > s2) cout << "Alice\n";
        else cout << "Bob\n";
    }
}