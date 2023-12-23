// https://atcoder.jp/contests/abc177/tasks/abc177_e
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int g = gcd(A[0], A[1]);
    for (int i = 2; i < N; i++) g = gcd(g, A[i]);
    if (g == 1) {
        vector<int> cnt(1e+6 +1, 0);
        for (int a : A) cnt[a]++;
        for (int x = 2; x <= 1e+6; x++) {
            int tmp = 0;
            for (int y = x; y <= 1e+6; y += x) tmp += cnt[y];
            if (tmp >= 2) {
                cout << "setwise coprime" << endl;
                return 0;
            }
        }
        cout << "pairwise coprime" << endl;
    } else {
        cout << "not coprime" << endl;
    }
}
