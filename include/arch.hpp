#include <arm_neon.h>
#include <arm_acle.h>

#define SIMD_VECTOR_WIDTH 16

#define ADD_PS_F(a, b) vaddq_f32(a, b)
#define MUL_PS_F(a, b) vmulq_f32(a, b)
#define FMA_PS_F(a, b, c) vfmaq_f32(c, a, b)

#define ADD_PS_I(a, b) vaddq_s64(a, b)
#define MUL_PS_I(a, b) vmulq_s32(a, b)

#define PREFETCH_KEEP(addr) asm volatile("prfm pldl1keep, [%0]" ::"r"(addr))
#define PREFETCH_STREAM(addr) asm volatile("prfm pldl1strm, [%0]" ::"r"(addr))
#define PREFETCH_L1(addr) asm volatile("prfm pldl1keep, [%0]" ::"r"(addr))
#define PREFETCH_L2(addr) asm volatile("prfm pldl2keep, [%0]" ::"r"(addr))
#define PREFETCH_L3(addr) asm volatile("prfm pldl3keep, [%0]" ::"r"(addr))

#define LIKELY(expr) __builtin_expect(!!(expr), 1)
#define UNLIKELY(expr) __builtin_expect(!!(expr), 0)

#define STREAM_STORE(addr, val) vst1q_u8((uint8_t *)(addr), val)
#define LOAD_VECTOR(addr) vld1q_u8((const uint8_t *)(addr))
#define STORE_VECTOR(addr, val) vst1q_u8((uint8_t *)(addr), val)
#define SET_ZERO_VECTOR() vdupq_n_u8(0)
#define STREAM_STORE_64(addr, val)                                             \
  vst1_u64((uint64_t *)(addr), vcreate_u64(val))

#define MEMORY_FENCE() asm volatile("dmb ish" ::: "memory")
#define STORE_FENCE() asm volatile("dmb ishst" ::: "memory")
#define LOAD_FENCE() asm volatile("dmb ishld" ::: "memory")
#define CPU_PAUSE() asm volatile("yield" ::: "memory")
#define CACHE_LINE_SIZE 64

#define CACHE_CLEAN(addr) asm volatile("dc cvac, %0" ::"r"(addr))
#define CACHE_INVALIDATE(addr) asm volatile("dc ivac, %0" ::"r"(addr))
#define CACHE_CLEAN_AND_INVALIDATE(addr)                                       \
  asm volatile("dc civac, %0" ::"r"(addr))

#define DSB() asm volatile("dsb sy" ::: "memory")
#define DSB_ST() asm volatile("dsb st" ::: "memory")
#define DSB_LD() asm volatile("dsb ld" ::: "memory")

#define ISB() asm volatile("isb" ::: "memory")

#define VECTORIZE_LOOP                                                         \
  _Pragma("clang loop vectorize(enable) interleave(enable)")
#define UNROLL_LOOP _Pragma("clang loop unroll(full)")
