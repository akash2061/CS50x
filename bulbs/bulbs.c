#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include<ctype.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    string input = get_string("Message: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        int x=128,a;
        char c = input[i];
        while (x > 0)
        {
            a = c & x;
            x = x >> 1;
            if (a==0)
            {
                print_bulb(0);
            }
            else
            {
                print_bulb(1);
            }
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
