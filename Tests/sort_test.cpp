#include <gtest/gtest.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include "sortfunctions.h"

using namespace std;

typedef struct _TestData {
  int* data;
  size_t len;
  int* sort_data;
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

int cmp(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
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
    // printArray(shared_exchange_->data, shared_exchange_->len);

    shared_exchange_->sort_data = new int[maxRandom];
    memcpy(shared_exchange_->sort_data, shared_exchange_->data,
           shared_exchange_->len * sizeof(int));
    qsort(shared_exchange_->sort_data, shared_exchange_->len, sizeof(int), cmp);
  }

  // You can define per-test tear-down logic as usual.
  virtual void TearDown() {
    delete[] shared_exchange_->data;
    delete[] shared_exchange_->sort_data;
    delete shared_exchange_;
  }

  // Some expensive resource shared by all tests.
  static TestData* shared_exchange_;
};
TestData* TestSuiteSort::shared_exchange_ = NULL;

TEST_F(TestSuiteSort, bubble) {
  if (0 < shared_exchange_->len) {
    int* bubble = new int[shared_exchange_->len];
    memcpy(bubble, shared_exchange_->data, shared_exchange_->len * sizeof(int));
    sort_bubble(bubble, shared_exchange_->len);
    printf("===== bubble =====\n");
    printArray(bubble, shared_exchange_->len);

    for (size_t i = 0; i < shared_exchange_->len; i++) {
      ASSERT_EQ(shared_exchange_->sort_data[i], bubble[i]);
    }

    delete[] bubble;
  }
}

TEST_F(TestSuiteSort, quick) {
  if (0 < shared_exchange_->len) {
    int* quick = new int[shared_exchange_->len];
    memcpy(quick, shared_exchange_->data, shared_exchange_->len * sizeof(int));
    sort_quick(quick, shared_exchange_->len);
    printf("===== quick =====\n");
    printArray(quick, shared_exchange_->len);

    for (size_t i = 0; i < shared_exchange_->len; i++) {
      ASSERT_EQ(shared_exchange_->sort_data[i], quick[i]);
    }

    delete[] quick;
  }
}
