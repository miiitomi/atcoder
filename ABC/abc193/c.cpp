#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;
    set<int64_t> S;

    for (int64_t i = 2; i*i <= N; i++) {
        for (int64_t j = 2; pow(i, j) <= N; j++) {
            S.insert(pow(i, j));
        }
    }
    cout << N - S.size() << endl;
}