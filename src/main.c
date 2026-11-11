#include <iso646.h>
#include <stdio.h>
#include "game.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char version_number[] = "1.0.0"; // Change this after every update or whatever you do.
char save_filename[] = "countersave.save";
int count(int count_amount, char end_message[])
{
    printf("Started Counting\n");

    int counter = 1;

    while (counter <= count_amount)
    {
        printf("%d\n", counter);
        sleep(1);
        counter++;
    }

    printf("%s\n", end_message);

    return 0;
}

int main(int argc, char *argv[])
{
    if (argc >= 2) {
        if (strcmp(argv[1], "--version") == 0) {
            printf("Counter Version Is Currently: %s", version_number);
            return 0;
        }
        if (strcmp(argv[1], "--game") == 0) {
            game();
            return 0;
        }
        if (strcmp(argv[1], "--help") == 0)
        {
            printf("Usage: counter <amount> <end message>\n");
            return 0;
        }
    }
    if (argc < 3)
    {
        printf("Usage: counter <amount> <end message>\n");
        return 1;
    }

    char *ending_message = argv[2];
    long amount = strtol(argv[1], NULL, 10);

    count(amount, ending_message);

    return 0;
}
