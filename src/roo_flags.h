
#pragma once

#define ROO_DECLARE_FLAG(type, name)            \
  namespace internal {                          \
  type& ROO_FLAGS_##name##_get();               \
  void ROO_FLAGS_##name##_set(const type& val); \
  void ROO_FLAGS_##name##_set(type&& val);      \
  }                                             \
  using ::internal::ROO_FLAGS_##name##_get;     \
  using ::internal::ROO_FLAGS_##name##_set;

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

#define GET_ROO_FLAG(name) ROO_FLAGS_##name##_get()
#define SET_ROO_FLAG(name, val) ROO_FLAGS_##name##_set(val)
