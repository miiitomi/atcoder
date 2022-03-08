#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;

    bool exists_zero = false;
    vector<ll> s(N);
    for (int i = 0; i < N; i++) {
        cin >> s[i];
        if (s[i] == 0) exists_zero = true;
    }

    if (exists_zero) {
        cout << N << endl;
        return 0;
    }

    if (K == 0) {
        cout << 0 << endl;
        return 0;
    }

    int start = 0;
    int end = 0;
    ll prod = 1;
    int ans = 0;

    while (true) {
        if (prod <= K) {
            ans = max(ans, end - start);
            if (end == N) break;
            prod *= s[end];
            end++;
        } else {
            prod /= s[start];
            start++;
            if (start == N) break;
        }
    }

    cout << ans << endl;
}
