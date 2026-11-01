#include <stdio.h>
unsigned long checks;

int prime_basic(unsigned long n) {
    checks=0;
    if (n<2) return 0;
    unsigned long i;
    for (i=2;i<n;i++) {
        checks++;
        if (n%i==0) return 0;
    }
    return 1;
}
int prime_sqrt_for(unsigned long n) {
    checks=0;
    if (n<2) return 0;
    unsigned long i;
    for (i=2; i<=n/i; i++) {
        checks++;
        if (n%i==0) return 0;
    }
    return 1;
}
int prime_sqrt_while(unsigned long n) {
    checks=0;
    if (n<2) return 0;
    unsigned long i=2;
    while (i<=n/i) {
        checks++;
        if (n%i==0) return 0;
        i++;
    }
    return 1;
}
int prime_sqrt_do(unsigned long n) {
    checks=0;
    if (n<2) return 0;
    unsigned long i=2;
    do {
        if (i>n/i) break;
        checks++;
        if (n%i==0) return 0;
        i++;
    } while (1);
    return 1;
}
int main(void) {
    unsigned long a[]={97,100,7919,1000003};
    int k;
    for (k=0;k<4;k++) {
        int p=prime_sqrt_for(a[k]);
        printf("%8lu %-9s divisions=%lu\n",a[k],p?"prime":"not prime",checks);
    }
    return 0;
}
