#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, P;
    cin >> N >> M >> P;
    N -= M;
    if (N < 0) cout << 0 << endl;
    else cout << (N / P) + 1 << endl;
}
