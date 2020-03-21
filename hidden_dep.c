#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

static int k = -1;

int main(int argc, char **argv){
    char input[255];
    memset(input, 0, sizeof(input));
    int max = sizeof(input);
    int i = 0;
    for(; i < max - 2; i+=3){
        if(k > 80){
            printf("treasure found\n");
            assert(k<0);
        }
        read(0, &input[i], sizeof(unsigned char));
        read(0, &input[i+1], sizeof(unsigned char));
        read(0, &input[i+2], sizeof(unsigned char));
        char x = input[i];
        char y = input[i+1];
        char z = input[i+2];
        if(x > 65 && y < 65){
			if(z == 65)
				k++;
			else
				continue;
		}else{
			k--;
		}
    }
    printf("k: %d\n", k);
    return 0;
}
