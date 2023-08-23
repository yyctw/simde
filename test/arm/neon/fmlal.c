#define SIMDE_TEST_ARM_NEON_INSN fmlal

#include "test-neon.h"
#include "../../../simde/arm/neon/fmlal.h"

static int
test_simde_vfmlal_low_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t buf[2];
    simde_float16_t a[4];
    simde_float16_t b[4];
    simde_float32_t r[2];
  } test_vec[] = {
    { { -SIMDE_FLOAT32_C(   853.754),  SIMDE_FLOAT32_C(   132.918) },
      {  SIMDE_FLOAT16_C(    25.907), -SIMDE_FLOAT16_C(    25.022), -SIMDE_FLOAT16_C(    10.666),  SIMDE_FLOAT16_C(    18.244) },
      {  SIMDE_FLOAT16_C(     3.455), -SIMDE_FLOAT16_C(     1.129),  SIMDE_FLOAT16_C(    11.321),  SIMDE_FLOAT16_C(     8.592) },
      { -SIMDE_FLOAT32_C(   764.239),  SIMDE_FLOAT32_C(   161.160) } },
    { { -SIMDE_FLOAT32_C(   574.541), -SIMDE_FLOAT32_C(   751.170) },
      { -SIMDE_FLOAT16_C(    18.887), -SIMDE_FLOAT16_C(     4.060), -SIMDE_FLOAT16_C(    27.337), -SIMDE_FLOAT16_C(     8.600) },
      {  SIMDE_FLOAT16_C(     0.479), -SIMDE_FLOAT16_C(    17.365), -SIMDE_FLOAT16_C(    14.284),  SIMDE_FLOAT16_C(     3.517) },
      { -SIMDE_FLOAT32_C(   583.591), -SIMDE_FLOAT32_C(   680.675) } },
    { { -SIMDE_FLOAT32_C(   559.529),  SIMDE_FLOAT32_C(   383.880) },
      {  SIMDE_FLOAT16_C(     1.220), -SIMDE_FLOAT16_C(    16.412),  SIMDE_FLOAT16_C(    20.898), -SIMDE_FLOAT16_C(     9.212) },
      { -SIMDE_FLOAT16_C(     4.990), -SIMDE_FLOAT16_C(    29.042), -SIMDE_FLOAT16_C(    23.184), -SIMDE_FLOAT16_C(     5.445) },
      { -SIMDE_FLOAT32_C(   565.617),  SIMDE_FLOAT32_C(   860.509) } },
    { { -SIMDE_FLOAT32_C(   631.012),  SIMDE_FLOAT32_C(    22.518) },
      { -SIMDE_FLOAT16_C(    14.014),  SIMDE_FLOAT16_C(     0.179), -SIMDE_FLOAT16_C(     4.565), -SIMDE_FLOAT16_C(    10.458) },
      { -SIMDE_FLOAT16_C(    12.924),  SIMDE_FLOAT16_C(    21.513),  SIMDE_FLOAT16_C(     1.812), -SIMDE_FLOAT16_C(    13.888) },
      { -SIMDE_FLOAT32_C(   449.892),  SIMDE_FLOAT32_C(    26.369) } },
    { { -SIMDE_FLOAT32_C(   921.736), -SIMDE_FLOAT32_C(   359.865) },
      { -SIMDE_FLOAT16_C(     0.052), -SIMDE_FLOAT16_C(    20.310), -SIMDE_FLOAT16_C(    29.849), -SIMDE_FLOAT16_C(    20.255) },
      {  SIMDE_FLOAT16_C(    29.664),  SIMDE_FLOAT16_C(    18.725), -SIMDE_FLOAT16_C(    10.817), -SIMDE_FLOAT16_C(     6.813) },
      { -SIMDE_FLOAT32_C(   923.273), -SIMDE_FLOAT32_C(   740.173) } },
    { {  SIMDE_FLOAT32_C(   581.148), -SIMDE_FLOAT32_C(   733.713) },
      {  SIMDE_FLOAT16_C(    28.873), -SIMDE_FLOAT16_C(     8.158), -SIMDE_FLOAT16_C(     5.395), -SIMDE_FLOAT16_C(    21.684) },
      { -SIMDE_FLOAT16_C(    17.341),  SIMDE_FLOAT16_C(     9.982),  SIMDE_FLOAT16_C(    22.665),  SIMDE_FLOAT16_C(    20.518) },
      {  SIMDE_FLOAT32_C(    80.347), -SIMDE_FLOAT32_C(   815.151) } },
    { {  SIMDE_FLOAT32_C(   201.725), -SIMDE_FLOAT32_C(   236.950) },
      { -SIMDE_FLOAT16_C(     5.450), -SIMDE_FLOAT16_C(    28.771), -SIMDE_FLOAT16_C(    19.191), -SIMDE_FLOAT16_C(    28.638) },
      { -SIMDE_FLOAT16_C(    25.479), -SIMDE_FLOAT16_C(    11.617),  SIMDE_FLOAT16_C(     4.413),  SIMDE_FLOAT16_C(    17.728) },
      {  SIMDE_FLOAT32_C(   340.575),  SIMDE_FLOAT32_C(    97.290) } },
    { {  SIMDE_FLOAT32_C(   515.504),  SIMDE_FLOAT32_C(   196.872) },
      { -SIMDE_FLOAT16_C(    10.101), -SIMDE_FLOAT16_C(    10.913),  SIMDE_FLOAT16_C(    13.987),  SIMDE_FLOAT16_C(     6.371) },
      { -SIMDE_FLOAT16_C(     6.557),  SIMDE_FLOAT16_C(    18.161), -SIMDE_FLOAT16_C(    24.919),  SIMDE_FLOAT16_C(    25.647) },
      {  SIMDE_FLOAT32_C(   581.740), -SIMDE_FLOAT32_C(     1.315) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t buf = simde_vld1_f32(test_vec[i].buf);
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float32x2_t r = simde_vfmlal_low_f16(buf, a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vfmlalq_low_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t buf[4];
    simde_float16_t a[8];
    simde_float16_t b[8];
    simde_float32_t r[4];
  } test_vec[] = {
    { {  SIMDE_FLOAT32_C(   784.580), -SIMDE_FLOAT32_C(   328.400),  SIMDE_FLOAT32_C(   828.707),  SIMDE_FLOAT32_C(   794.695) },
      {  SIMDE_FLOAT16_C(     0.218), -SIMDE_FLOAT16_C(    11.465),  SIMDE_FLOAT16_C(    24.875),  SIMDE_FLOAT16_C(     4.716),
        -SIMDE_FLOAT16_C(    19.619), -SIMDE_FLOAT16_C(    23.453), -SIMDE_FLOAT16_C(     0.833), -SIMDE_FLOAT16_C(    17.146) },
      { -SIMDE_FLOAT16_C(    15.931), -SIMDE_FLOAT16_C(    11.760),  SIMDE_FLOAT16_C(    25.990),  SIMDE_FLOAT16_C(    15.672),
         SIMDE_FLOAT16_C(    15.581),  SIMDE_FLOAT16_C(     4.497), -SIMDE_FLOAT16_C(     3.364),  SIMDE_FLOAT16_C(    10.447) },
      {  SIMDE_FLOAT32_C(   781.107), -SIMDE_FLOAT32_C(   193.572),  SIMDE_FLOAT32_C(  1475.068),  SIMDE_FLOAT32_C(   868.604) } },
    { { -SIMDE_FLOAT32_C(   470.689),  SIMDE_FLOAT32_C(   877.197),  SIMDE_FLOAT32_C(   160.200),  SIMDE_FLOAT32_C(   230.522) },
      { -SIMDE_FLOAT16_C(     5.173),  SIMDE_FLOAT16_C(    26.357),  SIMDE_FLOAT16_C(    20.434),  SIMDE_FLOAT16_C(     6.694),
         SIMDE_FLOAT16_C(     0.805),  SIMDE_FLOAT16_C(    13.406), -SIMDE_FLOAT16_C(     6.967), -SIMDE_FLOAT16_C(    22.064) },
      { -SIMDE_FLOAT16_C(    18.464), -SIMDE_FLOAT16_C(    11.382),  SIMDE_FLOAT16_C(     4.509),  SIMDE_FLOAT16_C(    20.912),
        -SIMDE_FLOAT16_C(     0.252), -SIMDE_FLOAT16_C(     6.348),  SIMDE_FLOAT16_C(    24.612), -SIMDE_FLOAT16_C(     9.948) },
      { -SIMDE_FLOAT32_C(   375.175),  SIMDE_FLOAT32_C(   577.202),  SIMDE_FLOAT32_C(   252.337),  SIMDE_FLOAT32_C(   370.507) } },
    { { -SIMDE_FLOAT32_C(   354.804), -SIMDE_FLOAT32_C(   463.819),  SIMDE_FLOAT32_C(   754.596), -SIMDE_FLOAT32_C(   179.754) },
      {  SIMDE_FLOAT16_C(     2.982),  SIMDE_FLOAT16_C(     9.067), -SIMDE_FLOAT16_C(    22.898),  SIMDE_FLOAT16_C(    25.336),
        -SIMDE_FLOAT16_C(     2.414), -SIMDE_FLOAT16_C(     3.470), -SIMDE_FLOAT16_C(     6.007), -SIMDE_FLOAT16_C(     1.155) },
      {  SIMDE_FLOAT16_C(    26.794),  SIMDE_FLOAT16_C(    18.416),  SIMDE_FLOAT16_C(     5.500),  SIMDE_FLOAT16_C(    20.843),
         SIMDE_FLOAT16_C(    22.256), -SIMDE_FLOAT16_C(    13.408),  SIMDE_FLOAT16_C(     1.597),  SIMDE_FLOAT16_C(     2.985) },
      { -SIMDE_FLOAT32_C(   274.904), -SIMDE_FLOAT32_C(   296.726),  SIMDE_FLOAT32_C(   628.657),  SIMDE_FLOAT32_C(   348.504) } },
    { { -SIMDE_FLOAT32_C(   239.317),  SIMDE_FLOAT32_C(   596.431), -SIMDE_FLOAT32_C(   939.913), -SIMDE_FLOAT32_C(   533.173) },
      {  SIMDE_FLOAT16_C(     3.623),  SIMDE_FLOAT16_C(    28.619),  SIMDE_FLOAT16_C(    25.847), -SIMDE_FLOAT16_C(    23.012),
        -SIMDE_FLOAT16_C(     0.126),  SIMDE_FLOAT16_C(    18.454),  SIMDE_FLOAT16_C(    26.740), -SIMDE_FLOAT16_C(    20.158) },
      { -SIMDE_FLOAT16_C(     5.793),  SIMDE_FLOAT16_C(    17.984),  SIMDE_FLOAT16_C(     8.343), -SIMDE_FLOAT16_C(     6.354),
         SIMDE_FLOAT16_C(    21.138), -SIMDE_FLOAT16_C(    15.859), -SIMDE_FLOAT16_C(     0.831),  SIMDE_FLOAT16_C(    11.413) },
      { -SIMDE_FLOAT32_C(   260.305),  SIMDE_FLOAT32_C(  1111.233), -SIMDE_FLOAT32_C(   724.271), -SIMDE_FLOAT32_C(   386.955) } },
    { {  SIMDE_FLOAT32_C(   149.635),  SIMDE_FLOAT32_C(   788.869),  SIMDE_FLOAT32_C(   325.410), -SIMDE_FLOAT32_C(   754.606) },
      { -SIMDE_FLOAT16_C(    24.417),  SIMDE_FLOAT16_C(     9.313),  SIMDE_FLOAT16_C(    21.810), -SIMDE_FLOAT16_C(    10.214),
         SIMDE_FLOAT16_C(     8.568),  SIMDE_FLOAT16_C(     2.603), -SIMDE_FLOAT16_C(    28.921), -SIMDE_FLOAT16_C(     0.238) },
      {  SIMDE_FLOAT16_C(     5.981), -SIMDE_FLOAT16_C(     7.791),  SIMDE_FLOAT16_C(    23.927),  SIMDE_FLOAT16_C(     4.006),
        -SIMDE_FLOAT16_C(    18.782), -SIMDE_FLOAT16_C(     1.670),  SIMDE_FLOAT16_C(    17.644), -SIMDE_FLOAT16_C(     7.963) },
      {  SIMDE_FLOAT32_C(     3.597),  SIMDE_FLOAT32_C(   716.311),  SIMDE_FLOAT32_C(   847.258), -SIMDE_FLOAT32_C(   795.523) } },
    { {  SIMDE_FLOAT32_C(   706.928),  SIMDE_FLOAT32_C(   415.429),  SIMDE_FLOAT32_C(   368.350), -SIMDE_FLOAT32_C(   363.635) },
      {  SIMDE_FLOAT16_C(     5.777),  SIMDE_FLOAT16_C(     4.240), -SIMDE_FLOAT16_C(    14.862), -SIMDE_FLOAT16_C(    20.526),
         SIMDE_FLOAT16_C(    18.466), -SIMDE_FLOAT16_C(     2.750),  SIMDE_FLOAT16_C(     2.364), -SIMDE_FLOAT16_C(    29.732) },
      { -SIMDE_FLOAT16_C(     8.959),  SIMDE_FLOAT16_C(    18.339), -SIMDE_FLOAT16_C(     5.241),  SIMDE_FLOAT16_C(    12.494),
        -SIMDE_FLOAT16_C(    10.337), -SIMDE_FLOAT16_C(    18.136),  SIMDE_FLOAT16_C(     7.657), -SIMDE_FLOAT16_C(    11.446) },
      {  SIMDE_FLOAT32_C(   655.172),  SIMDE_FLOAT32_C(   493.186),  SIMDE_FLOAT32_C(   446.242), -SIMDE_FLOAT32_C(   620.087) } },
    { { -SIMDE_FLOAT32_C(   695.957), -SIMDE_FLOAT32_C(   783.110),  SIMDE_FLOAT32_C(   517.153),  SIMDE_FLOAT32_C(   749.657) },
      {  SIMDE_FLOAT16_C(    15.502),  SIMDE_FLOAT16_C(    29.662),  SIMDE_FLOAT16_C(     8.075),  SIMDE_FLOAT16_C(     4.052),
        -SIMDE_FLOAT16_C(    16.507), -SIMDE_FLOAT16_C(     8.330), -SIMDE_FLOAT16_C(    13.673),  SIMDE_FLOAT16_C(     2.713) },
      {  SIMDE_FLOAT16_C(    10.339), -SIMDE_FLOAT16_C(    15.830), -SIMDE_FLOAT16_C(     3.031),  SIMDE_FLOAT16_C(    18.224),
        -SIMDE_FLOAT16_C(    18.963),  SIMDE_FLOAT16_C(     2.396),  SIMDE_FLOAT16_C(    29.380), -SIMDE_FLOAT16_C(     3.013) },
      { -SIMDE_FLOAT32_C(   535.682), -SIMDE_FLOAT32_C(  1252.512),  SIMDE_FLOAT32_C(   492.678),  SIMDE_FLOAT32_C(   823.501) } },
    { { -SIMDE_FLOAT32_C(   253.703), -SIMDE_FLOAT32_C(   221.312),  SIMDE_FLOAT32_C(    35.199),  SIMDE_FLOAT32_C(   884.028) },
      {  SIMDE_FLOAT16_C(     1.849), -SIMDE_FLOAT16_C(     6.314),  SIMDE_FLOAT16_C(    12.199),  SIMDE_FLOAT16_C(    29.127),
         SIMDE_FLOAT16_C(    16.628), -SIMDE_FLOAT16_C(     5.324), -SIMDE_FLOAT16_C(    22.966), -SIMDE_FLOAT16_C(     4.079) },
      { -SIMDE_FLOAT16_C(    11.196), -SIMDE_FLOAT16_C(     3.907),  SIMDE_FLOAT16_C(     9.315), -SIMDE_FLOAT16_C(    23.381),
         SIMDE_FLOAT16_C(    15.334), -SIMDE_FLOAT16_C(    28.596),  SIMDE_FLOAT16_C(     7.043), -SIMDE_FLOAT16_C(    27.219) },
      { -SIMDE_FLOAT32_C(   274.404), -SIMDE_FLOAT32_C(   196.643),  SIMDE_FLOAT32_C(   148.833),  SIMDE_FLOAT32_C(   203.231) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t buf = simde_vld1q_f32(test_vec[i].buf);
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float32x4_t r = simde_vfmlalq_low_f16(buf, a, b);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vfmlal_high_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t buf[2];
    simde_float16_t a[4];
    simde_float16_t b[4];
    simde_float32_t r[2];
  } test_vec[] = {
    { {  SIMDE_FLOAT32_C(   702.710),  SIMDE_FLOAT32_C(   864.782) },
      { -SIMDE_FLOAT16_C(    21.132),  SIMDE_FLOAT16_C(     1.218),  SIMDE_FLOAT16_C(    24.520), -SIMDE_FLOAT16_C(    17.676) },
      { -SIMDE_FLOAT16_C(    11.597),  SIMDE_FLOAT16_C(    14.243), -SIMDE_FLOAT16_C(     0.830),  SIMDE_FLOAT16_C(     2.712) },
      {  SIMDE_FLOAT32_C(   682.358),  SIMDE_FLOAT32_C(   816.845) } },
    { {  SIMDE_FLOAT32_C(   444.620),  SIMDE_FLOAT32_C(    20.088) },
      { -SIMDE_FLOAT16_C(    24.136), -SIMDE_FLOAT16_C(    11.873), -SIMDE_FLOAT16_C(     3.602), -SIMDE_FLOAT16_C(    10.091) },
      { -SIMDE_FLOAT16_C(     7.450),  SIMDE_FLOAT16_C(    23.421),  SIMDE_FLOAT16_C(    18.084), -SIMDE_FLOAT16_C(    24.408) },
      {  SIMDE_FLOAT32_C(   379.481),  SIMDE_FLOAT32_C(   266.389) } },
    { {  SIMDE_FLOAT32_C(   478.147),  SIMDE_FLOAT32_C(   388.716) },
      {  SIMDE_FLOAT16_C(    20.848), -SIMDE_FLOAT16_C(     5.806),  SIMDE_FLOAT16_C(     8.744),  SIMDE_FLOAT16_C(     1.880) },
      { -SIMDE_FLOAT16_C(    17.334),  SIMDE_FLOAT16_C(    29.771),  SIMDE_FLOAT16_C(    11.341),  SIMDE_FLOAT16_C(     8.505) },
      {  SIMDE_FLOAT32_C(   577.313),  SIMDE_FLOAT32_C(   404.705) } },
    { {  SIMDE_FLOAT32_C(   196.323), -SIMDE_FLOAT32_C(   146.874) },
      {  SIMDE_FLOAT16_C(     1.098),  SIMDE_FLOAT16_C(    19.634),  SIMDE_FLOAT16_C(    25.363), -SIMDE_FLOAT16_C(     1.493) },
      {  SIMDE_FLOAT16_C(    22.813),  SIMDE_FLOAT16_C(    15.566), -SIMDE_FLOAT16_C(    23.858),  SIMDE_FLOAT16_C(    10.897) },
      { -SIMDE_FLOAT32_C(   408.787), -SIMDE_FLOAT32_C(   163.143) } },
    { { -SIMDE_FLOAT32_C(   171.853),  SIMDE_FLOAT32_C(   204.898) },
      { -SIMDE_FLOAT16_C(    23.661), -SIMDE_FLOAT16_C(    29.271), -SIMDE_FLOAT16_C(    20.347),  SIMDE_FLOAT16_C(    16.334) },
      { -SIMDE_FLOAT16_C(    22.648),  SIMDE_FLOAT16_C(     9.889), -SIMDE_FLOAT16_C(     8.490),  SIMDE_FLOAT16_C(    12.781) },
      {  SIMDE_FLOAT32_C(     0.893),  SIMDE_FLOAT32_C(   413.663) } },
    { {  SIMDE_FLOAT32_C(   177.412), -SIMDE_FLOAT32_C(   875.675) },
      {  SIMDE_FLOAT16_C(    16.490), -SIMDE_FLOAT16_C(     4.761),  SIMDE_FLOAT16_C(     6.624),  SIMDE_FLOAT16_C(    14.736) },
      { -SIMDE_FLOAT16_C(     4.745),  SIMDE_FLOAT16_C(     3.723), -SIMDE_FLOAT16_C(    27.392),  SIMDE_FLOAT16_C(    23.872) },
      { -SIMDE_FLOAT32_C(     4.033), -SIMDE_FLOAT32_C(   523.897) } },
    { {  SIMDE_FLOAT32_C(   124.990),  SIMDE_FLOAT32_C(    43.975) },
      { -SIMDE_FLOAT16_C(     5.856),  SIMDE_FLOAT16_C(    19.562),  SIMDE_FLOAT16_C(    13.778),  SIMDE_FLOAT16_C(    29.608) },
      { -SIMDE_FLOAT16_C(    26.341),  SIMDE_FLOAT16_C(     9.426),  SIMDE_FLOAT16_C(    17.171),  SIMDE_FLOAT16_C(    20.851) },
      {  SIMDE_FLOAT32_C(   361.572),  SIMDE_FLOAT32_C(   661.145) } },
    { { -SIMDE_FLOAT32_C(   904.650), -SIMDE_FLOAT32_C(   966.811) },
      {  SIMDE_FLOAT16_C(    19.116), -SIMDE_FLOAT16_C(     0.640), -SIMDE_FLOAT16_C(     7.226), -SIMDE_FLOAT16_C(    20.031) },
      {  SIMDE_FLOAT16_C(     1.794),  SIMDE_FLOAT16_C(     5.224),  SIMDE_FLOAT16_C(    10.450),  SIMDE_FLOAT16_C(    11.411) },
      { -SIMDE_FLOAT32_C(   980.162), -SIMDE_FLOAT32_C(  1195.385) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t buf = simde_vld1_f32(test_vec[i].buf);
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float32x2_t r = simde_vfmlal_high_f16(buf, a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vfmlalq_high_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t buf[4];
    simde_float16_t a[8];
    simde_float16_t b[8];
    simde_float32_t r[4];
  } test_vec[] = {
    { { -SIMDE_FLOAT32_C(   657.333), -SIMDE_FLOAT32_C(   920.509),  SIMDE_FLOAT32_C(   472.011), -SIMDE_FLOAT32_C(   133.223) },
      { -SIMDE_FLOAT16_C(     5.069), -SIMDE_FLOAT16_C(     9.452), -SIMDE_FLOAT16_C(    10.249), -SIMDE_FLOAT16_C(    16.982),
        -SIMDE_FLOAT16_C(     2.336), -SIMDE_FLOAT16_C(    27.814), -SIMDE_FLOAT16_C(    21.733), -SIMDE_FLOAT16_C(     0.446) },
      {  SIMDE_FLOAT16_C(     9.571),  SIMDE_FLOAT16_C(    29.231),  SIMDE_FLOAT16_C(    24.088),  SIMDE_FLOAT16_C(     9.249),
         SIMDE_FLOAT16_C(    22.824),  SIMDE_FLOAT16_C(    19.453),  SIMDE_FLOAT16_C(    13.139), -SIMDE_FLOAT16_C(    28.983) },
      { -SIMDE_FLOAT32_C(   710.650), -SIMDE_FLOAT32_C(  1461.575),  SIMDE_FLOAT32_C(   186.461), -SIMDE_FLOAT32_C(   120.297) } },
    { {  SIMDE_FLOAT32_C(   505.275),  SIMDE_FLOAT32_C(    63.609),  SIMDE_FLOAT32_C(   535.023), -SIMDE_FLOAT32_C(   203.955) },
      { -SIMDE_FLOAT16_C(    21.340), -SIMDE_FLOAT16_C(    13.340),  SIMDE_FLOAT16_C(    27.400),  SIMDE_FLOAT16_C(    21.469),
         SIMDE_FLOAT16_C(    17.669), -SIMDE_FLOAT16_C(    23.930),  SIMDE_FLOAT16_C(    29.427),  SIMDE_FLOAT16_C(    21.033) },
      {  SIMDE_FLOAT16_C(    26.582),  SIMDE_FLOAT16_C(    17.664),  SIMDE_FLOAT16_C(    19.519), -SIMDE_FLOAT16_C(    19.485),
        -SIMDE_FLOAT16_C(    18.472),  SIMDE_FLOAT16_C(    13.390),  SIMDE_FLOAT16_C(     1.862),  SIMDE_FLOAT16_C(     6.481) },
      {  SIMDE_FLOAT32_C(   178.893), -SIMDE_FLOAT32_C(   256.929),  SIMDE_FLOAT32_C(   589.816), -SIMDE_FLOAT32_C(    67.640) } },
    { {  SIMDE_FLOAT32_C(   146.726), -SIMDE_FLOAT32_C(   958.185), -SIMDE_FLOAT32_C(   246.707),  SIMDE_FLOAT32_C(    95.867) },
      {  SIMDE_FLOAT16_C(    11.767),  SIMDE_FLOAT16_C(     4.188), -SIMDE_FLOAT16_C(     8.591), -SIMDE_FLOAT16_C(    25.659),
        -SIMDE_FLOAT16_C(    14.838),  SIMDE_FLOAT16_C(    17.729),  SIMDE_FLOAT16_C(     0.934),  SIMDE_FLOAT16_C(     6.272) },
      { -SIMDE_FLOAT16_C(    10.833),  SIMDE_FLOAT16_C(    22.521), -SIMDE_FLOAT16_C(    23.037),  SIMDE_FLOAT16_C(    11.228),
        -SIMDE_FLOAT16_C(    18.964), -SIMDE_FLOAT16_C(     8.764),  SIMDE_FLOAT16_C(    16.271), -SIMDE_FLOAT16_C(    16.270) },
      {  SIMDE_FLOAT32_C(   428.114), -SIMDE_FLOAT32_C(  1113.562), -SIMDE_FLOAT32_C(   231.510), -SIMDE_FLOAT32_C(     6.178) } },
    { { -SIMDE_FLOAT32_C(   665.185), -SIMDE_FLOAT32_C(   806.004),  SIMDE_FLOAT32_C(   295.424),  SIMDE_FLOAT32_C(   629.280) },
      { -SIMDE_FLOAT16_C(    13.539), -SIMDE_FLOAT16_C(    12.762),  SIMDE_FLOAT16_C(    12.314), -SIMDE_FLOAT16_C(    21.198),
        -SIMDE_FLOAT16_C(     1.521),  SIMDE_FLOAT16_C(    27.567),  SIMDE_FLOAT16_C(    24.214), -SIMDE_FLOAT16_C(     6.105) },
      {  SIMDE_FLOAT16_C(    27.152), -SIMDE_FLOAT16_C(     2.556), -SIMDE_FLOAT16_C(    18.037),  SIMDE_FLOAT16_C(     4.801),
        -SIMDE_FLOAT16_C(     5.621),  SIMDE_FLOAT16_C(     8.879), -SIMDE_FLOAT16_C(     6.765),  SIMDE_FLOAT16_C(     4.412) },
      { -SIMDE_FLOAT32_C(   656.635), -SIMDE_FLOAT32_C(   561.237),  SIMDE_FLOAT32_C(   131.616),  SIMDE_FLOAT32_C(   602.345) } },
    { { -SIMDE_FLOAT32_C(    83.069),  SIMDE_FLOAT32_C(   237.219), -SIMDE_FLOAT32_C(    10.825), -SIMDE_FLOAT32_C(   343.582) },
      {  SIMDE_FLOAT16_C(    13.599),  SIMDE_FLOAT16_C(    27.243),  SIMDE_FLOAT16_C(    21.106), -SIMDE_FLOAT16_C(    17.077),
         SIMDE_FLOAT16_C(     4.623), -SIMDE_FLOAT16_C(    14.054),  SIMDE_FLOAT16_C(    13.145),  SIMDE_FLOAT16_C(    14.266) },
      { -SIMDE_FLOAT16_C(    28.894), -SIMDE_FLOAT16_C(     1.422),  SIMDE_FLOAT16_C(     2.596), -SIMDE_FLOAT16_C(     8.926),
         SIMDE_FLOAT16_C(    21.681),  SIMDE_FLOAT16_C(     2.494), -SIMDE_FLOAT16_C(     1.393), -SIMDE_FLOAT16_C(    19.855) },
      {  SIMDE_FLOAT32_C(    17.162),  SIMDE_FLOAT32_C(   202.168), -SIMDE_FLOAT32_C(    29.136), -SIMDE_FLOAT32_C(   626.833) } },
    { { -SIMDE_FLOAT32_C(   304.342), -SIMDE_FLOAT32_C(   795.813),  SIMDE_FLOAT32_C(   352.852),  SIMDE_FLOAT32_C(   303.873) },
      { -SIMDE_FLOAT16_C(     4.465), -SIMDE_FLOAT16_C(     3.099),  SIMDE_FLOAT16_C(     4.375), -SIMDE_FLOAT16_C(     9.244),
         SIMDE_FLOAT16_C(     5.281), -SIMDE_FLOAT16_C(    18.004),  SIMDE_FLOAT16_C(     3.289),  SIMDE_FLOAT16_C(    11.251) },
      {  SIMDE_FLOAT16_C(     8.779),  SIMDE_FLOAT16_C(    13.324),  SIMDE_FLOAT16_C(    11.662), -SIMDE_FLOAT16_C(    14.920),
        -SIMDE_FLOAT16_C(     8.187),  SIMDE_FLOAT16_C(    25.735), -SIMDE_FLOAT16_C(    26.103), -SIMDE_FLOAT16_C(    10.258) },
      { -SIMDE_FLOAT32_C(   347.578), -SIMDE_FLOAT32_C(  1259.031),  SIMDE_FLOAT32_C(   266.999),  SIMDE_FLOAT32_C(   188.460) } },
    { {  SIMDE_FLOAT32_C(   272.202),  SIMDE_FLOAT32_C(   938.301),  SIMDE_FLOAT32_C(   527.822), -SIMDE_FLOAT32_C(   204.304) },
      {  SIMDE_FLOAT16_C(    18.385), -SIMDE_FLOAT16_C(     6.275), -SIMDE_FLOAT16_C(    24.892),  SIMDE_FLOAT16_C(     5.443),
         SIMDE_FLOAT16_C(    19.632), -SIMDE_FLOAT16_C(     3.434),  SIMDE_FLOAT16_C(    20.480),  SIMDE_FLOAT16_C(     0.479) },
      { -SIMDE_FLOAT16_C(    13.953),  SIMDE_FLOAT16_C(    10.981),  SIMDE_FLOAT16_C(     8.627),  SIMDE_FLOAT16_C(     8.017),
         SIMDE_FLOAT16_C(    23.170), -SIMDE_FLOAT16_C(     8.365),  SIMDE_FLOAT16_C(    17.543),  SIMDE_FLOAT16_C(    22.874) },
      {  SIMDE_FLOAT32_C(   726.950),  SIMDE_FLOAT32_C(   967.026),  SIMDE_FLOAT32_C(   887.258), -SIMDE_FLOAT32_C(   193.347) } },
    { {  SIMDE_FLOAT32_C(   459.394),  SIMDE_FLOAT32_C(   718.963), -SIMDE_FLOAT32_C(   215.189), -SIMDE_FLOAT32_C(   199.080) },
      { -SIMDE_FLOAT16_C(    10.232), -SIMDE_FLOAT16_C(    16.379),  SIMDE_FLOAT16_C(    14.912),  SIMDE_FLOAT16_C(     2.776),
        -SIMDE_FLOAT16_C(    29.143), -SIMDE_FLOAT16_C(     5.960), -SIMDE_FLOAT16_C(     8.064),  SIMDE_FLOAT16_C(    12.878) },
      { -SIMDE_FLOAT16_C(    16.158),  SIMDE_FLOAT16_C(    11.968), -SIMDE_FLOAT16_C(    28.546),  SIMDE_FLOAT16_C(     6.196),
         SIMDE_FLOAT16_C(    27.401), -SIMDE_FLOAT16_C(    22.540), -SIMDE_FLOAT16_C(    12.690), -SIMDE_FLOAT16_C(    17.194) },
      { -SIMDE_FLOAT32_C(   339.153),  SIMDE_FLOAT32_C(   853.301), -SIMDE_FLOAT32_C(   112.857), -SIMDE_FLOAT32_C(   420.369) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t buf = simde_vld1q_f32(test_vec[i].buf);
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float32x4_t r = simde_vfmlalq_high_f16(buf, a, b);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vfmlal_lane_low_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t buf[2];
    simde_float16_t a[4];
    simde_float16_t b[4];
    int8_t lane;
    simde_float32_t r[2];
  } test_vec[] = {
    { { -SIMDE_FLOAT32_C(   383.706), -SIMDE_FLOAT32_C(   454.883) },
      { -SIMDE_FLOAT16_C(    12.568),  SIMDE_FLOAT16_C(    28.226), -SIMDE_FLOAT16_C(    26.744), -SIMDE_FLOAT16_C(     1.231) },
      { -SIMDE_FLOAT16_C(     4.139),  SIMDE_FLOAT16_C(     4.036), -SIMDE_FLOAT16_C(    24.349), -SIMDE_FLOAT16_C(    16.357) },
         INT8_C(         0),
      { -SIMDE_FLOAT32_C(   331.687), -SIMDE_FLOAT32_C(   571.710) } },
    { { -SIMDE_FLOAT32_C(    54.748), -SIMDE_FLOAT32_C(   239.323) },
      { -SIMDE_FLOAT16_C(     4.199),  SIMDE_FLOAT16_C(    22.553), -SIMDE_FLOAT16_C(    21.214), -SIMDE_FLOAT16_C(    21.941) },
      {  SIMDE_FLOAT16_C(    13.523),  SIMDE_FLOAT16_C(    24.541),  SIMDE_FLOAT16_C(     1.057), -SIMDE_FLOAT16_C(    11.171) },
         INT8_C(         1),
      { -SIMDE_FLOAT32_C(   157.796),  SIMDE_FLOAT32_C(   314.150) } },
    { { -SIMDE_FLOAT32_C(   884.028), -SIMDE_FLOAT32_C(   632.455) },
      { -SIMDE_FLOAT16_C(    25.077), -SIMDE_FLOAT16_C(     1.923), -SIMDE_FLOAT16_C(    26.899),  SIMDE_FLOAT16_C(    20.795) },
      { -SIMDE_FLOAT16_C(     9.245), -SIMDE_FLOAT16_C(    27.668), -SIMDE_FLOAT16_C(    23.263), -SIMDE_FLOAT16_C(     1.502) },
         INT8_C(         3),
      { -SIMDE_FLOAT32_C(   846.362), -SIMDE_FLOAT32_C(   629.567) } },
    { { -SIMDE_FLOAT32_C(   775.176), -SIMDE_FLOAT32_C(   970.447) },
      { -SIMDE_FLOAT16_C(     0.548), -SIMDE_FLOAT16_C(    25.245),  SIMDE_FLOAT16_C(    19.927), -SIMDE_FLOAT16_C(     7.279) },
      { -SIMDE_FLOAT16_C(    26.036), -SIMDE_FLOAT16_C(     3.500), -SIMDE_FLOAT16_C(     3.128),  SIMDE_FLOAT16_C(    19.673) },
         INT8_C(         1),
      { -SIMDE_FLOAT32_C(   773.258), -SIMDE_FLOAT32_C(   882.090) } },
    { {  SIMDE_FLOAT32_C(   927.656),  SIMDE_FLOAT32_C(   647.602) },
      { -SIMDE_FLOAT16_C(    22.002),  SIMDE_FLOAT16_C(     0.822),  SIMDE_FLOAT16_C(     7.416),  SIMDE_FLOAT16_C(    14.160) },
      {  SIMDE_FLOAT16_C(     2.305), -SIMDE_FLOAT16_C(     1.288), -SIMDE_FLOAT16_C(    20.803),  SIMDE_FLOAT16_C(    21.848) },
         INT8_C(         3),
      {  SIMDE_FLOAT32_C(   447.093),  SIMDE_FLOAT32_C(   665.561) } },
    { { -SIMDE_FLOAT32_C(    85.667), -SIMDE_FLOAT32_C(   139.653) },
      {  SIMDE_FLOAT16_C(    27.906), -SIMDE_FLOAT16_C(    20.945),  SIMDE_FLOAT16_C(    23.060), -SIMDE_FLOAT16_C(     5.590) },
      { -SIMDE_FLOAT16_C(     4.161), -SIMDE_FLOAT16_C(    24.314),  SIMDE_FLOAT16_C(    29.494),  SIMDE_FLOAT16_C(     8.934) },
         INT8_C(         0),
      { -SIMDE_FLOAT32_C(   201.784), -SIMDE_FLOAT32_C(    52.501) } },
    { { -SIMDE_FLOAT32_C(   148.275), -SIMDE_FLOAT32_C(    52.267) },
      { -SIMDE_FLOAT16_C(    16.059), -SIMDE_FLOAT16_C(    27.163), -SIMDE_FLOAT16_C(    14.561), -SIMDE_FLOAT16_C(    15.885) },
      {  SIMDE_FLOAT16_C(    20.661), -SIMDE_FLOAT16_C(     4.493),  SIMDE_FLOAT16_C(     9.654), -SIMDE_FLOAT16_C(    19.232) },
         INT8_C(         0),
      { -SIMDE_FLOAT32_C(   480.070), -SIMDE_FLOAT32_C(   613.213) } },
    { { -SIMDE_FLOAT32_C(    31.578), -SIMDE_FLOAT32_C(   121.097) },
      {  SIMDE_FLOAT16_C(     1.003), -SIMDE_FLOAT16_C(    14.958),  SIMDE_FLOAT16_C(    13.941), -SIMDE_FLOAT16_C(     8.364) },
      { -SIMDE_FLOAT16_C(     0.032), -SIMDE_FLOAT16_C(     1.581),  SIMDE_FLOAT16_C(     9.709),  SIMDE_FLOAT16_C(    15.731) },
         INT8_C(         0),
      { -SIMDE_FLOAT32_C(    31.610), -SIMDE_FLOAT32_C(   120.618) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t buf = simde_vld1_f32(test_vec[i].buf);
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float32x2_t r;
    int lane = test_vec[i].lane;
    SIMDE_CONSTIFY_4_(simde_vfmlal_lane_low_f16, r, (HEDLEY_UNREACHABLE(), r), lane, buf, a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vfmlal_laneq_low_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t buf[2];
    simde_float16_t a[4];
    simde_float16_t b[8];
    int8_t lane;
    simde_float32_t r[2];
  } test_vec[] = {
    { {  SIMDE_FLOAT32_C(   970.794), -SIMDE_FLOAT32_C(   417.196) },
      {  SIMDE_FLOAT16_C(     7.465),  SIMDE_FLOAT16_C(    13.519), -SIMDE_FLOAT16_C(    25.844),  SIMDE_FLOAT16_C(     4.214) },
      {  SIMDE_FLOAT16_C(    10.346),  SIMDE_FLOAT16_C(    19.625),  SIMDE_FLOAT16_C(     5.309),  SIMDE_FLOAT16_C(     2.236),
         SIMDE_FLOAT16_C(     7.168), -SIMDE_FLOAT16_C(    25.612),  SIMDE_FLOAT16_C(    20.580),  SIMDE_FLOAT16_C(     2.354) },
         INT8_C(         7),
      {  SIMDE_FLOAT32_C(   988.367), -SIMDE_FLOAT32_C(   385.372) } },
    { {  SIMDE_FLOAT32_C(    57.105), -SIMDE_FLOAT32_C(   746.461) },
      {  SIMDE_FLOAT16_C(     7.487),  SIMDE_FLOAT16_C(    20.179),  SIMDE_FLOAT16_C(    16.118), -SIMDE_FLOAT16_C(    17.541) },
      { -SIMDE_FLOAT16_C(    19.232),  SIMDE_FLOAT16_C(    29.544),  SIMDE_FLOAT16_C(    10.908), -SIMDE_FLOAT16_C(     6.743),
         SIMDE_FLOAT16_C(    19.582),  SIMDE_FLOAT16_C(    10.925), -SIMDE_FLOAT16_C(    19.464), -SIMDE_FLOAT16_C(     8.936) },
         INT8_C(         3),
      {  SIMDE_FLOAT32_C(     6.620), -SIMDE_FLOAT32_C(   882.528) } },
    { {  SIMDE_FLOAT32_C(   514.022), -SIMDE_FLOAT32_C(   593.779) },
      {  SIMDE_FLOAT16_C(    22.303),  SIMDE_FLOAT16_C(    18.307), -SIMDE_FLOAT16_C(    29.352), -SIMDE_FLOAT16_C(    17.945) },
      {  SIMDE_FLOAT16_C(     9.297), -SIMDE_FLOAT16_C(    11.981), -SIMDE_FLOAT16_C(    24.390), -SIMDE_FLOAT16_C(     9.335),
         SIMDE_FLOAT16_C(    20.524),  SIMDE_FLOAT16_C(    14.769),  SIMDE_FLOAT16_C(    22.289), -SIMDE_FLOAT16_C(    24.038) },
         INT8_C(         5),
      {  SIMDE_FLOAT32_C(   843.249), -SIMDE_FLOAT32_C(   323.403) } },
    { {  SIMDE_FLOAT32_C(   868.814),  SIMDE_FLOAT32_C(   145.994) },
      {  SIMDE_FLOAT16_C(    17.788), -SIMDE_FLOAT16_C(    17.865), -SIMDE_FLOAT16_C(    29.388), -SIMDE_FLOAT16_C(     8.152) },
      { -SIMDE_FLOAT16_C(    12.678),  SIMDE_FLOAT16_C(     9.756), -SIMDE_FLOAT16_C(    23.874), -SIMDE_FLOAT16_C(    26.287),
        -SIMDE_FLOAT16_C(    20.084), -SIMDE_FLOAT16_C(     4.832),  SIMDE_FLOAT16_C(    19.781),  SIMDE_FLOAT16_C(    19.911) },
         INT8_C(         7),
      {  SIMDE_FLOAT32_C(  1222.771), -SIMDE_FLOAT32_C(   209.519) } },
    { { -SIMDE_FLOAT32_C(    91.832), -SIMDE_FLOAT32_C(   558.211) },
      { -SIMDE_FLOAT16_C(    14.852), -SIMDE_FLOAT16_C(    13.989),  SIMDE_FLOAT16_C(     6.888), -SIMDE_FLOAT16_C(    17.552) },
      {  SIMDE_FLOAT16_C(     6.935), -SIMDE_FLOAT16_C(     1.348), -SIMDE_FLOAT16_C(    28.843), -SIMDE_FLOAT16_C(     0.676),
         SIMDE_FLOAT16_C(    17.989),  SIMDE_FLOAT16_C(    22.137), -SIMDE_FLOAT16_C(    22.545), -SIMDE_FLOAT16_C(    18.760) },
         INT8_C(         2),
      {  SIMDE_FLOAT32_C(   336.544), -SIMDE_FLOAT32_C(   154.623) } },
    { {  SIMDE_FLOAT32_C(   220.583), -SIMDE_FLOAT32_C(   629.867) },
      { -SIMDE_FLOAT16_C(    22.190), -SIMDE_FLOAT16_C(    11.082),  SIMDE_FLOAT16_C(     5.266), -SIMDE_FLOAT16_C(    17.109) },
      {  SIMDE_FLOAT16_C(    20.562), -SIMDE_FLOAT16_C(     4.360),  SIMDE_FLOAT16_C(    19.857), -SIMDE_FLOAT16_C(    26.833),
         SIMDE_FLOAT16_C(     3.429),  SIMDE_FLOAT16_C(    18.078),  SIMDE_FLOAT16_C(    26.925),  SIMDE_FLOAT16_C(    26.446) },
         INT8_C(         0),
      { -SIMDE_FLOAT32_C(   235.688), -SIMDE_FLOAT32_C(   857.735) } },
    { { -SIMDE_FLOAT32_C(    58.721), -SIMDE_FLOAT32_C(   761.797) },
      {  SIMDE_FLOAT16_C(    22.966), -SIMDE_FLOAT16_C(    20.744),  SIMDE_FLOAT16_C(    24.876), -SIMDE_FLOAT16_C(     1.164) },
      {  SIMDE_FLOAT16_C(    29.465),  SIMDE_FLOAT16_C(     5.667), -SIMDE_FLOAT16_C(     7.231), -SIMDE_FLOAT16_C(    18.400),
         SIMDE_FLOAT16_C(    16.727),  SIMDE_FLOAT16_C(    22.593), -SIMDE_FLOAT16_C(    14.828),  SIMDE_FLOAT16_C(     4.738) },
         INT8_C(         3),
      { -SIMDE_FLOAT32_C(   481.489), -SIMDE_FLOAT32_C(   379.867) } },
    { { -SIMDE_FLOAT32_C(   973.005), -SIMDE_FLOAT32_C(    98.890) },
      {  SIMDE_FLOAT16_C(    10.023), -SIMDE_FLOAT16_C(     0.077), -SIMDE_FLOAT16_C(    19.275),  SIMDE_FLOAT16_C(     1.948) },
      {  SIMDE_FLOAT16_C(    20.587),  SIMDE_FLOAT16_C(    25.295),  SIMDE_FLOAT16_C(    28.345), -SIMDE_FLOAT16_C(    26.733),
        -SIMDE_FLOAT16_C(     3.950),  SIMDE_FLOAT16_C(    29.385), -SIMDE_FLOAT16_C(    24.046),  SIMDE_FLOAT16_C(    27.180) },
         INT8_C(         2),
      { -SIMDE_FLOAT32_C(   688.903), -SIMDE_FLOAT32_C(   101.073) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t buf = simde_vld1_f32(test_vec[i].buf);
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float32x2_t r;
    int lane = test_vec[i].lane;
    SIMDE_CONSTIFY_8_(simde_vfmlal_laneq_low_f16, r, (HEDLEY_UNREACHABLE(), r), lane, buf, a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vfmlalq_lane_low_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t buf[4];
    simde_float16_t a[8];
    simde_float16_t b[4];
    int8_t lane;
    simde_float32_t r[4];
  } test_vec[] = {
    { {  SIMDE_FLOAT32_C(   631.028),  SIMDE_FLOAT32_C(   137.991),  SIMDE_FLOAT32_C(   335.541),  SIMDE_FLOAT32_C(   212.273) },
      {  SIMDE_FLOAT16_C(    28.260),  SIMDE_FLOAT16_C(     7.017), -SIMDE_FLOAT16_C(    29.621), -SIMDE_FLOAT16_C(    23.915),
        -SIMDE_FLOAT16_C(    16.779),  SIMDE_FLOAT16_C(    29.487),  SIMDE_FLOAT16_C(     7.151), -SIMDE_FLOAT16_C(     6.889) },
      {  SIMDE_FLOAT16_C(    28.759), -SIMDE_FLOAT16_C(    29.373),  SIMDE_FLOAT16_C(    26.049),  SIMDE_FLOAT16_C(     0.320) },
         INT8_C(         3),
      {  SIMDE_FLOAT32_C(   640.071),  SIMDE_FLOAT32_C(   140.236),  SIMDE_FLOAT32_C(   326.062),  SIMDE_FLOAT32_C(   204.620) } },
    { {  SIMDE_FLOAT32_C(   739.523),  SIMDE_FLOAT32_C(   876.361),  SIMDE_FLOAT32_C(   512.377),  SIMDE_FLOAT32_C(   393.800) },
      {  SIMDE_FLOAT16_C(     2.010),  SIMDE_FLOAT16_C(    25.604),  SIMDE_FLOAT16_C(    16.697), -SIMDE_FLOAT16_C(    18.061),
         SIMDE_FLOAT16_C(    12.960), -SIMDE_FLOAT16_C(     3.725),  SIMDE_FLOAT16_C(     2.898), -SIMDE_FLOAT16_C(    21.849) },
      {  SIMDE_FLOAT16_C(     0.667), -SIMDE_FLOAT16_C(     0.597),  SIMDE_FLOAT16_C(     1.053),  SIMDE_FLOAT16_C(    11.976) },
         INT8_C(         0),
      {  SIMDE_FLOAT32_C(   740.864),  SIMDE_FLOAT32_C(   893.439),  SIMDE_FLOAT32_C(   523.514),  SIMDE_FLOAT32_C(   381.753) } },
    { { -SIMDE_FLOAT32_C(    56.114),  SIMDE_FLOAT32_C(   645.103),  SIMDE_FLOAT32_C(   944.164), -SIMDE_FLOAT32_C(   472.236) },
      { -SIMDE_FLOAT16_C(    25.524),  SIMDE_FLOAT16_C(     5.129), -SIMDE_FLOAT16_C(     7.468),  SIMDE_FLOAT16_C(    28.854),
        -SIMDE_FLOAT16_C(    11.480), -SIMDE_FLOAT16_C(    17.685), -SIMDE_FLOAT16_C(    10.192), -SIMDE_FLOAT16_C(     1.114) },
      {  SIMDE_FLOAT16_C(    13.998), -SIMDE_FLOAT16_C(    17.465),  SIMDE_FLOAT16_C(     9.957), -SIMDE_FLOAT16_C(     0.504) },
         INT8_C(         2),
      { -SIMDE_FLOAT32_C(   310.256),  SIMDE_FLOAT32_C(   696.172),  SIMDE_FLOAT32_C(   869.805), -SIMDE_FLOAT32_C(   184.937) } },
    { {  SIMDE_FLOAT32_C(   333.790),  SIMDE_FLOAT32_C(   413.221),  SIMDE_FLOAT32_C(   245.961),  SIMDE_FLOAT32_C(   950.463) },
      {  SIMDE_FLOAT16_C(    27.147),  SIMDE_FLOAT16_C(    18.076),  SIMDE_FLOAT16_C(     2.107),  SIMDE_FLOAT16_C(    17.873),
         SIMDE_FLOAT16_C(    12.019),  SIMDE_FLOAT16_C(    29.658), -SIMDE_FLOAT16_C(    10.520),  SIMDE_FLOAT16_C(    18.986) },
      { -SIMDE_FLOAT16_C(     0.555),  SIMDE_FLOAT16_C(    12.199), -SIMDE_FLOAT16_C(     6.390),  SIMDE_FLOAT16_C(     4.464) },
         INT8_C(         1),
      {  SIMDE_FLOAT32_C(   664.778),  SIMDE_FLOAT32_C(   633.730),  SIMDE_FLOAT32_C(   271.664),  SIMDE_FLOAT32_C(  1168.496) } },
    { {  SIMDE_FLOAT32_C(   121.727),  SIMDE_FLOAT32_C(   349.278),  SIMDE_FLOAT32_C(   884.384), -SIMDE_FLOAT32_C(   561.994) },
      { -SIMDE_FLOAT16_C(     9.680),  SIMDE_FLOAT16_C(    27.111),  SIMDE_FLOAT16_C(    11.910),  SIMDE_FLOAT16_C(    15.370),
        -SIMDE_FLOAT16_C(    21.995), -SIMDE_FLOAT16_C(    12.465), -SIMDE_FLOAT16_C(    18.598), -SIMDE_FLOAT16_C(    20.849) },
      { -SIMDE_FLOAT16_C(    14.399), -SIMDE_FLOAT16_C(     0.664), -SIMDE_FLOAT16_C(    17.376), -SIMDE_FLOAT16_C(     1.795) },
         INT8_C(         2),
      {  SIMDE_FLOAT32_C(   289.927), -SIMDE_FLOAT32_C(   121.803),  SIMDE_FLOAT32_C(   677.436), -SIMDE_FLOAT32_C(   829.063) } },
    { { -SIMDE_FLOAT32_C(   431.037), -SIMDE_FLOAT32_C(    96.239),  SIMDE_FLOAT32_C(    87.055), -SIMDE_FLOAT32_C(    65.455) },
      {  SIMDE_FLOAT16_C(    20.711), -SIMDE_FLOAT16_C(     2.797), -SIMDE_FLOAT16_C(     6.554), -SIMDE_FLOAT16_C(    16.764),
         SIMDE_FLOAT16_C(    19.178),  SIMDE_FLOAT16_C(    29.149), -SIMDE_FLOAT16_C(    16.573), -SIMDE_FLOAT16_C(    24.849) },
      {  SIMDE_FLOAT16_C(     6.826), -SIMDE_FLOAT16_C(     3.597), -SIMDE_FLOAT16_C(    17.765),  SIMDE_FLOAT16_C(    28.479) },
         INT8_C(         0),
      { -SIMDE_FLOAT32_C(   289.664), -SIMDE_FLOAT32_C(   115.331),  SIMDE_FLOAT32_C(    42.317), -SIMDE_FLOAT32_C(   179.886) } },
    { { -SIMDE_FLOAT32_C(   976.771), -SIMDE_FLOAT32_C(   927.320),  SIMDE_FLOAT32_C(   663.868), -SIMDE_FLOAT32_C(   103.496) },
      { -SIMDE_FLOAT16_C(    18.155),  SIMDE_FLOAT16_C(    14.809),  SIMDE_FLOAT16_C(    20.902),  SIMDE_FLOAT16_C(    12.803),
        -SIMDE_FLOAT16_C(     1.721),  SIMDE_FLOAT16_C(     9.063),  SIMDE_FLOAT16_C(    25.983),  SIMDE_FLOAT16_C(     1.779) },
      { -SIMDE_FLOAT16_C(    23.107),  SIMDE_FLOAT16_C(    28.318), -SIMDE_FLOAT16_C(    29.501), -SIMDE_FLOAT16_C(     8.240) },
         INT8_C(         1),
      { -SIMDE_FLOAT32_C(  1490.884), -SIMDE_FLOAT32_C(   507.959),  SIMDE_FLOAT32_C(  1255.771),  SIMDE_FLOAT32_C(   259.059) } },
    { { -SIMDE_FLOAT32_C(   351.028),  SIMDE_FLOAT32_C(   949.305),  SIMDE_FLOAT32_C(   269.686),  SIMDE_FLOAT32_C(   774.750) },
      { -SIMDE_FLOAT16_C(    13.143), -SIMDE_FLOAT16_C(    13.075), -SIMDE_FLOAT16_C(     0.618),  SIMDE_FLOAT16_C(    15.138),
         SIMDE_FLOAT16_C(     0.402),  SIMDE_FLOAT16_C(    17.285), -SIMDE_FLOAT16_C(     7.068), -SIMDE_FLOAT16_C(    10.913) },
      {  SIMDE_FLOAT16_C(    24.839),  SIMDE_FLOAT16_C(    10.831), -SIMDE_FLOAT16_C(    25.945),  SIMDE_FLOAT16_C(    14.709) },
         INT8_C(         3),
      { -SIMDE_FLOAT32_C(   544.348),  SIMDE_FLOAT32_C(   756.985),  SIMDE_FLOAT32_C(   260.596),  SIMDE_FLOAT32_C(   997.415) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t buf = simde_vld1q_f32(test_vec[i].buf);
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float32x4_t r;
    int lane = test_vec[i].lane;
    SIMDE_CONSTIFY_4_(simde_vfmlalq_lane_low_f16, r, (HEDLEY_UNREACHABLE(), r), lane, buf, a, b);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vfmlalq_laneq_low_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t buf[4];
    simde_float16_t a[8];
    simde_float16_t b[8];
    int8_t lane;
    simde_float32_t r[4];
  } test_vec[] = {
    { { -SIMDE_FLOAT32_C(   254.540), -SIMDE_FLOAT32_C(   992.020), -SIMDE_FLOAT32_C(   405.595), -SIMDE_FLOAT32_C(   985.635) },
      {  SIMDE_FLOAT16_C(    11.774), -SIMDE_FLOAT16_C(     1.103),  SIMDE_FLOAT16_C(    28.393), -SIMDE_FLOAT16_C(    15.921),
        -SIMDE_FLOAT16_C(     2.962),  SIMDE_FLOAT16_C(     2.598),  SIMDE_FLOAT16_C(    14.738),  SIMDE_FLOAT16_C(    27.738) },
      {  SIMDE_FLOAT16_C(     9.523), -SIMDE_FLOAT16_C(     8.193),  SIMDE_FLOAT16_C(    24.252), -SIMDE_FLOAT16_C(    23.765),
        -SIMDE_FLOAT16_C(    14.376),  SIMDE_FLOAT16_C(    29.848), -SIMDE_FLOAT16_C(     2.060),  SIMDE_FLOAT16_C(     8.033) },
         INT8_C(         5),
      {  SIMDE_FLOAT32_C(    96.890), -SIMDE_FLOAT32_C(  1024.942),  SIMDE_FLOAT32_C(   441.687), -SIMDE_FLOAT32_C(  1460.845) } },
    { {  SIMDE_FLOAT32_C(   806.266),  SIMDE_FLOAT32_C(    85.040), -SIMDE_FLOAT32_C(   277.432), -SIMDE_FLOAT32_C(   246.974) },
      { -SIMDE_FLOAT16_C(    14.046),  SIMDE_FLOAT16_C(     5.460), -SIMDE_FLOAT16_C(    20.004),  SIMDE_FLOAT16_C(     1.412),
         SIMDE_FLOAT16_C(     5.454), -SIMDE_FLOAT16_C(    17.020), -SIMDE_FLOAT16_C(    20.465),  SIMDE_FLOAT16_C(    15.431) },
      { -SIMDE_FLOAT16_C(    23.070),  SIMDE_FLOAT16_C(    18.333), -SIMDE_FLOAT16_C(    25.620), -SIMDE_FLOAT16_C(    27.402),
         SIMDE_FLOAT16_C(     1.223),  SIMDE_FLOAT16_C(    22.948), -SIMDE_FLOAT16_C(    26.255),  SIMDE_FLOAT16_C(    11.331) },
         INT8_C(         6),
      {  SIMDE_FLOAT32_C(  1175.044), -SIMDE_FLOAT32_C(    58.312),  SIMDE_FLOAT32_C(   247.567), -SIMDE_FLOAT32_C(   284.046) } },
    { {  SIMDE_FLOAT32_C(   949.415), -SIMDE_FLOAT32_C(   164.930),  SIMDE_FLOAT32_C(   612.080),  SIMDE_FLOAT32_C(   891.484) },
      {  SIMDE_FLOAT16_C(    13.077),  SIMDE_FLOAT16_C(     8.908),  SIMDE_FLOAT16_C(    14.925),  SIMDE_FLOAT16_C(    27.805),
         SIMDE_FLOAT16_C(    13.088),  SIMDE_FLOAT16_C(    23.090),  SIMDE_FLOAT16_C(     4.698), -SIMDE_FLOAT16_C(    22.937) },
      {  SIMDE_FLOAT16_C(     3.858), -SIMDE_FLOAT16_C(    25.124), -SIMDE_FLOAT16_C(    22.778), -SIMDE_FLOAT16_C(    24.134),
         SIMDE_FLOAT16_C(     4.887),  SIMDE_FLOAT16_C(     3.479), -SIMDE_FLOAT16_C(    22.872),  SIMDE_FLOAT16_C(    14.809) },
         INT8_C(         0),
      {  SIMDE_FLOAT32_C(   999.866), -SIMDE_FLOAT32_C(   130.563),  SIMDE_FLOAT32_C(   669.661),  SIMDE_FLOAT32_C(   998.756) } },
    { { -SIMDE_FLOAT32_C(   417.774),  SIMDE_FLOAT32_C(   862.260), -SIMDE_FLOAT32_C(   647.718),  SIMDE_FLOAT32_C(   703.965) },
      {  SIMDE_FLOAT16_C(     9.777), -SIMDE_FLOAT16_C(    13.217), -SIMDE_FLOAT16_C(     0.788), -SIMDE_FLOAT16_C(     6.800),
         SIMDE_FLOAT16_C(    11.726),  SIMDE_FLOAT16_C(    16.222), -SIMDE_FLOAT16_C(     7.319),  SIMDE_FLOAT16_C(    18.101) },
      {  SIMDE_FLOAT16_C(    23.738),  SIMDE_FLOAT16_C(    22.147), -SIMDE_FLOAT16_C(    11.766),  SIMDE_FLOAT16_C(     6.796),
         SIMDE_FLOAT16_C(    18.035), -SIMDE_FLOAT16_C(    25.249),  SIMDE_FLOAT16_C(    17.600),  SIMDE_FLOAT16_C(    24.549) },
         INT8_C(         5),
      { -SIMDE_FLOAT32_C(   664.633),  SIMDE_FLOAT32_C(  1195.976), -SIMDE_FLOAT32_C(   627.822),  SIMDE_FLOAT32_C(   875.658) } },
    { { -SIMDE_FLOAT32_C(   636.612),  SIMDE_FLOAT32_C(   810.246), -SIMDE_FLOAT32_C(   802.431), -SIMDE_FLOAT32_C(   221.726) },
      {  SIMDE_FLOAT16_C(    22.774),  SIMDE_FLOAT16_C(    14.795), -SIMDE_FLOAT16_C(     4.892),  SIMDE_FLOAT16_C(    19.192),
        -SIMDE_FLOAT16_C(     6.010), -SIMDE_FLOAT16_C(    11.784), -SIMDE_FLOAT16_C(     4.515),  SIMDE_FLOAT16_C(    19.125) },
      { -SIMDE_FLOAT16_C(    29.860),  SIMDE_FLOAT16_C(    22.253), -SIMDE_FLOAT16_C(     2.910),  SIMDE_FLOAT16_C(    20.788),
        -SIMDE_FLOAT16_C(    28.814),  SIMDE_FLOAT16_C(    15.232),  SIMDE_FLOAT16_C(    26.343),  SIMDE_FLOAT16_C(    29.172) },
         INT8_C(         2),
      { -SIMDE_FLOAT32_C(   702.884),  SIMDE_FLOAT32_C(   767.193), -SIMDE_FLOAT32_C(   788.195), -SIMDE_FLOAT32_C(   277.575) } },
    { {  SIMDE_FLOAT32_C(   187.414),  SIMDE_FLOAT32_C(   768.051), -SIMDE_FLOAT32_C(   938.953), -SIMDE_FLOAT32_C(   592.898) },
      {  SIMDE_FLOAT16_C(    20.186), -SIMDE_FLOAT16_C(    17.009),  SIMDE_FLOAT16_C(    29.460),  SIMDE_FLOAT16_C(     0.900),
         SIMDE_FLOAT16_C(    29.424), -SIMDE_FLOAT16_C(    21.030), -SIMDE_FLOAT16_C(    14.486),  SIMDE_FLOAT16_C(     6.244) },
      { -SIMDE_FLOAT16_C(    21.824),  SIMDE_FLOAT16_C(    20.129),  SIMDE_FLOAT16_C(    11.239), -SIMDE_FLOAT16_C(    22.568),
         SIMDE_FLOAT16_C(     2.809),  SIMDE_FLOAT16_C(    22.155),  SIMDE_FLOAT16_C(    12.664),  SIMDE_FLOAT16_C(    29.636) },
         INT8_C(         1),
      {  SIMDE_FLOAT32_C(   593.738),  SIMDE_FLOAT32_C(   425.677), -SIMDE_FLOAT32_C(   346.208), -SIMDE_FLOAT32_C(   574.782) } },
    { {  SIMDE_FLOAT32_C(   518.494),  SIMDE_FLOAT32_C(    82.805), -SIMDE_FLOAT32_C(   282.272), -SIMDE_FLOAT32_C(   882.041) },
      {  SIMDE_FLOAT16_C(    21.223), -SIMDE_FLOAT16_C(    10.813), -SIMDE_FLOAT16_C(    27.278),  SIMDE_FLOAT16_C(    29.456),
         SIMDE_FLOAT16_C(    22.270), -SIMDE_FLOAT16_C(    13.885),  SIMDE_FLOAT16_C(    22.239), -SIMDE_FLOAT16_C(    17.315) },
      { -SIMDE_FLOAT16_C(    15.870), -SIMDE_FLOAT16_C(    21.921), -SIMDE_FLOAT16_C(    15.477),  SIMDE_FLOAT16_C(    24.366),
         SIMDE_FLOAT16_C(    23.722),  SIMDE_FLOAT16_C(     8.421), -SIMDE_FLOAT16_C(    12.496),  SIMDE_FLOAT16_C(     9.348) },
         INT8_C(         7),
      {  SIMDE_FLOAT32_C(   716.887), -SIMDE_FLOAT32_C(    18.275), -SIMDE_FLOAT32_C(   537.394), -SIMDE_FLOAT32_C(   606.686) } },
    { {  SIMDE_FLOAT32_C(   889.267),  SIMDE_FLOAT32_C(   524.544),  SIMDE_FLOAT32_C(   428.174), -SIMDE_FLOAT32_C(   221.991) },
      { -SIMDE_FLOAT16_C(    12.974),  SIMDE_FLOAT16_C(    27.840),  SIMDE_FLOAT16_C(     3.897),  SIMDE_FLOAT16_C(    23.178),
        -SIMDE_FLOAT16_C(     3.067), -SIMDE_FLOAT16_C(    14.039),  SIMDE_FLOAT16_C(     7.460), -SIMDE_FLOAT16_C(    21.971) },
      { -SIMDE_FLOAT16_C(     4.388),  SIMDE_FLOAT16_C(    15.630), -SIMDE_FLOAT16_C(    10.128),  SIMDE_FLOAT16_C(    10.572),
        -SIMDE_FLOAT16_C(    14.175), -SIMDE_FLOAT16_C(     8.509),  SIMDE_FLOAT16_C(     1.430),  SIMDE_FLOAT16_C(    11.987) },
         INT8_C(         0),
      {  SIMDE_FLOAT32_C(   946.197),  SIMDE_FLOAT32_C(   402.382),  SIMDE_FLOAT32_C(   411.074), -SIMDE_FLOAT32_C(   323.696) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t buf = simde_vld1q_f32(test_vec[i].buf);
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float32x4_t r;
    int lane = test_vec[i].lane;
    SIMDE_CONSTIFY_8_(simde_vfmlalq_laneq_low_f16, r, (HEDLEY_UNREACHABLE(), r), lane, buf, a, b);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vfmlal_lane_high_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t buf[2];
    simde_float16_t a[4];
    simde_float16_t b[4];
    int8_t lane;
    simde_float32_t r[2];
  } test_vec[] = {
    { { -SIMDE_FLOAT32_C(   653.115),  SIMDE_FLOAT32_C(    46.449) },
      {  SIMDE_FLOAT16_C(    25.816), -SIMDE_FLOAT16_C(    25.192), -SIMDE_FLOAT16_C(    13.490),  SIMDE_FLOAT16_C(     8.040) },
      { -SIMDE_FLOAT16_C(    28.900),  SIMDE_FLOAT16_C(    19.618),  SIMDE_FLOAT16_C(    20.106),  SIMDE_FLOAT16_C(    23.968) },
         INT8_C(         0),
      { -SIMDE_FLOAT32_C(   263.106), -SIMDE_FLOAT32_C(   185.907) } },
    { { -SIMDE_FLOAT32_C(   221.230),  SIMDE_FLOAT32_C(   501.483) },
      { -SIMDE_FLOAT16_C(    14.724), -SIMDE_FLOAT16_C(    24.274), -SIMDE_FLOAT16_C(    22.492), -SIMDE_FLOAT16_C(    19.951) },
      { -SIMDE_FLOAT16_C(     5.417),  SIMDE_FLOAT16_C(    29.954),  SIMDE_FLOAT16_C(     5.589), -SIMDE_FLOAT16_C(    11.576) },
         INT8_C(         0),
      { -SIMDE_FLOAT32_C(    99.391),  SIMDE_FLOAT32_C(   609.558) } },
    { {  SIMDE_FLOAT32_C(   287.441), -SIMDE_FLOAT32_C(   179.862) },
      {  SIMDE_FLOAT16_C(     5.092),  SIMDE_FLOAT16_C(    28.823), -SIMDE_FLOAT16_C(     3.904), -SIMDE_FLOAT16_C(    12.475) },
      { -SIMDE_FLOAT16_C(    16.772), -SIMDE_FLOAT16_C(    17.246),  SIMDE_FLOAT16_C(     7.515),  SIMDE_FLOAT16_C(     1.360) },
         INT8_C(         0),
      {  SIMDE_FLOAT32_C(   352.919),  SIMDE_FLOAT32_C(    29.369) } },
    { {  SIMDE_FLOAT32_C(   232.334),  SIMDE_FLOAT32_C(   990.433) },
      {  SIMDE_FLOAT16_C(    23.101), -SIMDE_FLOAT16_C(     6.940), -SIMDE_FLOAT16_C(    11.295), -SIMDE_FLOAT16_C(    27.026) },
      {  SIMDE_FLOAT16_C(    19.921), -SIMDE_FLOAT16_C(     7.577),  SIMDE_FLOAT16_C(    18.547), -SIMDE_FLOAT16_C(    13.446) },
         INT8_C(         1),
      {  SIMDE_FLOAT32_C(   317.916),  SIMDE_FLOAT32_C(  1195.209) } },
    { {  SIMDE_FLOAT32_C(   522.399),  SIMDE_FLOAT32_C(   754.555) },
      {  SIMDE_FLOAT16_C(    14.086),  SIMDE_FLOAT16_C(    23.012), -SIMDE_FLOAT16_C(     0.229), -SIMDE_FLOAT16_C(     5.823) },
      { -SIMDE_FLOAT16_C(     2.352),  SIMDE_FLOAT16_C(    17.024),  SIMDE_FLOAT16_C(    22.368), -SIMDE_FLOAT16_C(     5.548) },
         INT8_C(         1),
      {  SIMDE_FLOAT32_C(   518.500),  SIMDE_FLOAT32_C(   655.424) } },
    { {  SIMDE_FLOAT32_C(   224.991), -SIMDE_FLOAT32_C(   223.979) },
      { -SIMDE_FLOAT16_C(    17.043), -SIMDE_FLOAT16_C(    14.222), -SIMDE_FLOAT16_C(    29.502), -SIMDE_FLOAT16_C(    17.998) },
      { -SIMDE_FLOAT16_C(    14.530),  SIMDE_FLOAT16_C(     9.281),  SIMDE_FLOAT16_C(     1.335),  SIMDE_FLOAT16_C(    17.699) },
         INT8_C(         1),
      { -SIMDE_FLOAT32_C(    48.817), -SIMDE_FLOAT32_C(   391.018) } },
    { { -SIMDE_FLOAT32_C(   348.860),  SIMDE_FLOAT32_C(   454.456) },
      {  SIMDE_FLOAT16_C(    13.760),  SIMDE_FLOAT16_C(    13.601), -SIMDE_FLOAT16_C(    18.064),  SIMDE_FLOAT16_C(    16.872) },
      {  SIMDE_FLOAT16_C(     3.020),  SIMDE_FLOAT16_C(    15.775),  SIMDE_FLOAT16_C(    20.437), -SIMDE_FLOAT16_C(    15.584) },
         INT8_C(         3),
      { -SIMDE_FLOAT32_C(    67.351),  SIMDE_FLOAT32_C(   191.523) } },
    { { -SIMDE_FLOAT32_C(   891.862),  SIMDE_FLOAT32_C(    59.061) },
      { -SIMDE_FLOAT16_C(     4.265),  SIMDE_FLOAT16_C(    15.782),  SIMDE_FLOAT16_C(    13.717), -SIMDE_FLOAT16_C(     3.924) },
      {  SIMDE_FLOAT16_C(    29.474), -SIMDE_FLOAT16_C(     5.309),  SIMDE_FLOAT16_C(     9.763),  SIMDE_FLOAT16_C(    16.316) },
         INT8_C(         2),
      { -SIMDE_FLOAT32_C(   757.943),  SIMDE_FLOAT32_C(    20.751) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t buf = simde_vld1_f32(test_vec[i].buf);
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float32x2_t r;
    int lane = test_vec[i].lane;
    SIMDE_CONSTIFY_4_(simde_vfmlal_lane_high_f16, r, (HEDLEY_UNREACHABLE(), r), lane, buf, a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vfmlal_laneq_high_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t buf[2];
    simde_float16_t a[4];
    simde_float16_t b[8];
    int8_t lane;
    simde_float32_t r[2];
  } test_vec[] = {
    { { -SIMDE_FLOAT32_C(   176.182), -SIMDE_FLOAT32_C(   404.864) },
      {  SIMDE_FLOAT16_C(     4.327),  SIMDE_FLOAT16_C(     8.110), -SIMDE_FLOAT16_C(     6.752),  SIMDE_FLOAT16_C(    25.842) },
      {  SIMDE_FLOAT16_C(    13.692), -SIMDE_FLOAT16_C(     1.668),  SIMDE_FLOAT16_C(    16.994), -SIMDE_FLOAT16_C(    27.096),
         SIMDE_FLOAT16_C(    16.710),  SIMDE_FLOAT16_C(    13.626),  SIMDE_FLOAT16_C(    29.592),  SIMDE_FLOAT16_C(    16.653) },
         INT8_C(         3),
      {  SIMDE_FLOAT32_C(     6.770), -SIMDE_FLOAT32_C(  1105.079) } },
    { { -SIMDE_FLOAT32_C(   475.693),  SIMDE_FLOAT32_C(   644.376) },
      {  SIMDE_FLOAT16_C(     1.135),  SIMDE_FLOAT16_C(    17.481),  SIMDE_FLOAT16_C(     8.532), -SIMDE_FLOAT16_C(    18.078) },
      {  SIMDE_FLOAT16_C(    14.609),  SIMDE_FLOAT16_C(    13.128), -SIMDE_FLOAT16_C(     2.938), -SIMDE_FLOAT16_C(    25.342),
         SIMDE_FLOAT16_C(     0.088),  SIMDE_FLOAT16_C(     9.320), -SIMDE_FLOAT16_C(    11.074), -SIMDE_FLOAT16_C(     9.005) },
         INT8_C(         7),
      { -SIMDE_FLOAT32_C(   552.524),  SIMDE_FLOAT32_C(   807.168) } },
    { {  SIMDE_FLOAT32_C(   325.413),  SIMDE_FLOAT32_C(   562.867) },
      {  SIMDE_FLOAT16_C(    19.207),  SIMDE_FLOAT16_C(    11.528),  SIMDE_FLOAT16_C(    24.243), -SIMDE_FLOAT16_C(     3.247) },
      {  SIMDE_FLOAT16_C(    11.660),  SIMDE_FLOAT16_C(    17.957),  SIMDE_FLOAT16_C(    26.721),  SIMDE_FLOAT16_C(    25.425),
         SIMDE_FLOAT16_C(    24.951), -SIMDE_FLOAT16_C(     0.580),  SIMDE_FLOAT16_C(    14.019), -SIMDE_FLOAT16_C(    17.320) },
         INT8_C(         4),
      {  SIMDE_FLOAT32_C(   930.526),  SIMDE_FLOAT32_C(   481.851) } },
    { {  SIMDE_FLOAT32_C(   323.610),  SIMDE_FLOAT32_C(   495.334) },
      {  SIMDE_FLOAT16_C(    27.298),  SIMDE_FLOAT16_C(     5.923), -SIMDE_FLOAT16_C(    15.544), -SIMDE_FLOAT16_C(    12.351) },
      { -SIMDE_FLOAT16_C(    27.380), -SIMDE_FLOAT16_C(    13.306), -SIMDE_FLOAT16_C(    17.911), -SIMDE_FLOAT16_C(    19.981),
        -SIMDE_FLOAT16_C(     6.324),  SIMDE_FLOAT16_C(    14.274),  SIMDE_FLOAT16_C(     7.433), -SIMDE_FLOAT16_C(    20.967) },
         INT8_C(         3),
      {  SIMDE_FLOAT32_C(   634.304),  SIMDE_FLOAT32_C(   742.119) } },
    { { -SIMDE_FLOAT32_C(   875.421), -SIMDE_FLOAT32_C(   422.011) },
      { -SIMDE_FLOAT16_C(    21.980), -SIMDE_FLOAT16_C(    18.207),  SIMDE_FLOAT16_C(    11.369),  SIMDE_FLOAT16_C(     3.724) },
      { -SIMDE_FLOAT16_C(    16.258),  SIMDE_FLOAT16_C(     5.042),  SIMDE_FLOAT16_C(    22.117), -SIMDE_FLOAT16_C(     1.945),
        -SIMDE_FLOAT16_C(    10.323),  SIMDE_FLOAT16_C(    23.247),  SIMDE_FLOAT16_C(    21.050), -SIMDE_FLOAT16_C(    14.925) },
         INT8_C(         1),
      { -SIMDE_FLOAT32_C(   818.099), -SIMDE_FLOAT32_C(   403.235) } },
    { { -SIMDE_FLOAT32_C(   765.574), -SIMDE_FLOAT32_C(   447.020) },
      {  SIMDE_FLOAT16_C(     5.016), -SIMDE_FLOAT16_C(     3.204),  SIMDE_FLOAT16_C(    25.753),  SIMDE_FLOAT16_C(    21.267) },
      {  SIMDE_FLOAT16_C(    26.188),  SIMDE_FLOAT16_C(    27.696),  SIMDE_FLOAT16_C(    29.818),  SIMDE_FLOAT16_C(    19.870),
        -SIMDE_FLOAT16_C(    22.479),  SIMDE_FLOAT16_C(    29.650), -SIMDE_FLOAT16_C(    20.191), -SIMDE_FLOAT16_C(     7.851) },
         INT8_C(         6),
      { -SIMDE_FLOAT32_C(  1285.402), -SIMDE_FLOAT32_C(   876.319) } },
    { {  SIMDE_FLOAT32_C(   138.913), -SIMDE_FLOAT32_C(   427.614) },
      {  SIMDE_FLOAT16_C(     5.594), -SIMDE_FLOAT16_C(    15.354), -SIMDE_FLOAT16_C(    18.293), -SIMDE_FLOAT16_C(    14.186) },
      {  SIMDE_FLOAT16_C(     8.614),  SIMDE_FLOAT16_C(     5.483), -SIMDE_FLOAT16_C(     0.722),  SIMDE_FLOAT16_C(    14.440),
        -SIMDE_FLOAT16_C(    17.573), -SIMDE_FLOAT16_C(    15.641), -SIMDE_FLOAT16_C(    14.151), -SIMDE_FLOAT16_C(    17.485) },
         INT8_C(         4),
      {  SIMDE_FLOAT32_C(   460.537), -SIMDE_FLOAT32_C(   178.323) } },
    { { -SIMDE_FLOAT32_C(   269.955), -SIMDE_FLOAT32_C(   883.008) },
      {  SIMDE_FLOAT16_C(    21.964), -SIMDE_FLOAT16_C(    24.812), -SIMDE_FLOAT16_C(     1.461),  SIMDE_FLOAT16_C(     4.549) },
      {  SIMDE_FLOAT16_C(    22.452),  SIMDE_FLOAT16_C(    27.427),  SIMDE_FLOAT16_C(    12.270),  SIMDE_FLOAT16_C(     8.971),
        -SIMDE_FLOAT16_C(    12.580),  SIMDE_FLOAT16_C(    14.647),  SIMDE_FLOAT16_C(     9.951),  SIMDE_FLOAT16_C(    24.510) },
         INT8_C(         4),
      { -SIMDE_FLOAT32_C(   251.576), -SIMDE_FLOAT32_C(   940.234) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t buf = simde_vld1_f32(test_vec[i].buf);
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float32x2_t r;
    int lane = test_vec[i].lane;
    SIMDE_CONSTIFY_8_(simde_vfmlal_laneq_high_f16, r, (HEDLEY_UNREACHABLE(), r), lane, buf, a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vfmlalq_lane_high_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t buf[4];
    simde_float16_t a[8];
    simde_float16_t b[4];
    int8_t lane;
    simde_float32_t r[4];
  } test_vec[] = {
    { {  SIMDE_FLOAT32_C(   295.250), -SIMDE_FLOAT32_C(    36.983),  SIMDE_FLOAT32_C(   175.799), -SIMDE_FLOAT32_C(   318.698) },
      { -SIMDE_FLOAT16_C(    21.879), -SIMDE_FLOAT16_C(     6.322), -SIMDE_FLOAT16_C(     7.247),  SIMDE_FLOAT16_C(    15.307),
        -SIMDE_FLOAT16_C(     1.516),  SIMDE_FLOAT16_C(    28.071), -SIMDE_FLOAT16_C(    25.506), -SIMDE_FLOAT16_C(    18.914) },
      {  SIMDE_FLOAT16_C(    22.272),  SIMDE_FLOAT16_C(    14.703), -SIMDE_FLOAT16_C(    29.517),  SIMDE_FLOAT16_C(    29.565) },
         INT8_C(         2),
      {  SIMDE_FLOAT32_C(   339.998), -SIMDE_FLOAT32_C(   865.726),  SIMDE_FLOAT32_C(   928.447),  SIMDE_FLOAT32_C(   239.331) } },
    { { -SIMDE_FLOAT32_C(   229.477), -SIMDE_FLOAT32_C(   420.347),  SIMDE_FLOAT32_C(   860.609),  SIMDE_FLOAT32_C(   534.276) },
      {  SIMDE_FLOAT16_C(     4.209), -SIMDE_FLOAT16_C(    29.813),  SIMDE_FLOAT16_C(     5.157),  SIMDE_FLOAT16_C(     6.699),
        -SIMDE_FLOAT16_C(    24.586), -SIMDE_FLOAT16_C(     8.731), -SIMDE_FLOAT16_C(    12.872),  SIMDE_FLOAT16_C(    27.443) },
      {  SIMDE_FLOAT16_C(    21.462), -SIMDE_FLOAT16_C(    18.252), -SIMDE_FLOAT16_C(    11.545), -SIMDE_FLOAT16_C(     4.632) },
         INT8_C(         2),
      {  SIMDE_FLOAT32_C(    54.503), -SIMDE_FLOAT32_C(   319.548),  SIMDE_FLOAT32_C(  1009.216),  SIMDE_FLOAT32_C(   217.447) } },
    { {  SIMDE_FLOAT32_C(   997.825),  SIMDE_FLOAT32_C(   583.282),  SIMDE_FLOAT32_C(   867.938),  SIMDE_FLOAT32_C(   768.010) },
      { -SIMDE_FLOAT16_C(    10.714),  SIMDE_FLOAT16_C(    25.525),  SIMDE_FLOAT16_C(    14.048), -SIMDE_FLOAT16_C(    28.972),
         SIMDE_FLOAT16_C(    12.356),  SIMDE_FLOAT16_C(     1.339),  SIMDE_FLOAT16_C(    24.574), -SIMDE_FLOAT16_C(     6.155) },
      {  SIMDE_FLOAT16_C(    29.503), -SIMDE_FLOAT16_C(     5.441), -SIMDE_FLOAT16_C(     1.890), -SIMDE_FLOAT16_C(    22.131) },
         INT8_C(         0),
      {  SIMDE_FLOAT32_C(  1362.364),  SIMDE_FLOAT32_C(   622.786),  SIMDE_FLOAT32_C(  1592.945),  SIMDE_FLOAT32_C(   586.419) } },
    { {  SIMDE_FLOAT32_C(   816.529),  SIMDE_FLOAT32_C(   723.621), -SIMDE_FLOAT32_C(   890.636),  SIMDE_FLOAT32_C(   428.760) },
      {  SIMDE_FLOAT16_C(    16.813), -SIMDE_FLOAT16_C(     0.946), -SIMDE_FLOAT16_C(     8.962),  SIMDE_FLOAT16_C(     9.562),
        -SIMDE_FLOAT16_C(    16.958), -SIMDE_FLOAT16_C(    21.080), -SIMDE_FLOAT16_C(    12.453),  SIMDE_FLOAT16_C(    16.260) },
      {  SIMDE_FLOAT16_C(     3.481), -SIMDE_FLOAT16_C(    16.199), -SIMDE_FLOAT16_C(    11.130), -SIMDE_FLOAT16_C(    15.187) },
         INT8_C(         1),
      {  SIMDE_FLOAT32_C(  1091.232),  SIMDE_FLOAT32_C(  1065.096), -SIMDE_FLOAT32_C(   688.910),  SIMDE_FLOAT32_C(   165.206) } },
    { { -SIMDE_FLOAT32_C(   418.117), -SIMDE_FLOAT32_C(   571.598), -SIMDE_FLOAT32_C(   163.791), -SIMDE_FLOAT32_C(   817.262) },
      { -SIMDE_FLOAT16_C(     2.051), -SIMDE_FLOAT16_C(    14.763),  SIMDE_FLOAT16_C(    13.257), -SIMDE_FLOAT16_C(     7.683),
        -SIMDE_FLOAT16_C(     6.620),  SIMDE_FLOAT16_C(    26.109),  SIMDE_FLOAT16_C(    17.664), -SIMDE_FLOAT16_C(    15.216) },
      {  SIMDE_FLOAT16_C(     7.138), -SIMDE_FLOAT16_C(     0.481),  SIMDE_FLOAT16_C(    29.463), -SIMDE_FLOAT16_C(    20.336) },
         INT8_C(         0),
      { -SIMDE_FLOAT32_C(   465.371), -SIMDE_FLOAT32_C(   385.232), -SIMDE_FLOAT32_C(    37.705), -SIMDE_FLOAT32_C(   925.874) } },
    { {  SIMDE_FLOAT32_C(   175.071),  SIMDE_FLOAT32_C(   489.257), -SIMDE_FLOAT32_C(   366.696),  SIMDE_FLOAT32_C(   844.854) },
      {  SIMDE_FLOAT16_C(    20.856),  SIMDE_FLOAT16_C(    23.147),  SIMDE_FLOAT16_C(     3.122), -SIMDE_FLOAT16_C(    12.760),
         SIMDE_FLOAT16_C(     4.788), -SIMDE_FLOAT16_C(    21.480), -SIMDE_FLOAT16_C(    26.401), -SIMDE_FLOAT16_C(     2.722) },
      {  SIMDE_FLOAT16_C(     0.548),  SIMDE_FLOAT16_C(     4.375),  SIMDE_FLOAT16_C(     0.825), -SIMDE_FLOAT16_C(    19.808) },
         INT8_C(         0),
      {  SIMDE_FLOAT32_C(   177.695),  SIMDE_FLOAT32_C(   477.486), -SIMDE_FLOAT32_C(   381.164),  SIMDE_FLOAT32_C(   843.362) } },
    { {  SIMDE_FLOAT32_C(    71.602), -SIMDE_FLOAT32_C(   421.023),  SIMDE_FLOAT32_C(   661.615),  SIMDE_FLOAT32_C(   842.891) },
      { -SIMDE_FLOAT16_C(    20.849),  SIMDE_FLOAT16_C(     7.141), -SIMDE_FLOAT16_C(    10.039),  SIMDE_FLOAT16_C(     1.530),
         SIMDE_FLOAT16_C(    17.306),  SIMDE_FLOAT16_C(    23.747), -SIMDE_FLOAT16_C(    15.433),  SIMDE_FLOAT16_C(     7.792) },
      {  SIMDE_FLOAT16_C(    16.220),  SIMDE_FLOAT16_C(     2.443), -SIMDE_FLOAT16_C(    27.396), -SIMDE_FLOAT16_C(    25.742) },
         INT8_C(         1),
      {  SIMDE_FLOAT32_C(   113.881), -SIMDE_FLOAT32_C(   363.009),  SIMDE_FLOAT32_C(   623.912),  SIMDE_FLOAT32_C(   861.927) } },
    { {  SIMDE_FLOAT32_C(   279.010),  SIMDE_FLOAT32_C(   614.350),  SIMDE_FLOAT32_C(   284.732), -SIMDE_FLOAT32_C(   882.098) },
      {  SIMDE_FLOAT16_C(    15.589), -SIMDE_FLOAT16_C(    20.403), -SIMDE_FLOAT16_C(    20.375), -SIMDE_FLOAT16_C(     4.651),
         SIMDE_FLOAT16_C(    25.777), -SIMDE_FLOAT16_C(    25.393), -SIMDE_FLOAT16_C(    21.729), -SIMDE_FLOAT16_C(    16.352) },
      { -SIMDE_FLOAT16_C(    24.911), -SIMDE_FLOAT16_C(    17.230), -SIMDE_FLOAT16_C(    25.911), -SIMDE_FLOAT16_C(    15.437) },
         INT8_C(         1),
      { -SIMDE_FLOAT32_C(   165.313),  SIMDE_FLOAT32_C(  1051.871),  SIMDE_FLOAT32_C(   659.310), -SIMDE_FLOAT32_C(   600.154) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t buf = simde_vld1q_f32(test_vec[i].buf);
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float32x4_t r;
    int lane = test_vec[i].lane;
    SIMDE_CONSTIFY_4_(simde_vfmlalq_lane_high_f16, r, (HEDLEY_UNREACHABLE(), r), lane, buf, a, b);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vfmlalq_laneq_high_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t buf[4];
    simde_float16_t a[8];
    simde_float16_t b[8];
    int8_t lane;
    simde_float32_t r[4];
  } test_vec[] = {
    { { -SIMDE_FLOAT32_C(   565.119), -SIMDE_FLOAT32_C(   227.110),  SIMDE_FLOAT32_C(   784.034), -SIMDE_FLOAT32_C(   933.119) },
      {  SIMDE_FLOAT16_C(    24.176),  SIMDE_FLOAT16_C(    14.148),  SIMDE_FLOAT16_C(    21.369), -SIMDE_FLOAT16_C(     3.686),
        -SIMDE_FLOAT16_C(    22.735), -SIMDE_FLOAT16_C(    28.672), -SIMDE_FLOAT16_C(    26.672),  SIMDE_FLOAT16_C(    25.650) },
      { -SIMDE_FLOAT16_C(    22.136), -SIMDE_FLOAT16_C(     8.643),  SIMDE_FLOAT16_C(     6.353), -SIMDE_FLOAT16_C(    25.092),
        -SIMDE_FLOAT16_C(    17.006),  SIMDE_FLOAT16_C(    11.218),  SIMDE_FLOAT16_C(    22.756),  SIMDE_FLOAT16_C(    22.905) },
         INT8_C(         1),
      { -SIMDE_FLOAT32_C(   368.620),  SIMDE_FLOAT32_C(    20.702),  SIMDE_FLOAT32_C(  1014.560), -SIMDE_FLOAT32_C(  1154.812) } },
    { {  SIMDE_FLOAT32_C(   294.270),  SIMDE_FLOAT32_C(   447.091),  SIMDE_FLOAT32_C(    51.261), -SIMDE_FLOAT32_C(   423.862) },
      { -SIMDE_FLOAT16_C(     8.593),  SIMDE_FLOAT16_C(    25.988),  SIMDE_FLOAT16_C(     2.261),  SIMDE_FLOAT16_C(     5.000),
         SIMDE_FLOAT16_C(    21.582),  SIMDE_FLOAT16_C(    23.202),  SIMDE_FLOAT16_C(    16.099), -SIMDE_FLOAT16_C(     5.159) },
      { -SIMDE_FLOAT16_C(     4.363),  SIMDE_FLOAT16_C(    29.873), -SIMDE_FLOAT16_C(     1.925), -SIMDE_FLOAT16_C(    27.644),
         SIMDE_FLOAT16_C(    21.297), -SIMDE_FLOAT16_C(    23.195),  SIMDE_FLOAT16_C(     8.860), -SIMDE_FLOAT16_C(    22.963) },
         INT8_C(         0),
      {  SIMDE_FLOAT32_C(   200.108),  SIMDE_FLOAT32_C(   345.861), -SIMDE_FLOAT32_C(    18.979), -SIMDE_FLOAT32_C(   401.353) } },
    { {  SIMDE_FLOAT32_C(   129.544), -SIMDE_FLOAT32_C(   787.134), -SIMDE_FLOAT32_C(   947.565), -SIMDE_FLOAT32_C(   190.133) },
      { -SIMDE_FLOAT16_C(     2.610),  SIMDE_FLOAT16_C(    15.259), -SIMDE_FLOAT16_C(    29.281), -SIMDE_FLOAT16_C(    10.038),
         SIMDE_FLOAT16_C(    28.771), -SIMDE_FLOAT16_C(    13.590),  SIMDE_FLOAT16_C(     1.381),  SIMDE_FLOAT16_C(     9.318) },
      {  SIMDE_FLOAT16_C(    13.776),  SIMDE_FLOAT16_C(     7.496), -SIMDE_FLOAT16_C(     0.283), -SIMDE_FLOAT16_C(    12.687),
         SIMDE_FLOAT16_C(     2.944), -SIMDE_FLOAT16_C(     1.035),  SIMDE_FLOAT16_C(     9.381), -SIMDE_FLOAT16_C(    25.531) },
         INT8_C(         3),
      { -SIMDE_FLOAT32_C(   235.474), -SIMDE_FLOAT32_C(   614.718), -SIMDE_FLOAT32_C(   965.086), -SIMDE_FLOAT32_C(   308.350) } },
    { { -SIMDE_FLOAT32_C(   334.760),  SIMDE_FLOAT32_C(    62.974),  SIMDE_FLOAT32_C(   164.083), -SIMDE_FLOAT32_C(   270.364) },
      { -SIMDE_FLOAT16_C(    14.494),  SIMDE_FLOAT16_C(    20.110),  SIMDE_FLOAT16_C(    11.039), -SIMDE_FLOAT16_C(     8.603),
         SIMDE_FLOAT16_C(    19.533), -SIMDE_FLOAT16_C(    11.108), -SIMDE_FLOAT16_C(    27.559), -SIMDE_FLOAT16_C(    11.172) },
      { -SIMDE_FLOAT16_C(    22.411),  SIMDE_FLOAT16_C(    14.386),  SIMDE_FLOAT16_C(    13.731),  SIMDE_FLOAT16_C(    23.562),
        -SIMDE_FLOAT16_C(    16.198),  SIMDE_FLOAT16_C(    23.693), -SIMDE_FLOAT16_C(    23.176), -SIMDE_FLOAT16_C(    17.366) },
         INT8_C(         5),
      {  SIMDE_FLOAT32_C(   127.886), -SIMDE_FLOAT32_C(   200.208), -SIMDE_FLOAT32_C(   488.872), -SIMDE_FLOAT32_C(   535.062) } },
    { { -SIMDE_FLOAT32_C(   690.183),  SIMDE_FLOAT32_C(    92.881),  SIMDE_FLOAT32_C(   235.320), -SIMDE_FLOAT32_C(   659.619) },
      { -SIMDE_FLOAT16_C(    22.720),  SIMDE_FLOAT16_C(     3.657), -SIMDE_FLOAT16_C(    11.725), -SIMDE_FLOAT16_C(    20.947),
        -SIMDE_FLOAT16_C(    22.749),  SIMDE_FLOAT16_C(     3.553),  SIMDE_FLOAT16_C(     3.176), -SIMDE_FLOAT16_C(     8.892) },
      {  SIMDE_FLOAT16_C(    29.666), -SIMDE_FLOAT16_C(    21.733),  SIMDE_FLOAT16_C(     6.451), -SIMDE_FLOAT16_C(    17.185),
         SIMDE_FLOAT16_C(    29.737),  SIMDE_FLOAT16_C(    12.085),  SIMDE_FLOAT16_C(     2.148),  SIMDE_FLOAT16_C(    17.419) },
         INT8_C(         5),
      { -SIMDE_FLOAT32_C(   965.105),  SIMDE_FLOAT32_C(   135.819),  SIMDE_FLOAT32_C(   273.702), -SIMDE_FLOAT32_C(   767.079) } },
    { { -SIMDE_FLOAT32_C(   967.070), -SIMDE_FLOAT32_C(   733.058),  SIMDE_FLOAT32_C(   272.480),  SIMDE_FLOAT32_C(   128.270) },
      {  SIMDE_FLOAT16_C(     2.255),  SIMDE_FLOAT16_C(    11.583),  SIMDE_FLOAT16_C(    23.222), -SIMDE_FLOAT16_C(     4.323),
        -SIMDE_FLOAT16_C(    29.875), -SIMDE_FLOAT16_C(     4.639),  SIMDE_FLOAT16_C(     9.404), -SIMDE_FLOAT16_C(     8.746) },
      { -SIMDE_FLOAT16_C(     1.222),  SIMDE_FLOAT16_C(     5.728),  SIMDE_FLOAT16_C(    23.421), -SIMDE_FLOAT16_C(    18.632),
         SIMDE_FLOAT16_C(    24.107),  SIMDE_FLOAT16_C(     4.919), -SIMDE_FLOAT16_C(    24.811), -SIMDE_FLOAT16_C(    18.437) },
         INT8_C(         6),
      { -SIMDE_FLOAT32_C(   225.841), -SIMDE_FLOAT32_C(   617.960),  SIMDE_FLOAT32_C(    39.157),  SIMDE_FLOAT32_C(   345.267) } },
    { {  SIMDE_FLOAT32_C(   494.505), -SIMDE_FLOAT32_C(   942.161), -SIMDE_FLOAT32_C(   968.468), -SIMDE_FLOAT32_C(   684.387) },
      { -SIMDE_FLOAT16_C(    21.616), -SIMDE_FLOAT16_C(     0.546),  SIMDE_FLOAT16_C(     6.769), -SIMDE_FLOAT16_C(    23.770),
         SIMDE_FLOAT16_C(     4.629), -SIMDE_FLOAT16_C(    26.547), -SIMDE_FLOAT16_C(     6.510),  SIMDE_FLOAT16_C(     3.240) },
      { -SIMDE_FLOAT16_C(    25.838),  SIMDE_FLOAT16_C(     5.364),  SIMDE_FLOAT16_C(    20.791), -SIMDE_FLOAT16_C(    13.207),
        -SIMDE_FLOAT16_C(    28.325), -SIMDE_FLOAT16_C(    16.763), -SIMDE_FLOAT16_C(    13.090), -SIMDE_FLOAT16_C(    21.909) },
         INT8_C(         3),
      {  SIMDE_FLOAT32_C(   433.370), -SIMDE_FLOAT32_C(   591.659), -SIMDE_FLOAT32_C(   882.490), -SIMDE_FLOAT32_C(   727.178) } },
    { { -SIMDE_FLOAT32_C(   171.260), -SIMDE_FLOAT32_C(   273.076), -SIMDE_FLOAT32_C(   877.827),  SIMDE_FLOAT32_C(   772.514) },
      {  SIMDE_FLOAT16_C(    17.441), -SIMDE_FLOAT16_C(    12.155),  SIMDE_FLOAT16_C(    23.661),  SIMDE_FLOAT16_C(     4.150),
         SIMDE_FLOAT16_C(     2.784),  SIMDE_FLOAT16_C(    10.004),  SIMDE_FLOAT16_C(    26.712), -SIMDE_FLOAT16_C(    18.108) },
      { -SIMDE_FLOAT16_C(    19.155), -SIMDE_FLOAT16_C(    13.921), -SIMDE_FLOAT16_C(    28.513), -SIMDE_FLOAT16_C(    27.155),
        -SIMDE_FLOAT16_C(    13.118), -SIMDE_FLOAT16_C(     3.134),  SIMDE_FLOAT16_C(    28.022), -SIMDE_FLOAT16_C(     7.083) },
         INT8_C(         3),
      { -SIMDE_FLOAT32_C(   246.860), -SIMDE_FLOAT32_C(   544.850), -SIMDE_FLOAT32_C(  1603.408),  SIMDE_FLOAT32_C(  1264.237) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t buf = simde_vld1q_f32(test_vec[i].buf);
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float32x4_t r;
    int lane = test_vec[i].lane;
    SIMDE_CONSTIFY_8_(simde_vfmlalq_laneq_high_f16, r, (HEDLEY_UNREACHABLE(), r), lane, buf, a, b);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vfmlal_low_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vfmlal_high_f16)

SIMDE_TEST_FUNC_LIST_ENTRY(vfmlalq_low_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vfmlalq_high_f16)

SIMDE_TEST_FUNC_LIST_ENTRY(vfmlal_lane_low_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vfmlal_lane_high_f16)

SIMDE_TEST_FUNC_LIST_ENTRY(vfmlal_laneq_low_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vfmlal_laneq_high_f16)

SIMDE_TEST_FUNC_LIST_ENTRY(vfmlalq_lane_low_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vfmlalq_lane_high_f16)

SIMDE_TEST_FUNC_LIST_ENTRY(vfmlalq_laneq_low_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vfmlalq_laneq_high_f16)

SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
