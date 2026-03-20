#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char *argv[]) {

    openlog("writer", LOG_PID, LOG_USER);

    if (argc != 3) {
        syslog(LOG_ERR, "Invalid arguments");
        return 1;
    }

    char *file = argv[1];
    char *text = argv[2];

    FILE *fp = fopen(file, "w");

    if (fp == NULL) {
        syslog(LOG_ERR, "Error opening file");
        return 1;
    }

    syslog(LOG_DEBUG, "Writing %s to %s", text, file);

    fprintf(fp, "%s", text);

    fclose(fp);
    closelog();

    return 0;
}
