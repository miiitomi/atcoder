#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> V(N);
    map<int, int> M;
    for (int i = 0; i < N; i++) {
        V[i] = i+1;
        M[i+1] = i;
    }

    for (int q = 0; q < Q; q++) {
        int x;
        cin >> x;

        int pos_x = M[x];
        int pos_y = pos_x + 1;
        if (pos_y == N) {
            pos_y -= 2;
        }
        int y = V[pos_y];

        swap(M[x], M[y]);
        swap(V[pos_x], V[pos_y]);
    }

    for (int i = 0; i < N; i++) {
        cout << V[i];
        if (i < N-1) cout << " ";
        else cout << endl;
    }
}
