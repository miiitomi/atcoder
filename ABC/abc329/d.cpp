#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; i++) cin >> A[i];

    vector<int> cnt(N+1, 0);
    int max_v = 0;
    int max_id = 1e+9;

    for (int i = 0; i < M; i++) {
        int a = A[i];
        cnt[a]++;
        if (cnt[a] > max_v) {
            max_v = cnt[a];
            max_id = a;
        } else if (cnt[a] == max_v) {
            max_id = min(max_id, a);
        }
        cout << max_id << endl;
    }
}
