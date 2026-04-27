#include <float.h>
#include <limits.h>
#include <stdio.h>

int main() {
  int i;
  unsigned int usi;
  short s;
  long l;
  char c;

  printf("MIN and MAX values.");
  printf("\n------------------------------------------------------------\n");
  printf("int max value: %d || ", INT_MAX);
  printf("int min value: %d\n", INT_MIN);
  printf("unsigned int max value: %d || ", UINT_MAX);
  printf("unsigned int min value: 0\n");
  printf("short max value: %d || ", SHRT_MAX);
  printf("short min: %d\n", SHRT_MIN);
  printf("long max value: %ld || ", LONG_MAX);
  printf("long min value: %ld\n", LONG_MIN);
  printf("char max value: %d || ", CHAR_MAX);
  printf("char min value: %d", CHAR_MIN);

  int *pi = &i;
  char *pc = &c;
  short *ps = &s;

  // overflow
  printf("\n------------------------------------------------------------\n");
  printf("Assign values beyond their maximum limits.");
  printf("\n------------------------------------------------------------\n");
  *ps = SHRT_MAX;
  printf("short max + 1 (overflow): %d\n", (short)(*ps + 1));
  *pi = INT_MAX;
  printf("int max + 1 (overflow): %d\n", *pi + 1);
  *pc = CHAR_MAX;
  printf("char max + 1 (overflow): %d\n", *pc + 1);

  // underflow
  printf("\n------------------------------------------------------------\n");
  printf("Assign values below their minimum limits.");
  printf("\n------------------------------------------------------------\n");
  *ps = SHRT_MIN;
  printf("short min - 1 (underflow): %d\n", (short)(*ps - 1));
  *pi = INT_MIN;
  printf("int min - 1 (underflow): %d\n", *pi - 1);
  *pc = CHAR_MIN;
  printf("char max - 1 (underflow): %d\n", *pc - 1);

  // comaparing signed and unsigned data types data ranges
  printf("\n------------------------------------------------------------\n");
  *pc = -1;
  unsigned char uc = -1; // Assigning -1 to an unsigned type
  printf("Signed char (-1): %d\n", *pc);
  printf("Unsigned char (-1): %u (Value wraps to its maximum limit)\n\n", uc);

  printf("\n------------------------------------------------------------\n");
  printf("- Overflow/Underflow: Occurs when a calculation exceeds the memory "
         "capacity of the data type.\n");
  printf("- Pointers: Variables were modified indirectly using memory "
         "addresses (e.g., *p_s = SHRT_MAX).\n");
  printf("- Signed vs Unsigned: Unsigned types cannot store negative numbers; "
         "assigning a negative value\n causes it to wrap around to the maximum "
         "positive value allowed for that size.\n");

  return 0;
}