#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> V(N, 0);

    for (int i = 0; i < Q; i++) {
        int k, x;
        cin >> k >> x;
        x--;

        if (k == 1) {
            V[x]++;
        } else if (k == 2) {
            V[x] += 2;
        } else {
            if (V[x] >= 2) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}
