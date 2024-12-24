#include <arm_neon.h>
#include <cstdint>
#include <iostream>
#include <vector>

#define STEP 4

uint64_t sum(const std::vector<uint32_t> &vec)
{
    uint64_t res = 0;
    for (const auto &e : vec)
        res += e;

        return res;
}

uint64_t sum_simd(const std::vector<uint32_t> &vec)
{
    uint32x4_t res = vdupq_n_u32(0);
    size_t i = 0;
    uint64_t sum = 0;
    while (i + STEP <= vec.size())
    {
        uint32x4_t v = vld1q_u32(&vec[i]);
        res = vaddq_u32(res, v);
        i += STEP;
    }

    uint32_t temp[4];
    vst1q_u32(temp, res);
    sum = temp[0] + temp[1] + temp[2] + temp[3];
    while (i < vec.size())
    {
        sum += vec[i];
        ++i;
    }
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
