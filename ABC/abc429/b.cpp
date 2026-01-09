#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, sum = 0;
    cin >> N >> M;
    vector<int> A(N);
    for (int &a: A) {
        cin >> a;
        sum += a;
    }
    for (int &a: A) {
        if (sum-a == M) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}
