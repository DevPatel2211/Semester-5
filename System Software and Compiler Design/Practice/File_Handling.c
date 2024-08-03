#include <stdio.h>

int main()
{
    FILE *file;

    // Open a file for writing
    file = fopen("example.txt", "w");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    // Write to the file
    fputs("Hello, world!\n", file);
    fclose(file);

    // Open the file for reading
    file = fopen("example.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    // Read from the file
    char ch;
    while ((ch = fgetc(file)) != EOF)
    {
        putchar(ch); // Print character to stdout
    }

    fclose(file);
    return 0;
}
