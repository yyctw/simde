#define SIMDE_TEST_ARM_NEON_INSN ld3

#include "test-neon.h"
#include "../../../simde/arm/neon/ld3.h"

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vld3_s8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int8_t a[24];
    int8_t r[3][8];
  } test_vec[] = {
    { {
      -INT8_C( 125),
       INT8_C(  63),
      -INT8_C(  63),
      -INT8_C(  82),
      -INT8_C(  12),
      -INT8_C( 118),
      -INT8_C(  51),
       INT8_C(  81),
       INT8_C(  94),
      -INT8_C( 114),
       INT8_C(  72),
       INT8_C(  42),
       INT8_C( 105),
      -INT8_C(  10),
      -INT8_C(  88),
       INT8_C(   0),
       INT8_C(  76),
      -INT8_C(  57),
      -INT8_C(  73),
       INT8_C(  20),
      -INT8_C(   6),
       INT8_C( 100),
      -INT8_C(  89),
       INT8_C(  16),
      },
      { { -INT8_C( 125), -INT8_C(  82), -INT8_C(  51), -INT8_C( 114),  INT8_C( 105),  INT8_C(   0), -INT8_C(  73),  INT8_C( 100) },
        {  INT8_C(  63), -INT8_C(  12),  INT8_C(  81),  INT8_C(  72), -INT8_C(  10),  INT8_C(  76),  INT8_C(  20), -INT8_C(  89) },
        { -INT8_C(  63), -INT8_C( 118),  INT8_C(  94),  INT8_C(  42), -INT8_C(  88), -INT8_C(  57), -INT8_C(   6),  INT8_C(  16) },
      },
    },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8x3_t r = simde_vld3_s8(test_vec[i].a);

    simde_int8x8x3_t expected = {
        {simde_vld1_s8(test_vec[i].r[0]), simde_vld1_s8(test_vec[i].r[1]), simde_vld1_s8(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_i8x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i8x8(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i8x8(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a[12];
    simde_float16_t r[3][4];
  } test_vec[] = {
     { {  SIMDE_FLOAT16_VALUE(37.48), SIMDE_FLOAT16_VALUE(43.92), SIMDE_FLOAT16_VALUE(23.99), SIMDE_FLOAT16_VALUE(-35.43), SIMDE_FLOAT16_VALUE(5.05), SIMDE_FLOAT16_VALUE(23.98),
        SIMDE_FLOAT16_VALUE(12.03), SIMDE_FLOAT16_VALUE(5.29), SIMDE_FLOAT16_VALUE(-23.02), SIMDE_FLOAT16_VALUE(-4.98), SIMDE_FLOAT16_VALUE(26.21), SIMDE_FLOAT16_VALUE(18.74) },
     { {  SIMDE_FLOAT16_VALUE(37.48), SIMDE_FLOAT16_VALUE(-35.43), SIMDE_FLOAT16_VALUE(12.03), SIMDE_FLOAT16_VALUE(-4.98) },
       {  SIMDE_FLOAT16_VALUE(43.92), SIMDE_FLOAT16_VALUE(5.05), SIMDE_FLOAT16_VALUE(5.29), SIMDE_FLOAT16_VALUE(26.21) },
       {  SIMDE_FLOAT16_VALUE(23.99), SIMDE_FLOAT16_VALUE(23.98), SIMDE_FLOAT16_VALUE(-23.02), SIMDE_FLOAT16_VALUE(18.74) } } },
     { {  SIMDE_FLOAT16_VALUE(42.18), SIMDE_FLOAT16_VALUE(31.30), SIMDE_FLOAT16_VALUE(25.00), SIMDE_FLOAT16_VALUE(-28.75), SIMDE_FLOAT16_VALUE(25.17), SIMDE_FLOAT16_VALUE(18.49),
        SIMDE_FLOAT16_VALUE(-18.33), SIMDE_FLOAT16_VALUE(5.37), SIMDE_FLOAT16_VALUE(24.27), SIMDE_FLOAT16_VALUE(-41.97), SIMDE_FLOAT16_VALUE(9.83), SIMDE_FLOAT16_VALUE(-0.27) },
     { {  SIMDE_FLOAT16_VALUE(42.18), SIMDE_FLOAT16_VALUE(-28.75), SIMDE_FLOAT16_VALUE(-18.33), SIMDE_FLOAT16_VALUE(-41.97) },
       {  SIMDE_FLOAT16_VALUE(31.30), SIMDE_FLOAT16_VALUE(25.17), SIMDE_FLOAT16_VALUE(5.37), SIMDE_FLOAT16_VALUE(9.83) },
       {  SIMDE_FLOAT16_VALUE(25.00), SIMDE_FLOAT16_VALUE(18.49), SIMDE_FLOAT16_VALUE(24.27), SIMDE_FLOAT16_VALUE(-0.27) } } },
     { {  SIMDE_FLOAT16_VALUE(-21.37), SIMDE_FLOAT16_VALUE(9.46), SIMDE_FLOAT16_VALUE(-7.71), SIMDE_FLOAT16_VALUE(30.30), SIMDE_FLOAT16_VALUE(-10.69), SIMDE_FLOAT16_VALUE(3.64),
        SIMDE_FLOAT16_VALUE(-43.24), SIMDE_FLOAT16_VALUE(13.34), SIMDE_FLOAT16_VALUE(31.94), SIMDE_FLOAT16_VALUE(-23.61), SIMDE_FLOAT16_VALUE(40.34), SIMDE_FLOAT16_VALUE(37.79) },
     { {  SIMDE_FLOAT16_VALUE(-21.37), SIMDE_FLOAT16_VALUE(30.30), SIMDE_FLOAT16_VALUE(-43.24), SIMDE_FLOAT16_VALUE(-23.61) },
       {  SIMDE_FLOAT16_VALUE(9.46), SIMDE_FLOAT16_VALUE(-10.69), SIMDE_FLOAT16_VALUE(13.34), SIMDE_FLOAT16_VALUE(40.34) },
       {  SIMDE_FLOAT16_VALUE(-7.71), SIMDE_FLOAT16_VALUE(3.64), SIMDE_FLOAT16_VALUE(31.94), SIMDE_FLOAT16_VALUE(37.79) } } },
     { {  SIMDE_FLOAT16_VALUE(3.11), SIMDE_FLOAT16_VALUE(22.56), SIMDE_FLOAT16_VALUE(15.35), SIMDE_FLOAT16_VALUE(27.37), SIMDE_FLOAT16_VALUE(22.92), SIMDE_FLOAT16_VALUE(-29.85),
        SIMDE_FLOAT16_VALUE(-16.70), SIMDE_FLOAT16_VALUE(47.88), SIMDE_FLOAT16_VALUE(-39.84), SIMDE_FLOAT16_VALUE(23.71), SIMDE_FLOAT16_VALUE(28.60), SIMDE_FLOAT16_VALUE(10.29) },
     { {  SIMDE_FLOAT16_VALUE(3.11), SIMDE_FLOAT16_VALUE(27.37), SIMDE_FLOAT16_VALUE(-16.70), SIMDE_FLOAT16_VALUE(23.71) },
       {  SIMDE_FLOAT16_VALUE(22.56), SIMDE_FLOAT16_VALUE(22.92), SIMDE_FLOAT16_VALUE(47.88), SIMDE_FLOAT16_VALUE(28.60) },
       {  SIMDE_FLOAT16_VALUE(15.35), SIMDE_FLOAT16_VALUE(-29.85), SIMDE_FLOAT16_VALUE(-39.84), SIMDE_FLOAT16_VALUE(10.29) } } },
     { {  SIMDE_FLOAT16_VALUE(17.73), SIMDE_FLOAT16_VALUE(33.62), SIMDE_FLOAT16_VALUE(30.49), SIMDE_FLOAT16_VALUE(-45.52), SIMDE_FLOAT16_VALUE(-32.12), SIMDE_FLOAT16_VALUE(21.94),
        SIMDE_FLOAT16_VALUE(-24.75), SIMDE_FLOAT16_VALUE(-16.54), SIMDE_FLOAT16_VALUE(23.29), SIMDE_FLOAT16_VALUE(40.42), SIMDE_FLOAT16_VALUE(10.94), SIMDE_FLOAT16_VALUE(16.67) },
     { {  SIMDE_FLOAT16_VALUE(17.73), SIMDE_FLOAT16_VALUE(-45.52), SIMDE_FLOAT16_VALUE(-24.75), SIMDE_FLOAT16_VALUE(40.42) },
       {  SIMDE_FLOAT16_VALUE(33.62), SIMDE_FLOAT16_VALUE(-32.12), SIMDE_FLOAT16_VALUE(-16.54), SIMDE_FLOAT16_VALUE(10.94) },
       {  SIMDE_FLOAT16_VALUE(30.49), SIMDE_FLOAT16_VALUE(21.94), SIMDE_FLOAT16_VALUE(23.29), SIMDE_FLOAT16_VALUE(16.67) } } },
     { {  SIMDE_FLOAT16_VALUE(-36.37), SIMDE_FLOAT16_VALUE(19.72), SIMDE_FLOAT16_VALUE(34.16), SIMDE_FLOAT16_VALUE(12.31), SIMDE_FLOAT16_VALUE(-32.49), SIMDE_FLOAT16_VALUE(18.71),
        SIMDE_FLOAT16_VALUE(32.02), SIMDE_FLOAT16_VALUE(-3.55), SIMDE_FLOAT16_VALUE(37.82), SIMDE_FLOAT16_VALUE(20.73), SIMDE_FLOAT16_VALUE(31.56), SIMDE_FLOAT16_VALUE(-14.40) },
     { {  SIMDE_FLOAT16_VALUE(-36.37), SIMDE_FLOAT16_VALUE(12.31), SIMDE_FLOAT16_VALUE(32.02), SIMDE_FLOAT16_VALUE(20.73) },
       {  SIMDE_FLOAT16_VALUE(19.72), SIMDE_FLOAT16_VALUE(-32.49), SIMDE_FLOAT16_VALUE(-3.55), SIMDE_FLOAT16_VALUE(31.56) },
       {  SIMDE_FLOAT16_VALUE(34.16), SIMDE_FLOAT16_VALUE(18.71), SIMDE_FLOAT16_VALUE(37.82), SIMDE_FLOAT16_VALUE(-14.40) } } },
     { {  SIMDE_FLOAT16_VALUE(-13.66), SIMDE_FLOAT16_VALUE(32.06), SIMDE_FLOAT16_VALUE(44.67), SIMDE_FLOAT16_VALUE(-12.02), SIMDE_FLOAT16_VALUE(23.43), SIMDE_FLOAT16_VALUE(-9.95),
        SIMDE_FLOAT16_VALUE(26.57), SIMDE_FLOAT16_VALUE(-36.45), SIMDE_FLOAT16_VALUE(8.78), SIMDE_FLOAT16_VALUE(-10.73), SIMDE_FLOAT16_VALUE(-18.07), SIMDE_FLOAT16_VALUE(-1.21) },
     { {  SIMDE_FLOAT16_VALUE(-13.66), SIMDE_FLOAT16_VALUE(-12.02), SIMDE_FLOAT16_VALUE(26.57), SIMDE_FLOAT16_VALUE(-10.73) },
       {  SIMDE_FLOAT16_VALUE(32.06), SIMDE_FLOAT16_VALUE(23.43), SIMDE_FLOAT16_VALUE(-36.45), SIMDE_FLOAT16_VALUE(-18.07) },
       {  SIMDE_FLOAT16_VALUE(44.67), SIMDE_FLOAT16_VALUE(-9.95), SIMDE_FLOAT16_VALUE(8.78), SIMDE_FLOAT16_VALUE(-1.21) } } },
     { {  SIMDE_FLOAT16_VALUE(8.83), SIMDE_FLOAT16_VALUE(37.66), SIMDE_FLOAT16_VALUE(-2.70), SIMDE_FLOAT16_VALUE(-20.01), SIMDE_FLOAT16_VALUE(-39.96), SIMDE_FLOAT16_VALUE(45.71),
        SIMDE_FLOAT16_VALUE(-33.07), SIMDE_FLOAT16_VALUE(-21.02), SIMDE_FLOAT16_VALUE(39.55), SIMDE_FLOAT16_VALUE(26.93), SIMDE_FLOAT16_VALUE(25.35), SIMDE_FLOAT16_VALUE(-5.48) },
     { {  SIMDE_FLOAT16_VALUE(8.83), SIMDE_FLOAT16_VALUE(-20.01), SIMDE_FLOAT16_VALUE(-33.07), SIMDE_FLOAT16_VALUE(26.93) },
       {  SIMDE_FLOAT16_VALUE(37.66), SIMDE_FLOAT16_VALUE(-39.96), SIMDE_FLOAT16_VALUE(-21.02), SIMDE_FLOAT16_VALUE(25.35) },
       {  SIMDE_FLOAT16_VALUE(-2.70), SIMDE_FLOAT16_VALUE(45.71), SIMDE_FLOAT16_VALUE(39.55), SIMDE_FLOAT16_VALUE(-5.48) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4x3_t r = simde_vld3_f16(test_vec[i].a);

    simde_float16x4x3_t expected = {
        {simde_vld1_f16(test_vec[i].r[0]), simde_vld1_f16(test_vec[i].r[1]), simde_vld1_f16(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_f16x4(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f16x4(r.val[1], expected.val[1], INT_MAX);
    simde_test_arm_neon_assert_equal_f16x4(r.val[2], expected.val[2], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld3q_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float16_t a[24];
    simde_float16_t r[3][8];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_C( 50.511),  SIMDE_FLOAT16_C( 86.684),  SIMDE_FLOAT16_C( 96.211),  SIMDE_FLOAT16_C( 21.009),
        -SIMDE_FLOAT16_C( 58.967), -SIMDE_FLOAT16_C( 95.046),  SIMDE_FLOAT16_C(  3.355), -SIMDE_FLOAT16_C( 32.048),
        -SIMDE_FLOAT16_C( 72.615),  SIMDE_FLOAT16_C( 13.174),  SIMDE_FLOAT16_C( 15.374), -SIMDE_FLOAT16_C( 72.543),
        -SIMDE_FLOAT16_C( 68.833),  SIMDE_FLOAT16_C( 53.897),  SIMDE_FLOAT16_C( 93.769),  SIMDE_FLOAT16_C(  0.685),
        -SIMDE_FLOAT16_C( 70.586),  SIMDE_FLOAT16_C( 38.881), -SIMDE_FLOAT16_C( 14.775), -SIMDE_FLOAT16_C(  3.719),
         SIMDE_FLOAT16_C( 20.072), -SIMDE_FLOAT16_C(  2.675), -SIMDE_FLOAT16_C( 36.488),  SIMDE_FLOAT16_C( 30.856) },
    { {  SIMDE_FLOAT16_C( 50.511),  SIMDE_FLOAT16_C( 21.009),  SIMDE_FLOAT16_C(  3.355),  SIMDE_FLOAT16_C( 13.174),
        -SIMDE_FLOAT16_C( 68.833),  SIMDE_FLOAT16_C(  0.685), -SIMDE_FLOAT16_C( 14.775), -SIMDE_FLOAT16_C(  2.675)  },
      {  SIMDE_FLOAT16_C( 86.684), -SIMDE_FLOAT16_C( 58.967), -SIMDE_FLOAT16_C( 32.048),  SIMDE_FLOAT16_C( 15.374),
         SIMDE_FLOAT16_C( 53.897), -SIMDE_FLOAT16_C( 70.586), -SIMDE_FLOAT16_C(  3.719), -SIMDE_FLOAT16_C( 36.488)  },
      {  SIMDE_FLOAT16_C( 96.211), -SIMDE_FLOAT16_C( 95.046), -SIMDE_FLOAT16_C( 72.615), -SIMDE_FLOAT16_C( 72.543),
         SIMDE_FLOAT16_C( 93.769),  SIMDE_FLOAT16_C( 38.881),  SIMDE_FLOAT16_C( 20.072),  SIMDE_FLOAT16_C( 30.856)  } } },
    { {  SIMDE_FLOAT16_C( 27.169),  SIMDE_FLOAT16_C( 97.696),  SIMDE_FLOAT16_C(  6.429),  SIMDE_FLOAT16_C(  1.851),
         SIMDE_FLOAT16_C( 57.529), -SIMDE_FLOAT16_C(  8.606), -SIMDE_FLOAT16_C( 73.783),  SIMDE_FLOAT16_C( 38.167),
         SIMDE_FLOAT16_C( 66.160), -SIMDE_FLOAT16_C( 43.612),  SIMDE_FLOAT16_C(  7.569),  SIMDE_FLOAT16_C( 30.400),
         SIMDE_FLOAT16_C( 73.369), -SIMDE_FLOAT16_C( 37.197),  SIMDE_FLOAT16_C( 44.001), -SIMDE_FLOAT16_C( 61.104),
        -SIMDE_FLOAT16_C( 91.738), -SIMDE_FLOAT16_C( 76.714),  SIMDE_FLOAT16_C( 62.278),  SIMDE_FLOAT16_C( 64.843),
        -SIMDE_FLOAT16_C( 31.622),  SIMDE_FLOAT16_C( 39.644), -SIMDE_FLOAT16_C( 50.048),  SIMDE_FLOAT16_C( 16.733) },
    { {  SIMDE_FLOAT16_C( 27.169),  SIMDE_FLOAT16_C(  1.851), -SIMDE_FLOAT16_C( 73.783), -SIMDE_FLOAT16_C( 43.612),
         SIMDE_FLOAT16_C( 73.369), -SIMDE_FLOAT16_C( 61.104),  SIMDE_FLOAT16_C( 62.278),  SIMDE_FLOAT16_C( 39.644)  },
      {  SIMDE_FLOAT16_C( 97.696),  SIMDE_FLOAT16_C( 57.529),  SIMDE_FLOAT16_C( 38.167),  SIMDE_FLOAT16_C(  7.569),
        -SIMDE_FLOAT16_C( 37.197), -SIMDE_FLOAT16_C( 91.738),  SIMDE_FLOAT16_C( 64.843), -SIMDE_FLOAT16_C( 50.048)  },
      {  SIMDE_FLOAT16_C(  6.429), -SIMDE_FLOAT16_C(  8.606),  SIMDE_FLOAT16_C( 66.160),  SIMDE_FLOAT16_C( 30.400),
         SIMDE_FLOAT16_C( 44.001), -SIMDE_FLOAT16_C( 76.714), -SIMDE_FLOAT16_C( 31.622),  SIMDE_FLOAT16_C( 16.733)  } } },
    { {  SIMDE_FLOAT16_C( 79.887),  SIMDE_FLOAT16_C( 75.064),  SIMDE_FLOAT16_C( 97.298), -SIMDE_FLOAT16_C( 36.532),
         SIMDE_FLOAT16_C( 31.519), -SIMDE_FLOAT16_C( 21.137),  SIMDE_FLOAT16_C( 37.884),  SIMDE_FLOAT16_C( 75.605),
        -SIMDE_FLOAT16_C(  7.086), -SIMDE_FLOAT16_C( 61.433),  SIMDE_FLOAT16_C(  4.750), -SIMDE_FLOAT16_C( 68.334),
        -SIMDE_FLOAT16_C( 27.825), -SIMDE_FLOAT16_C( 95.446), -SIMDE_FLOAT16_C( 57.864),  SIMDE_FLOAT16_C( 35.983),
         SIMDE_FLOAT16_C( 47.271),  SIMDE_FLOAT16_C( 89.486),  SIMDE_FLOAT16_C( 44.198), -SIMDE_FLOAT16_C( 43.979),
         SIMDE_FLOAT16_C( 98.973),  SIMDE_FLOAT16_C( 96.892),  SIMDE_FLOAT16_C( 83.644),  SIMDE_FLOAT16_C(  1.933) },
    { {  SIMDE_FLOAT16_C( 79.887), -SIMDE_FLOAT16_C( 36.532),  SIMDE_FLOAT16_C( 37.884), -SIMDE_FLOAT16_C( 61.433),
        -SIMDE_FLOAT16_C( 27.825),  SIMDE_FLOAT16_C( 35.983),  SIMDE_FLOAT16_C( 44.198),  SIMDE_FLOAT16_C( 96.892)  },
      {  SIMDE_FLOAT16_C( 75.064),  SIMDE_FLOAT16_C( 31.519),  SIMDE_FLOAT16_C( 75.605),  SIMDE_FLOAT16_C(  4.750),
        -SIMDE_FLOAT16_C( 95.446),  SIMDE_FLOAT16_C( 47.271), -SIMDE_FLOAT16_C( 43.979),  SIMDE_FLOAT16_C( 83.644)  },
      {  SIMDE_FLOAT16_C( 97.298), -SIMDE_FLOAT16_C( 21.137), -SIMDE_FLOAT16_C(  7.086), -SIMDE_FLOAT16_C( 68.334),
        -SIMDE_FLOAT16_C( 57.864),  SIMDE_FLOAT16_C( 89.486),  SIMDE_FLOAT16_C( 98.973),  SIMDE_FLOAT16_C(  1.933)  } } },
    { {  SIMDE_FLOAT16_C( 45.623),  SIMDE_FLOAT16_C( 40.930), -SIMDE_FLOAT16_C( 18.856), -SIMDE_FLOAT16_C( 35.474),
        -SIMDE_FLOAT16_C( 25.714),  SIMDE_FLOAT16_C( 28.034),  SIMDE_FLOAT16_C( 86.809),  SIMDE_FLOAT16_C( 96.976),
        -SIMDE_FLOAT16_C( 81.890), -SIMDE_FLOAT16_C(  7.184), -SIMDE_FLOAT16_C( 66.904), -SIMDE_FLOAT16_C( 32.987),
        -SIMDE_FLOAT16_C( 21.348), -SIMDE_FLOAT16_C( 74.742), -SIMDE_FLOAT16_C( 34.888),  SIMDE_FLOAT16_C( 18.741),
        -SIMDE_FLOAT16_C( 15.061),  SIMDE_FLOAT16_C( 38.458), -SIMDE_FLOAT16_C( 14.151), -SIMDE_FLOAT16_C( 48.572),
         SIMDE_FLOAT16_C( 57.645), -SIMDE_FLOAT16_C( 40.036), -SIMDE_FLOAT16_C( 33.994),  SIMDE_FLOAT16_C( 52.148) },
    { {  SIMDE_FLOAT16_C( 45.623), -SIMDE_FLOAT16_C( 35.474),  SIMDE_FLOAT16_C( 86.809), -SIMDE_FLOAT16_C(  7.184),
        -SIMDE_FLOAT16_C( 21.348),  SIMDE_FLOAT16_C( 18.741), -SIMDE_FLOAT16_C( 14.151), -SIMDE_FLOAT16_C( 40.036)  },
      {  SIMDE_FLOAT16_C( 40.930), -SIMDE_FLOAT16_C( 25.714),  SIMDE_FLOAT16_C( 96.976), -SIMDE_FLOAT16_C( 66.904),
        -SIMDE_FLOAT16_C( 74.742), -SIMDE_FLOAT16_C( 15.061), -SIMDE_FLOAT16_C( 48.572), -SIMDE_FLOAT16_C( 33.994)  },
      { -SIMDE_FLOAT16_C( 18.856),  SIMDE_FLOAT16_C( 28.034), -SIMDE_FLOAT16_C( 81.890), -SIMDE_FLOAT16_C( 32.987),
        -SIMDE_FLOAT16_C( 34.888),  SIMDE_FLOAT16_C( 38.458),  SIMDE_FLOAT16_C( 57.645),  SIMDE_FLOAT16_C( 52.148)  } } },
    { {  SIMDE_FLOAT16_C( 77.853), -SIMDE_FLOAT16_C(  5.293),  SIMDE_FLOAT16_C( 65.177), -SIMDE_FLOAT16_C( 50.710),
         SIMDE_FLOAT16_C( 22.953), -SIMDE_FLOAT16_C(  6.422),  SIMDE_FLOAT16_C( 85.417),  SIMDE_FLOAT16_C(  1.387),
         SIMDE_FLOAT16_C( 65.246), -SIMDE_FLOAT16_C( 24.277), -SIMDE_FLOAT16_C( 46.158), -SIMDE_FLOAT16_C( 67.905),
         SIMDE_FLOAT16_C( 43.158), -SIMDE_FLOAT16_C( 62.899), -SIMDE_FLOAT16_C( 27.784),  SIMDE_FLOAT16_C( 56.200),
         SIMDE_FLOAT16_C( 82.898), -SIMDE_FLOAT16_C( 71.415), -SIMDE_FLOAT16_C( 29.585), -SIMDE_FLOAT16_C( 28.012),
         SIMDE_FLOAT16_C( 52.765),  SIMDE_FLOAT16_C( 82.867),  SIMDE_FLOAT16_C( 22.238), -SIMDE_FLOAT16_C( 37.496) },
    { {  SIMDE_FLOAT16_C( 77.853), -SIMDE_FLOAT16_C( 50.710),  SIMDE_FLOAT16_C( 85.417), -SIMDE_FLOAT16_C( 24.277),
         SIMDE_FLOAT16_C( 43.158),  SIMDE_FLOAT16_C( 56.200), -SIMDE_FLOAT16_C( 29.585),  SIMDE_FLOAT16_C( 82.867)  },
      { -SIMDE_FLOAT16_C(  5.293),  SIMDE_FLOAT16_C( 22.953),  SIMDE_FLOAT16_C(  1.387), -SIMDE_FLOAT16_C( 46.158),
        -SIMDE_FLOAT16_C( 62.899),  SIMDE_FLOAT16_C( 82.898), -SIMDE_FLOAT16_C( 28.012),  SIMDE_FLOAT16_C( 22.238)  },
      {  SIMDE_FLOAT16_C( 65.177), -SIMDE_FLOAT16_C(  6.422),  SIMDE_FLOAT16_C( 65.246), -SIMDE_FLOAT16_C( 67.905),
        -SIMDE_FLOAT16_C( 27.784), -SIMDE_FLOAT16_C( 71.415),  SIMDE_FLOAT16_C( 52.765), -SIMDE_FLOAT16_C( 37.496)  } } },
    { { -SIMDE_FLOAT16_C(  2.331),  SIMDE_FLOAT16_C( 29.415),  SIMDE_FLOAT16_C( 35.770),  SIMDE_FLOAT16_C( 16.302),
        -SIMDE_FLOAT16_C( 91.643), -SIMDE_FLOAT16_C( 70.642), -SIMDE_FLOAT16_C( 22.834), -SIMDE_FLOAT16_C( 16.944),
         SIMDE_FLOAT16_C( 84.108),  SIMDE_FLOAT16_C(  1.977), -SIMDE_FLOAT16_C(  9.416),  SIMDE_FLOAT16_C( 74.766),
        -SIMDE_FLOAT16_C( 30.242),  SIMDE_FLOAT16_C( 20.937), -SIMDE_FLOAT16_C(  2.896), -SIMDE_FLOAT16_C(  6.387),
         SIMDE_FLOAT16_C(  3.481),  SIMDE_FLOAT16_C( 35.087), -SIMDE_FLOAT16_C( 51.719),  SIMDE_FLOAT16_C( 63.190),
         SIMDE_FLOAT16_C( 69.433),  SIMDE_FLOAT16_C( 25.431),  SIMDE_FLOAT16_C( 62.916),  SIMDE_FLOAT16_C( 65.064) },
    { { -SIMDE_FLOAT16_C(  2.331),  SIMDE_FLOAT16_C( 16.302), -SIMDE_FLOAT16_C( 22.834),  SIMDE_FLOAT16_C(  1.977),
        -SIMDE_FLOAT16_C( 30.242), -SIMDE_FLOAT16_C(  6.387), -SIMDE_FLOAT16_C( 51.719),  SIMDE_FLOAT16_C( 25.431)  },
      {  SIMDE_FLOAT16_C( 29.415), -SIMDE_FLOAT16_C( 91.643), -SIMDE_FLOAT16_C( 16.944), -SIMDE_FLOAT16_C(  9.416),
         SIMDE_FLOAT16_C( 20.937),  SIMDE_FLOAT16_C(  3.481),  SIMDE_FLOAT16_C( 63.190),  SIMDE_FLOAT16_C( 62.916)  },
      {  SIMDE_FLOAT16_C( 35.770), -SIMDE_FLOAT16_C( 70.642),  SIMDE_FLOAT16_C( 84.108),  SIMDE_FLOAT16_C( 74.766),
        -SIMDE_FLOAT16_C(  2.896),  SIMDE_FLOAT16_C( 35.087),  SIMDE_FLOAT16_C( 69.433),  SIMDE_FLOAT16_C( 65.064)  } } },
    { {  SIMDE_FLOAT16_C( 98.895),  SIMDE_FLOAT16_C( 72.717), -SIMDE_FLOAT16_C(  6.353),  SIMDE_FLOAT16_C( 70.032),
         SIMDE_FLOAT16_C(  3.465), -SIMDE_FLOAT16_C( 59.832), -SIMDE_FLOAT16_C( 45.154),  SIMDE_FLOAT16_C( 21.203),
         SIMDE_FLOAT16_C( 58.153), -SIMDE_FLOAT16_C( 22.957), -SIMDE_FLOAT16_C( 85.381),  SIMDE_FLOAT16_C( 81.511),
         SIMDE_FLOAT16_C( 14.659),  SIMDE_FLOAT16_C( 98.757),  SIMDE_FLOAT16_C( 99.317), -SIMDE_FLOAT16_C( 83.947),
         SIMDE_FLOAT16_C( 38.963), -SIMDE_FLOAT16_C( 44.639), -SIMDE_FLOAT16_C( 34.702), -SIMDE_FLOAT16_C( 64.943),
        -SIMDE_FLOAT16_C( 90.372), -SIMDE_FLOAT16_C( 85.000),  SIMDE_FLOAT16_C( 24.672),  SIMDE_FLOAT16_C( 12.816) },
    { {  SIMDE_FLOAT16_C( 98.895),  SIMDE_FLOAT16_C( 70.032), -SIMDE_FLOAT16_C( 45.154), -SIMDE_FLOAT16_C( 22.957),
         SIMDE_FLOAT16_C( 14.659), -SIMDE_FLOAT16_C( 83.947), -SIMDE_FLOAT16_C( 34.702), -SIMDE_FLOAT16_C( 85.000)  },
      {  SIMDE_FLOAT16_C( 72.717),  SIMDE_FLOAT16_C(  3.465),  SIMDE_FLOAT16_C( 21.203), -SIMDE_FLOAT16_C( 85.381),
         SIMDE_FLOAT16_C( 98.757),  SIMDE_FLOAT16_C( 38.963), -SIMDE_FLOAT16_C( 64.943),  SIMDE_FLOAT16_C( 24.672)  },
      { -SIMDE_FLOAT16_C(  6.353), -SIMDE_FLOAT16_C( 59.832),  SIMDE_FLOAT16_C( 58.153),  SIMDE_FLOAT16_C( 81.511),
         SIMDE_FLOAT16_C( 99.317), -SIMDE_FLOAT16_C( 44.639), -SIMDE_FLOAT16_C( 90.372),  SIMDE_FLOAT16_C( 12.816)  } } },
    { {  SIMDE_FLOAT16_C( 67.964), -SIMDE_FLOAT16_C( 49.709),  SIMDE_FLOAT16_C( 91.615), -SIMDE_FLOAT16_C( 45.904),
         SIMDE_FLOAT16_C( 25.435),  SIMDE_FLOAT16_C( 79.259),  SIMDE_FLOAT16_C( 12.338), -SIMDE_FLOAT16_C( 54.866),
        -SIMDE_FLOAT16_C(  4.301), -SIMDE_FLOAT16_C( 20.530),  SIMDE_FLOAT16_C( 71.469),  SIMDE_FLOAT16_C(  9.646),
         SIMDE_FLOAT16_C( 27.156),  SIMDE_FLOAT16_C(  4.728),  SIMDE_FLOAT16_C(  9.490),  SIMDE_FLOAT16_C( 82.699),
        -SIMDE_FLOAT16_C( 27.427),  SIMDE_FLOAT16_C( 57.932),  SIMDE_FLOAT16_C( 66.510), -SIMDE_FLOAT16_C( 27.262),
         SIMDE_FLOAT16_C( 54.618),  SIMDE_FLOAT16_C( 46.855),  SIMDE_FLOAT16_C( 62.478),  SIMDE_FLOAT16_C( 61.709) },
    { {  SIMDE_FLOAT16_C( 67.964), -SIMDE_FLOAT16_C( 45.904),  SIMDE_FLOAT16_C( 12.338), -SIMDE_FLOAT16_C( 20.530),
         SIMDE_FLOAT16_C( 27.156),  SIMDE_FLOAT16_C( 82.699),  SIMDE_FLOAT16_C( 66.510),  SIMDE_FLOAT16_C( 46.855)  },
      { -SIMDE_FLOAT16_C( 49.709),  SIMDE_FLOAT16_C( 25.435), -SIMDE_FLOAT16_C( 54.866),  SIMDE_FLOAT16_C( 71.469),
         SIMDE_FLOAT16_C(  4.728), -SIMDE_FLOAT16_C( 27.427), -SIMDE_FLOAT16_C( 27.262),  SIMDE_FLOAT16_C( 62.478)  },
      {  SIMDE_FLOAT16_C( 91.615),  SIMDE_FLOAT16_C( 79.259), -SIMDE_FLOAT16_C(  4.301),  SIMDE_FLOAT16_C(  9.646),
         SIMDE_FLOAT16_C(  9.490),  SIMDE_FLOAT16_C( 57.932),  SIMDE_FLOAT16_C( 54.618),  SIMDE_FLOAT16_C( 61.709)  } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8x3_t r = simde_vld3q_f16(test_vec[i].a);

    simde_float16x8x3_t expected = {
        {simde_vld1q_f16(test_vec[i].r[0]), simde_vld1q_f16(test_vec[i].r[1]), simde_vld1q_f16(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_f16x8(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f16x8(r.val[1], expected.val[1], INT_MAX);
    simde_test_arm_neon_assert_equal_f16x8(r.val[2], expected.val[2], INT_MAX);
  }

  return 0;
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_f16)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
