// https://atcoder.jp/contests/abc228/tasks/abc228_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> P(N, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            int a;
            cin >> a;
            P[i] += a;
        }
    }
    vector<int> Q = P;
    sort(Q.begin(), Q.end());

    for (int i = 0; i < N; i++) {
        int p = P[i] + 300;
        int cnt = distance(lower_bound(Q.begin(), Q.end(), p+1), Q.end());
        if (cnt <= K-1) cout << "Yes\n";
        else cout << "No\n";
    }
}
