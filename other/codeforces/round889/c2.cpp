#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> B = A;
    int min_i = distance(A.begin(), min_element(A.begin(), A.end()));
    int min_value = A[min_i];
    int max_i = distance(A.begin(), max_element(A.begin(), A.end()));
    int max_value = A[max_i];

    vector<pair<int,int>> V, W;
    V.reserve(50);
    W.reserve(50);

    if (max_value == min_value) {
        cout << 0 << endl;
        return;
    }

    bool max_ok = false;
    bool min_ok = false;

    if (max_value > 0) {
        max_ok = true;
        while (abs(A[max_i]) < abs(A[min_i])) {
            A[max_i] *= 2;
            V.push_back(make_pair(max_i, max_i));
        }
        for (int i = 0; i < N; i++) {
            if (A[i] < 0) {
                V.push_back(make_pair(i, max_i));
                A[i] += A[max_i];
            }
        }
        for (int i = 0; i < N-1; i++) {
            if (A[i] > A[i+1]) {
                A[i+1] += A[i];
                V.push_back(make_pair(i+1, i));
            }
        }
    }

    if (min_value < 0) {
        min_ok = true;
        while (abs(B[min_i]) < abs(B[max_i])) {
            B[min_i] *= 2;
            W.push_back(make_pair(min_i, min_i));
        }
        for (int i = 0; i < N; i++) {
            if (B[i] > 0) {
                B[i] += B[min_i];
                W.push_back(make_pair(i, min_i));
            }
        }
        for (int i = N-1; i >= 1; i--) {
            if (B[i-1] > B[i]) {
                B[i-1] += B[i];
                W.push_back(make_pair(i-1, i));
            }
        }
    }

    if ((max_ok && min_ok && V.size() <= W.size()) || !min_ok) {
        cout << V.size() << endl;
        for (auto v : V) cout << v.first+1 << " " << v.second+1 << endl;
    } else {
        cout << W.size() << endl;
        for (auto w : W) cout << w.first+1 << " " << w.second+1 << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
