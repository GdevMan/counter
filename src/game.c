#include <stdio.h>
#include <ctype.h>
#include "sls.h"
#include "achivements.h"
#include <string.h>

void lowercase(char input[])
{
    for (int i = 0; input[i] != '\0'; i++)
    {
        input[i] = tolower((unsigned char)input[i]);
    }
}

void game(void)
{
    int counts = 0;
    char input[100];

    int first_click = load_data("first_click.save");
    int click_100 = load_data("click_100.save");
    int click_1000 = load_data("click_1000.save");
    int click_10000 = load_data("click_10000.save");

    printf("=== COUNT CLICKER ===\n");
    printf("Type 'click' to earn clicks!\n");
    printf("Type 'achievements' to view achievements.\n");
    printf("Type 'quit' to quit!\n");

    while (1)
    {
        printf("> ");

        if (scanf("%99s", input) != 1)
            break;

        lowercase(input);

        if (strcmp(input, "click") == 0)
        {
            counts++;

            if (counts >= 1)
                unlock_achivement("First Click", &first_click, "first_click.save");

            if (counts >= 100)
                unlock_achivement("Getting Started", &click_100, "click_100.save");

            if (counts >= 1000)
                unlock_achivement("Dedicated", &click_1000, "click_1000.save");
        }

        else if (strcmp(input, "achievements") == 0)
        {
            printf("\n=== ACHIEVEMENTS ===\n");

            printf("[%c] First Click\n", first_click ? 'X' : ' ');
            printf("[%c] Getting Started (100 clicks)\n", click_100 ? 'X' : ' ');
            printf("[%c] Dedicated (1000 clicks)\n", click_1000 ? 'X' : ' ');
            printf("[%c] Insanity (10000 clicks)\n", click_10000 ? 'X' : ' ');

            printf("\n");
        }

        else if (strcmp(input, "quit") == 0)
        {
            printf("Thanks for playing!\n");
            break;
        }

        else
        {
            continue;
        }
    }
}