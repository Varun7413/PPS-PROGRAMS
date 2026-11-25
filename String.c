#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int wish, n, i, j, found;
    char str1[100], str2[100], ch, sub[50];

    while (1) {
        printf("\n String Operations Menu \n");
        printf("1. Find length (strlen)\n");
        printf("2. Copy string (strcpy)\n");
        printf("3. Concatenate strings (strcat)\n");
        printf("4. Compare strings (strcmp)\n");
        printf("5. Find character (strchr)\n");
        printf("6. Find substring (strstr)\n");
        printf("7. Tokenize string (strtok)\n");
        printf("8. Convert to uppercase\n");
        printf("9. Convert to lowercase\n");
        printf("10. Exit\n");

        printf("Enter your wish: ");
        scanf("%d", &wish);
        getchar();

        switch (wish) {

            case 1:
                printf("Enter string: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';

                printf("Length = %lu\n", strlen(str1));
                break;

            case 2:
                printf("Enter source string: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';

                strcpy(str2, str1);
                printf("Copied string: %s\n", str2);
                break;

            case 3:
                printf("Enter first string: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';

                printf("Enter second string: ");
                fgets(str2, 100, stdin);
                str2[strcspn(str2, "\n")] = '\0';

                strcat(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;

            case 4:
                printf("Enter first string: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';

                printf("Enter second string: ");
                fgets(str2, 100, stdin);
                str2[strcspn(str2, "\n")] = '\0';

                {
                    int res = strcmp(str1, str2);

                    if (res == 0)
                        printf("Strings are equal.\n");
                    else if (res < 0)
                        printf("String 1 is smaller.\n");
                    else
                        printf("String 1 is greater.\n");
                }
                break;

            case 5:
                printf("Enter string: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';

                printf("Enter character to find: ");
                scanf("%c", &ch);
                getchar();

                found = 0;

                for (i = 0; str1[i] != '\0'; i++) {
                    if (str1[i] == ch) {
                        printf("Character found at position %d (index %d).\n",
                               i + 1, i);
                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                    printf("Character not found.\n");

                break;

            case 6:
                printf("Enter main string: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';

                printf("Enter substring to search: ");
                fgets(sub, 50, stdin);
                sub[strcspn(sub, "\n")] = '\0';

                found = 0;

                for (i = 0; str1[i] != '\0'; i++) {
                    for (j = 0; sub[j] != '\0'; j++) {
                        if (str1[i + j] != sub[j])
                            break;
                    }

                    if (sub[j] == '\0') {
                        printf("Substring found at position %d (index %d).\n",
                               i + 1, i);
                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                    printf("Substring not found.\n");

                break;

            case 7:
                printf("Enter string to tokenize: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';

                printf("Enter delimiter characters: ");
                fgets(sub, 50, stdin);
                sub[strcspn(sub, "\n")] = '\0';

                n = 1;
                i = 0;

                while (str1[i] != '\0') {

                    while (str1[i] != '\0' &&
                           strchr(sub, str1[i]) != NULL) {
                        i++;
                    }

                    if (str1[i] == '\0')
                        break;

                    printf("Token %d: ", n++);

                    while (str1[i] != '\0' &&
                           strchr(sub, str1[i]) == NULL) {
                        printf("%c", str1[i]);
                        i++;
                    }

                    printf("\n");
                }
                break;

            case 8:
                printf("Enter string: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';

                for (i = 0; str1[i] != '\0'; i++)
                    str1[i] = toupper((unsigned char)str1[i]);

                printf("Uppercase string: %s\n", str1);
                break;

            case 9:
                printf("Enter string: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';

                for (i = 0; str1[i] != '\0'; i++)
                    str1[i] = tolower((unsigned char)str1[i]);

                printf("Lowercase string: %s\n", str1);
                break;

            case 10:
                printf("Exiting\n");
                return 0;

            default:
                printf("Invalid wish\n");
        }
    }

    return 0;
}
