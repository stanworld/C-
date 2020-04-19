#include "fmi2Functions.h"
#include "fmi2FunctionTypes.h"
#include "fmi2TypesPlatform.h"
#include "adevs.h"
#include "adevs_fmi.h"

using namespace std;
using namespace adevs;
class CherryBomb: public FMI<string> {
   public:
       CherryBomb(): FMI<string>(
           "CherryBomb",
           "{43090a83-fa63-4360-8929-20ef5d425dfd}",
           3,
           3,
           "/home/stan/Tool/adevs-3.2/examples/fmi/Example3/binaries/linux64/CherryBomb.so"
       ){}

       void internal_event(double* q, const bool* state_event) {
            FMI<string>::internal_event(q,state_event);    
       }

       void external_event(double* q, double e, const Bag<std::string>& xb) {
            FMI<string>::external_event(q,e,xb);
            set_dropped();
            FMI<string>::external_event(q,e,xb);
       }

       double time_event_func(const double* q) {
           return FMI<std::string>::time_event_func(q);
       }

       void output_func(const double*q, const bool* state_event, Bag<string>& yb) {
           if(state_event[1])
             yb.insert("boom!");
       }

       bool get_exploded() {return get_bool(3);}

       double get_height() {return get_real(1);}

       void set_dropped() { set_bool(2,true); }

       bool get_dropped() { return get_bool(2); }

       double get_fuse() {return get_real(0); }

       
};