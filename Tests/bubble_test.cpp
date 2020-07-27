#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "sortfunctions.h"

using namespace std;

typedef struct _TestData {
  int* data;
  size_t len;
} TestData;

void makeRandom(int* data, int n, int left, int right) {
  srand((int)time(0));
  for (int i = 0; i < n; i++) {
    data[i] = rand() % (right - left + 1) + left;
  }
}

void printArray(int* data, int n) {
  for (int i = 0; i < n; i++)
    cout << data[i] << " ";
  cout << endl;
}

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
  virtual void SetUp() {
    shared_exchange_ = new TestData;
    const size_t maxRandom = 0xff;
    shared_exchange_->data = new int[maxRandom];
    shared_exchange_->len = maxRandom;
    makeRandom(shared_exchange_->data, maxRandom, 0, 0xffff);
    printArray(shared_exchange_->data, shared_exchange_->len);
  }

  // You can define per-test tear-down logic as usual.
  virtual void TearDown() {
    delete[] shared_exchange_->data;
    delete shared_exchange_;
  }

  // Some expensive resource shared by all tests.
  static TestData* shared_exchange_;
};
TestData* TestSuiteSort::shared_exchange_ = NULL;

TEST_F(TestSuiteSort, shared_exchange) {
  EXPECT_EQ(2, 1 + 1);
  if (0 < shared_exchange_->len) {
    int* p = new int[shared_exchange_->len];
    memcpy(p, shared_exchange_->data, shared_exchange_->len * sizeof(int));
    sort_bubble(p, shared_exchange_->len);
    printArray(p, shared_exchange_->len);
    delete[] p;
  }

  EXPECT_EQ(2, 1 + 1);
}
