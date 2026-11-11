#include <stdio.h>
#include "sls.h"
int first_click = 0;
int click_100 = 0;
int click_1000 = 0;

void load_achivements(void)
{
    first_click = load_data("first_click.save");
    click_100 = load_data("click_100.save");
    click_1000 = load_data("click_1000.save");
}

void unlock_achivement(const char *name, int *status, const char *save_file)
{
    if (*status)
        return;

    *status = 1;

    printf("\nAchievement unlocked: %s!\n", name);

    save_data(*status, (char *)save_file);
}

void show_achivements(void)
{
    printf("\n=== ACHIEVEMENTS ===\n");

    printf("[%c] First Click\n", first_click ? 'X' : ' ');
    printf("[%c] Getting Started (100 clicks)\n", click_100 ? 'X' : ' ');
    printf("[%c] Dedicated (1000 clicks)\n", click_1000 ? 'X' : ' ');
}
