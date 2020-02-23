#include "Generator.hpp"
#include <fstream>

const int Generator::arrive = 0;

Generator::Generator(const char* data_file) {
    std::fstream input_strm(data_file);
    double next_arrival_time = 0.0;
    double last_arrival_time = 0.0;

    while(true) {
        Customer* customer = new Customer;
        input_strm >> next_arrival_time >> customer->twait;

        if(input_strm.eof()) {
            delete customer;
            break;
        }
        customer->tenter = next_arrival_time-last_arrival_time;
        arrivals.push_back(customer);
        last_arrival_time = next_arrival_time;
    }
}

void Generator::delta_ext(double e, const adevs::Bag<IO_Type>& xb) {
    
}

void Generator::delta_conf(const adevs::Bag<IO_Type>& xb) {
    delta_int();
}

void Generator::output_func(adevs::Bag<IO_Type>& yb) {
    IO_Type output(arrive,arrivals.front());
    yb.insert(output);
}

void Generator::delta_int() {
    arrivals.pop_front();
}

double Generator::ta() {
    if(arrivals.empty()) return DBL_MAX;
    return arrivals.front()->tenter;
}

void Generator::gc_output(adevs::Bag<IO_Type>& g) {
    adevs::Bag<IO_Type>::iterator i;
    for (i = g.begin(); i != g.end(); i++)
    {
        delete (*i).value;
    }
}

