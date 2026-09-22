#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Global variable to count signal triggers
volatile sig_atomic_t signal_count = 0;

void handle_sigint(int sig) {
    signal_count++;

    if (signal_count < 3) {
        printf("\nSIGINT received! Ctrl+C pressed %d time(s).\n", signal_count);
        printf("Press Ctrl+C %d more time(s) to exit.\n", 3 - signal_count);
    } else {
        printf("\nSIGINT received 3 times. Exiting program...\n");
        exit(0);
    }
}

int main() {
    // Register signal handler
    signal(SIGINT, handle_sigint);

    printf("Program running (PID: %d). Try pressing Ctrl+C...\n", getpid());

    while (1) {
        sleep(1);
    }

    return 0;
}
