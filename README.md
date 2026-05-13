# FInal-Project---XV6-Lottery-Scheduler

## Overview

This project modifies the xv6 operating system to implement a Lottery Scheduler, a probabilistic CPU scheduling algorithm that allocates CPU time based on ticket ownership.

Each runnable process is assigned a number of lottery tickets, and during each scheduling cycle, one ticket is randomly selected from the total pool. The process holding the winning ticket is scheduled to run.

### Core Idea:
- More tickets = Higher probability of CPU time
- Fewer tickets = Lower probability of CPU time

This creates proportional fairness and flexible scheduling.

---

## Learning Objectives

- Understand xv6 kernel structure
- Learn CPU scheduling concepts
- Replace Round-Robin scheduling with Lottery Scheduling
- Implement custom system calls
- Track process scheduling statistics
- Analyze fairness through testing

---

## Modified Files

- proc.c
- proc.h
- syscall.c
- syscall.h
- sysproc.c
- user.h
- usys.S
- Makefile
- pstat.h
- lotterytest.c

---

## Process Structure Changes

Two new fields were added to `struct proc`:

```c
int tickets;
int ticks;
