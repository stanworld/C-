#include "cherrybomb.h"

int main() {
  CherryBomb* bomb = new CherryBomb();
  ode_solver<string>* ode_solve = new corrected_euler<string>(bomb,1E-4,0.01);
  
  event_locator<string>* event_find = new linear_event_locator<string>(bomb, 1E-8);
  Hybrid<string>* model = new Hybrid<string>(bomb,ode_solve,event_find);
  Simulator<string>* sim = new Simulator<string>(model);
  while(bomb->getPhase() == FUSE_LIT)
    sim->execNextEvent();
  delete sim;
  delete bomb;
  return 0;
}