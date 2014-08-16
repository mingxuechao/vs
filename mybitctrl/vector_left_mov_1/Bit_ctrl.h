#include <stdio.h>
#define BIT_MASK(NUM) (1 << ((NUM) % 8))
#define BIT_SLOT(NUM) ((NUM) / 8)
#define BIT_SET(ARR, N) ((ARR)[BIT_SLOT(N)] = BIT_MASK(N))
#define BIT_VALUE(ARR , N) (((ARR)[BIT_SLOT(N)] & BIT_MASK(N)) >> ((N) %8 ))
//#define BIT_VALUE(ARR , N) (((ARR)[BIT_SLOT(N)] & BIT_MASK(N)))
#define BIT_CLEAN(ARR, N) ((ARR)[BIT_SLOT(N)] &= ~BIT_MASK(N))
#define BIT_N_SLOTS(NUM) (((NUM) % 8) ? (NUM) / 8 + 1 :(NUM) /8)
#define BIT_INIT(ARR, NUM) {for (int i = 0; i < BIT_N_SLOTS(NUM); i++){ (ARR)[i] = 0; };}