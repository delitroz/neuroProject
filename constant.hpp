#ifndef constant_HPP
#define constant_HPP

//time constant (20 ms)
static const double tau = 200;
//refractory period (20 ms)
static const double tau_rp = 200;
//timstep (0.1ms)
static const double h = 1;

//treshold memrane electrical potential of the neurone [mvolt]
static const double V_tresh = 200;
//standard memrane electrical potential of the neurone [mvolt]
static const double V_reset = 100;

//electrical capacitance [farad]
static const double C = 10;
//electric resistance of the membrane (=tau/C) 
static const double R = 20; 

#endif
