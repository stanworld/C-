#include "adevs.h"
using namespace std;
using namespace adevs;

class Miscreant: public Atomic<std::string> {
   public:
     Miscreant():
     Atomic<string>(),
     start(true),
     tstart(1.0){

     }

     double ta() {
         return start ? tstart: adevs_inf<double>();

     }

     void delta_int() {
         start = false;
     }

     void delta_ext(double e, const Bag<std::string>& xb) {
         cout << (tstart+e) << " " << (*(xb.begin())) <<endl;
     }

     void delta_conf(const Bag<std::string>&) {

     }

     void output_func(Bag<std::string>& yb) {
         if (start) 
         yb.insert("light");
     }

     void gc_output(Bag<std::string>&){
         
     }
   private:
    bool start;
    const double tstart;  
};