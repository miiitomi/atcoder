// https://atcoder.jp/contests/abc164/tasks/abc164_d
#include <bits/stdc++.h>
using namespace std;
const int MOD = 2019;
typedef long long ll;

int main() {
    string S;
    cin >> S;

    ll ans = 0;
    vector<ll> cnt(2019, 0);
    cnt[0] = 1;
    int p = 1;
    int y = 0;
    for (int i = (int)S.size()-1; i >= 0; i--) {
        int x = S[i] - '0';
        y = (y + p*x) % 2019;
        ans += cnt[y];
        cnt[y]++;
        p = (p * 10) % 2019;
    }
    cout << ans << endl;
}
