#include<bits/stdc++.h>
using namespace std;


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
long long p=23,g=5;

long long a=6;
long long b=15;
long long A=power(g,a,p);
long long B=power(g,b,p);



long long S1=power(B,a,p);
long long S2=power(A,b,p);


cout<<S1<<" "<<S2<<endl;


cout<<(S1==S2?"S1 and S2 Matched...!":"S1 and S2 Not Matched...X");
}
