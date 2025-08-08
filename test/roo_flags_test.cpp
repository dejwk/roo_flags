#include "roo_flags.h"

#include <string>

#include "gtest/gtest.h"

// Example flag definitions.
ROO_FLAG(bool, test_bool_flag, false);
ROO_FLAG(int, test_int_flag, 42);
ROO_FLAG(std::string, test_string_flag, "default");

class RooFlagsTest : public ::testing::Test {
 protected:
  void SetUp() override {
    // Reset flags to default before each test.
    SET_ROO_FLAG(test_bool_flag, false);
    SET_ROO_FLAG(test_int_flag, 42);
    SET_ROO_FLAG(test_string_flag, "default");
  }
};

TEST_F(RooFlagsTest, DefaultValues) {
  EXPECT_FALSE(GET_ROO_FLAG(test_bool_flag));
  EXPECT_EQ(GET_ROO_FLAG(test_int_flag), 42);
  EXPECT_EQ(GET_ROO_FLAG(test_string_flag), "default");
}

TEST_F(RooFlagsTest, SetBoolFlag) {
  SET_ROO_FLAG(test_bool_flag, true);
  EXPECT_TRUE(GET_ROO_FLAG(test_bool_flag));
}

TEST_F(RooFlagsTest, SetIntFlag) {
  SET_ROO_FLAG(test_int_flag, 123);
  EXPECT_EQ(GET_ROO_FLAG(test_int_flag), 123);
}

TEST_F(RooFlagsTest, SetStringFlag) {
  SET_ROO_FLAG(test_string_flag, "changed");
  EXPECT_EQ(GET_ROO_FLAG(test_string_flag), "changed");
}

TEST_F(RooFlagsTest, MultipleFlags) {
  SET_ROO_FLAG(test_bool_flag, true);
  SET_ROO_FLAG(test_int_flag, 7);
  SET_ROO_FLAG(test_string_flag, "abc");
  EXPECT_TRUE(GET_ROO_FLAG(test_bool_flag));
  EXPECT_EQ(GET_ROO_FLAG(test_int_flag), 7);
  EXPECT_EQ(GET_ROO_FLAG(test_string_flag), "abc");
}
