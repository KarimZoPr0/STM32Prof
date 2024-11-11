#ifndef BASE_CORE_H
#define BASE_CORE_H


////////////////////////////////////////////////////////////////
//~ karim: Macros

#define global
#define internal
#define local_persist

//- karim: memory copy/set operations

#define MemoryCopy(dst, src, size) memcpy((dst), (src), (size))
#define MemoryMove(dst, src, size) memmove((dst), (src), (size))
#define MemorySet(dst, byte, size) memset((dst), (byte), (size))

#define MemoryCopyStruct(dst, src) do { Assert(sizeof(*(dst)) == sizeof(*(src))); MemoryCopy((dst), (src), sizeof(*(dst))); } while(0)
#define MemoryCopyArray(dst, src)  do { Assert(sizeof(dst) == sizeof(src)); MemoryCopy((dst), (src), sizeof(src)); }while(0)

#define MemoryZero(ptr, size) MemorySet((ptr), 0, (size))
#define MemoryZeroStruct(ptr) MemoryZero((ptr), sizeof(*(ptr)))
#define MemoryZeroArray(arr)  MemoryZero((arr), sizeof(arr))

//- karim: integer/array/type manipulations

#define ArrayCount(a) (sizeof(a) / sizeof((a)[0]))

#define Bytes(n)      (n)
#define Kilobytes(n)  (n << 10)
#define Megabytes(n)  (n << 20)
#define Gigabytes(n)  (((U64)n) << 30)
#define Terabytes(n)  (((U64)n) << 40)

#define Thousand(n) ((n)*1000)
#define Million(n)  ((n)*1000000)
#define Billion(n)  ((n)*1000000000LL)

#define Swap(type, a, b) do{ type _swapper_ = a; a = b; b = _swapper_; }while(0)

#define AbsoluteValueS16(x) (S16)abs((x))
#define AbsoluteValueS32(x) (S32)abs((x))
#define AbsoluteValueS64(x) (S64)llabs((S64)(x))
#define AbsoluteValueU64(x) (U64)llabs((U64)(x))

#define CONCAT(a, b) a##b
#define CONCAT2(a, b) CONCAT(a, b)
#define UNIQUE_ID(base) CONCAT2(base, __COUNTER__)

////////////////////////////////////////////////////////////////
//~ karim: Base-Types

typedef int8_t   S8;
typedef int16_t  S16;
typedef int32_t  S32;
typedef int64_t  S64;
typedef uint8_t  U8;
typedef uint16_t U16;
typedef uint32_t U32;
typedef uint64_t U64;
typedef S8       B8;
typedef S16      B16;
typedef S32      B32;
typedef S64      B64;
typedef float    F32;
typedef double   F64;


#endif //BASE_CORE_H
