#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
    int i = 0;
    clock_t start_time = 0;
    clock_t end_time = 0;
    double time_spent = 0;

    /********************************************************/
    // STDOUT time comparison

    start_time = clock();

    for(i = 0; i < 100000; i++)
    {
        printf("%d\n", i);
    }

    end_time = clock();

    time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("printf time elapsed: %f seconds\n", time_spent);

    /*********************************************************/
    // String concatenation time comparison

    start_time = clock();

    char test1[40] = "Hello ";
    char test2[40] = "World!";
    // If I remember correctly, strcat is actually unoptimized and there is a better alternative lol
    strcat(test1, test2);

    end_time = clock();
    
    printf("%s\n", test1);
    
    time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("strcat time elapsed: %f seconds\n", time_spent);

    /*********************************************************/
    // Array operations time comparison

    start_time = clock();

    int testArr_size = 50;
    int *testArr = malloc(sizeof(*testArr) * testArr_size);
    int value = 0;

    if (testArr){
        for (i = 0; i < testArr_size; i++)
        {
            testArr[i] = i;
        }
        value = testArr[25];
        free(testArr);
    }
    else
        printf("testArr failed to initialize!");
    
    end_time = clock();

    printf("%d\n", value);

    time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Array operations time elapsed: %f seconds\n", time_spent);

    return 0;
}
