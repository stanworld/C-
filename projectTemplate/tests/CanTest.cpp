/*
 * CanTest.cpp
 *
 *  Created on: Aug 25, 2020
 *      Author: stan
 */
#include "gtest/gtest.h"

namespace {
   class CanTest: public testing::Test {};

   TEST_F(CanTest, CanReallyTest) {
       EXPECT_EQ(0,0);
   }

}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}



