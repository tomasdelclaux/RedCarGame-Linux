#include "vehicle.h"


Vehicle::Vehicle(Type type){
    switch(type)
    {
        case red :
            w = 5;
            h = 5;
            v = 5;
        case blue :
            w = 5;
            h = 5;
            v = 5;
        case truck :
            w = 5;
            h = 5;
            v = 5;
        case white :
            w = 5;
            h = 5;
            v = 5;
    }
}