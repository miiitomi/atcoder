#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    string S;
    cin >> N >> S;
    vector<ll> cnt(26, 0);

    for (int c = 'a'; c <= 'z'; c++) {
        ll tmp = 0;
        for (int i = 0; i < N; i++) {
            if (S[i] == c) tmp++;
            else {
                cnt[c - 'a'] = max(cnt[c - 'a'], tmp);
                tmp = 0;
            }
        }
        cnt[c - 'a'] = max(cnt[c - 'a'], tmp);
    }

    ll ans = 0;
    for (int i = 0; i < 26; i++) ans += cnt[i];
    cout << ans << endl;
}
