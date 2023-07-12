#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int i, j, m, n, f;
  void *ptr;
  int shmid = shm_open("VK", O_RDWR | O_CREAT, 0666);
  int x = ftruncate(shmid, 4096);
  ptr = mmap(0, 4096, PROT_WRITE, MAP_SHARED, shmid, 0);
  printf("CHILD\n");
  sscanf(argv[1], "%d", &m);
  sscanf(argv[2], "%d", &n);
  m = atoi(argv[1]);
  n = atoi(argv[2]);
  for (i = m; i <= n; i++) {
    f = 0;
    for (j = 2; j <= i / 2; j++) {
      if (i % j == 0) {
        f = 1;
        break;
      }
    }
    if (f == 0) {
      sprintf(ptr, "%d ", i);
      printf("%d ", i);
      ptr += strlen(ptr);
    }
  }
  return 0;
}
