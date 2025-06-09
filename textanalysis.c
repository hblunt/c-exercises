#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* read_lines()
{
    static char text[1000] = "";
    char line[100];
    text[0] = '\0';

    printf("Enter some sentences (type END and hit enter to finish):\n");
    while(1)
    {
        fgets(line, sizeof(line), stdin);
        if (strcmp(line, "END\n") == 0) break;
        strcat(text, line);
    }

    return text;
}

void counter(char str[])
{
    int senCount = 0;
    int wordCount = 1;
    int avgWordLen = 0;
    int totalChars = 0;
    int size = strlen(str);

    for (int i = 0; i < size; i++)
    {
        if (str[i] == '.' || str[i] == '!' || str[i] == '?') senCount++;
        if (str[i] == ' ') wordCount++;
        else totalChars++;
    }

    printf("Sentences: %d\n", senCount);
    printf("Words: %d\n", wordCount);
    printf("Average chars per word: %d\n", totalChars / wordCount);
}

void frequent_word(char str[])
{
    char words[100][50];
    char count[100] = {0};
    char temp[1000];
    int unique = 0;

    strcpy(temp, str);

    char *word = strtok(temp, " \n\t.,!?");
    while(word != NULL)
    {
        int found = -1;
        for (int i = 0; i < unique; i++)
        {
            if (strcmp(words[i], word) == 0)
            {
                found = i;
                break;
            }
        }

        if (found == -1)
        {
            strcpy(words[unique], word);
            count[unique] = 1;
            unique++;
        } else {
            count[found]++;
        }

        word = strtok(NULL, " \n\t.,!?");
    }

    int max_count = 0;
    int max_index = 0;
    for (int i = 0; i < unique; i++)
    {
        if (count[i] > max_count)
        {
            max_count = count[i];
            max_index = i;
        }
    }

    printf("Most frequent word: '%s' (appears %d times)\n", words[max_index], max_count);

}

void readability(char str[])
{
    int vowels = 0;
    int words = 0;
    int sentences = 0;
    int size = strlen(str);

    for (int i = 0; i < size; i++) {
        if (str[i] == '.' || str[i] == '!' || str[i] == '?') sentences++;
    }

    char temp[1000];
    strcpy(temp, str);

    char *word = strtok(temp, " \n\t.,!?");
    while (word != NULL) {
        words++;
        for (int i = 0; i < strlen(word); i++)
        {
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') vowels++;
        }
        word = strtok(NULL, " \n\t.,!?");
    }

    float avgSenLength = (float)(words / sentences);
    float avgSyl = (float)(vowels / words);


    float readability = 206.835 - (1.015 * avgSenLength) - (84.6 * avgSyl);
    printf("Readability score of: %.2f", readability);
}


int main(void)
{
    char *str = read_lines();
    counter(str);
    frequent_word(str);
    readability(str);

    return (0);
}
