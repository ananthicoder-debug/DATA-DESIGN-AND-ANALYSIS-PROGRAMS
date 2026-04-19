#include <stdio.h>
#include <string.h>

#define MAX 256

int shift[MAX];

void shiftTable(char pattern[])
{
    int m = strlen(pattern);
    int i;

    for(i = 0; i < MAX; i++)
        shift[i] = m;

    for(i = 0; i < m-1; i++)
        shift[(int)pattern[i]] = m - 1 - i;
}

int horspool(char text[], char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);
    int i = m - 1;
    int k;

    while(i < n)
    {
        k = 0;

        while(k < m && pattern[m-1-k] == text[i-k])
            k++;

        if(k == m)
            return i - m + 1;

        else
            i = i + shift[(int)text[i]];
    }

    return -1;
}

int main()
{
    char text[100], pattern[100];
    int pos;

    printf("Enter the text: ");
    scanf("%99s",text);

    printf("Enter the pattern: ");
    scanf("%99s",pattern);

    shiftTable(pattern);

    pos = horspool(text, pattern);

    if(pos >= 0)
        printf("Pattern found at position %d", pos);
    else
        printf("Pattern not found");

    return 0;
}
