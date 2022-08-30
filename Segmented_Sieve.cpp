// Segmented Sieve

/* For generating a ranged prime numbers. suppose
to show primes between 100 and 700. here if we start
searching from the start, then we will have to do more
iterations than necessary. This is where segmented
sieve comes. Moreover, for finding primes beyond 10^5 or
10^8, we face storage issue - which can be avoided
using segmented sieve
*/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
#define N 100000

using namespace std;

vector<int> primes;                         /*generating prime numbers in a vector*/

void sieve()
{
    ll i, j;
    bool isComposite[N];                    // stores the prime numbers
    for (i = 2; i < N; i++)
    {
        if (!isComposite[i])                // checks if i is a prime number
        {
            primes.push_back(i);
            for (j = i + i; j < N; j += i)  // flags out multiples of i as
                isComposite[j] = true;      // composite number
        }
    }
}                                           /*generating the prime numbers from
                                            the beginning till 10^5 and storing them
                                            in primes vector, these primes will be
                                            used to create the segmented sieve
                                            */

void segmentedSieve(ll L, ll R)             /*primes in [L, R] range*/
{
    bool isPrime[R - L + 1];                /* the array to maintain number status in the segment.
                                            here the first index shows the status of the first
                                            number in the segment, L. 1st index for L+1,
                                            and last index for R.
                                            */
    
    for (int i = 0; i <= R - L + 1; i++)
        isPrime[i] = true;                  // assuming all are primes

    if (L == 1)
        isPrime[0] = false;                 // 1 is not a prime

    for (int i = 0; primes[i] * primes[i] <= R; i++)
    {
        ll curPrime = primes[i];
        ll base = curPrime * curPrime;      /*we will take primes from the sieve
                                            and use them to find primes that are
                                            inside the range
                                            */
        if (base < L)
        {
            // two different formula to find base
            // base = ((L + curPrime - 1) / curPrime) * curPrime;
            
            base = L + curPrime - (L % curPrime); 
        }                                   /*finding the first prime (base) that is greater than L
                                            we will use that to find more primes inside the range
                                            */
        
        for (ll j = base; j <= R; j += curPrime)
            isPrime[j - L] = false;         /*multiples of curprimes inside the range
                                            will be flagged out as false
                                            */
    }
    
    cout << "Prime numbers in range [" << L << ", " << R << "]: " << endl;
    for (int i = 0; i <= R - L; i++)
    {
        if (isPrime[i] == true)
            cout << L + i << endl;
    }                                       // printing out the primes in the segment
    cout << endl;
}

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    sieve();                                // basic sieve to generate primes till 10^5
                                            /* using basic sieve generated primes to create
                                            segmented sieve, that goes beyond 10^5*/
    
    ll L, R;
    cout << "Provide range: L and R" << endl;
    cin >> L >> R;
    segmentedSieve(L, R);

    return 0;
}
