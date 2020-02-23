#include "adevs.h"
#include "Customer.h"
#include <list>

class Generator: public adevs::Atomic<IO_Type> {
    public:

        Generator(const char* data_file);
        void delta_int();
        void delta_ext(double e, const adevs::Bag<IO_Type>& xb);
        void delta_conf(const adevs::Bag<IO_Type>& xb);
        void output_func(adevs::Bag<IO_Type>& yb);
        double ta();
        void gc_output(adevs::Bag<IO_Type>& g);
        ~Generator()=default;
        static const int arrive;
    private:
        std::list<Customer*> arrivals;

};