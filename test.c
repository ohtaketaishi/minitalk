#include <stdio.h>

int main()
{
    int decimal;
    int binary = 0;
    int base = 1;

    decimal = 0b10101010| 0b01010101;//0x11111111

    while (decimal>0){
    binary = binary + ( decimal % 2 ) * base;
    decimal = decimal / 2;
    base = base * 10;
  }

    printf("binary:%d\n",binary);

    return (0);

}