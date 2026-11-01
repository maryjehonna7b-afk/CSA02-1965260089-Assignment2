#include <stdio.h>
char grade(int marks) {
    if (marks < 0 || marks > 100) return '?';
    switch (marks / 10) {
        case 10: case 9: return 'S';
        case 8: return 'A';
        case 7: return 'B';
        case 6: return 'C';
        case 5: return 'D';
        default: return 'F';
    }
}
char grade_ladder(int marks) {
    if (marks < 0 || marks > 100) return '?';
    if (marks >= 90) return 'S';
    else if (marks >= 80) return 'A';
    else if (marks >= 70) return 'B';
    else if (marks >= 60) return 'C';
    else if (marks >= 50) return 'D';
    else return 'F';
}
int main(void) {
    int tests[]={100,90,89,0,-1,101,80,79,70,69,60,59,50,49};
    int i;
    for(i=0;i<14;i++)
        printf("%d: switch=%c ladder=%c\n", tests[i], grade(tests[i]), grade_ladder(tests[i]));
    return 0;
}
