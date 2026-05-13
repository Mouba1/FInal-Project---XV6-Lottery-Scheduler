#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

int
main(void)
{
  int i, j;
  int tickets[3] = {30, 20, 10};

  for(i = 0; i < 3; i++){
    int pid = fork();

    if(pid == 0){
      settickets(tickets[i]);
      while(1){
        for(j = 0; j < 1000000; j++)
          ;
      }
    }
  }

  sleep(500);

  struct pstat ps;
  getpinfo(&ps);

  printf(1, "PID\tTickets\tTicks\n");
  for(i = 0; i < NPROC; i++){
    if(ps.inuse[i] && ps.tickets[i] > 1){
      printf(1, "%d\t%d\t%d\n", ps.pid[i], ps.tickets[i], ps.ticks[i]);
    }
  }

  kill(-1);
  exit();
}
