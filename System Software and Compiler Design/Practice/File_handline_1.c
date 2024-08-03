#include <stdio.h>
#include <ctype.h>

// Function to check if a character is whitespace
int is_whitespace(char ch)
{
    return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r';
}

// Function to remove white spaces and comments from the file
void cleanFile(const char *inputFilename, const char *outputFilename)
{
    FILE *inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL)
    {
        perror("Error opening input file");
        return;
    }

    FILE *outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL)
    {
        perror("Error opening output file");
        fclose(inputFile);
        return;
    }

    int ch;
    while ((ch = fgetc(inputFile)) != EOF)
    {
        // Skip white spaces
        if (is_whitespace(ch))
        {
            continue;
        }

        // Handle single-line comments
        if (ch == '/')
        {
            int next_ch = fgetc(inputFile);
            if (next_ch == '/')
            { // Single-line comment
                // while ((ch = fgetc(inputFile)) != EOF && ch != '\n');
                continue;
            }
            else if (next_ch == '*')
            { // Multi-line comment
                while ((ch = fgetc(inputFile)) != EOF)
                {
                    if (ch == '*')
                    {
                        if ((ch = fgetc(inputFile)) == '/')
                        {
                            break;
                        }
                        else
                        {
                            ungetc(ch, inputFile);
                        }
                    }
                }
                continue;
            }
            else
            {
                ungetc(next_ch, inputFile);
            }
        }

        // Write the character to the output file
        fputc(ch, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}

int main()
{
    const char *inputFilename = "input.c";
    const char *outputFilename = "output.c";

    cleanFile(inputFilename, outputFilename);

    printf("File cleaned and written to %s\n", outputFilename);

    return 0;
}