#include "fmi_1.h"
#include "cherrybomb_fmi.h"

int main() {
    CherryBomb* bomb  = new CherryBomb();

    Hybrid<std::string>* hybrid_model = new Hybrid<std::string>
    (bomb,
    new corrected_euler<std::string>(bomb,1E-5,0.01),
    new discontinuous_event_locator<std::string>(bomb, 1E-5)  
    );

    SimpleDigraph<std::string>* model = new SimpleDigraph<std::string>();
    Miscreant* miscreant = new Miscreant();
    model->add(miscreant);
    model->add(hybrid_model);
    model->couple(miscreant,hybrid_model);
    model->couple(hybrid_model,miscreant);

    Simulator<std::string>* sim = 
    new Simulator<std::string>(model);

    while(sim->nextEventTime()<=4.0) {
        cout << sim->nextEventTime() << " ";
        sim->execNextEvent();
        cout << bomb->get_height() << " " << bomb->get_fuse() <<endl;
    }


    delete sim;
    delete hybrid_model;
    return 0;
}