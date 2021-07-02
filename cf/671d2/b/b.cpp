#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        long long n;
        cin >> n;

        int co = 0;

        for (long long i = 1; 1; i += i + 1) {
            long long sa = i * (i + 1) / 2;
            if (sa > n) {
                break;
            }

            n -= sa;
            co++;
        }

        cout << co << endl;
    }
}