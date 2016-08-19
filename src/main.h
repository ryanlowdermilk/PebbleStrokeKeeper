#pragma once
  
// This is a custom defined key for saving our count field
#define NUM_CURRENT_HOLE_PKEY 0
#define NUM_TOTAL_PKEY 1
#define NUM_HOLE_PKEY 2
#define NUM_HOLE1_PKEY 3
#define NUM_HOLE2_PKEY 4
#define NUM_HOLE3_PKEY 5
#define NUM_HOLE4_PKEY 6
#define NUM_HOLE5_PKEY 7
#define NUM_HOLE6_PKEY 8
#define NUM_HOLE7_PKEY 9
#define NUM_HOLE8_PKEY 10
#define NUM_HOLE9_PKEY 11
#define NUM_HOLE10_PKEY 12
#define NUM_HOLE11_PKEY 13
#define NUM_HOLE12_PKEY 14
#define NUM_HOLE13_PKEY 15
#define NUM_HOLE14_PKEY 16
#define NUM_HOLE15_PKEY 17
#define NUM_HOLE16_PKEY 18
#define NUM_HOLE17_PKEY 19
#define NUM_HOLE18_PKEY 20
 
#define NUM_CURRENT_HOLE_DEFAULT 0
#define NUM_TOTAL_DEFAULT 0
#define NUM_HOLE_DEFAULT 1  

// Front 9 Scores
#define NUM_HOLE1_DEFAULT 0
#define NUM_HOLE2_DEFAULT 0
#define NUM_HOLE3_DEFAULT 0
#define NUM_HOLE4_DEFAULT 0
#define NUM_HOLE5_DEFAULT 0
#define NUM_HOLE6_DEFAULT 0
#define NUM_HOLE7_DEFAULT 0
#define NUM_HOLE8_DEFAULT 0
#define NUM_HOLE9_DEFAULT 0
  
// Back 9 Scores
#define NUM_HOLE10_DEFAULT 0
#define NUM_HOLE11_DEFAULT 0
#define NUM_HOLE12_DEFAULT 0
#define NUM_HOLE13_DEFAULT 0
#define NUM_HOLE14_DEFAULT 0
#define NUM_HOLE15_DEFAULT 0
#define NUM_HOLE16_DEFAULT 0
#define NUM_HOLE17_DEFAULT 0
#define NUM_HOLE18_DEFAULT 0

// We'll save the count in memory from persistent storage
static int num_current_hole = NUM_CURRENT_HOLE_DEFAULT;
static int num_total = NUM_TOTAL_DEFAULT;
static int num_hole = NUM_HOLE_DEFAULT;
static int num_hole1 = NUM_HOLE1_DEFAULT;
static int num_hole2 = NUM_HOLE2_DEFAULT;
static int num_hole3 = NUM_HOLE3_DEFAULT;
static int num_hole4 = NUM_HOLE4_DEFAULT;
static int num_hole5 = NUM_HOLE5_DEFAULT;
static int num_hole6 = NUM_HOLE6_DEFAULT;
static int num_hole7 = NUM_HOLE7_DEFAULT;
static int num_hole8 = NUM_HOLE8_DEFAULT;
static int num_hole9 = NUM_HOLE9_DEFAULT;
static int num_hole10 = NUM_HOLE10_DEFAULT;
static int num_hole11 = NUM_HOLE11_DEFAULT;
static int num_hole12 = NUM_HOLE12_DEFAULT;
static int num_hole13 = NUM_HOLE13_DEFAULT;
static int num_hole14 = NUM_HOLE14_DEFAULT;
static int num_hole15 = NUM_HOLE15_DEFAULT;
static int num_hole16 = NUM_HOLE16_DEFAULT;
static int num_hole17 = NUM_HOLE17_DEFAULT;
static int num_hole18 = NUM_HOLE18_DEFAULT;

void window_push();
