#include <stdio.h>

int main(void) {
    int price, qty, senior, count = 0;
    int total, net;

    printf("Enter unit price, quantity, senior (1=yes, 0=no): ");
    if (scanf("%d%d%d", &price, &qty, &senior) != 3) return 1;

    /* Original expressions from the assignment */
    total = price * qty - price * qty * 15 / 100 * senior + price * qty * 5 / 100;
    net = total > 1000 ? total - 50 : total;

    printf("Original total = %d\nNet = %d\n", total, net);
    /* Do not use count = count++ + 1: it has undefined behavior. */
    count++;
    printf("Count after safe increment = %d\n", count);

    /* Correct readable calculation (integer rupees, rounded down by integer division) */
    {
        int gross = price * qty;
        int discount = senior ? gross * 15 / 100 : 0;
        int taxable = gross - discount;
        int tax = taxable * 5 / 100;
        int corrected = taxable + tax;
        int corrected_net = corrected > 1000 ? corrected - 50 : corrected;
        printf("Corrected total = %d\nCorrected net = %d\n", corrected, corrected_net);
    }
    return 0;
}
