#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define MAX_DEPTH 100.0
#define MAX_PRESSURE 10.0
#define MAX_TEMP 40.0
#define MIN_BATTERY 20.0

// Structure to store underwater robot sensor data
struct Robot
{
    int id;
    float depth;
    float pressure;
    float temperature;
    float battery;
    char sensorStatus[20];
};

// Function declarations
void addRecord();
void displayRecords();
void analyzeData();
void generateReport();
int readRecords(struct Robot *r);
void checkSafety(struct Robot *r);

// Read records from file using pointer
int readRecords(struct Robot *r)
{
    FILE *fp;
    int count = 0;

    fp = fopen("robot_data.txt", "r");

    if (fp == NULL)
        return 0;

    while (count < MAX &&
           fscanf(fp, "%d,%f,%f,%f,%f,%19s",
                  &(r + count)->id,
                  &(r + count)->depth,
                  &(r + count)->pressure,
                  &(r + count)->temperature,
                  &(r + count)->battery,
                  (r + count)->sensorStatus) == 6)
    {
        count++;
    }

    fclose(fp);
    return count;
}

// Check unsafe conditions
void checkSafety(struct Robot *r)
{
    int unsafe = 0;

    printf("\nSafety Analysis:\n");

    if (r->depth > MAX_DEPTH)
    {
        printf("WARNING: Excessive depth!\n");
        unsafe = 1;
    }

    if (r->pressure > MAX_PRESSURE)
    {
        printf("WARNING: High pressure!\n");
        unsafe = 1;
    }

    if (r->temperature > MAX_TEMP)
    {
        printf("WARNING: High temperature!\n");
        unsafe = 1;
    }

    if (r->battery < MIN_BATTERY)
    {
        printf("WARNING: Low battery!\n");
        unsafe = 1;
    }

    if (r->sensorStatus[0] == 'F')
    {
        printf("WARNING: Sensor fault detected!\n");
        unsafe = 1;
    }

    if (unsafe == 0)
        printf("STATUS: All parameters are NORMAL.\n");
    else
        printf("STATUS: UNSAFE CONDITION DETECTED!\n");
}

// Add new robot record
void addRecord()
{
    FILE *fp;
    struct Robot r;

    fp = fopen("robot_data.txt", "a");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("\nEnter Robot ID: ");
    scanf("%d", &r.id);

    printf("Enter Depth (meters): ");
    scanf("%f", &r.depth);

    printf("Enter Pressure: ");
    scanf("%f", &r.pressure);

    printf("Enter Temperature: ");
    scanf("%f", &r.temperature);

    printf("Enter Battery Percentage: ");
    scanf("%f", &r.battery);

    printf("Enter Sensor Status (OK/FAULT): ");
    scanf("%19s", r.sensorStatus);

    fprintf(fp, "%d,%.2f,%.2f,%.2f,%.2f,%s\n",
            r.id,
            r.depth,
            r.pressure,
            r.temperature,
            r.battery,
            r.sensorStatus);

    fclose(fp);

    printf("\nRecord saved successfully!\n");

    checkSafety(&r);
}

// Display all historical records
void displayRecords()
{
    struct Robot r[MAX];
    struct Robot *ptr = r;

    int i, count;

    count = readRecords(ptr);

    if (count == 0)
    {
        printf("\nNo records found!\n");
        return;
    }

    printf("\n========== HISTORICAL RECORDS ==========\n");

    for (i = 0; i < count; i++)
    {
        printf("\nRobot ID: %d", (ptr + i)->id);
        printf("\nDepth: %.2f", (ptr + i)->depth);
        printf("\nPressure: %.2f", (ptr + i)->pressure);
        printf("\nTemperature: %.2f", (ptr + i)->temperature);
        printf("\nBattery: %.2f%%", (ptr + i)->battery);
        printf("\nSensor: %s\n", (ptr + i)->sensorStatus);
    }
}

