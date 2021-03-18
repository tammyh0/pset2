#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int get_letter_count(string text);
int get_word_count(string text);
int get_sentence_count(string text);

int main(void)
{
    // Get input text from user
    string text = get_string("Text: ");
    
    // Calculate and print reading level
    float L = ((100.0 * (float) get_letter_count(text)) / (float) get_word_count(text)); // Average number of letters per 100 words
    float S = ((100.0 * (float) get_sentence_count(text)) / (float) get_word_count(text)); // Average number of sentences per 100 words
    int index = round((0.0588 * L) - (0.296 * S) - 15.8); // Calculates grade level using special formula
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
    
}

// Returns the number of letters in the given text
int get_letter_count(string text)
{
    int letterCount = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letterCount += 1;
        }
    }
    return letterCount;
}

// Returns the number of words in the given text
int get_word_count(string text)
{
    int wordCount = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            wordCount += 1;
        }
    }
    if (wordCount > 0)
    {
        wordCount += 1;
    }
    return wordCount;
}

// Returns the number of sentences in the given text
int get_sentence_count(string text)
{
    int sentenceCount = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentenceCount += 1;
        }
    }
    return sentenceCount;
}