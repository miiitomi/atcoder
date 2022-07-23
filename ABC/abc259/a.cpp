#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, X, T, D;
    cin >> N >> M >> X >> T >> D;

    int barth = T - (X * D);
    if (M < X) {
        cout << barth + (M * D) << endl;
    } else {
        cout << barth + (X * D) << endl;
    }
}
