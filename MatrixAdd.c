#include <stdio.h>

int main()
{
    float wafer1[2][2], wafer2[2][2], wafer3[2][2];
    int i, j;

    // Enter voltages for Wafer 1
    printf("Enter voltages for Wafer 1:\n");

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            printf("Enter voltage for Wafer 1[%d][%d]: ", i, j);
            scanf("%f", &wafer1[i][j]);
        }
    }

    // Enter voltages for Wafer 2
    printf("\nEnter voltages for Wafer 2:\n");

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            printf("Enter voltage for Wafer 2[%d][%d]: ", i, j);
            scanf("%f", &wafer2[i][j]);
        }
    }

    // Combine voltages
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            wafer3[i][j] = wafer1[i][j] + wafer2[i][j];
        }
    }

    // Display Wafer 1
    printf("\nWafer 1:\n");
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            printf("%.2f V\t", wafer1[i][j]);
        }
        printf("\n");
    }

    // Display Wafer 2
    printf("\nWafer 2:\n");
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            printf("%.2f V\t", wafer2[i][j]);
        }
        printf("\n");
    }

    // Display Wafer 3
    printf("\nWafer 3 (Combined Voltages):\n");
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            printf("%.2f V\t", wafer3[i][j]);
        }
        printf("\n");
    }

    return 0;
}
