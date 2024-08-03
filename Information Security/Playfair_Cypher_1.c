#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    // Initializations
    char matrix[5][5];
    char key[15];
    char plaintext[50];
    bool alphabet[26] = {false};
    int j, k;
    int count = 0;

    // Making the matrix
    for (int i = 0; i < strlen(key); i++)
    {
        if (count >= 5)
        {
            j++;
            k = 0;
            count = 0;
            matrix[j][k] = key[i];
            count++;
        }
        else
        {
            matrix[j][k] = key[i];
            count++;
        }
    }

    for (char ch = 'a'; ch <= 'z'; ch++)
    {

        if (ch == 'j')
        {
            continue;
        }

        if (count >= 5)
        {
            j++;
            k = 0;
            matrix[j][k] = ch;
        }
        else
        {
            matrix[j][k] = ch;
        }
    }

    // Refine the Plain Text

    // Encryption

    return 0;
}