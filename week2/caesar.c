#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to validate if a string is numeric
bool is_numeric(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

int main(int argc, string argv[])
{
    // Check for a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Validate that the argument is a non-negative integer
    if (!is_numeric(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert the key from string to an integer
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string plaintext = get_string("plaintext:  ");

    // Encrypt plaintext
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        // Check if character is an uppercase letter
        if (isupper(c))
        {
            printf("%c", ((c - 'A' + key) % 26) + 'A');
        }
        // Check if character is a lowercase letter
        else if (islower(c))
        {
            printf("%c", ((c - 'a' + key) % 26) + 'a');
        }
        // If it's neither, just print the character as is
        else
        {
            printf("%c", c);
        }
    }

    // Print a newline at the end
    printf("\n");
    return 0;
}
