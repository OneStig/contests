#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long first, second;
    cin >> first >> second;

    int steps = 0;
    while (first > second) {
        if (first % 2 == 0) {
            first /= 2;
            steps++;
        }
        else {
            first++;
            steps++;
        }
    }

    if (first == second) {
        cout << steps << endl;
        return;
    }

    while (second > first) {
        if (second % 2 == 0) {
            if (second / 2 >= first) {
                second /= 2;
                steps++;
            }
            else {
                break;
            }
        }
        else {
            second--;
            steps++;
        }
    }

    while (first > second) {
        if (first % 2 == 0) {
            if (first / 2 >= second) {
                first /= 2;
                steps++;
            }
            else {
                break;
            }
        } else {
            steps++;
            first--;
        }
        
    }

    steps += abs(first - second);

    cout << steps << endl;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        solve();
    } 
}