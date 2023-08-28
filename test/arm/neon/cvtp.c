#define SIMDE_TEST_ARM_NEON_INSN cvtp

#include "test-neon.h"
#include "../../../simde/arm/neon/cvtp.h"

static int
test_simde_vcvtpq_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32 a[4];
    int32_t r[4];
  } test_vec[] = {
    { { -SIMDE_FLOAT32_C(   607.741),  SIMDE_FLOAT32_C(   403.453),  SIMDE_FLOAT32_C(    97.739), -SIMDE_FLOAT32_C(     2.667) },
      { -INT32_C(       607),  INT32_C(       404),  INT32_C(        98), -INT32_C(         2) } },
    { { -SIMDE_FLOAT32_C(   438.220), -SIMDE_FLOAT32_C(   356.632), -SIMDE_FLOAT32_C(   355.499),  SIMDE_FLOAT32_C(    12.256) },
      { -INT32_C(       438), -INT32_C(       356), -INT32_C(       355),  INT32_C(        13) } },
    { { -SIMDE_FLOAT32_C(   712.986),  SIMDE_FLOAT32_C(   505.464), -SIMDE_FLOAT32_C(   103.452), -SIMDE_FLOAT32_C(   725.220) },
      { -INT32_C(       712),  INT32_C(       506), -INT32_C(       103), -INT32_C(       725) } },
    { {  SIMDE_FLOAT32_C(   824.850),  SIMDE_FLOAT32_C(    62.658), -SIMDE_FLOAT32_C(   644.643),  SIMDE_FLOAT32_C(   510.005) },
      {  INT32_C(       825),  INT32_C(        63), -INT32_C(       644),  INT32_C(       511) } },
    { { -SIMDE_FLOAT32_C(     2.843), -SIMDE_FLOAT32_C(   710.183), -SIMDE_FLOAT32_C(   382.143), -SIMDE_FLOAT32_C(   280.409) },
      { -INT32_C(         2), -INT32_C(       710), -INT32_C(       382), -INT32_C(       280) } },
    { {  SIMDE_FLOAT32_C(   209.258), -SIMDE_FLOAT32_C(    68.390),  SIMDE_FLOAT32_C(   737.373),  SIMDE_FLOAT32_C(   383.386) },
      {  INT32_C(       210), -INT32_C(        68),  INT32_C(       738),  INT32_C(       384) } },
    { {  SIMDE_FLOAT32_C(   411.326), -SIMDE_FLOAT32_C(   427.964), -SIMDE_FLOAT32_C(    38.293), -SIMDE_FLOAT32_C(    18.446) },
      {  INT32_C(       412), -INT32_C(       427), -INT32_C(        38), -INT32_C(        18) } },
    { { -SIMDE_FLOAT32_C(   375.151), -SIMDE_FLOAT32_C(   477.988), -SIMDE_FLOAT32_C(   879.299),  SIMDE_FLOAT32_C(   967.790) },
      { -INT32_C(       375), -INT32_C(       477), -INT32_C(       879),  INT32_C(       968) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_int32x4_t r = simde_vcvtpq_s32_f32(a);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtpq_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64 a[2];
    int64_t r[2];
  } test_vec[] = {
    { {  SIMDE_FLOAT64_C( 99237.141), -SIMDE_FLOAT64_C( 50717.117) },
      {  INT64_C(     99238), -INT64_C(     50717) } },
    { { -SIMDE_FLOAT64_C( 74116.766),  SIMDE_FLOAT64_C( 66114.500) },
      { -INT64_C(     74116),  INT64_C(     66115) } },
    { { -SIMDE_FLOAT64_C( 88666.844),  SIMDE_FLOAT64_C( 79431.297) },
      { -INT64_C(     88666),  INT64_C(     79432) } },
    { {  SIMDE_FLOAT64_C( 18760.219), -SIMDE_FLOAT64_C( 76336.250) },
      {  INT64_C(     18761), -INT64_C(     76336) } },
    { { -SIMDE_FLOAT64_C( 86460.719),  SIMDE_FLOAT64_C( 56061.813) },
      { -INT64_C(     86460),  INT64_C(     56062) } },
    { { -SIMDE_FLOAT64_C( 52624.641),  SIMDE_FLOAT64_C( 76414.109) },
      { -INT64_C(     52624),  INT64_C(     76415) } },
    { {  SIMDE_FLOAT64_C( 87426.969), -SIMDE_FLOAT64_C( 65214.336) },
      {  INT64_C(     87427), -INT64_C(     65214) } },
    { {  SIMDE_FLOAT64_C( 94206.609), -SIMDE_FLOAT64_C( 63892.445) },
      {  INT64_C(     94207), -INT64_C(     63892) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_int64x2_t r = simde_vcvtpq_s64_f64(a);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtph_s64_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float16 a;
    int64_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    #if !defined(SIMDE_RISCV_RVV_NATIVE)
      {            SIMDE_MATH_NANF,
        INT64_C(           0) },
    #endif
      { HEDLEY_STATIC_CAST(simde_float16, INT64_MAX),
                  INT64_MAX },
      { HEDLEY_STATIC_CAST(simde_float16, INT64_MIN),
                  INT64_MIN },
    #endif
    {    SIMDE_FLOAT16_C(     3.188),
         INT64_C(         4) },
    {    SIMDE_FLOAT16_C(     6.484),
         INT64_C(         7) },
    {   -SIMDE_FLOAT16_C(    18.336),
        -INT64_C(        18) },
    {    SIMDE_FLOAT16_C(    27.028),
         INT64_C(        28) },
    {   -SIMDE_FLOAT16_C(    22.919),
        -INT64_C(        22) },
    {    SIMDE_FLOAT16_C(    13.598),
         INT64_C(        14) },
    {    SIMDE_FLOAT16_C(    27.711),
         INT64_C(        28) },
    {   -SIMDE_FLOAT16_C(     1.019),
        -INT64_C(         1) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16 a = test_vec[i].a;
    int64_t r = simde_vcvtph_s64_f16(a);
    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vcvtph_s32_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float16 a;
    int32_t r;
  } test_vec[] = {
    {            SIMDE_MATH_NANF,
      INT32_C(           0) },
    { HEDLEY_STATIC_CAST(simde_float16, INT32_MAX),
                INT32_MAX },
    { HEDLEY_STATIC_CAST(simde_float16, INT32_MIN),
                INT32_MIN },
    {   -SIMDE_FLOAT16_C(    13.547),
        -INT32_C(        13) },
    {   -SIMDE_FLOAT16_C(    28.627),
        -INT32_C(        28) },
    {   -SIMDE_FLOAT16_C(    26.702),
        -INT32_C(        26) },
    {   -SIMDE_FLOAT16_C(     8.158),
        -INT32_C(         8) },
    {   -SIMDE_FLOAT16_C(    10.661),
        -INT32_C(        10) },
    {   -SIMDE_FLOAT16_C(    14.185),
        -INT32_C(        14) },
    {    SIMDE_FLOAT16_C(    10.164),
         INT32_C(        11) },
    {   -SIMDE_FLOAT16_C(    14.690),
        -INT32_C(        14) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16 a = test_vec[i].a;
    int32_t r = simde_vcvtph_s32_f16(a);
    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vcvtph_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float16 a;
    int16_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    #if !defined(SIMDE_RISCV_RVV_NATIVE)
      {            SIMDE_MATH_NANF,
        INT16_C(           0) },
    #endif
      { HEDLEY_STATIC_CAST(simde_float16, INT16_MAX) + SIMDE_FLOAT16_C(100.0),
                  INT16_MAX },
      { HEDLEY_STATIC_CAST(simde_float16, INT16_MIN) + SIMDE_FLOAT16_C(-100.0),
                  INT16_MIN },
    #endif
    {    SIMDE_FLOAT16_C(    26.840),
         INT16_C(        27) },
    {    SIMDE_FLOAT16_C(    28.316),
         INT16_C(        29) },
    {    SIMDE_FLOAT16_C(    11.363),
         INT16_C(        12) },
    {   -SIMDE_FLOAT16_C(     9.731),
        -INT16_C(         9) },
    {    SIMDE_FLOAT16_C(     7.723),
         INT16_C(         8) },
    {   -SIMDE_FLOAT16_C(    22.898),
        -INT16_C(        22) },
    {   -SIMDE_FLOAT16_C(    19.354),
        -INT16_C(        19) },
    {    SIMDE_FLOAT16_C(    24.613),
         INT16_C(        25) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16 a = test_vec[i].a;
    int16_t r = simde_vcvtph_s16_f16(a);
    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vcvtps_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32 a;
    int32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {            SIMDE_MATH_NANF,
        INT32_C(           0) },
      { HEDLEY_STATIC_CAST(simde_float32, INT32_MAX) + SIMDE_FLOAT32_C(1000.0),
                  INT32_MAX },
      { HEDLEY_STATIC_CAST(simde_float32, INT32_MIN) + SIMDE_FLOAT32_C(-1000.0),
                  INT32_MIN },
    #endif
    {    SIMDE_FLOAT32_C(    14.178),
         INT32_C(        15) },
    {   -SIMDE_FLOAT32_C(   607.139),
        -INT32_C(       607) },
    {   -SIMDE_FLOAT32_C(   414.899),
        -INT32_C(       414) },
    {   -SIMDE_FLOAT32_C(   887.709),
        -INT32_C(       887) },
    {   -SIMDE_FLOAT32_C(   746.822),
        -INT32_C(       746) },
    {    SIMDE_FLOAT32_C(   170.845),
         INT32_C(       171) },
    {    SIMDE_FLOAT32_C(   991.922),
         INT32_C(       992) },
    {   -SIMDE_FLOAT32_C(   557.800),
        -INT32_C(       557) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32 a = test_vec[i].a;
    int32_t r = simde_vcvtps_s32_f32(a);
    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vcvtph_u64_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float16 a;
    uint64_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    #if !defined(SIMDE_RISCV_RVV_NATIVE)
      {            SIMDE_MATH_NANF,
        INT64_C(           0) },
    #endif
      { HEDLEY_STATIC_CAST(simde_float16, UINT64_MAX),
                  UINT64_MAX },
      { SIMDE_FLOAT16_C(-1000.0),
        UINT64_C(         0) },
    #endif
    {    SIMDE_FLOAT16_C(     9.136),
         UINT64_C(        10) },
    {   -SIMDE_FLOAT16_C(    10.194),
         UINT64_C(         0) },
    {   -SIMDE_FLOAT16_C(    24.774),
         UINT64_C(         0) },
    {   -SIMDE_FLOAT16_C(    14.346),
         UINT64_C(         0) },
    {   -SIMDE_FLOAT16_C(    10.756),
         UINT64_C(         0) },
    {    SIMDE_FLOAT16_C(     8.945),
         UINT64_C(         9) },
    {    SIMDE_FLOAT16_C(     4.916),
         UINT64_C(         5) },
    {   -SIMDE_FLOAT16_C(     4.343),
         UINT64_C(         0) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16 a = test_vec[i].a;
    uint64_t r = simde_vcvtph_u64_f16(a);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vcvtph_u32_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float16 a;
    uint32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    #if !defined(SIMDE_RISCV_RVV_NATIVE)
      {            SIMDE_MATH_NANF,
        INT32_C(           0) },
    #endif
      { HEDLEY_STATIC_CAST(simde_float16, UINT32_MAX),
                  UINT32_MAX },
      { SIMDE_FLOAT16_C(-1000.0),
        UINT32_C(         0) },
    #endif
    {   -SIMDE_FLOAT16_C(    27.684),
         UINT32_C(         0) },
    {   -SIMDE_FLOAT16_C(    26.915),
         UINT32_C(         0) },
    {    SIMDE_FLOAT16_C(    14.954),
         UINT32_C(        15) },
    {   -SIMDE_FLOAT16_C(    27.780),
         UINT32_C(         0) },
    {   -SIMDE_FLOAT16_C(     5.217),
         UINT32_C(         0) },
    {    SIMDE_FLOAT16_C(    17.106),
         UINT32_C(        18) },
    {   -SIMDE_FLOAT16_C(    20.283),
         UINT32_C(         0) },
    {   -SIMDE_FLOAT16_C(    21.315),
         UINT32_C(         0) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16 a = test_vec[i].a;
    uint32_t r = simde_vcvtph_u32_f16(a);
    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vcvtph_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float16 a;
    uint16_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    #if !defined(SIMDE_RISCV_RVV_NATIVE)
      {            SIMDE_MATH_NANF,
        INT16_C(           0) },
    #endif
      { HEDLEY_STATIC_CAST(simde_float16, UINT16_MAX),
                  UINT16_MAX },
      { SIMDE_FLOAT16_C(-1000.0),
        UINT16_C(         0) },
    #endif
    {   -SIMDE_FLOAT16_C(     8.513),
         UINT16_C(         0) },
    {    SIMDE_FLOAT16_C(    17.766),
         UINT16_C(        18) },
    {    SIMDE_FLOAT16_C(    22.378),
         UINT16_C(        23) },
    {    SIMDE_FLOAT16_C(     2.456),
         UINT16_C(         3) },
    {   -SIMDE_FLOAT16_C(     2.731),
         UINT16_C(         0) },
    {    SIMDE_FLOAT16_C(    25.255),
         UINT16_C(        26) },
    {   -SIMDE_FLOAT16_C(    26.507),
         UINT16_C(         0) },
    {    SIMDE_FLOAT16_C(     5.504),
         UINT16_C(         6) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16 a = test_vec[i].a;
    uint16_t r = simde_vcvtph_u16_f16(a);
    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vcvtps_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32 a;
    uint32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {            SIMDE_MATH_NANF,
        INT32_C(           0) },
      { HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX) + SIMDE_FLOAT32_C(1000.0),
                  UINT32_MAX },
      { SIMDE_FLOAT32_C(-1000.0),
        UINT32_C(         0) },
    #endif
    {    SIMDE_FLOAT32_C(   517.893),
         UINT32_C(       518) },
    {   -SIMDE_FLOAT32_C(   204.507),
         UINT32_C(         0) },
    {    SIMDE_FLOAT32_C(   288.716),
         UINT32_C(       289) },
    {    SIMDE_FLOAT32_C(   197.506),
         UINT32_C(       198) },
    {    SIMDE_FLOAT32_C(   973.600),
         UINT32_C(       974) },
    {    SIMDE_FLOAT32_C(   976.840),
         UINT32_C(       977) },
    {    SIMDE_FLOAT32_C(   920.392),
         UINT32_C(       921) },
    {    SIMDE_FLOAT32_C(    70.544),
         UINT32_C(        71) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32 a = test_vec[i].a;
    uint32_t r = simde_vcvtps_u32_f32(a);
    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vcvtpq_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32 a[4];
    uint32_t r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX) + SIMDE_FLOAT32_C(10000.0), SIMDE_MATH_NANF, -SIMDE_MATH_NANF, SIMDE_MATH_INFINITYF },
        {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    #endif
    { { -SIMDE_FLOAT32_C(   730.460),  SIMDE_FLOAT32_C(   119.588),  SIMDE_FLOAT32_C(   201.108), -SIMDE_FLOAT32_C(   143.672) },
      {  UINT32_C(         0),  UINT32_C(       120),  UINT32_C(       202),  UINT32_C(         0) } },
    { { -SIMDE_FLOAT32_C(   734.690), -SIMDE_FLOAT32_C(   494.553),  SIMDE_FLOAT32_C(   835.514),  SIMDE_FLOAT32_C(   778.079) },
      {  UINT32_C(         0),  UINT32_C(         0),  UINT32_C(       836),  UINT32_C(       779) } },
    { {  SIMDE_FLOAT32_C(   450.979),  SIMDE_FLOAT32_C(   694.603),  SIMDE_FLOAT32_C(   509.597),  SIMDE_FLOAT32_C(   391.277) },
      {  UINT32_C(       451),  UINT32_C(       695),  UINT32_C(       510),  UINT32_C(       392) } },
    { {  SIMDE_FLOAT32_C(   792.841), -SIMDE_FLOAT32_C(   706.039),  SIMDE_FLOAT32_C(   942.828),  SIMDE_FLOAT32_C(   229.087) },
      {  UINT32_C(       793),  UINT32_C(         0),  UINT32_C(       943),  UINT32_C(       230) } },
    { { -SIMDE_FLOAT32_C(    29.631), -SIMDE_FLOAT32_C(   573.159),  SIMDE_FLOAT32_C(   206.868),  SIMDE_FLOAT32_C(    68.827) },
      {  UINT32_C(         0),  UINT32_C(         0),  UINT32_C(       207),  UINT32_C(        69) } },
    { {  SIMDE_FLOAT32_C(   281.788), -SIMDE_FLOAT32_C(   534.711),  SIMDE_FLOAT32_C(   100.106), -SIMDE_FLOAT32_C(   525.881) },
      {  UINT32_C(       282),  UINT32_C(         0),  UINT32_C(       101),  UINT32_C(         0) } },
    { {  SIMDE_FLOAT32_C(   249.134), -SIMDE_FLOAT32_C(   861.506), -SIMDE_FLOAT32_C(   857.366),  SIMDE_FLOAT32_C(   987.604) },
      {  UINT32_C(       250),  UINT32_C(         0),  UINT32_C(         0),  UINT32_C(       988) } },
    { { -SIMDE_FLOAT32_C(    72.933),  SIMDE_FLOAT32_C(   412.447), -SIMDE_FLOAT32_C(   673.455),  SIMDE_FLOAT32_C(   741.723) },
      {  UINT32_C(         0),  UINT32_C(       413),  UINT32_C(         0),  UINT32_C(       742) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_uint32x4_t r = simde_vcvtpq_u32_f32(a);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtpd_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64 a;
    int64_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {             SIMDE_MATH_NAN,
        INT64_C(           0) },
      { HEDLEY_STATIC_CAST(simde_float64, INT64_MAX) + SIMDE_FLOAT64_C(10000.0),
                  INT64_MAX },
      { HEDLEY_STATIC_CAST(simde_float64, INT64_MIN) + SIMDE_FLOAT64_C(-10000.0),
                  INT64_MIN },
    #endif
    {   -SIMDE_FLOAT64_C( 79202.922),
        -INT64_C(     79202) },
    {   -SIMDE_FLOAT64_C( 89537.219),
        -INT64_C(     89537) },
    {   -SIMDE_FLOAT64_C( 12001.297),
        -INT64_C(     12001) },
    {   -SIMDE_FLOAT64_C(  9055.063),
        -INT64_C(      9055) },
    {    SIMDE_FLOAT64_C( 17832.305),
         INT64_C(     17833) },
    {    SIMDE_FLOAT64_C( 96832.719),
         INT64_C(     96833) },
    {    SIMDE_FLOAT64_C(  1258.672),
         INT64_C(      1259) },
    {   -SIMDE_FLOAT64_C( 68830.148),
        -INT64_C(     68830) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64 a = test_vec[i].a;
    int64_t r = simde_vcvtpd_s64_f64(a);
    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vcvtpd_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64 a;
    uint64_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {             SIMDE_MATH_NAN,
        INT64_C(           0) },
      { HEDLEY_STATIC_CAST(simde_float64, UINT64_MAX) + SIMDE_FLOAT64_C(10000.0),
                  UINT64_MAX },
      { SIMDE_FLOAT64_C(-1000.0),
        UINT64_C(         0) },
    #endif
    {   -SIMDE_FLOAT64_C( 84790.281),
         UINT64_C(         0) },
    {   -SIMDE_FLOAT64_C( 60574.262),
         UINT64_C(         0) },
    {   -SIMDE_FLOAT64_C( 38330.883),
         UINT64_C(         0) },
    {   -SIMDE_FLOAT64_C( 32369.992),
         UINT64_C(         0) },
    {   -SIMDE_FLOAT64_C( 89585.359),
         UINT64_C(         0) },
    {   -SIMDE_FLOAT64_C( 97223.203),
         UINT64_C(         0) },
    {    SIMDE_FLOAT64_C( 60286.391),
         UINT64_C(     60287) },
    {    SIMDE_FLOAT64_C( 75317.063),
         UINT64_C(     75318) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64 a = test_vec[i].a;
    uint64_t r = simde_vcvtpd_u64_f64(a);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vcvtpq_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64 a[2];
    uint64_t r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float64, UINT64_MAX) + SIMDE_FLOAT64_C(10000.0) },
        {           UINT64_MAX, UINT64_C(         0) } },
      { {  -SIMDE_MATH_NAN, -SIMDE_FLOAT64_C(10000.0) },
        { UINT64_C(         0), UINT64_C(         0) } },
    #endif
    { {  SIMDE_FLOAT64_C( 40548.281),  SIMDE_FLOAT64_C( 75623.734) },
      {  UINT64_C(     40549),  UINT64_C(     75624) } },
    { {  SIMDE_FLOAT64_C( 73904.125),  SIMDE_FLOAT64_C( 60351.406) },
      {  UINT64_C(     73905),  UINT64_C(     60352) } },
    { { -SIMDE_FLOAT64_C(  7687.164), -SIMDE_FLOAT64_C( 54845.516) },
      {  UINT64_C(         0),  UINT64_C(         0) } },
    { { -SIMDE_FLOAT64_C(  6370.984), -SIMDE_FLOAT64_C( 15883.758) },
      {  UINT64_C(         0),  UINT64_C(         0) } },
    { { -SIMDE_FLOAT64_C(  1463.313), -SIMDE_FLOAT64_C( 89720.492) },
      {  UINT64_C(         0),  UINT64_C(         0) } },
    { {  SIMDE_FLOAT64_C( 77919.359), -SIMDE_FLOAT64_C( 57334.516) },
      {  UINT64_C(     77920),  UINT64_C(         0) } },
    { {  SIMDE_FLOAT64_C( 25524.688), -SIMDE_FLOAT64_C( 18422.711) },
      {  UINT64_C(     25525),  UINT64_C(         0) } },
    { {  SIMDE_FLOAT64_C( 85632.547), -SIMDE_FLOAT64_C(  2039.086) },
      {  UINT64_C(     85633),  UINT64_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_uint64x2_t r = simde_vcvtpq_u64_f64(a);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtpq_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16 a[8];
    int16_t r[8];
  } test_vec[] = {
    { { -SIMDE_FLOAT16_C(    17.482),  SIMDE_FLOAT16_C(    25.249), -SIMDE_FLOAT16_C(    23.786),  SIMDE_FLOAT16_C(    26.713),
        -SIMDE_FLOAT16_C(    27.250), -SIMDE_FLOAT16_C(    25.132),  SIMDE_FLOAT16_C(    16.970),  SIMDE_FLOAT16_C(     1.147) },
      { -INT16_C(        17),  INT16_C(        26), -INT16_C(        23),  INT16_C(        27),
        -INT16_C(        27), -INT16_C(        25),  INT16_C(        17),  INT16_C(         2) } },
    { { -SIMDE_FLOAT16_C(    22.099), -SIMDE_FLOAT16_C(    21.667), -SIMDE_FLOAT16_C(     8.017), -SIMDE_FLOAT16_C(     2.271),
        -SIMDE_FLOAT16_C(    12.312),  SIMDE_FLOAT16_C(    22.849),  SIMDE_FLOAT16_C(    15.892), -SIMDE_FLOAT16_C(     8.588) },
      { -INT16_C(        22), -INT16_C(        21), -INT16_C(         8), -INT16_C(         2),
        -INT16_C(        12),  INT16_C(        23),  INT16_C(        16), -INT16_C(         8) } },
    { {  SIMDE_FLOAT16_C(     2.094), -SIMDE_FLOAT16_C(     2.744), -SIMDE_FLOAT16_C(    25.968), -SIMDE_FLOAT16_C(    21.280),
         SIMDE_FLOAT16_C(    19.739),  SIMDE_FLOAT16_C(    20.780), -SIMDE_FLOAT16_C(     3.155),  SIMDE_FLOAT16_C(    19.892) },
      {  INT16_C(         3), -INT16_C(         2), -INT16_C(        25), -INT16_C(        21),
         INT16_C(        20),  INT16_C(        21), -INT16_C(         3),  INT16_C(        20) } },
    { { -SIMDE_FLOAT16_C(    17.802), -SIMDE_FLOAT16_C(     7.956), -SIMDE_FLOAT16_C(    25.547),  SIMDE_FLOAT16_C(    29.976),
        -SIMDE_FLOAT16_C(    16.109), -SIMDE_FLOAT16_C(     0.241), -SIMDE_FLOAT16_C(    17.325),  SIMDE_FLOAT16_C(     2.343) },
      { -INT16_C(        17), -INT16_C(         7), -INT16_C(        25),  INT16_C(        30),
        -INT16_C(        16),  INT16_C(         0), -INT16_C(        17),  INT16_C(         3) } },
    { { -SIMDE_FLOAT16_C(     2.318),  SIMDE_FLOAT16_C(    27.885),  SIMDE_FLOAT16_C(    10.828),  SIMDE_FLOAT16_C(    16.530),
         SIMDE_FLOAT16_C(    19.659), -SIMDE_FLOAT16_C(    11.861), -SIMDE_FLOAT16_C(    15.435), -SIMDE_FLOAT16_C(    22.972) },
      { -INT16_C(         2),  INT16_C(        28),  INT16_C(        11),  INT16_C(        17),
         INT16_C(        20), -INT16_C(        11), -INT16_C(        15), -INT16_C(        22) } },
    { { -SIMDE_FLOAT16_C(    26.398),  SIMDE_FLOAT16_C(    12.636),  SIMDE_FLOAT16_C(    23.632),  SIMDE_FLOAT16_C(    22.209),
         SIMDE_FLOAT16_C(    16.480), -SIMDE_FLOAT16_C(     8.479), -SIMDE_FLOAT16_C(    11.944), -SIMDE_FLOAT16_C(    10.576) },
      { -INT16_C(        26),  INT16_C(        13),  INT16_C(        24),  INT16_C(        23),
         INT16_C(        17), -INT16_C(         8), -INT16_C(        11), -INT16_C(        10) } },
    { {  SIMDE_FLOAT16_C(    10.556),  SIMDE_FLOAT16_C(    14.462),  SIMDE_FLOAT16_C(     4.323),  SIMDE_FLOAT16_C(    29.542),
        -SIMDE_FLOAT16_C(    13.708), -SIMDE_FLOAT16_C(    11.548),  SIMDE_FLOAT16_C(    13.467),  SIMDE_FLOAT16_C(     4.887) },
      {  INT16_C(        11),  INT16_C(        15),  INT16_C(         5),  INT16_C(        30),
        -INT16_C(        13), -INT16_C(        11),  INT16_C(        14),  INT16_C(         5) } },
    { { -SIMDE_FLOAT16_C(    28.249),  SIMDE_FLOAT16_C(    10.669),  SIMDE_FLOAT16_C(    15.634), -SIMDE_FLOAT16_C(    29.024),
        -SIMDE_FLOAT16_C(     5.544),  SIMDE_FLOAT16_C(     5.271),  SIMDE_FLOAT16_C(     7.326),  SIMDE_FLOAT16_C(    22.421) },
      { -INT16_C(        28),  INT16_C(        11),  INT16_C(        16), -INT16_C(        29),
        -INT16_C(         5),  INT16_C(         6),  INT16_C(         8),  INT16_C(        23) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_int16x8_t r = simde_vcvtpq_s16_f16(a);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtp_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16 a[4];
    int16_t r[4];
  } test_vec[] = {
    { { -SIMDE_FLOAT16_C(    24.451), -SIMDE_FLOAT16_C(    26.951),  SIMDE_FLOAT16_C(     4.545), -SIMDE_FLOAT16_C(    16.203) },
      { -INT16_C(        24), -INT16_C(        26),  INT16_C(         5), -INT16_C(        16) } },
    { { -SIMDE_FLOAT16_C(     6.971), -SIMDE_FLOAT16_C(     0.372), -SIMDE_FLOAT16_C(    23.985), -SIMDE_FLOAT16_C(     5.566) },
      { -INT16_C(         6),  INT16_C(         0), -INT16_C(        23), -INT16_C(         5) } },
    { { -SIMDE_FLOAT16_C(    17.684), -SIMDE_FLOAT16_C(    12.522), -SIMDE_FLOAT16_C(    26.196), -SIMDE_FLOAT16_C(    17.907) },
      { -INT16_C(        17), -INT16_C(        12), -INT16_C(        26), -INT16_C(        17) } },
    { { -SIMDE_FLOAT16_C(    15.913),  SIMDE_FLOAT16_C(    11.327), -SIMDE_FLOAT16_C(    20.331),  SIMDE_FLOAT16_C(     6.990) },
      { -INT16_C(        15),  INT16_C(        12), -INT16_C(        20),  INT16_C(         7) } },
    { { -SIMDE_FLOAT16_C(     7.259),  SIMDE_FLOAT16_C(    10.857), -SIMDE_FLOAT16_C(    14.002),  SIMDE_FLOAT16_C(    16.367) },
      { -INT16_C(         7),  INT16_C(        11), -INT16_C(        14),  INT16_C(        17) } },
    { { -SIMDE_FLOAT16_C(    14.487),  SIMDE_FLOAT16_C(    25.818),  SIMDE_FLOAT16_C(    25.545), -SIMDE_FLOAT16_C(     9.464) },
      { -INT16_C(        14),  INT16_C(        26),  INT16_C(        26), -INT16_C(         9) } },
    { {  SIMDE_FLOAT16_C(    10.801), -SIMDE_FLOAT16_C(    16.889),  SIMDE_FLOAT16_C(    15.712), -SIMDE_FLOAT16_C(    26.668) },
      {  INT16_C(        11), -INT16_C(        16),  INT16_C(        16), -INT16_C(        26) } },
    { {  SIMDE_FLOAT16_C(    16.707), -SIMDE_FLOAT16_C(     6.907), -SIMDE_FLOAT16_C(    16.125),  SIMDE_FLOAT16_C(    16.581) },
      {  INT16_C(        17), -INT16_C(         6), -INT16_C(        16),  INT16_C(        17) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_int16x4_t r = simde_vcvtp_s16_f16(a);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtpq_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16 a[8];
    uint16_t r[8];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_C(     8.412), -SIMDE_FLOAT16_C(    20.676),  SIMDE_FLOAT16_C(    20.459), -SIMDE_FLOAT16_C(    13.452),
        -SIMDE_FLOAT16_C(    29.146), -SIMDE_FLOAT16_C(    14.819),  SIMDE_FLOAT16_C(    20.802), -SIMDE_FLOAT16_C(    24.492) },
      {  UINT16_C(         9),  UINT16_C(         0),  UINT16_C(        21),  UINT16_C(         0),
         UINT16_C(         0),  UINT16_C(         0),  UINT16_C(        21),  UINT16_C(         0) } },
    { { -SIMDE_FLOAT16_C(     2.614), -SIMDE_FLOAT16_C(    15.601),  SIMDE_FLOAT16_C(     8.786), -SIMDE_FLOAT16_C(     6.447),
         SIMDE_FLOAT16_C(    10.565), -SIMDE_FLOAT16_C(     2.841), -SIMDE_FLOAT16_C(    22.172), -SIMDE_FLOAT16_C(    29.225) },
      {  UINT16_C(         0),  UINT16_C(         0),  UINT16_C(         9),  UINT16_C(         0),
         UINT16_C(        11),  UINT16_C(         0),  UINT16_C(         0),  UINT16_C(         0) } },
    { { -SIMDE_FLOAT16_C(    14.661), -SIMDE_FLOAT16_C(    19.655),  SIMDE_FLOAT16_C(    20.945), -SIMDE_FLOAT16_C(    14.723),
        -SIMDE_FLOAT16_C(     6.795), -SIMDE_FLOAT16_C(    15.668), -SIMDE_FLOAT16_C(    14.611), -SIMDE_FLOAT16_C(     1.305) },
      {  UINT16_C(         0),  UINT16_C(         0),  UINT16_C(        21),  UINT16_C(         0),
         UINT16_C(         0),  UINT16_C(         0),  UINT16_C(         0),  UINT16_C(         0) } },
    { {  SIMDE_FLOAT16_C(    19.446), -SIMDE_FLOAT16_C(     4.649),  SIMDE_FLOAT16_C(    15.291),  SIMDE_FLOAT16_C(    27.089),
         SIMDE_FLOAT16_C(    21.245),  SIMDE_FLOAT16_C(    26.014), -SIMDE_FLOAT16_C(    26.170), -SIMDE_FLOAT16_C(     5.297) },
      {  UINT16_C(        20),  UINT16_C(         0),  UINT16_C(        16),  UINT16_C(        28),
         UINT16_C(        22),  UINT16_C(        27),  UINT16_C(         0),  UINT16_C(         0) } },
    { { -SIMDE_FLOAT16_C(    24.950), -SIMDE_FLOAT16_C(     6.918),  SIMDE_FLOAT16_C(     0.448), -SIMDE_FLOAT16_C(    15.577),
        -SIMDE_FLOAT16_C(     0.695),  SIMDE_FLOAT16_C(     5.113),  SIMDE_FLOAT16_C(    25.849),  SIMDE_FLOAT16_C(    14.897) },
      {  UINT16_C(         0),  UINT16_C(         0),  UINT16_C(         1),  UINT16_C(         0),
         UINT16_C(         0),  UINT16_C(         6),  UINT16_C(        26),  UINT16_C(        15) } },
    { {  SIMDE_FLOAT16_C(     1.047),  SIMDE_FLOAT16_C(    24.092), -SIMDE_FLOAT16_C(     1.801), -SIMDE_FLOAT16_C(    17.346),
         SIMDE_FLOAT16_C(    29.217), -SIMDE_FLOAT16_C(     9.152),  SIMDE_FLOAT16_C(    28.523), -SIMDE_FLOAT16_C(     4.282) },
      {  UINT16_C(         2),  UINT16_C(        25),  UINT16_C(         0),  UINT16_C(         0),
         UINT16_C(        30),  UINT16_C(         0),  UINT16_C(        29),  UINT16_C(         0) } },
    { {  SIMDE_FLOAT16_C(     4.652),  SIMDE_FLOAT16_C(     7.864), -SIMDE_FLOAT16_C(    17.356), -SIMDE_FLOAT16_C(    28.063),
         SIMDE_FLOAT16_C(     6.314),  SIMDE_FLOAT16_C(     6.172),  SIMDE_FLOAT16_C(    26.258),  SIMDE_FLOAT16_C(     9.995) },
      {  UINT16_C(         5),  UINT16_C(         8),  UINT16_C(         0),  UINT16_C(         0),
         UINT16_C(         7),  UINT16_C(         7),  UINT16_C(        27),  UINT16_C(        10) } },
    { {  SIMDE_FLOAT16_C(    18.260), -SIMDE_FLOAT16_C(    10.321),  SIMDE_FLOAT16_C(    22.847), -SIMDE_FLOAT16_C(     0.938),
        -SIMDE_FLOAT16_C(    14.103), -SIMDE_FLOAT16_C(    19.351), -SIMDE_FLOAT16_C(    14.925),  SIMDE_FLOAT16_C(     9.615) },
      {  UINT16_C(        19),  UINT16_C(         0),  UINT16_C(        23),  UINT16_C(         0),
         UINT16_C(         0),  UINT16_C(         0),  UINT16_C(         0),  UINT16_C(        10) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_uint16x8_t r = simde_vcvtpq_u16_f16(a);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtp_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16 a[4];
    uint16_t r[4];
  } test_vec[] = {
    { { -SIMDE_FLOAT16_C(    28.193), -SIMDE_FLOAT16_C(     5.895), -SIMDE_FLOAT16_C(    19.920),  SIMDE_FLOAT16_C(     6.564) },
      {  UINT16_C(         0),  UINT16_C(         0),  UINT16_C(         0),  UINT16_C(         7) } },
    { {  SIMDE_FLOAT16_C(     0.585), -SIMDE_FLOAT16_C(     6.201), -SIMDE_FLOAT16_C(    22.634),  SIMDE_FLOAT16_C(    24.041) },
      {  UINT16_C(         1),  UINT16_C(         0),  UINT16_C(         0),  UINT16_C(        25) } },
    { {  SIMDE_FLOAT16_C(     4.740),  SIMDE_FLOAT16_C(    23.654),  SIMDE_FLOAT16_C(    11.130), -SIMDE_FLOAT16_C(     5.253) },
      {  UINT16_C(         5),  UINT16_C(        24),  UINT16_C(        12),  UINT16_C(         0) } },
    { {  SIMDE_FLOAT16_C(     1.349),  SIMDE_FLOAT16_C(     2.498),  SIMDE_FLOAT16_C(    13.681), -SIMDE_FLOAT16_C(    29.260) },
      {  UINT16_C(         2),  UINT16_C(         3),  UINT16_C(        14),  UINT16_C(         0) } },
    { { -SIMDE_FLOAT16_C(    23.131), -SIMDE_FLOAT16_C(    13.650), -SIMDE_FLOAT16_C(    17.659), -SIMDE_FLOAT16_C(    13.515) },
      {  UINT16_C(         0),  UINT16_C(         0),  UINT16_C(         0),  UINT16_C(         0) } },
    { {  SIMDE_FLOAT16_C(     8.833), -SIMDE_FLOAT16_C(     2.183),  SIMDE_FLOAT16_C(    18.027), -SIMDE_FLOAT16_C(    17.240) },
      {  UINT16_C(         9),  UINT16_C(         0),  UINT16_C(        19),  UINT16_C(         0) } },
    { {  SIMDE_FLOAT16_C(    10.889), -SIMDE_FLOAT16_C(    11.836),  SIMDE_FLOAT16_C(    29.920), -SIMDE_FLOAT16_C(     7.524) },
      {  UINT16_C(        11),  UINT16_C(         0),  UINT16_C(        30),  UINT16_C(         0) } },
    { { -SIMDE_FLOAT16_C(    29.853),  SIMDE_FLOAT16_C(    19.538),  SIMDE_FLOAT16_C(    25.232),  SIMDE_FLOAT16_C(    12.122) },
      {  UINT16_C(         0),  UINT16_C(        20),  UINT16_C(        26),  UINT16_C(        13) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_uint16x4_t r = simde_vcvtp_u16_f16(a);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtp_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
    uint32_t r[2];
  } test_vec[] = {
    { { -SIMDE_FLOAT32_C(   597.398), -SIMDE_FLOAT32_C(   458.709) },
      {  UINT32_C(         0),  UINT32_C(         0) } },
    { {  SIMDE_FLOAT32_C(   610.058),  SIMDE_FLOAT32_C(   408.327) },
      {  UINT32_C(       611),  UINT32_C(       409) } },
    { {  SIMDE_FLOAT32_C(   683.218),  SIMDE_FLOAT32_C(   523.587) },
      {  UINT32_C(       684),  UINT32_C(       524) } },
    { {  SIMDE_FLOAT32_C(   840.155),  SIMDE_FLOAT32_C(   535.544) },
      {  UINT32_C(       841),  UINT32_C(       536) } },
    { {  SIMDE_FLOAT32_C(   878.489),  SIMDE_FLOAT32_C(   177.802) },
      {  UINT32_C(       879),  UINT32_C(       178) } },
    { {  SIMDE_FLOAT32_C(   160.684),  SIMDE_FLOAT32_C(   430.784) },
      {  UINT32_C(       161),  UINT32_C(       431) } },
    { {  SIMDE_FLOAT32_C(   816.827),  SIMDE_FLOAT32_C(   582.145) },
      {  UINT32_C(       817),  UINT32_C(       583) } },
    { { -SIMDE_FLOAT32_C(   107.822), -SIMDE_FLOAT32_C(   304.504) },
      {  UINT32_C(         0),  UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_uint32x2_t r = simde_vcvtp_u32_f32(a);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtp_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
    int32_t r[2];
  } test_vec[] = {
    { { -SIMDE_FLOAT32_C(   308.681),  SIMDE_FLOAT32_C(   253.856) },
      { -INT32_C(       308),  INT32_C(       254) } },
    { {  SIMDE_FLOAT32_C(   415.847), -SIMDE_FLOAT32_C(   667.662) },
      {  INT32_C(       416), -INT32_C(       667) } },
    { {  SIMDE_FLOAT32_C(   225.278), -SIMDE_FLOAT32_C(   604.949) },
      {  INT32_C(       226), -INT32_C(       604) } },
    { {  SIMDE_FLOAT32_C(   924.365),  SIMDE_FLOAT32_C(   945.477) },
      {  INT32_C(       925),  INT32_C(       946) } },
    { {  SIMDE_FLOAT32_C(   895.563),  SIMDE_FLOAT32_C(    45.311) },
      {  INT32_C(       896),  INT32_C(        46) } },
    { { -SIMDE_FLOAT32_C(   317.703), -SIMDE_FLOAT32_C(   868.310) },
      { -INT32_C(       317), -INT32_C(       868) } },
    { {  SIMDE_FLOAT32_C(   541.485), -SIMDE_FLOAT32_C(   504.698) },
      {  INT32_C(       542), -INT32_C(       504) } },
    { { -SIMDE_FLOAT32_C(   653.810), -SIMDE_FLOAT32_C(   265.026) },
      { -INT32_C(       653), -INT32_C(       265) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_int32x2_t r = simde_vcvtp_s32_f32(a);
    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtp_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[1];
    int64_t r[1];
  } test_vec[] = {
    { {  SIMDE_FLOAT64_C( 24965.766) },
      {  INT64_C(     24966) } },
    { { -SIMDE_FLOAT64_C( 30984.422) },
      { -INT64_C(     30984) } },
    { { -SIMDE_FLOAT64_C( 16724.391) },
      { -INT64_C(     16724) } },
    { {  SIMDE_FLOAT64_C( 31802.109) },
      {  INT64_C(     31803) } },
    { {  SIMDE_FLOAT64_C( 46616.438) },
      {  INT64_C(     46617) } },
    { {  SIMDE_FLOAT64_C( 57103.266) },
      {  INT64_C(     57104) } },
    { { -SIMDE_FLOAT64_C( 21279.477) },
      { -INT64_C(     21279) } },
    { { -SIMDE_FLOAT64_C( 18106.797) },
      { -INT64_C(     18106) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_int64x1_t r = simde_vcvtp_s64_f64(a);
    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtp_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[1];
    uint64_t r[1];
  } test_vec[] = {
    { { -SIMDE_FLOAT64_C( 35426.270) },
      {  UINT64_C(         0) } },
    { {  SIMDE_FLOAT64_C( 20147.570) },
      {  UINT64_C(     20148) } },
    { { -SIMDE_FLOAT64_C( 99335.164) },
      {  UINT64_C(         0) } },
    { { -SIMDE_FLOAT64_C(   261.680) },
      {  UINT64_C(         0) } },
    { { -SIMDE_FLOAT64_C( 35468.840) },
      {  UINT64_C(         0) } },
    { {  SIMDE_FLOAT64_C( 83020.297) },
      {  UINT64_C(     83021) } },
    { { -SIMDE_FLOAT64_C( 32519.094) },
      {  UINT64_C(         0) } },
    { { -SIMDE_FLOAT64_C( 36452.516) },
      {  UINT64_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_uint64x1_t r = simde_vcvtp_u64_f64(a);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtps_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtpd_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtps_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtpd_u64_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvtph_s16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtph_s32_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtph_s64_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtph_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtph_u32_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtph_u64_f16)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvtp_s16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtp_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtp_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtp_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtp_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtp_u64_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvtpq_s16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtpq_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtpq_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtpq_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtpq_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtpq_u64_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"