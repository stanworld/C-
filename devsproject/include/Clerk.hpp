#include "adevs.h"
#include "Customer.h"
#include <list>
class Clerk : public adevs::Atomic<IO_Type>
{
public:
    Clerk();
    void delta_int();
    void delta_ext(double e, const adevs::Bag<IO_Type> &xb);
    void delta_conf(const adevs::Bag<IO_Type> &xb);

    void output_func(adevs::Bag<IO_Type> &g);
    double ta();
    void gc_output(adevs::Bag<IO_Type>&g);
    ~Clerk()=default;
    static const int arrive;
    static const int depart;

private:
    double t;
    std::list<Customer*> line;

    double t_spent;
};