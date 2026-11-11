#include <iso646.h>
#include <stdio.h>
#include <unistd.h>

int load_data(char *file_name)
{
    FILE *file = fopen(file_name, "r");

    if (file == NULL)
    {
        return 0; // No save file yet
    }

    int saved_count = 0;

    fscanf(file, "%d", &saved_count);

    fclose(file);

    return saved_count;
}

void save_data(char data, char *file_name)
{
    FILE *file = fopen(file_name, "w");

    if (file == NULL)
    {
        printf("Failed to save data!\n");
        return;
    }

    fprintf(file, "%d\n", data);

    fclose(file);
}