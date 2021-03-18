#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

bool valid_key_length(string key);
bool valid_key_chars(string key);
bool valid_key_no_repeat_char(string key);

int main(int argc, string argv[])
{
    // Check if single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        // Check if key is invalid
        if (!valid_key_length(argv[1]) || !valid_key_chars(argv[1]) || !valid_key_no_repeat_char(argv[1]))
        {
            printf("Key must contain 26 non-repeating, alphabetic characters.\n");
            return 1;
        }
        // Key is valid
        else 
        {
            // Get plaintext and print ciphertext
            string plaintext = get_string("plaintext: ");
            printf("ciphertext: ");
            int place = 0;
            // Print ciphertext the same case as plaintext characters
            for (int i = 0, n = strlen(plaintext); i < n; i++)
            {
                // Deal with uppercase letters
                if (isupper(plaintext[i]))
                {
                    place = plaintext[i] - 65;
                    printf("%c", toupper(argv[1][place]));
                }
                // Deal with lowercase letters
                else if (islower(plaintext[i]))
                {
                    place = plaintext[i] - 97;
                    printf("%c", tolower(argv[1][place]));
                }
                // Deal with non-letter characters
                else
                {
                    printf("%c", plaintext[i]);
                }
            }
            printf("\n");
            return 0;
        }
    }
}

// Check if key contains 26 characters
bool valid_key_length(string key)
{
    if (strlen(key) == 26)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Check if key does not contain non-letters
bool valid_key_chars(string key)
{
    bool hasLettersOnly = true;
    // Search each character for non-letters
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            hasLettersOnly = false;
        }
    }
    return hasLettersOnly;
}

// Check if key does not have repeating characters
bool valid_key_no_repeat_char(string key)
{
    bool noRepeat = true;
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        int repeatCount = 0;
        // Look for repeating characters
        for (int j = 0, k = strlen(key); j < k; j++)
        {
            if (key[i] == key[j])
            {
                repeatCount++;
            }
        }
        if (repeatCount > 1)
        {
            noRepeat = false;
        }
    }
    return noRepeat;
}