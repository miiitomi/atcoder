#include <bits/stdc++.h>
using namespace std;

void rec(vector<vector<int>> &G, int v, vector<int> &color) {
    for (int w : G[v]) {
        if (color[w] != 0) continue;
        color[w] = - color[v];
        rec(G, w, color);
    }
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> color(N, 0);
    color[0] = 1;
    rec(G, 0, color);

    int one = 0;
    for (int i = 0; i < N; i++) {
        if (color[i] == 1) one++;
    }
    if (one >= N/2) {
        int counter = 0;
        for (int i = 0; i < N; i++) {
            if (color[i] == 1) {
                cout << i + 1 << " ";
                counter++;
                if (counter >= N/2) {
                    cout << endl;
                    return 0;
                }
            }
        }
    } else {
        int counter = 0;
        for (int i = 0; i < N; i++) {
            if (color[i] == -1) {
                cout << i + 1 << " ";
                counter++;
                if (counter >= N/2) {
                    cout << endl;
                    return 0;
                }
            }
        }
    }
}
