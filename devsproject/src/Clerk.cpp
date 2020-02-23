#include "Clerk.hpp"

const int Clerk::arrive = 0;
const int Clerk::depart =1;

Clerk::Clerk(): t(0),t_spent(0){}

void Clerk::delta_ext(double e, const adevs::Bag<IO_Type>& xb) {
    cout<< "Clerk: Computed the external transition function at t = " << t+e<< endl;
    t += e;
    if (!line.empty()) {
        t_spent += e;
    }
    for(auto i=xb.begin(); i !=xb.end();i++) {
        line.emplace_back(new Customer(*((*i).value)));
        line.back()->tenter=t;
    }

    cout<< "Clerk: There are " <<line.size() << " customers waiting." <<endl;
    cout<< "Clerk: The next customer will leave at t = " <<t+ta() << "." <<endl;
}  

double Clerk::ta() {
    if(line.empty()) {
        return DBL_MAX;
    }

    return line.front()->twait-t_spent;
}

void Clerk::output_func(adevs::Bag<IO_Type>& yb) {
    Customer* leaving = line.front();
    leaving->tleave = t+ta();

    IO_Type y(depart,leaving);
    yb.insert(y);
    cout<< "Clerk: Computed the output function at t= " << t+ta() <<endl;
    cout<< "Clerk: A customer just departed! " <<endl;
}

void Clerk::delta_int() {
    cout<< "Clerk: Computed the internal transition function at t=" << t+ta() <<endl;
    t +=ta();
    t_spent = 0.0;
    line.pop_front();
    cout<< "Clerk: There are " <<line.size() << " customers waiting. "<<endl;
    cout<< "Clerk: The next customer will leave at t = " << t+ta() << "." <<endl;
}

void Clerk::delta_conf(const adevs::Bag<IO_Type>& xb) {
    delta_int();
    delta_ext(0,xb);
}

void Clerk::gc_output(adevs::Bag<IO_Type>& g) {
    adevs::Bag<IO_Type>::iterator i;
    for (i = g.begin(); i != g.end(); i++)
    {
        delete (*i).value;
    }
}