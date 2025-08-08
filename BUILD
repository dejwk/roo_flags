
cc_library(
    name = "roo_flags",
    visibility = ["//visibility:public"],
    srcs = glob(
        [
            "src/**/*.h",
        ],
        exclude = ["test/**"],
    ),
    includes = [ "src" ]
)

cc_test(
    name = "roo_flags_test",
    srcs = ["test/roo_flags_test.cpp"],
    deps = [
        ":roo_flags",
        "@googletest//:gtest_main",
    ],
)
