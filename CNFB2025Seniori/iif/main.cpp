#define CHECK(a, b, c) CHECK_##a(b, c)
#define CHECK_1(a, b) a
#define CHECK_0(a, b) b
