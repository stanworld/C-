#include <iostream>
#include "Customer.h"
#include "Clerk.hpp"
#include "Generator.hpp"
#include "Observer.hpp"

using namespace std;

int main(int argc, char** argv) {

    if(argc !=3) {
        cout<<"Need input and output files! "<<endl;
        return 1;
    }

    adevs::Digraph<Customer*> store;
    Clerk* clrk = new Clerk();
    Generator* genr = new Generator(argv[1]);
    Observer* obsrv = new Observer(argv[2]);
    store.add(clrk);
    store.add(genr);
    store.add(obsrv);
    store.couple(genr,genr->arrive,clrk,clrk->arrive);
    store.couple(clrk,clrk->depart,obsrv,obsrv->departed);

    adevs::Simulator<IO_Type> sim(&store);
    while(sim.nextEventTime() < DBL_MAX) {
        sim.execNextEvent();
    }
    return 0;
}