#include <stdio.h>
unsigned long long divisions;
int is_prime_odd(unsigned long n) {
    divisions=0;
    if (n<2) return 0;
    if (n==2) return 1;
    if (n%2==0) { divisions++; return 0; }
    unsigned long d;
    for (d=3; d<=n/d; d+=2) {
        divisions++;
        if (n%d==0) return 0;
    }
    return 1;
}
int main(void) {
    unsigned long tests[]={97,100,7919,1000003};
    int i;
    for (i=0;i<4;i++) {
        int p=is_prime_odd(tests[i]);
        printf("%lu: %s, divisions=%llu\n",tests[i],p?"prime":"not prime",divisions);
    }
    return 0;
}
