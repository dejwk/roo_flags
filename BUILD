load("@rules_cc//cc:cc_library.bzl", "cc_library")
load("@rules_cc//cc:cc_test.bzl", "cc_test")

cc_library(
    name = "roo_flags",
    srcs = glob(
        [
            "src/**/*.h",
        ],
        exclude = ["test/**"],
    ),
    includes = ["src"],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "roo_flags_test",
    srcs = ["test/roo_flags_test.cpp"],
    deps = [
        ":roo_flags",
        "@googletest//:gtest_main",
    ],
)
