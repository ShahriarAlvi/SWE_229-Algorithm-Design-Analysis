// Basic sieve

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
#define N 1500000

using namespace std;

bool isComposite[N];                        // checks the composite numbers
                                            // 0 for primes and 1 for composite

void sieve(ll n)
{
    ll i, j;
    vector<ll> primes;                      // stores the prime numbers
    for (i = 2; i < n; i++)
    {
        if (!isComposite[i])                //checks if i is a prime number
        {
            primes.push_back(i);            
            for (j = i + i; j < n; j += i)  //flags out multiples of i as 
                isComposite[j] = true;      //composite number
        }
    }

    for (auto it = primes.begin(); it != primes.end(); it++)
        cout << *it << endl;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;
    sieve(n);

    return 0;
}
