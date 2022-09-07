#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
#define N 1000005

using namespace std;

vector<int> phi_sieve(N + 1);

vector<int> phi_divisor(N + 1);

int phi(int n)                              /* basic phi function that generates the
                                            result of one particular number
                                            */
{
    int result = n;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n = n / i;

            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}


void phi_1_to_n(int n)                      /*Using sieve algorithm to store the phi
                                            results in a range in a single operation
                                            */

{
    // vector<int> phi_sieve(n + 1);

    for (int i = 0; i <= n; i++)
        phi_sieve[i] = i;

    for (int i = 2; i <= n; i++)
    {
        if (phi_sieve[i] == i)
        {
            for (int j = i; j <= n; j += i)
                phi_sieve[j] -= phi_sieve[j] / i;
        }
    }
}


void phi_with_divisor_count(int n)          /*if a number x has divisors: a, b, and x
                                            (as a number has itself as its divisor),
                                            phi[a] + phi[b] + phi[x] == x
                                            we apply this formula to find out phi[x]
                                            */
{
    // vector <int> phi_divisor (n + 1);

    phi_divisor[0] = 0;
    phi_divisor[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        phi_divisor[i] = i - 1;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 2 * i; j <= n; j += i)
                phi_divisor[j] -= phi_divisor[i];
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    // checking if all the functions give the same result
    cout << "result with basic phi: " << phi(10) << endl;

    phi_1_to_n(10);
    cout << "result with sieve phi: " << phi_sieve[10] << endl;

    phi_with_divisor_count(10);
    cout << "result with divisor count phi: " << phi_divisor[10] << endl;

    return 0;
}
