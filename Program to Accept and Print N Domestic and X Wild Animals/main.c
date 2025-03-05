#include <stdio.h>

int main() {
    int N, X;

    // Input the number of domestic animals
    printf("Enter the number of domestic animals: ");
    scanf("%d", &N);

    char domesticAnimals[N][50]; // Assuming max 50 characters per name
    printf("Enter the names of %d domestic animals:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%s", domesticAnimals[i]);
    }

    // Input the number of wild animals
    printf("\nEnter the number of wild animals: ");
    scanf("%d", &X);

    char wildAnimals[X][50];
    printf("Enter the names of %d wild animals:\n", X);
    for (int i = 0; i < X; i++) {
        scanf("%s", wildAnimals[i]);
    }

    // Print all animals
    printf("\nList of all animals:\n");
    for (int i = 0; i < N; i++) {
        printf("%s\n", domesticAnimals[i]);
    }
    for (int i = 0; i < X; i++) {
        printf("%s\n", wildAnimals[i]);
    }

    return 0;
}

