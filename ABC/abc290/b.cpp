#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    string T = "";

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'o' && count < K) {
            T.push_back('o');
            count++;
        } else {
            T.push_back('x');
        }
    }

    cout << T << endl;
}
