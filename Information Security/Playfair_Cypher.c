#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void findPosition(char matrix[5][5], char ch, int *row, int *col)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matrix[i][j] == ch)
            {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

int main()
{
    char matrix[5][5];
    char key[10];
    char plaintext[15] = "HiHello";
    char ciphertext[30];
    bool included[26] = {false};
    int j = 0, k = 0;

    printf("Enter the Key: ");
    scanf("%9s", key);

    for (int i = 0; i < strlen(key); i++)
    {
        char ch = key[i];
        if (ch == 'j')
        {
            ch = 'i';
        }
        ch = tolower(ch);

        if (!included[ch - 'a'])
        {
            matrix[j][k] = ch;
            included[ch - 'a'] = true;
            k++;
            if (k == 5)
            {
                k = 0;
                j++;
            }
        }
    }

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        if (ch == 'j')
        {
            continue;
        }

        if (!included[ch - 'a'])
        {
            matrix[j][k] = ch;
            included[ch - 'a'] = true;
            k++;
            if (k == 5)
            {
                k = 0;
                j++;
            }
        }
    }

    printf("Playfair Matrix:\n");
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            printf("%c ", matrix[row][col]);
        }
        printf("\n");
    }

    int len = strlen(plaintext);
    for (int i = 0; i < len; i++)
    {
        if (plaintext[i] == 'j')
        {
            plaintext[i] = 'i';
        }
        plaintext[i] = tolower(plaintext[i]);
    }

    if (len % 2 != 0)
    {
        plaintext[len] = 'x';
        plaintext[len + 1] = '\0';
        len++;
    }

    for (int m = 0; m < len; m += 2)
    {
        if (plaintext[m] == plaintext[m + 1])
        {
            for (int n = len; n > m; n--)
            {
                plaintext[n] = plaintext[n - 1];
            }
            plaintext[m + 1] = 'x';
            len++;
            plaintext[len] = '\0';
        }
    }

    printf("Plaintext Reformed:\n");
    for (int row = 0; row < strlen(plaintext); row++)
    {
        printf("%c ", plaintext[row]);
    }
    printf("\n");

    for (int i = 0; i < len; i += 2)
    {
        int row1, col1, row2, col2;
        findPosition(matrix, plaintext[i], &row1, &col1);
        findPosition(matrix, plaintext[i + 1], &row2, &col2);

        if (row1 == row2)
        {
            ciphertext[i] = matrix[row1][(col1 + 1) % 5];
            ciphertext[i + 1] = matrix[row2][(col2 + 1) % 5];
        }
        else if (col1 == col2)
        {
            ciphertext[i] = matrix[(row1 + 1) % 5][col1];
            ciphertext[i + 1] = matrix[(row2 + 1) % 5][col2];
        }
        else
        {
            ciphertext[i] = matrix[row1][col2];
            ciphertext[i + 1] = matrix[row2][col1];
        }
    }

    ciphertext[len] = '\0';

    printf("Ciphertext:\n");
    for (int row = 0; row < len; row++)
    {
        printf("%c ", ciphertext[row]);
    }
    printf("\n");

    return 0;
}
