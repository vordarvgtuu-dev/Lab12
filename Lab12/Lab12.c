#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);


    printf("ЗАДАНИЕ 1:\n");
    char* pc, c = 'A';
    int* pi, i = 5;
    double* pd, d = 3.14;

    pc = &c;
    pi = &i;
    pd = &d;

    printf("Размер char*:   %lu\n", sizeof(pc));
    printf("Размер int*:    %lu\n", sizeof(pi));
    printf("Размер double*: %lu\n", sizeof(pd));



    printf("\nЗАДАНИЕ 2:\n");
    float PI = 3.14159f, * p1, * p2;
    p1 = p2 = &PI;

    printf("По адресу p1 = %p хранится *p1 = %g\n", p1, *p1);
    printf("По адресу p2 = %p хранится *p2 = %g\n", p2, *p2);
    printf("В 16-ричном виде (%%x): p1 = %x, p2 = %x\n", p1, p2);



    printf("\nЗАДАНИЕ 3:\n");


    int x = 5;
    int* pa = &x;
    printf("int:\n");
    printf("По адресу %p хранится *pa = %d\n", pa, *pa);
    pa++;
    printf("По адресу %p (после pa++)\n", pa);
    pa--;
    printf("По адресу %p хранится *pa = %d\n\n", pa, *pa);


    double xd = 5.5;
    double* pdbl = &xd;
    printf("double:\n");
    printf("По адресу %p хранится *pdbl = %g\n", pdbl, *pdbl);
    pdbl++;
    printf("По адресу %p (после pdbl++)\n", pdbl);
    pdbl--;
    printf("По адресу %p хранится *pdbl = %g\n\n", pdbl, *pdbl);


    char xc = 'a';
    char* pchr = &xc;
    printf("char:\n");
    printf("По адресу %p хранится *pchr = %c\n", pchr, *pchr);
    pchr++;
    printf("По адресу %p (после pchr++)\n", pchr);
    pchr--;
    printf("По адресу %p хранится *pchr = %c\n\n", pchr, *pchr);


    long double xld = 5.5;
    long double* pldbl = &xld;
    printf("long double:\n");
    printf("По адресу %p хранится *pldbl = %Lg\n", pldbl, *pldbl);
    pldbl++;
    printf("По адресу %p (после pldbl++)\n", pldbl);
    pldbl--;
    printf("По адресу %p хранится *pldbl = %Lg\n\n", pldbl, *pldbl);


    short unsigned int xs = 10;
    short unsigned int* pshrt = &xs;
    printf("short unsigned int:\n");
    printf("По адресу %p хранится *pshrt = %u\n", pshrt, *pshrt);
    pshrt++;
    printf("По адресу %p (после pshrt++)\n", pshrt);
    pshrt--;
    printf("По адресу %p хранится *pshrt = %u\n\n", pshrt, *pshrt);


    _Bool xb = 1;
    _Bool* pbool = &xb;
    printf("_Bool:\n");
    printf("По адресу %p хранится *pbool = %d\n", pbool, *pbool);
    pbool++;
    printf("По адресу %p (после pbool++)\n", pbool);
    pbool--;
    printf("По адресу %p хранится *pbool = %d\n", pbool, *pbool);



    printf("\nЗАДАНИЕ 4:\n");
    float array[10] = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 10.1f };
    float* ptr_a;


    printf("4.1 Адреса:\n");
    printf("array     = %p\n", array);
    printf("&array = %p\n", &array);
    printf("&array    = %p\n\n", &array);


    printf("4.2 Операции с указателем:\n");
    ptr_a = array;
    printf("Начало:      адрес %p, значение %.1f\n", ptr_a, *ptr_a);

    ptr_a++;
    printf("ptr_a++:     адрес %p, значение %.1f\n", ptr_a, *ptr_a);
    printf("ptr_a + 4:   адрес %p, значение %.1f\n", ptr_a + 4, *(ptr_a + 4));
    printf("ptr_a - 2:   адрес %p (выход за пределы массива)\n\n", ptr_a - 2);


    printf("4.3 Прямой проход с шагом +2:\n");
    ptr_a = array;
    for (int k = 0; k < 5; k++) {
        printf("%.1f ", *ptr_a);
        ptr_a += 2;
    }
    printf("\n\n");


    printf("4.4 Обратный проход:\n");
    ptr_a = &array;
    for (int k = 0; k < 10; k++) {
        printf("%.1f ", *ptr_a);
        ptr_a--;
    }
    printf("\n");



    printf("\nЗАДАНИЕ 5:\n");
    unsigned char* b;


    int num = 0x12345678;
    b = (unsigned char*)&num;
    printf("5.1 Число 0x12345678 по байтам: ");
    for (int k = 0; k < sizeof(num); k++) {
        printf("%x ", b[k]);
    }
    printf("(порядок little-endian)\n\n");


    int a_int = 12345;
    float a_float = 12345.0f;
    double a_double = 12345.0;

    printf("5.3 Число 12345 в разных типах:\n");

    b = (unsigned char*)&a_int;
    printf("int:    ");
    for (int k = 0; k < sizeof(a_int); k++) {
        printf("%02x ", b[k]);
    }
    printf("\n");

    b = (unsigned char*)&a_float;
    printf("float:  ");
    for (int k = 0; k < sizeof(a_float); k++) {
        printf("%02x ", b[k]);
    }
    printf("\n");

    b = (unsigned char*)&a_double;
    printf("double: ");
    for (int k = 0; k < sizeof(a_double); k++) {
        printf("%02x ", b[k]);
    }
    printf("\n");

    return 0;
}
