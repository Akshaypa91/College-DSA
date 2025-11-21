#include <stdio.h>
#include <stdlib.h>

int main() {
    int nums[5] = {1, 1, 4, 1, 1};

    for(int i = 0; i < 5; i++) {
        if(nums[i] == '4') {
            goto end;
        }
    }
    end:
        printf("This is the End \n");

    return 0;
}