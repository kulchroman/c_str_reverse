#include <stdio.h>
#include <ctype.h>


int getline(FILE* _in, char* buf, int len, int ch){
    int c, i = 0;
    len -= 1;
    while((c = fgetc(_in)) != EOF){
        if((i >= len) || (c == ch) || ferror(_in))
            break;
        buf[i++] = c;
    }
    buf[i] = '\0';
    return i;
}


void str_rev(char* s, int len){

    char c;

    for( int  i = 0, j = len - 1; i < j; ++i, --j){
        c    = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}


int main(void){
    char buf[32];
    int len = getline(stdin, buf, sizeof(buf), '\n');
    str_rev(buf, len);
    puts(buf);
    return 0;
}
