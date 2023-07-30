#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int count = 0;
    bool is_new = true;
    bool left_zero, has_two;

    for (int i = 0; i < N; i++) {
        int a = A[i];
        if (is_new) {
            is_new = false;
            has_two = false;
            left_zero = (a == 0);
            continue;
        }

        if (a == 0) {
            if (!left_zero || has_two) {
                count++;
                is_new = true;
            } else {
                count++;
                left_zero = true;
                has_two = false;
            }
        } else if (a == 2) {
            has_two = 2;
        }
    }

    if (!is_new) count++;

    cout << count << endl;
}
