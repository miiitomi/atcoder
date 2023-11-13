// https://atcoder.jp/contests/abc143/tasks/abc143_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<int> L(N);
    for (int i = 0; i < N; i++) cin >> L[i];
    sort(L.begin(), L.end());
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            int k = distance(L.begin(), lower_bound(L.begin(), L.end(), L[i] + L[j]));
            k--;
            ans += max(0, k - j);
        }
    }
    cout << ans << endl;
}
