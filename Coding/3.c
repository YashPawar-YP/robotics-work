#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter total number of inputs: ");
    scanf("%d", &n);

    //write inputs
    float arr[n];
    FILE *fi;
    fi = fopen("input", "w");
    if (fi == NULL) {
        printf("Error opening input file.");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Enter inputs: ");
        scanf("%f", &arr[i]);
        fprintf(fi, "%.2f\n", arr[i]);
    }
    fclose(fi); //file close

    //reading and calculation
    float sum = 0, max = 0, min = arr[0];
    FILE *fo;
    fi = fopen("input", "r");
    float *p = (float *)malloc(n * sizeof(float));
    float *ptr = arr;
    int i = 0;
    while (fscanf(fi, "%f", ptr) != EOF) {
        sum += *(ptr + i);
        if (*(ptr + i) > max) {
            max = *(ptr + i);
        }
        if (*(ptr + i) < min) {
            min = *(ptr + i);
        }
        i++;
    }
    fclose(fi); //file close
    
    //write in another file
    fo = fopen("output", "w");
    if (fo == NULL) {
        printf("Error opening output file.");
        return 1;
    }
    fprintf(fo, "Sum:- %.2f\n", sum);
    fprintf(fo, "Max:- %.2f\n", max);
    fprintf(fo, "Min:- %.2f", min);
    
    fclose(fo); //file close

    printf("Sum:- %.2f\n", sum);
    printf("Max:- %.2f\n", max);
    printf("Min:- %.2f\n", min);

    free(p); //free memory

    return 0;
}