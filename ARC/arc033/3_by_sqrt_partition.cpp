#include <bits/stdc++.h>
using namespace std;

int N = 200001;
int n = sqrt(N) + 1;
vector<int> A(N, 0);
vector<int> B(n, 0);

bool less_than_k(int k, int a) {
    int count = 0;
    while (a % n != 0) {
        count += A[a-1];
        a--;
    }
    for (int i = 0; i < a/n; i++) {
        count += B[i];
    }
    return (count < k);
}

int query(int k) {
    int left = 0;
    int right = N;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (less_than_k(k, mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    A[left]--;
    B[left/n]--;
    return left;
}

int main() {
    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            if (A[x] == 0) {
                A[x]++;
                B[x/n]++;
            }
        } else {
            cout << query(x) << endl;
        }
    }
}
