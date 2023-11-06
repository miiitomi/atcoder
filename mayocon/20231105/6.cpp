// https://atcoder.jp/contests/abc165/tasks/abc165_e
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> a(M), b(M);
    vector<int> v, w;
    for (int i = M; i >= 1; i--) {
        if (i & 1) v.push_back(i);
        else w.push_back(i);
    }

    int n = 1;
    for (int i = 0; i < (int)v.size(); i++) {
        a[i] = n;
        b[i] = n + v[i];
        n++;
    }
    n = 1 + 2*(int)v.size();
    for (int i = 0; i < w.size(); i++) {
        a[(int)v.size() + i] = n;
        b[(int)v.size() + i] = n+w[i];
        n++;
    }

    for (int i = 0; i < M; i++) {
        cout << a[i] << " " << b[i] << endl;
    }
}
