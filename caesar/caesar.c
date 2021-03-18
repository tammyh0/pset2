#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Check if arguments are valid
    if (argc == 2) 
    {
        // Check if second argument is number
        bool isNum = true;
        for (int i = 0, n = strlen(argv[1]); i < n; i++) 
        {
            if (!isdigit(argv[1][i]))
            {
                isNum = false;
            }
        }
        if (isNum == true) // Get user's plain text
        {
            string text = get_string("plaintext: ");
            printf("ciphertext: ");
            // Shift characters by the inputted key number
            for (int i = 0, n = strlen(text); i < n; i++)
            {
                // Checks if character is a letter
                if (isalpha(text[i]))
                {
                    int newNum = 0;
                    if (isupper(text[i])) // Handles uppercase letters
                    {
                        newNum = ((text[i] - 65) + atoi(argv[1])) % 26 + 65;
                        printf("%c", newNum);
                    }
                    else // Handles lowercase letters
                    {
                        newNum = ((text[i] - 97) + atoi(argv[1])) % 26 + 97;
                        printf("%c", newNum);
                    }
                }
                else
                {
                    printf("%c", text[i]);
                }
            }
            printf("\n");
            return 0;
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}