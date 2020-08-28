#include "gtest/gtest.h"
#include "../src/SumFunc.h"
namespace {
   class AnotherTest: public testing::Test {};

   TEST_F(AnotherTest, CanReallyTest1) {
       SumFunc ss;
       EXPECT_EQ(7,ss.sum(3,4));
   }

   TEST_F(AnotherTest, CanReallyTest2) {
       SumFunc ss;
       EXPECT_EQ(6,ss.sum(3,3));
   }
}