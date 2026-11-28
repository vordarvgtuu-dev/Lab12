#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <wchar.h>

void task1_pointer_sizes(void) {
    char* pc, c = 'A';
    int* pi, i = 5;
    double* pd, d = 3.14;

    pc = &c;
    pi = &i;
    pd = &d;

    printf("Размер char*:   %lu\n", sizeof(pc));
    printf("Размер int*:    %lu\n", sizeof(pi));
    printf("Размер double*: %lu\n", sizeof(pd));
}

void task2_two_pointers(void) {
    float PI = 3.14159f, * p1, * p2;
    p1 = p2 = &PI;

    printf("По адресу p1 = %p хранится *p1 = %g\n", p1, *p1);
    printf("По адресу p2 = %p хранится *p2 = %g\n", p2, *p2);
    printf("В 16-ричном виде (%%x): p1 = %x, p2 = %x\n", p1, p2);
}

void ptr_step_int(void) {
    int x = 5;
    int* pa = &x;
    printf("int:\n");
    printf("По адресу %p хранится *pa = %d\n", pa, *pa);
    pa++;
    printf("По адресу %p (после pa++)\n", pa);
    pa--;
    printf("По адресу %p хранится *pa = %d\n\n", pa, *pa);
}

void ptr_step_double(void) {
    double xd = 5.5;
    double* pdbl = &xd;
    printf("double:\n");
    printf("По адресу %p хранится *pdbl = %g\n", pdbl, *pdbl);
    pdbl++;
    printf("По адресу %p (после pdbl++)\n", pdbl);
    pdbl--;
    printf("По адресу %p хранится *pdbl = %g\n\n", pdbl, *pdbl);
}

void ptr_step_char(void) {
    char xc = 'a';
    char* pchr = &xc;
    printf("char:\n");
    printf("По адресу %p хранится *pchr = %c\n", pchr, *pchr);
    pchr++;
    printf("По адресу %p (после pchr++)\n", pchr);
    pchr--;
    printf("По адресу %p хранится *pchr = %c\n\n", pchr, *pchr);
}

void ptr_step_ldouble(void) {
    long double xld = 5.5;
    long double* pldbl = &xld;
    printf("long double:\n");
    printf("По адресу %p хранится *pldbl = %Lg\n", pldbl, *pldbl);
    pldbl++;
    printf("По адресу %p (после pldbl++)\n", pldbl);
    pldbl--;
    printf("По адресу %p хранится *pldbl = %Lg\n\n", pldbl, *pldbl);
}

void ptr_step_ushort(void) {
    short unsigned int xs = 10;
    short unsigned int* pshrt = &xs;
    printf("short unsigned int:\n");
    printf("По адресу %p хранится *pshrt = %u\n", pshrt, *pshrt);
    pshrt++;
    printf("По адресу %p (после pshrt++)\n", pshrt);
    pshrt--;
    printf("По адресу %p хранится *pshrt = %u\n\n", pshrt, *pshrt);
}

void ptr_step_bool(void) {
    _Bool xb = 1;
    _Bool* pbool = &xb;
    printf("_Bool:\n");
    printf("По адресу %p хранится *pbool = %d\n", pbool, *pbool);
    pbool++;
    printf("По адресу %p (после pbool++)\n", pbool);
    pbool--;
    printf("По адресу %p хранится *pbool = %d\n", pbool, *pbool);
}

void task4_addresses(const float array[], int size) {
    printf("4.1 Адреса:\n");
    printf("array     = %p\n", array);
    printf("&array[0] = %p\n", &array[0]);
    printf("&array    = %p\n\n", &array);
}

void task4_operations(float array[]) {
    float* ptr_a = array;
    printf("4.2 Операции с указателем:\n");
    printf("Начало:      адрес %p, значение %.1f\n", ptr_a, *ptr_a);

    ptr_a++;
    printf("ptr_a++:     адрес %p, значение %.1f\n", ptr_a, *ptr_a);
    printf("ptr_a + 4:   адрес %p, значение %.1f\n", ptr_a + 4, *(ptr_a + 4));
    printf("ptr_a - 2:   адрес %p (выход за пределы массива)\n\n", ptr_a - 2);
}

void task4_forward_step2(const float array[], int count) {
    const float* ptr_a = array;
    printf("4.3 Прямой проход с шагом +2:\n");
    for (int k = 0; k < count; k++) {
        printf("%.1f ", *ptr_a);
        ptr_a += 2;
    }
    printf("\n\n");
}

void task4_backward(const float array[], int size) {
    const float* ptr_a = &array[size - 1];
    printf("4.4 Обратный проход:\n");
    for (int k = 0; k < size; k++) {
        printf("%.1f ", *ptr_a);
        ptr_a--;
    }
    printf("\n");
}

void print_bytes(const void* data, int size, const char* fmt) {
    const unsigned char* b = (const unsigned char*)data;
    for (int k = 0; k < size; k++) {
        printf(fmt, b[k]);
    }
}

void task5_endianness(void) {
    int num = 0x12345678;
    printf("5.1 Число 0x12345678 по байтам: ");
    print_bytes(&num, sizeof(num), "%x ");
    printf("(порядок little-endian)\n\n");
}

void task5_types_representation(void) {
    int a_int = 12345;
    float a_float = 12345.0f;
    double a_double = 12345.0;

    printf("5.3 Число 12345 в разных типах:\n");

    printf("int:    ");
    print_bytes(&a_int, sizeof(a_int), "%02x ");
    printf("\n");

    printf("float:  ");
    print_bytes(&a_float, sizeof(a_float), "%02x ");
    printf("\n");

    printf("double: ");
    print_bytes(&a_double, sizeof(a_double), "%02x ");
    printf("\n");
}

void homework_wchar_size(void) {
    wchar_t arr[2];
    int size = (int)((char*)(&arr[1]) - (char*)(&arr[0]));
    printf("Размер типа wchar_t (без sizeof): %d байт\n", size);
}

int main(void) {
    SetConsoleOutputCP(65001);

    printf("ЗАДАНИЕ 1:\n");
    task1_pointer_sizes();

    printf("\nЗАДАНИЕ 2:\n");
    task2_two_pointers();

    printf("\nЗАДАНИЕ 3:\n\n");
    ptr_step_int();
    ptr_step_double();
    ptr_step_char();
    ptr_step_ldouble();
    ptr_step_ushort();
    ptr_step_bool();

    printf("\nЗАДАНИЕ 4:\n");
    float array[10] = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 10.1f };
    task4_addresses(array, 10);
    task4_operations(array);
    task4_forward_step2(array, 5);
    task4_backward(array, 10);

    printf("\nЗАДАНИЕ 5:\n");
    task5_endianness();
    task5_types_representation();

    printf("\nДОМАШНЕЕ ЗАДАНИЕ:\n");
    homework_wchar_size();

    return 0;
}
