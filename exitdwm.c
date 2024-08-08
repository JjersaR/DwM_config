#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void exitdwm() {
    FILE *exit_menu;
    char exit_action[16];

    #define S_LOCK "Lock"
    #define S_RESTART_DWM "restart Dwm"
    #define S_OFFSCREEN "Off-screen"
    #define S_EXIT "Exit"
    #define S_REBOOT "Reboot"
    #define S_SHUTDOWN "Shutdown"
    #define S_LOCK_ICON "\uf023"            // <= FontAwesome icons
    #define S_RESTART_DWM_ICON "\uf01e"
    #define S_OFFSCREEN_ICON "\uf108"
    #define S_EXIT_ICON "\uf2f5"
    #define S_REBOOT_ICON "\uf021"
    #define S_SHUTDOWN_ICON "\uf011"
    #define S_FORMAT(ACTION) S_##ACTION##_ICON " " S_##ACTION
    #define S_FORMAT_CLEAR "sed 's/^..//'"

    exit_menu = popen(
        "echo \""
        S_FORMAT(LOCK) "\n"
        S_FORMAT(RESTART_DWM) "\n"
        S_FORMAT(OFFSCREEN) "\n"
        S_FORMAT(EXIT) "\n"
        S_FORMAT(REBOOT) "\n"
        S_FORMAT(SHUTDOWN)
        "\" | dmenu -p exit: | " S_FORMAT_CLEAR,
        "r"
    );

    if (exit_menu == NULL || fscanf(exit_menu, "%15[a-zA-Z -]", exit_action) == EOF) {
        fputs("Error. Failure in exit_dwm.", stderr);
        pclose(exit_menu);
        return;
    }

    if (strcmp(exit_action, S_LOCK) == 0) {
        system("slock & sleep .5; xset dpms force off");
    } else if (strcmp(exit_action, S_RESTART_DWM) == 0) {
        system("pkill dwm");
        // Optionally, you can use `exec` to restart dwm immediately
        // exec("dwm");
    } else if (strcmp(exit_action, S_OFFSCREEN) == 0) {
        system("sleep .5; xset dpms force off");
    } else if (strcmp(exit_action, S_EXIT) == 0) {
        system("pkill dwm");
    } else if (strcmp(exit_action, S_REBOOT) == 0) {
        system("systemctl reboot");
    } else if (strcmp(exit_action, S_SHUTDOWN) == 0) {
        system("systemctl poweroff -i");
    }

    pclose(exit_menu);

    #undef S_LOCK
    #undef S_RESTART_DWM
    #undef S_OFFSCREEN
    #undef S_EXIT
    #undef S_REBOOT
    #undef S_SHUTDOWN
    #undef S_LOCK_ICON
    #undef S_RESTART_DWM_ICON
    #undef S_OFFSCREEN_ICON
    #undef S_EXIT_ICON
    #undef S_REBOOT_ICON
    #undef S_SHUTDOWN_ICON
    #undef S_FORMAT
    #undef S_FORMAT_CLEAR
}
