#include <stdio.h>

int main()
{
    int a, b;
    char ch;

    printf("Enter operator (+, -, *, /, %%): ");
    scanf(" %c", &ch);

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    switch(ch)
    {
        case '+':
            printf("%d\n", a + b);
            break;

        case '-':
            printf("%d\n", a - b);
            break;

        case '*':
            printf("%d\n", a * b);
            break;

        case '/':
            if(b != 0)
                printf("%d\n", a / b);
            else
                printf("Cannot divide by zero");
            break;

        case '%':
            if(b != 0)
                printf("%d/n", a % b);
            else
                printf("Cannot divide by zero");
            break;

        default:
            printf("Invalid operator");
    }

    return 0;
}
