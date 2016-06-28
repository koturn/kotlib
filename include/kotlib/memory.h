/*!
 * @file  memory.h
 * @author  koturn
 * @brief  Provide functions about memory
 */
#ifndef KOTLIB_MEMORY_H
#define KOTLIB_MEMORY_H


#include <type_traits>
#ifdef _MSC_VER
#  include <malloc.h>
#else
#  include <cstdlib>
#endif  // _MSC_VER


namespace kot
{

/*!
 * @brief  Allocate memory on specified alignment
 * @param [in] size       Size of memory (unit is byte) to allocate.
 * @param [in] alignment  Address alignment
 * @return  Pointer to allocated memory
 */
template<typename T = void*, typename std::enable_if<std::is_pointer<T>, std::nullptr_t>::type = nullptr>
static inline T
alignedMalloc(std::size_t size, std::size_t alignment) noexcept
{
#ifdef _MSC_VER
  return reinterpret_cast<T>(_aligned_malloc(size, alignment));
#else
  T p;
  return reinterpret_cast<T>(posix_memalign(reinterpret_cast<void**>(&p), alignment, size) == 0 ? p : nullptr);
#endif  // _MSC_VER
}


/*!
 * @brief  Free alignmented memory
 * @param [in] ptr  Address of alignmented memory
 */
static inline void
alignedFree(void* ptr) noexcept
{
#ifdef _MSC_VER
  _aligned_free(ptr);
#else
  std::free(ptr);
#endif  // _MSC_VER
}


}  // namespace kot


#endif  // KOTLIB_MEMORY_H
