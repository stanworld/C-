#include <iostream>
#include <vector>
#include "mylib/myclass.hpp"
int main(int, char**) {
    std::cout << "Hello, world!\n";
    std::vector<int> ss;
    ss.emplace_back(1);
    std::cout<<ss[0]<<std::endl;
    myclass t1;
    t1.good();

}
