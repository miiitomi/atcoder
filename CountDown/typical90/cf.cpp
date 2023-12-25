#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    string S;
    cin >> N >> S;
    vector<int> os, xs;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'o') os.push_back(i);
        else xs.push_back(i);
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'o') {
            auto iter = lower_bound(xs.begin(), xs.end(), i);
            if (iter != xs.end()) {
                int j = *iter;
                ans += N - j;
            }
        } else {
            auto iter = lower_bound(os.begin(), os.end(), i);
            if (iter != os.end()) {
                int j = *iter;
                ans += N - j;
            }
        }
    }

    cout << ans << endl;
}
