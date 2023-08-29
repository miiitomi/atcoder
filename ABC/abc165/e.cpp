#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> a, b;
    a.reserve(M);
    b.reserve(M);

    int K = M;
    if (K % 2 == 0) K--;

    int i = 1;
    while (K > 0) {
        a.push_back(i);
        b.push_back(i+K);
        K -= 2;
        i++;
    }

    i = b[0] + 1;
    K = M;
    if (K % 2 == 1) K--;
    while (K > 0) {
        a.push_back(i);
        b.push_back(i+K);
        K -= 2;
        i++;
    }

    for (int i = 0; i < M; i++) {
        cout << a[i] << " " << b[i] << endl;
    }
}
