#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> maru, batsu;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'o') maru.push_back(i);
        else batsu.push_back(i);
    }
    ll ans = 0LL;
    for (int i = 0; i < N-1; i++) {
        auto iter1 = lower_bound(maru.begin(), maru.end(), i);
        auto iter2 = lower_bound(batsu.begin(), batsu.end(), i);
        if (iter1 != maru.end() && iter2 != batsu.end()) {
            int x = *iter1;
            int y = *iter2;
            ans += N - 1 - max(x, y) + 1;
        }
    }
    cout << ans << endl;
}
