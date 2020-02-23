#include "Observer.hpp"
using namespace std;
using namespace adevs;

const int Observer::departed = 0;

Observer::Observer(const char* result_file):output_strm(result_file) {
    output_strm << "# Col 1: Time customer enters the line" <<endl;
    output_strm << "# Col 2: Time required for customer checkout" <<endl;
    output_strm << "# Col 3: Time customer leaves the store" <<endl;
    output_strm << "# Col 4: Time spent waiting in line" <<endl;
}

double Observer::ta() {
    return DBL_MAX;
}

void Observer::delta_int() {

}

void Observer::delta_ext(double e, const Bag<IO_Type>& xb) {
    for (auto i =xb.begin(); i!=xb.end();i++) {
        const Customer* c= (*i).value;
        double waiting_time = (c->tleave-c->tenter)-c->twait;
        output_strm << c->tenter << " " << c->twait << " "
        << c->tenter << " " << waiting_time <<endl;
    }
}

void Observer::delta_conf(const Bag<IO_Type>& sb) {

}

void Observer::output_func(Bag<IO_Type>& xb) {

}

void Observer::gc_output(Bag<IO_Type>& g) {

}

Observer::~Observer() {
    output_strm.close();
}