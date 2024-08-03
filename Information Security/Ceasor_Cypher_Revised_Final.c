#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encryption(char *plain_text, int key)
{
    int key1 = key / 100;
    int key2 = (key / 10) % 10;
    int key3 = key % 10;
    int count = 0;

    for (int i = 0; plain_text[i] != '\0'; i++)
    {
        if (isalpha(plain_text[i]))
        {
            char base = isupper(plain_text[i]) ? 'A' : 'a';
            int shift;

            if (count % 3 == 0)
            {
                shift = key1;
            }
            else if (count % 3 == 1)
            {
                shift = key2;
            }
            else
            {
                shift = key3;
            }

            plain_text[i] = (plain_text[i] - base + shift) % 26 + base;
            count++;
        }
    }
}

void decryption(char *cipher_text, int key)
{
    int key1 = key / 100;
    int key2 = (key / 10) % 10;
    int key3 = key % 10;
    int count = 0;

    for (int i = 0; cipher_text[i] != '\0'; i++)
    {
        if (isalpha(cipher_text[i]))
        {
            char base = isupper(cipher_text[i]) ? 'A' : 'a';
            int shift;

            if (count % 3 == 0)
            {
                shift = key1;
            }
            else if (count % 3 == 1)
            {
                shift = key2;
            }
            else
            {
                shift = key3;
            }

            cipher_text[i] = (cipher_text[i] - base - shift + 26) % 26 + base;
            count++;
        }
    }
}

int main()
{
    char text[1000];
    int key;

    printf("Enter input string: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; // Remove newline if present

    printf("Plain Text is: %s\n", text);

    printf("Enter three digit key: ");
    scanf("%d", &key);

    encryption(text, key);
    printf("Encrypted Text is: %s\n", text);

    decryption(text, key);
    printf("Decrypted Text is: %s\n", text);

    return 0;
}