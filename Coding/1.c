#include <stdio.h>
#include <string.h>

struct Product {
    int id, price;
    char name[50];
};

int Count(char *s) {
    char *ptr = s;
    int n = 1;
    while (*ptr != '\0')
    {
        if (*ptr == ';')
            n++;
        ptr++;
    }
    return (int)n;
}

void Parse(char *ptr, struct Product *products) {
    int field = 0;
    int prod_id = 0, arr_id = 0;
    char arr[30] = {0};

    while (1) {
        switch (*ptr) {
        case ',': {
            arr[arr_id] = '\0';
            if (field == 0) {
                products[prod_id].id = (int)arr[0];
            }
            if (field == 2) {
                char *s = arr;
                char *p = products[prod_id].price;
                while (*s != '\0') {
                    *p = (int)*s;
                    p++;
                    s++;
                }
            }
            arr_id = 0;
            field++;
            ptr++;
            break;
        }
        case ';': {
            char *p = arr;
            char *src = products[i].price;

            while (*src != '\0') {
                *src = *p;
                src++;
                ptr++;
            }
            *src = '\0';

            arr_id = 0;
            field = 0;
            ptr++;
            prod_id++;
            break;
        }
        case '\0':{
            arr[arr_id] = '\0';
            break;
            return;
        }

        default: {
            arr[arr_id] = *ptr;
            arr_id++;
            ptr++;
            break;
        }
        }   
    } 
}

int main()
{
    char input[] = "1,Laptop,75000;2,Mouse,500;3,Keyboard,1500";
    int n = Count(input);
    printf("The no.of records in string:- %d", n);

    struct Product product[n];
    for (int i = 0; i < n; i++) {
        Parse(input, product);
        printf("ID: %d, Name: %s, Price: %d", product[i].id, product[i].name, product[i].price);
    }
    return 0;
}