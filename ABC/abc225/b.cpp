#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> V(N, 0);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a]++;
        V[b]++;
    }
    int node_1 = 0;
    int node_N_1 = 0;
    for (int i = 0; i < N; i++) {
        if (V[i] == 1) node_1++;
        if (V[i] == N-1) node_N_1++;
    }
    if (node_1 == N-1 && node_N_1 == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
