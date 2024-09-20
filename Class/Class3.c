//
// Created by Administrator on 2024/9/20.
//

#include <stdio.h>
#include <stdlib.h>


// int main() {
//     int *i;
//     i = (int *)malloc(1 * sizeof(int));
//     scanf("%d", i);
//     printf("The int num is %d ", *i);
//     // system("pause");
//     return 0;
// }


// int main() {
//     int *a;
//     int i;
//     a = (int *)malloc(5 * sizeof(int));
//     printf("Input 5 int nums :");
//     for (i = 0; i < 5; i++)
//         scanf("%d", &a[i]);
//     printf("print 5 int nums : ");
//     for (i = 0;i < 5; i++)
//         printf("%d ", a[i]);
// 
//     return 0;
// }
// 


int main() {
    int n;
    printf("Input the size, please :");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int max = a[0];
    for (int i = 0; i < n; i++)
        if (a[i] > max)
            max = a[i];

    printf("The MAX num is : %d", max);

    return 0;
}
