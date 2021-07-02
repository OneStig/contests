#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fcin("test.in");

int main()
{
    int t;
    fcin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        int f;
        vector<int> srt;
        fcin >> n;

        for (int j = 0; j < n; j++)
        {
            fcin >> f;
            srt.push_back(f);
        }

        sort(srt.begin(), srt.end());

        int exp = 0; 
        int sol = 0;
        int hol = 2;

        for (auto i = srt.begin(); i != srt.end(); i++) {

            if (hol == 0) {
                break;
            }

            if (hol == 1 && *i == exp) {
                exp++;
                continue;
            }

            if (*i > exp) {

                if (hol == 2) {
                    sol = exp * 2;
                    hol = 0;
                    break;
                }

                if (hol == 1) {
                    sol += exp;
                    hol = 0;
                    break;
                }
            }

            if (hol == 2 && *i == exp) {
                if (i + 1 != srt.end()) {
                    if (*(i + 1) == exp) {
                        exp++;
                        continue;
                    }
                    else
                    {
                        sol += exp;
                        exp++;
                        hol--;
                    }
                }
            }
        }

        sol += (*(srt.end() - 1) + 1) * hol;

        cout << sol << endl;
    }
}