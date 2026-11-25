#include <stdio.h>

struct Device
{
    int id;
    int type;
    float Vf;
    float Ir;
    float Vr;
};

int main()
{
    struct Device d[100];
    int n, i;

    printf("Enter number of semiconductor devices: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of Device %d\n", i + 1);

        printf("Enter Device ID: ");
        scanf("%d", &d[i].id);

        printf("Select Device Type:\n");
        printf("1. Diode\n");
        printf("2. BJT\n");
        printf("3. MOSFET\n");
        printf("4. LED\n");
        printf("Enter device type: ");
        scanf("%d", &d[i].type);

        printf("Enter Forward Voltage (Vf): ");
        scanf("%f", &d[i].Vf);

        printf("Enter Reverse Leakage Current (Ir): ");
        scanf("%f", &d[i].Ir);

        printf("Enter Rated Voltage (Vr): ");
        scanf("%f", &d[i].Vr);
    }

    printf("\n\n--- DEVICE SPECIFICATION REPORT ---\n");

    for(i = 0; i < n; i++)
    {
        printf("\nDevice ID: %d\n", d[i].id);

        printf("Device Type: ");

        switch(d[i].type)
        {
            case 1:
                printf("Diode\n");
                break;

            case 2:
                printf("BJT\n");
                break;

            case 3:
                printf("MOSFET\n");
                break;

            case 4:
                printf("LED\n");
                break;

            default:
                printf("Invalid Type\n");
                break;
        }

        printf("Forward Voltage: %.2f V\n", d[i].Vf);
        printf("Reverse Leakage Current: %.2f\n", d[i].Ir);
        printf("Rated Voltage: %.2f V\n", d[i].Vr);

        if(d[i].Vf >= 0 && d[i].Vf <= 5 &&
           d[i].Ir >= 0 && d[i].Ir <= 10 &&
           d[i].Vr >= 0 && d[i].Vr <= 100)
        {
            printf("Status: WITHIN SPECIFICATION\n");
        }
        else
        {
            printf("Status: OUT OF SPECIFICATION\n");
        }
    }

    printf("\n--- OUT OF SPECIFICATION DEVICES ---\n");

    for(i = 0; i < n; i++)
    {
        if(d[i].Vf < 0 || d[i].Vf > 5 ||
           d[i].Ir < 0 || d[i].Ir > 10 ||
           d[i].Vr < 0 || d[i].Vr > 100)
        {
            printf("Device ID: %d\n", d[i].id);
        }
    }

    return 0;
}
