
#include <bits/stdc++.h>

using namespace std;

using namespace std;

vector<vector<long long>> base(10);
// A utility for creating palindrome
long long createPalindrome(long long input, long long b, bool isOdd)
{
    long long n = input;
    long long palin = input;
 
    // checks if number of digits is odd or even
    // if odd then neglect the last digit of input in
    // finding reverse as in case of odd number of
    // digits middle element occur once
    if (isOdd)
        n /= b;
 
    // Creates palindrome by just appending reverse
    // of number to itself
    while (n > 0)
    {
        palin = palin * b + (n % b);
        n /= b;
    }
    return palin;
}
 
// Function to prlong long decimal palindromic number
void generatePalindromes(long long n)
{
    long long number;
 
    // Run two times for odd and even length palindromes
    for (long long j = 0; j < 2; j++)
    {
        // Creates palindrome numbers with first half as i.
        // Value of j decided whether we need an odd length
        // of even length palindrome.
        long long i = 1;
        while ((number = createPalindrome(i, 10, j % 2)) < n)
        {
            for (long long k = 2; k <= 9; k++) {
                vector<long long> things;
                long long t = number;
                while (t != 0) {
                    things.push_back(t % k);
                    t /= k;
                }
                
                long long n = 0;
                
                long long b = 1;
                
                for (long long j = 0; j < things.size() - 1; j++) {
                    if (things[j] != things[things.size() - j - 1]) {
                        b = 0;
                        break;
                    }
                }
                
                if (b) {
                    base[k].push_back(number);
                }
            }
            
            i++;
        }
    }
}



// Driver Program to test above function
int main()
{
    // for (long long i = 1; i < 10; i += 2) {
    //     for (long long k = 2; k <= 9; k++) {
    //             vector<long long> things;
    //             long long t = i;
    //             while (t != 0) {
    //                 things.push_back(t % k);
    //                 t /= k;
    //             }
                
    //             long long n = 0;
                
    //             long long b = 1;
                
    //             for (long long j = 0; j < things.size() - 1; j++) {
    //                 if (things[j] != things[things.size() - j - 1]) {
    //                     b = 0;
    //                     break;
    //                 }
    //             }
                
    //             if (b) {
    //                 base[k].push_back(i);



    //                 for (int i = 0; i < base[k].size(); i++) {

    //                 }
    //             }
    //         }
    // }
    
    long long n = 10000000000;
    generatePalindromes(n);
    
    cout << "{";

    for (long long i = 2; i <= 9; i++) {
        sort(base[i].begin(), base[i].end());

        cout << "{";
        for (long long j = 0; j < base[i].size(); j++) {
            if (j >= 30) {
                break;
            }

            if (j != 0) {
                cout << ", ";
            }
            
            cout << base[i][j];
        }

        cout << "}," << endl;
    }

    for (int i = 2; i <= 9; i++) {
        cout << i << " : " << base[i].size() << endl;
    }
    
    cout << "d" << endl;
    return 0;
}