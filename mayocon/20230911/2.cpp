// https://atcoder.jp/contests/abc214/tasks/abc214_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> S(N), T(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    for (int i = 0; i < N; i++) cin >> T[i];

    int s = distance(T.begin(), min_element(T.begin(), T.end()));
    vector<ll> ans(N, 1e+18);
    ans[s] = T[s];
    int i = (s + 1) % N;
    while (s != i) {
        ans[i] = min(T[i], ans[(i - 1 + N) % N] + S[(i - 1 + N) % N]);
        i = (i + 1) % N;
    }

    for (int x : ans) cout << x << endl;
}
