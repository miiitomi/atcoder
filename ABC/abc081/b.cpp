#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < N; j++) {
            if (A.at(j) % 2 == 1) {
                cout << i << endl;
                return 0;
            } 
            A.at(j) /= 2;
        }
    }
}