#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "adevs.h"
struct Customer {
  double twait;
  double tenter;
  double tleave;

};
using IO_Type=adevs::PortValue<Customer*>;

#endif