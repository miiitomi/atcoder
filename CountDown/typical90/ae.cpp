#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g(51, vector<int>(1276, 0));

int main() {
    for (int w = 0; w <= 50; w++) {
        for (int b = 0; b <= 1275; b++) {
            if (w == 0 && b <= 1) continue;
            vector<bool> c(1000, true);
            if (w > 0 && b + w-1 <= 1275) c[g[w-1][b+w]] = false;
            for (int k = 1; k <= b/2; k++) c[g[w][b-k]] = false;
            for (int x = 0; x < 1000; x++) {
                if (c[x]) {
                    g[w][b] = x;
                    break;
                }
            }        
        }
    }

    int N, x=0;
    cin >> N;
    vector<int> W(N), B(N);
    for (int i = 0; i < N; i++) cin >> W[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    for (int i = 0; i < N; i++) x ^= g[W[i]][B[i]];

    if (x == 0) cout << "Second" << endl;
    else cout << "First" << endl;
}
