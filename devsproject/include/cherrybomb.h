#include "adevs.h"
#include <iostream>
using namespace std;
using namespace adevs;

#define H 0
#define V 1
#define T 2

typedef enum {FUSE_LIT, DOUSE, EXPLODE } Phase;

class CherryBomb: public ode_system<string> {
  public:
    CherryBomb():ode_system<string>(3,1) {
        phase = FUSE_LIT;
    }

    void init(double *q) {
        q[H] = 1.0;
        q[V] = 0.0;
        q[T] = 0.0;
    }

    void der_func(const double* q, double* dq) {
        dq[V]= -9.8;
        dq[H]= q[V];
        dq[T] = 1.0;
    }

    void state_event_func(const double* q, double *z) {
        if (q[V] <0.0) z[0] = q[H];
        else z[0] = 1.0;
    }

    double time_event_func(const double* q) {
        if(q[T] < 2.0) return 2.0 - q[T];
        else return DBL_MAX;
    }

    void external_event(double* q, double e, const Bag<string>& xb) {
        phase = DOUSE;
    }

    void internal_event(double *q, const bool* state_event) {
        if(state_event[0]) q[V]= -q[V];
        if(state_event[1]) phase = EXPLODE;
    }

    void confluent_event(double*q , const bool* state_event, const Bag<string>& xb) {
        internal_event(q, state_event);
        external_event(q,0.0,xb);
    }

    void output_func(const double * q, const bool* state_event, Bag<string>& yb) {
        if (state_event[1] && phase == FUSE_LIT)
            yb.insert("BOOM!");
    }

    void postStep(const double* q) {
        cout << q[T] << " " << q[H] << " " << q[V] << " " << phase << endl;
    }

    void gc_output(Bag<string>&) {}

    Phase getPhase() { return phase; }

  private:
    Phase phase; 
};