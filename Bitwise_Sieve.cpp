//Bitwise Sieve
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
#define N 100000

using namespace std;

int flag[N / 32];                           //the flag to check prime

bool checkBit(int index, int bit)           //a function that checks the status of the number                              
{
    return (bool)(index & (1 << bit));
}                                           /*index decides the array index, bit decides the bit
                                            location in that particular index. index provides the
                                            whole 32 bit data and bit provides 1 in the desired position
                                            and 0 in other positions.*/
                                    
bool setBit(int index, int bit)             //a function that sets the status of the number 1
{
    index = index | (1 << bit);
    // cout << index << endl;
    return index;
}                                           /*index decides the array index, bit decides the bit
                                            location in that particular index. index provides the
                                            whole 32 bit data and bit provides 1 in the desired position
                                            and 1 in other positions. The outcome is the desired position 
                                            gets 1, and the other positions get unaffected.*/

void sieve(int n)
{
    int i, j;

    for (i = 3; i * i <= N; i += 2)
    {

        if (!checkBit(flag[i/32], i % 32))
        {
            for (j = i * i; j <= N; j += i)
                flag[j / 32] = setBit(flag[j / 32], j % 32);
        }
    }                                       
                                            /* i.e. if 2 is a composite number, then flag[2/32][2%32] = 0.
                                            therefore, check will work this way:
                                            index bits (first 4):   *0**
                                            bit(after 2 left shift):0100
                                            the result will be: 0, which says 2 is a prime number.
                                            */

                                            /* similarly, to set a bit, suppose for 4
                                            index bits:              *****
                                            bit (after 4 left shift):10000
                                            result:                  1****
                                            therefore, other bits do not get affected
                                            and our desired location gets a 1 bit, that says
                                            it's not a prime number.
                                            */


    puts("2");                              //printing the prime numbers
    for(i = 3; i <= n; i+=2){
        if(!checkBit(flag[i/32], i%32)){
            cout << i << endl;
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    cout << "Prime numbers in this range(" << n << "):" << endl;
    sieve(n);
    
    return 0;
}
