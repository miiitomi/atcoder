// https://atcoder.jp/contests/abc268/tasks/abc268_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> c(N, 0);
    for (int p = 0; p < N; p++) {
        int q;
        cin >> q;
        int k;
        if (q >= p) k = q - p;
        else k = q - p + N;

        for (int s = -1; s <= 1; s++) c[(k + s + N) % N]++;
    }

    cout << *max_element(c.begin(), c.end()) << endl;
}
