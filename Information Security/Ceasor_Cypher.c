#include <stdio.h>

int main()
{
    char a[100];
    int key;

    printf("Enter the Text for Encryption: ");
    fgets(a, sizeof(a), stdin);

    printf("Enter the key to Encrypt the data : ");
    scanf("%d", &key);

    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == '\n')
        {
            a[i] = '\0';
            break;
        }
    }

    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == ' ')
        {
            continue;
        }
        else if (a[i] >= 'A' && a[i] <= 'Z')
        {
            a[i] = ((a[i] - 'A' + key) % 26) + 'A';
        }
        else if (a[i] >= 'a' && a[i] <= 'z')
        {
            a[i] = ((a[i] - 'a' + key) % 26) + 'a';
        }
        else if (a[i] >= '0' && a[i] <= '9')
        {
            a[i] = ((a[i] - '0' + key) % 10) + '0';
        }
    }

    printf("Encrypted Text: %s\n", a);

    printf("Enter the key to Decrypted the data : ");
    scanf("%d", &key);

    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == ' ')
        {
            continue;
        }
        else if (a[i] >= 'A' && a[i] <= 'Z')
        {
            a[i] = ((a[i] - 'A' - key + 26) % 26) + 'A';
        }
        else if (a[i] >= 'a' && a[i] <= 'z')
        {
            a[i] = ((a[i] - 'a' - key + 26) % 26) + 'a';
        }
        else if (a[i] >= '0' && a[i] <= '9')
        {
            a[i] = ((a[i] - '0' - key + 10) % 10) + '0';
        }
    }

    printf("Decrypted Text: %s\n", a);

    return 0;
}
