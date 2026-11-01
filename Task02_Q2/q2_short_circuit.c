#include <stdio.h>

static int calls;
int verify_card(int has_card) {
    calls++;
    return has_card;
}

int main(void) {
    int senior = 1, eligible = 0, disability = 0;
    calls = 0;
    int concession = (senior && eligible) || verify_card(disability);
    printf("Concession=%d, verification calls=%d\n", concession, calls);

    calls = 0;
    concession = (senior && verify_card(disability)) || eligible;
    printf("Reordered concession=%d, verification calls=%d\n", concession, calls);

    calls = 0;
    /* Bitwise & evaluates both operands; use only for this demonstration. */
    concession = (senior & eligible) | verify_card(disability);
    printf("Bitwise result=%d, verification calls=%d\n", concession, calls);
    return 0;
}
