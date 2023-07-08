//
//  malloc_testing.c
//  estudo_C
//
//  Created by Rômulo Santana on 08/07/23.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int *pointer = NULL;
    int n;
    // obter o valor ocupado por n na memoria
    pointer = (int *)malloc(n*sizeof(int));
    
    if (!pointer) {
        printf("not enough memory");
        exit(EXIT_FAILURE);
    }
    if (pointer != NULL) {
        free(pointer);
        pointer = NULL;
    }
    return EXIT_SUCCESS;
}
