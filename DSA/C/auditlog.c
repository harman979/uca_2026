#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define LOGFILE "audit.log"
#define BUF_SIZE 1024

void write_str(int fd, const char *s) { 
    write(fd, s, strlen(s));
}

void write_num(int fd, int n) {
    char buf[20];
    int i = 0;

    if (n == 0) {
        buf[i++] = '0';
    } else {
        char temp[20];
        int j = 0;
        while (n > 0) {
            temp[j++] = (n % 10) + '0';
            n /= 10;
        }
        while (j > 0)
            buf[i++] = temp[--j];
    }

    write(fd, buf, i);
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        write_str(1, "Usage:\n");
        write_str(1, "./auditlog --add \"message\"\n");
        write_str(1, "./auditlog --view\n");
        return 1;
    }

    if (strcmp(argv[1], "--add") == 0) {

        if (argc < 3) {
            write_str(1, "Missing log message\n");
            return 1;
        }

        int fd = open(LOGFILE, O_WRONLY | O_CREAT | O_APPEND, 0644);
        if (fd < 0) {
            write_str(1, "Cannot open log file\n");
            return 1;
        }

        write_str(fd, argv[2]);
        write_str(fd, "\n");

        close(fd);
    }

    else if (strcmp(argv[1], "--view") == 0) {

        int fd = open(LOGFILE, O_RDONLY);

        if (fd < 0) {
            write_str(1, "No log file found.\n");
            return 1;
        }

        char buf[BUF_SIZE];
        ssize_t bytes;
        int line = 1;
        int start = 1;

        while ((bytes = read(fd, buf, BUF_SIZE)) > 0) {

            for (ssize_t i = 0; i < bytes; i++) {

                if (start) {
                    write_num(1, line++);
                    write_str(1, ": ");
                    start = 0;
                }

                write(1, &buf[i], 1);

                if (buf[i] == '\n')
                    start = 1;
            }
        }

        close(fd);
    }

    else {
        write_str(1, "Unknown command\n");
    }

    return 0;
}