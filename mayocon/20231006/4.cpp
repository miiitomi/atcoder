// https://atcoder.jp/contests/abc178/tasks/abc178_e
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> z(N, 0), w(N, 0);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        z[i] = x + y;
        w[i] = x - y;
    }

    int a = *max_element(z.begin(), z.end()) - *min_element(z.begin(), z.end());
    int b = *max_element(w.begin(), w.end()) - *min_element(w.begin(), w.end());

    cout << max(a, b) << endl;
}
