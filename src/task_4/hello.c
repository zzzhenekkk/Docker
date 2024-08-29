#include <fcgi_stdio.h>
#include <stdlib.h>
// #include <stdio.h>

int main() {
    while (FCGI_Accept() >= 0) {
        printf("Content-type: text/html\r\n"
               "\r\n"
               "<html><head><title>Test</title></head>"
               "<body>Hello World!</body></html>\n");
    }
    return 0;
}