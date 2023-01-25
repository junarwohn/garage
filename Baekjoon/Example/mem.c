#include <stdio.h>
int main(void) {
    int mam[10] = {0,};
    int mam_[3] = {1,};
    (mam + 2) = mam_;
    for (int i = 0; i < 10; i++)
        printf("%d", mam[i]);
    return 0;
}
