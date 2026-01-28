#include<bits/stdc++.h>
using namespace std;
#include "MFA-SJR.h"

int power(long long base, long long expo, long m) {
    int res = 1;
    base = base % m;
    while (expo > 0) {
        if (expo & 1)
            res = (res * 1LL * base) % m;
        base = (base * 1LL * base) % m;
        expo = expo / 2;
    }
    return res;
}


int main (){
long long p=37, q=41;

long long n=p*q;
long long plainText=120;

long long fi_n=(p-1)*(q-1);

long long kpub=17;

cout<<"Kpub GCD with FI_N: "<<__gcd(kpub,fi_n)<<endl;

long long k_private=modInverse(kpub,fi_n);


long long X=power(plainText,kpub,n);
cout<<"Plain Text: "<<plainText<<endl;

cout<<"ENC: "<<X<<endl;
long long Y=power(X,k_private,n);
cout<<"DEC: "<<Y<<endl;
}
