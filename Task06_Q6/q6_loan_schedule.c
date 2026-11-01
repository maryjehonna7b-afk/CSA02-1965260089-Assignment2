#include <stdio.h>

int main(void) {
    double principal, rate, repayment, balance, total_interest=0.0;
    int month=0, limit=360;
    printf("Enter principal, monthly interest rate (%%), fixed repayment: ");
    if (scanf("%lf%lf%lf",&principal,&rate,&repayment)!=3) return 1;
    if (principal<=0 || rate<0 || repayment<=0) {
        puts("Invalid input."); return 1;
    }
    balance=principal;
    while (balance>0.005 && month<limit) {
        double interest=balance*rate/100.0;
        double due=balance+interest;
        double paid=repayment;
        if (repayment<=interest) {
            puts("Repayment must be greater than monthly interest; loan will not reduce.");
            return 1;
        }
        if (paid>due) paid=due;
        balance=due-paid;
        if (balance<0.005) balance=0.0;
        total_interest+=interest;
        month++;
        printf("Month %d: interest=%.2f paid=%.2f balance=%.2f\n",month,interest,paid,balance);
    }
    if (balance==0.0) printf("Repaid in %d months; total interest=%.2f\n",month,total_interest);
    else printf("Safety limit reached after %d months; remaining balance=%.2f\n",month,balance);
    return 0;
}
