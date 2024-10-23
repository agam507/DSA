#include <stdio.h>
void TOH (int n, int A, int B, int C);
int main() {
    int n = 3;
    TOH(n, 1, 2, 3);
    return 0;
}
void TOH (int n, int A, int B, int C) {
    if (n>0) {
        TOH (n-1, A, C, B);
        printf("A->C = %d->%d \n", A, C);
        TOH(n-1, B, A, C);
    } else {
        return;
    }
}




/*
A->C = 1->3 
A->C = 1->2
A->C = 3->2
A->C = 1->3
A->C = 2->1
A->C = 2->3
A->C = 1->3
*/