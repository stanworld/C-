#include "gtest/gtest.h"
#include "../src/SumFunc.h"
namespace {
   class SumFuncTest: public testing::Test {};

   TEST_F(SumFuncTest, CanReallyTest1) {
       SumFunc ss;
       EXPECT_EQ(7,ss.sum(3,4));
   }
}