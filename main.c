#include <stdlib.h>
#include <stdio.h>

static int    count_words(char const *s, char c)
{
    int    count;
    int    in_quotes;

    count = 0;
    in_quotes = 0;
    while (*s)
    {
        if (*s == c && !in_quotes)
            count++;
        else if (*s == '\'')
            in_quotes = !in_quotes;
        s++;
    }
    if (!in_quotes && *s == '\0')
        count++;
    return (count);
}

static char    *copy_word(char const *s, char c)
{
    char    *word;
    int        len;
    int        in_quotes;

    len = 0;
    in_quotes = 0;
    while (s[len] && (s[len] != c || in_quotes))
    {
        if (s[len] == '\'')
            in_quotes = !in_quotes;
        len++;
    }
    word = (char *)malloc(sizeof(char) * (len + 1));
    if (!word)
        return (NULL);
    len = 0;
    in_quotes = 0;
    while (s[len] && (s[len] != c || in_quotes))
    {
        if (s[len] == '\'')
            in_quotes = !in_quotes;
        word[len] = s[len];
        len++;
    }
    word[len] = '\0';
    return (word);
}

char    **ft_split(char const *s, char c)
{
    char    **result;
    int        word_count;
    int        i;

    if (!s)
        return (NULL);
    word_count = count_words(s, c);
    result = (char **)malloc(sizeof(char *) * (word_count + 1));
    if (!result)
        return (NULL);
    i = 0;
    while (*s)
    {
        if (*s != c)
        {
            result[i++] = copy_word(s, c);
            while (*s && (*s != c || (*(s - 1) == '\'' && *(s + 1) == '\'')))
                s++;
        }
        else
            s++;
    }
    result[i] = NULL;
    return (result);
}

int main (void)
{
  char **string = ft_split("tr ' ' p1 p2", ' ');
  printf("%s \n", string[0]);
  printf("%s \n", string[1]);
  printf("%s \n", string[2]);
  printf("%s \n", string[3]);
  printf("%s \n", string[4]);
}

// int main (void)
// {
//   char **string = ft_split("tr ex ' X'", ' ');
// }

// int main (void)
// {
//   char **string = ft_split("tr ' ' p", ' ');
// }