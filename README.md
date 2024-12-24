# Christmas Challenge

A collection of 50 performance-focused programming challenges.

## Getting Started

The challenges focus on hardware optimization using SIMD instructions, cache optimization, lock-free programming and other hardware intrinstrics.

## Table of Content

1. [Easy](#easy)
2. [Medium](#medium)
3. [Hard](#hard)

## Questions

### Easy

1. **SIMD Vector Sum**
```cpp
/* Compute sum of int32 vector using SIMD
Input: vector<int> nums(1M)
Compare: Normal vs SIMD vs unrolled */
```

2. **Bit Population Counter**
```cpp
/* Count set bits without __builtin_popcount
Input: uint64_t n = 0xDEADBEEFCAFEBABE
Implement: Parallel count, SWAR counting */
```

3. **Cache-Friendly Matrix Multiply**
```cpp
/* Optimize 1024x1024 matrix multiplication
Requirements:
- Tiled multiplication for L1 cache
- Compare against naive approach
- Measure cache misses */
```

4. **Branch Predictor Challenge**
```cpp
/* Sort boolean array using branchless ops
Input: vector<bool> flags(1M)
Compare: if-else vs branchless */
```

5. **SIMD Polynomial**
```cpp
/* Evaluate polynomial using Horner
Input: coeffs={1,2,3,4}, x=vector<float>(1024)
Optimize: Register pressure, FMA instructions */
```

6. **Circular Buffer**
```cpp
/* Lock-free circular buffer using atomics
Requirements:
- Single producer/consumer
- No false sharing
- Compare with mutex version */
```

7. **Fast String Compare**
```cpp
/* SSE4.2 string comparison
Input: Two strings ~1KB each
Use: pcmpestri instruction */
```

8. **Bitfield Operations**
```cpp
/* Pack/unpack 3 RGB bytes into uint32
Requirements:
- No branching
- SIMD version for array of pixels */
```

9. **CPU Pipeline Puzzle**
```cpp
/* Minimize pipeline stalls in merge sort
Input: vector<int>(100K)
Measure: Branch mispredictions */
```

10. **Memory Pattern**
```cpp
/* Find repeating byte pattern
Input: 1MB binary data
Use: SSE4.2 string instructions */
```

### Medium

11. **Lock-free Stack**
```cpp
/* Wait-free stack with ABA protection
Test: 8 threads push/pop
Measure: Throughput vs mutex stack */
```

12. **Prefetch Tree**
```cpp
/* BST with prefetch optimization
Input: 1M nodes
Use: __builtin_prefetch */
```

13. **SIMD Pattern Match**
```cpp
/* Boyer-Moore with AVX2 acceleration
Input: Text(10MB), Pattern(16B)
Compare: Normal vs SIMD implementation */
```

14. **Thread Counter**
```cpp
/* Fix false sharing in counter array
Input: 8 threads incrementing counters
Use: Cache line padding */
```

15. **Sort Pipeline**
```cpp
/* Pipeline-friendly bubble sort
Focus: Instruction parallelism
Measure: IPC (Instructions Per Cycle) */
```

16. **Fast JSON Parser**
```cpp
/* SIMD-accelerated JSON parsing
Input: 100MB JSON file
Use: SSE4.2 string operations */
```

17. **Bit Matrix**
```cpp
/* Transpose bit matrix using SWAR
Input: 64x64 bit matrix
No loops allowed */
```

18. **Memory Pool**
```cpp
/* Fixed-size block allocator
Requirements:
- O(1) alloc/free
- No fragmentation
- Thread-safe */
```

19. **Fast CRC32**
```cpp
/* Hardware-accelerated CRC32
Input: 1GB file
Use: crc32 instruction */
```

20. **Vector Quantization**
```cpp
/* K-means using SIMD
Input: 1M 3D points
Optimize: Distance calculations */
```

### Hard

31. **Lock-free Allocator**
```cpp
/* Size-class optimized allocator
Features:
- Thread-local caches
- Bulk deallocation
- Minimal contention */
```

32. **SIMD Hash Table**
```cpp
/* Vectorized open addressing
Features:
- SIMD parallel probing
- SSE4.2 hash function
- Dynamic resizing */
```

33. **Cache-Oblivious FFT**
```cpp
/* FFT optimized for arbitrary cache
Input: Complex<float>[2^20]
Features:
- Cache-oblivious recursion
- Vectorized butterfly ops
- In-place computation */
```

34. **Minimal Sync Queue**
```cpp
/* Low-latency MPMC queue
Test: 4 producers, 4 consumers
Use: Memory fences, atomics */
```

35. **SIMD Compression**
```cpp
/* Bit-packing with SIMD
Input: Mostly small integers
Features: Delta encoding */
```

36. **Lock-free Tree**
```cpp
/* Concurrent BST operations
Features:
- RCU for readers
- Lock-free updates
- Help mechanism */
```

37. **Fast Regex Engine**
```cpp
/* JIT-compiled regex using SIMD
Features:
- SSE4.2 string instructions
- Thompson NFA
- Bytecode generation */
```

38. **Parallel Sort**
```cpp
/* Hybrid parallel sorting
Features:
- SIMD sorting networks
- Multi-way merge
- Cache-aware partitioning */
```

39. **Compressed Trie**
```cpp
/* Memory-efficient string index
Features:
- Path compression
- SIMD string compare
- Bulk loading */
```

40. **Vector Database**
```cpp
/* SIMD KNN search engine
Features:
- Product quantization
- SIMD distance calc
- LSH indexing */
```

41. **JIT Compiler**
```cpp
/* Expression evaluator with JIT
Features:
- x86-64 code generation
- Register allocation
- SIMD optimization */
```

42. **Graph Processing**
```cpp
/* Parallel graph algorithms
Input: 1M vertices, 10M edges
Features:
- Edge list compression
- NUMA-aware processing */
```

43. **Network Protocol**
```cpp
/* Zero-copy protocol parser
Features:
- SIMD header parsing
- Scatter-gather I/O
- Lock-free queuing */
```

44. **Time Series DB**
```cpp
/* Columnar time series engine
Features:
- Delta-RLE compression
- SIMD aggregations
- LSM tree storage */
```

45. **Bitmap Index**
```cpp
/* Compressed bitmap operations
Features:
- EWAH compression
- SIMD boolean ops
- Parallel scanning */
```

46. **Memory Allocator**
```cpp
/* NUMA-aware allocator
Features:
- Per-CPU arenas
- Huge page support
- Thread cache */
```

47. **String Dictionary**
```cpp
/* String deduplication engine
Features:
- Rolling hash
- SSE4.2 comparison
- Reference counting */
```

48. **Stream Processing**
```cpp
/* Streaming analytics engine
Features:
- Vectorized operators
- Window aggregation
- Back-pressure */
```

49. **Storage Engine**
```cpp
/* Log-structured storage
Features:
- Zero-copy reads
- SIMD CRC validation
- Concurrent compaction */
```

50. **Query Engine**
```cpp
/* Vectorized query processor
Features:
- SIMD join/filter ops
- Runtime code gen
- Parallel execution */
```

## Acknowledgement
Thanks to @alpluspluss for the challenges.
