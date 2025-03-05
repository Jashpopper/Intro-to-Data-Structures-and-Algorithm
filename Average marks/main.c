#include <stdio.h>

int main() {
    float physics[4], chemistry[4], math[4];
    float sumPhysics = 0, sumChemistry = 0, sumMath = 0;
    float avgPhysics, avgChemistry, avgMath, overallAvg;
    char *tests[] = {"Assignment", "Course work", "Mid Term", "End of Term"};

    // Input marks for Physics
    printf("Enter marks for Physics:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s: ", tests[i]);
        scanf("%f", &physics[i]);
        sumPhysics += physics[i];
    }
    avgPhysics = sumPhysics / 4;

    // Input marks for Chemistry
    printf("\nEnter marks for Chemistry:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s: ", tests[i]);
        scanf("%f", &chemistry[i]);
        sumChemistry += chemistry[i];
    }
    avgChemistry = sumChemistry / 4;

    // Input marks for Math
    printf("\nEnter marks for Math:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s: ", tests[i]);
        scanf("%f", &math[i]);
        sumMath += math[i];
    }
    avgMath = sumMath / 4;

    // Calculate overall average
    overallAvg = (avgPhysics + avgChemistry + avgMath) / 3;

    // Display results
    printf("\nAverage Marks:\n");
    printf("Physics: %.2f\n", avgPhysics);
    printf("Chemistry: %.2f\n", avgChemistry);
    printf("Math: %.2f\n", avgMath);
    printf("Overall Average: %.2f\n", overallAvg);

    return 0;
}
