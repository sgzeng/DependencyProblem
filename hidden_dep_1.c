#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

static inline void write2log(const char * str){
  FILE *fp = fopen("my.log", "a+");
  if (fp != NULL)
  {
    fprintf(fp, "%s, ", str);
    fclose(fp);
  }
}

size_t receive( char *dst, char delim, size_t max ){
    size_t len = 0;
    char c = 0;
    while( len < max ) {
        dst[len] = 0x00;
        if ( read(0, &c, sizeof(unsigned char)) <= 0 ) {
            len = 0;
            goto end;
        }
        if ( c == delim ) {
            goto end;
        }
        dst[len] = c;
        len++;
    }
end:
    return len;
}

int main(int argc, char **argv){
    char input[255];
    memset(input, 0, sizeof(input));
    receive(input, '\n', 255);
    char max = 255;
    int i = 1;
    int k = -1;
    while(i < max){
        char x = input[i];
        char y = input[i+1];
        char z = input[i+2];
        if(x > 65 && y < 65 && z == 65)
            k++;
        i += 3;
    }
    if(k > 30){
        printf("treasure found\n");
        assert(k<0);
    }
    printf("k: %d\n", k);
    return 0;
}
