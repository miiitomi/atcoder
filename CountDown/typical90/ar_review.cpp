#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    deque<int> A;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }

    while (Q--) {
        int t, x, y;
        cin >> t >> x >> y;
        x--;
        y--;
        if (t == 1) swap(A[x], A[y]);
        else if (t == 2) {
            int a = A.back();
            A.pop_back();
            A.push_front(a);
        } else {
            cout << A[x] << endl;
        }
    }
}
