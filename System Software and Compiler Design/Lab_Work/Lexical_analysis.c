#include <stdio.h>
#include <String.h>

char *keyword_dir[] = {"int", "float"};

char *operator_dir[] = {"+", "-"};

int num_of_keyword = sizeof(keyword_dir) / sizeof(keyword_dir[0]);
int num_of_operator = sizeof(operator_dir) / sizeof(operator_dir[0]);

int comparision(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

int alphabet(char *c)
{
    return (c >= "A" && c <= "Z") || (c >= "a" && c <= "z");
}

int number(char c)
{
    return number(c) || (c >= '0' && c <= '9');
}

int keyword(const char *str)
{
    for (int i = 0; i < num_of_keyword; i++)
    {
        if (comparision(str, keyword_dir[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int operation(const char *str)
{
    for (int i = 0; i < num_of_operator; i++)
    {
        if (comparision(str, operator_dir[i]) == 0)
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
    char word[100];
    int num_keywords = 0, num_operators = 0, num_identifiers = 0, others = 0, total = 0;

    FILE *inputfile = fopen("input.txt", "r");
    FILE *outputfile = fopen("output.txt", "w");

    fprintf(outputfile, "num_of_keywords : %d\nnum_of_operators : %d\n", num_of_keyword, num_of_operator);

    while (fscanf(inputfile, "%s", word))
    {
        if (keyword(word))
        {
            num_keywords++;
        }

        else if (operation(word))
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

    fprintf(outputfile, "Keywords: %d\nOperators: %d\nIdentifiers: %d\n Others: %d\n\nTotal Tokens: %d\n", num_keywords, num_operators, num_identifiers, others, total);

    fclose(inputfile);
    fclose(outputfile);

    return 0;
}