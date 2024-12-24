/*
 * @author alpluspluss
 * @data 12/24/2024 5:40 PM UTC + 7
 */

#include <arm_neon.h>
#include <cstdint>
#include <chrono>
#include <iostream>
#include <vector>

#define STEP 16
#define PREFETCH_DIST 256

uint64_t sum(const std::vector<uint32_t> &vec)
{
    uint64_t res = 0;
    for (const auto &e : vec)
        res += e;

        return res;
}

uint64_t sum_simd(const std::vector<uint32_t> &vec)
{
     uint64x2_t res0 = vdupq_n_u64(0);
     uint64x2_t res1 = vdupq_n_u64(0);

     size_t i = 0;
     while (i + STEP <= vec.size())
     {
        __builtin_prefetch(&vec[i + PREFETCH_DIST], 0, 0);

        uint32x4_t v0 = vld1q_u32(&vec[i]);
        uint32x4_t v1 = vld1q_u32(&vec[i + 4]);
        uint32x4_t v2 = vld1q_u32(&vec[i + 8]);
        uint32x4_t v3 = vld1q_u32(&vec[i + 12]);

        res0 = vaddw_u32(res0, vget_low_u32(v0));
        res0 = vaddw_high_u32(res0, v0);
        res1 = vaddw_u32(res1, vget_low_u32(v1));
        res1 = vaddw_high_u32(res1, v1);

        res0 = vaddw_u32(res0, vget_low_u32(v2));
        res0 = vaddw_high_u32(res0, v2);
        res1 = vaddw_u32(res1, vget_low_u32(v3));
        res1 = vaddw_high_u32(res1, v3);

        i += STEP;
     }

     uint64x2_t final_sum = vaddq_u64(res0, res1);
     uint64_t sum = vgetq_lane_u64(final_sum, 0) + vgetq_lane_u64(final_sum, 1);
     while (i < vec.size())
        sum += vec[i++];

     return sum;
}

int main()
{
    std::vector<uint32_t> data(1000000, 1);

    auto start = std::chrono::high_resolution_clock::now();
    uint64_t result1 = sum(data);
    auto end = std::chrono::high_resolution_clock::now();
    auto normal_time =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start)
            .count();

    start = std::chrono::high_resolution_clock::now();
    uint64_t result2 = sum_simd(data);
    end = std::chrono::high_resolution_clock::now();
    auto simd_time =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start)
            .count();

    std::cout << "Normal: " << normal_time << "us\n"
                << "SIMD: " << simd_time << "us\n"
                << "Speedup: " << static_cast<float>(normal_time) / simd_time
                << "x\n"
                << "Results match: " << (result1 == result2 ? "yes" : "no")
                << "\tstd";

    return 0;
}
