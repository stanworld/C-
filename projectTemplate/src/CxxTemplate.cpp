
#include "CxxTemplate.h"
#include "ANewclass.h"
#include "SumFunc.h"
#include <string>
#include <iostream>
#include <chrono>
#include <gtest/gtest.h>

using namespace std::chrono_literals;

namespace cxxt {

CxxApplication::CxxApplication( int argc, char *argv[] ) {
  std::cout << "Hello CMake1." << std::endl;
  ANewclass anew;
  anew.run();
  SumFunc s;

}

CxxApplication::~CxxApplication() {
  // TODO cleanup
}

} // namespace cxxt


int main( int argc, char *argv[] ) {
  cxxt::CxxApplication app( argc, argv );

  return 0;
}
