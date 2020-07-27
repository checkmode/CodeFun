#include "bubble.h"
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

typedef struct _TestData {
  int* data;
  size_t len;
} TestData;

class TestSuiteSort : public ::testing::Test {
 protected:
  // Per-test-suite set-up.
  // Called before the first test in this test suite.
  // Can be omitted if not needed.
  static void SetUpTestSuite() {}

  // Per-test-suite tear-down.
  // Called after the last test in this test suite.
  // Can be omitted if not needed.
  static void TearDownTestSuite() {}

  // You can define per-test set-up logic as usual.
  virtual void SetUp() {}

  // You can define per-test tear-down logic as usual.
  virtual void TearDown() {}

  // Some expensive resource shared by all tests.
  static TestData* shared_exchange_;
};
TestData* TestSuiteSort::shared_exchange_ = NULL;

TEST_F(TestSuiteSort, shared_exchange) {
  EXPECT_EQ(2, 1 + 1);
  int ss[] = {1, 3, 4, 33, 56, 21, 3, 8, 44, 6};
  sort_bubble(ss, sizeof(ss) / sizeof(ss[0]));

  EXPECT_EQ(2, 1 + 1);
}
