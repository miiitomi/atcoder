#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N), cnt(N+1, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] <= N) cnt[A[i]]++;
    }
    set<int> no;
    for (int x = 0; x <= N; x++) if (cnt[x] == 0) no.insert(x);

    for (int q = 0; q < Q; q++) {
        int i, x;
        cin >> i >> x;
        i--;

        if (A[i] <= N) {
            cnt[A[i]]--;
            if (cnt[A[i]] == 0) no.insert(A[i]);
        }

        A[i] = x;
        if (x <= N) {
            cnt[x]++;
            if (cnt[x] == 1) no.erase(x);
        }

        cout << *no.begin() << endl;
    }
}
