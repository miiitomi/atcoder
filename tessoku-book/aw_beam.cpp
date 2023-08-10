#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct State {
    int score;
    vector<int> X;
    char LastMove;
    int LastPos;
};

bool cmp(const State &a, const State &b) {
    return a.score > b.score;
}

const int WIDTH = 1000;
const int N = 20;
int T;
vector<vector<int> > P;
vector<int> NumState;
vector<vector<State> > Beam;
vector<char> Answer;

void BeamSearch() {
    NumState[0] = 1;
    Beam[0][0].score;
    Beam[0][0].X.resize(N);
    for (int i = 0; i < N; i++) Beam[0][0].X[i] = 0;

    for (int i = 1; i <= T; i++) {
        vector<State> Candidates;
        for (int j = 0; j < NumState[i-1]; j++) {
            State A = Beam[i-1][j];
            A.LastMove = 'A';
            A.LastPos = j;
            for (int k = 0; k < 3; k++) A.X[P[i-1][k]]++;
            for (int k = 0; k < N; k++) {
                if (A.X[k] == 0) A.score++;
            }
            Candidates.push_back(A);
            State B = Beam[i-1][j];
            B.LastMove = 'B';
            B.LastPos = j;
            for (int k = 0; k < 3; k++) B.X[P[i-1][k]]--;
            for (int k = 0; k < N; k++) {
                if (B.X[k] == 0) B.score++;
            }
            Candidates.push_back(B);
        }
        sort(Candidates.begin(), Candidates.end(), cmp);
        NumState[i] = min(WIDTH, (int)Candidates.size());
        for (int j = 0; j < NumState[i]; j++) Beam[i][j] = Candidates[j];
    }
}

int main() {
    cin >> T;
    P.assign(T, vector<int>(3));
    NumState.resize(T+1);
    Beam.assign(T+1, vector<State>(WIDTH));
    Answer.resize(T);
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> P[i][j];
            P[i][j]--;
        }
    }

    BeamSearch();

    int CurrentPlace = 0;
    for (int i = T; i >= 1; i--) {
        Answer[i-1] = Beam[i][CurrentPlace].LastMove;
        CurrentPlace = Beam[i][CurrentPlace].LastPos;
    }

    for (char a : Answer) cout << a << endl;
    // vector<int> A(20, 0);
    // int last_score = 0;
    // for (int i = 0; i < T; i++) {
    //     if (Answer[i] == 'A') {
    //         for (int k = 0; k < 3; k++) A[P[i][k]]++;
    //     } else {
    //         for (int k = 0; k < 3; k++) A[P[i][k]]--;
    //     }
    //     for (int j = 0; j < N; j++) {
    //         if (A[j] == 0) last_score++;
    //     }
    // }
    // cout << last_score << endl;
}
