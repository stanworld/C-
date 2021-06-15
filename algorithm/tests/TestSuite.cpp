/*
 *  TestSuite.cpp
 *
 *  Created on: Aug 25, 2020
 *      Author: stan
 */
#include "gtest/gtest.h"

namespace {
   class TestSuite: public testing::Test {};

   TEST_F(TestSuite, CanReallyTest) {
       EXPECT_EQ(0,0);
   }

}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}



