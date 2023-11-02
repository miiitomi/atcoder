// https://atcoder.jp/contests/abc228/tasks/abc228_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> P(N, 0), Q(N, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            int p;
            cin >> p;
            P[i] += p;
            Q[i] += p;
        }
    }
    sort(P.begin(), P.end());

    for (int j = 0; j < N; j++) {
        auto iter = lower_bound(P.begin(), P.end(), Q[j] + 301);
        iter--;
        if (distance(iter, P.end()) <= K) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