// Analyze all historical data
void analyzeData()
{
    struct Robot r[MAX];
    struct Robot *ptr = r;

    int i, count, unsafeCount = 0;
    float totalDepth = 0;
    float totalPressure = 0;
    float totalTemp = 0;
    float totalBattery = 0;

    count = readRecords(ptr);

    if (count == 0)
    {
        printf("\nNo data available for analysis!\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        totalDepth += (ptr + i)->depth;
        totalPressure += (ptr + i)->pressure;
        totalTemp += (ptr + i)->temperature;
        totalBattery += (ptr + i)->battery;

        if ((ptr + i)->depth > MAX_DEPTH ||
            (ptr + i)->pressure > MAX_PRESSURE ||
            (ptr + i)->temperature > MAX_TEMP ||
            (ptr + i)->battery < MIN_BATTERY ||
            (ptr + i)->sensorStatus[0] == 'F')
        {
            unsafeCount++;
        }
    }

    printf("\n========== DATA ANALYSIS ==========\n");

    printf("\nTotal Records: %d", count);

    printf("\nAverage Depth: %.2f meters",
           totalDepth / count);

    printf("\nAverage Pressure: %.2f",
           totalPressure / count);

    printf("\nAverage Temperature: %.2f",
           totalTemp / count);

    printf("\nAverage Battery: %.2f%%",
           totalBattery / count);

    printf("\nUnsafe Records: %d", unsafeCount);

    printf("\nSafe Records: %d\n", count - unsafeCount);
}

// Generate inspection report in a separate file
void generateReport()
{
    struct Robot r[MAX];
    struct Robot *ptr = r;

    FILE *fp;

    int i, count, unsafeCount = 0;

    count = readRecords(ptr);

    if (count == 0)
    {
        printf("\nNo records available!\n");
        return;
    }

    fp = fopen("inspection_report.txt", "w");

    if (fp == NULL)
    {
        printf("\nUnable to create report!\n");
        return;
    }

    fprintf(fp, "UNDERWATER ROBOT INSPECTION REPORT\n");
    fprintf(fp, "===================================\n");

    for (i = 0; i < count; i++)
    {
        fprintf(fp, "\nRobot ID: %d", (ptr + i)->id);
        fprintf(fp, "\nDepth: %.2f", (ptr + i)->depth);
        fprintf(fp, "\nPressure: %.2f", (ptr + i)->pressure);
        fprintf(fp, "\nTemperature: %.2f",
                (ptr + i)->temperature);
        fprintf(fp, "\nBattery: %.2f%%",
                (ptr + i)->battery);
        fprintf(fp, "\nSensor Status: %s",
                (ptr + i)->sensorStatus);

        if ((ptr + i)->depth > MAX_DEPTH ||
            (ptr + i)->pressure > MAX_PRESSURE ||
            (ptr + i)->temperature > MAX_TEMP ||
            (ptr + i)->battery < MIN_BATTERY ||
            (ptr + i)->sensorStatus[0] == 'F')
        {
            fprintf(fp, "\nResult: UNSAFE");
            unsafeCount++;
        }
        else
        {
            fprintf(fp, "\nResult: SAFE");
        }

        fprintf(fp, "\n-----------------------------\n");
    }

    fprintf(fp, "\nTOTAL RECORDS: %d", count);
    fprintf(fp, "\nUNSAFE RECORDS: %d", unsafeCount);
    fprintf(fp, "\nSAFE RECORDS: %d", count - unsafeCount);

    fclose(fp);

    printf("\nInspection report generated successfully!");
    printf("\nFile name: inspection_report.txt\n");
}

// Main function
int main()
{
    int choice;

    do
    {
        printf("\n\n========================================");
        printf("\n UNDERWATER ROBOT INSPECTION SYSTEM");
        printf("\n========================================");

        printf("\n1. Add Robot Sensor Record");
        printf("\n2. Display Historical Records");
        printf("\n3. Analyze Sensor Data");
        printf("\n4. Generate Inspection Report");
        printf("\n5. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addRecord();
                break;

            case 2:
                displayRecords();
                break;

            case 3:
                analyzeData();
                break;

            case 4:
                generateReport();
                break;

            case 5:
                printf("\nExiting Program...\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
