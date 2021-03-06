
.include "defs.hs"

.section .init

.globl _start
_start:

// Return CPU ID (0..3) Of The CPU Executed On
mrc p15,0,r0,c0,c0,5 // R0 = Multiprocessor Affinity Register (MPIDR)
ands r0,#3 // R0 = CPU ID (Bits 0..1)
bne CoreLoop // IF (CPU ID != 0) Branch To Infinite Loop (Core ID 1..3)

// Start L1 Cache
mrc p15,0,r0,c1,c0,0 // R0 = System Control Register
orr r0,#0x0004 // Data Cache (Bit 2)
orr r0,#0x0800 // Branch Prediction (Bit 11)
orr r0,#0x1000 // Instruction Caches (Bit 12)
mcr p15,0,r0,c1,c0,0 // System Control Register = R0

  ldr r0, =__bss_start__
  ldr r1, =__bss_end__
ClearBSS:
  mov r2, #0
  mov r3, #0
  strd r2, r3, [r0]
  add r0, #8
  cmp r0, r1
  blt ClearBSS

b Entry

.section .text

Entry:

  ldr sp, =(64 * 1024 * 1024)

  b MainZero

Loop:
  b Loop

CoreLoop: // Infinite Loop For Core 1..3
  b CoreLoop

.ltorg

.globl wait_some_time
wait_some_time:

w:
  subs r0, #1
  bne w

  mov pc, lr

