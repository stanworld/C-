#include "adevs.h"
#include "Customer.h"
#include <fstream>
class Observer: public adevs::Atomic<IO_Type> {
    
    public:
        static const int departed;
        Observer(const char* results_file);
        void delta_int();
        void delta_ext(double e, const adevs::Bag<IO_Type>& xb);
        void delta_conf(const adevs::Bag<IO_Type>& xb);
        double ta();
        void output_func(adevs::Bag<IO_Type>& yb);
        void gc_output(adevs::Bag<IO_Type>&g);
        ~Observer();
    private:
        std::ofstream output_strm;

};