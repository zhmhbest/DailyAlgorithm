#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int hammingWeight(uint32_t n) {
    int ret = 0;
    for (int i = 0; i < 32; i++) {
        if (n & (1u << i)) {
            ret++;
        }
    }
    return ret;
}

int main() {
    printf("w=%d\n", hammingWeight(0xFFFFFFFF));
    return 0;
}