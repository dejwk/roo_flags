
#pragma once

/// Declares accessor functions for a global flag.
///
/// Use this in a header to expose a flag defined elsewhere with `ROO_FLAG`.
///
/// @param type Flag value type.
/// @param name Flag name token.
#define ROO_DECLARE_FLAG(type, name)            \
  namespace internal {                          \
  type& ROO_FLAGS_##name##_get();               \
  void ROO_FLAGS_##name##_set(const type& val); \
  void ROO_FLAGS_##name##_set(type&& val);      \
  }                                             \
  using ::internal::ROO_FLAGS_##name##_get;     \
  using ::internal::ROO_FLAGS_##name##_set;

/// Defines storage and accessors for a global flag.
///
/// Use this in exactly one translation unit for each flag.
///
/// @param type Flag value type.
/// @param name Flag name token.
/// @param value Initial flag value.
#define ROO_FLAG(type, name, value)                               \
  namespace internal {                                            \
  type ROO_FLAGS_##name##_val;                                    \
  struct ROO_FLAGS_##name##_init {                                \
    ROO_FLAGS_##name##_init() { ROO_FLAGS_##name##_val = value; } \
  };                                                              \
  type& ROO_FLAGS_##name##_get() {                                \
    static ROO_FLAGS_##name##_init init;                          \
    return ROO_FLAGS_##name##_val;                                \
  };                                                              \
  void ROO_FLAGS_##name##_set(const type& val) {                  \
    ROO_FLAGS_##name##_get();                                     \
    ROO_FLAGS_##name##_val = val;                                 \
  };                                                              \
  void ROO_FLAGS_##name##_set(type&& val) {                       \
    ROO_FLAGS_##name##_get();                                     \
    ROO_FLAGS_##name##_val = val;                                 \
  };                                                              \
  char FLAGS_no##name;                                            \
  }                                                               \
  using ::internal::ROO_FLAGS_##name##_get;                       \
  using ::internal::ROO_FLAGS_##name##_set;

/// Returns the current value of a flag declared with `ROO_DECLARE_FLAG`.
#define GET_ROO_FLAG(name) ROO_FLAGS_##name##_get()
/// Sets the value of a flag declared with `ROO_DECLARE_FLAG`.
#define SET_ROO_FLAG(name, val) ROO_FLAGS_##name##_set(val)
