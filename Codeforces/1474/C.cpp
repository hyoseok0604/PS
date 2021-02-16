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


int cnt[1000001];

int main(){
    fastIO();

    TC{
        int n;
        cin >> n;

        int a[n*2];
        rep(i, 0, n * 2){
            cin >> a[i];
        }

        sort(a, a + (n * 2));

        int tarPos = n * 2 - 1;
        int tar = a[tarPos];
        bool ansflag = false;
        pair<int, int> ans[n];
        rep(i, 0, n * 2 - 1){
            // count init
            mset(0, cnt);
            rep(j, 0, n * 2){
                cnt[a[j]]++;
            }

            tarPos = n * 2 - 1;
            tar = a[tarPos];

            mset(0, ans);
            int cur = 0;

            cnt[tar]--;
            cnt[a[i]]--;

            ans[cur++] = {tar, a[i]};

            bool flag = true;
            rep(j, 1, n){
                while(cnt[a[tarPos]] == 0) tarPos--;

                cnt[a[tarPos]]--;
                
                if(cnt[tar - a[tarPos]] == 0){
                    flag = false;
                    break;
                }
                cnt[tar - a[tarPos]]--;

                ans[cur++] = {tar-a[tarPos], a[tarPos]};

                tar = a[tarPos];
            }

            if(flag){
                cout << "YES\n";
                cout << ans[0].first + ans[0].second << '\n';
                rep(j, 0, n){
                    cout << ans[j].first << ' ' << ans[j].second << '\n';
                }
                ansflag = true;
                break;
            }
        }

        if(!ansflag) cout << "NO\n";
    }
}