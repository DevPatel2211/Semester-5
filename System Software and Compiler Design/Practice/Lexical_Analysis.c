#include <stdio.h>
#include <string.h>

char *keywords[] = {
    "int", "return", "if", "else", "while", "for", "continue",
    "void", "char", "float", "double", "const", "sizeof", "case", "switch", "do", "short", "long",
    "auto"};

char *operators[] = {
    "+",
    "-",
    "*",
    "/",
    "%",
    "++",
    "--",
    "==",
    "!=",
    ">",
    "<",
    ">=",
    "<=",
};

int num_operators = sizeof(operators) / sizeof(operators[0]);
int num_of_keywords = sizeof(keywords) / sizeof(keywords[0]);

int comparision(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

int alphabet(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int number(char c)
{
    return alphabet(c) || (c >= '0' && c <= '9');
}

int keyword(const char *str)
{
    for (int i = 0; i < num_of_keywords; i++)
    {
        if (comparision(str, keywords[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int operator(const char *str)
{
    for (int i = 0; i < num_operators; i++)
    {
        if (comparision(str, operators[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int identifier(const char *str)
{
    if (alphabet(str[0]) || str[0] == '_')
    {
        for (int i = 1; str[i]; i++)
        {
            if (!number(str[i]) && str[i] != '_')
            {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

int main()
{
    // printf("%d %d", num_of_keyword, num_of_operator);

    FILE *inputfile = fopen("demo.c", "r");
    FILE *outputfile = fopen("output.txt", "w");

    if (inputfile == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    char word[100];
    int num_of_keywords = 0, num_operators = 0, num_identifiers = 0, others = 0, total = 0;

    while (fscanf(inputfile, "%s", word) != EOF)
    {
        if (keyword(word))
        {
            num_of_keywords++;
        }
        else if (operator(word))
        {
            num_operators++;
        }
        else if (identifier(word))
        {
            num_identifiers++;
        }
        else
        {
            others++;
        }
        total++;
    }

    fclose(inputfile);

    fprintf(outputfile, "Keywords: %d\nOperators: %d\nIdentifiers: %d\n Others: %d\n\nTotal Tokens: %d\n", num_of_keywords, num_operators, num_identifiers, others, total);

    // printf("Number of keywords: %d\n", num_of_keywords);
    // printf("Number of operators: %d\n", num_operators);
    // printf("Number of identifiers: %d\n", num_identifiers);
    // printf("Number of others: %d\n", others);
    // printf("Number of tokens: %d\n", total);
    return 0;
}