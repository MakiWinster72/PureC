#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <seconds>\n", argv[0]);
    return 1;
  }

  int seconds = atoi(argv[1]);
  if (seconds <= 0) {
    fprintf(stderr, "Error: seconds must be positive\n");
    return 1;
  }

  for (int i = seconds; i >= 0; i--) {
    printf("\r\033[KCountdown: %d", i);
    fflush(stdout);
    sleep(1);
  }

  printf("\nDone.\n");
  return 0;
}
