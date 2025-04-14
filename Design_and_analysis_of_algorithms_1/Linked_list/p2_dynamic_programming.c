// malloc
// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     int *ptr;
//     ptr = (int *)malloc(5 * sizeof(int));
//     if (ptr == NULL)
//     {
//         printf("memory not allocated!");
//     }
//     else
//     {
//         printf("memory allocation successfull");
//     }
// }

// calloc
// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     int *ptr;
//     ptr = (int *)calloc(5, sizeof(int));
//     if (ptr == NULL)
//     {
//         printf("memory not allocated!");
//     }
//     else
//     {
//         printf("memory allocation successfull");
//     }
// }

// free

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     int *ptr;
//     ptr = (int *)malloc(5 * sizeof(int));
//     if (ptr == NULL)
//     {
//         printf("memory not allocated!");
//     }
//     else
//     {
//         printf("memory allocation successfull\n");
//         free(ptr);
//         printf("memory free successfull");
//     }
// }

//realloc

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr1,*ptr2;
    ptr1 = (int *)malloc(5 * sizeof(int));
    ptr2 = (int *)calloc(5, sizeof(int));
    if (ptr1 == NULL || ptr2==NULL)
    {
        printf("memory not allocated!");
    }
    else
    {
        printf("memory allocation successfull\n");
        realloc(ptr1,50);
        printf("memory realloc successfull");
    }
}