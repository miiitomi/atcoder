#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int min_i = distance(A.begin(), min_element(A.begin(), A.end()));
    int min_value = A[min_i];
    int max_i = distance(A.begin(), max_element(A.begin(), A.end()));
    int max_value = A[max_i];

    vector<pair<int, int>> V;
    V.reserve(50);

    if (abs(max_value) > abs(min_value) || (abs(max_value) == abs(min_value) && max_value != min_value)) {
        for (int i = 0; i < N; i++) {
            if (i != max_i) {
                V.push_back(make_pair(i, max_i));
                A[i] += max_value;
            }
        }
        for (int i = 0; i < N-1; i++) {
            V.push_back(make_pair(i+1, i));
            A[i+1] += A[i];
        }
    } else if (abs(max_value) < abs(min_value)) {
        for (int i = 0; i < N; i++) {
            if (i != min_i) {
                V.push_back(make_pair(i, min_i));
                A[i] += min_value;
            }
        }
        for (int i = N-1; i > 0; i--) {
            V.push_back(make_pair(i-1, i));
            A[i-1] += A[i];
        }
    }

    cout << (int)V.size() << endl;
    for (auto v : V) {
        cout << v.first+1 << " " << v.second+1 << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
