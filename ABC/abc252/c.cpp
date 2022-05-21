#include <bits/stdc++.h>
using namespace std;

int f(int N, vector<string> &S, int k) {
    vector<int> V;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            if ((int)(S[i][j] - '0') == k) {
                V.push_back(j);
                break;
            }
        }
    }
    sort(V.begin(), V.end());
    int now = -1;
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (V[i] == now) {
            count++;
            V[i] += 10*count;
        } else {
            now = V[i];
            count = 0;
        }
    }

    return *max_element(V.begin(), V.end());
}

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    int ans = 1e+9;
    for (int k = 0; k < 10; k++) {
        ans = min(ans, f(N, S, k));
    }
    cout << ans << endl;
}
