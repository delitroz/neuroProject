#ifndef constant_HPP
#define constant_HPP

//time constant (20 ms)
static const double tau(200);
//refractory period (20 ms)
static const double tau_rp(20);
//timstep (0.1ms)
static const double h(1);

//treshold memrane electrical potential of the neurone [mvolt]
static const double V_tresh(20);
//standard memrane electrical potential of the neurone [mvolt]
static const double V_reset(0);

//electrical capacitance [farad]
static const double C(1);
//electric resistance of the membrane (=tau/C) 
static const double R (200) ;

//amplitude transmitted after a spike
static const double J(0.1); //numeric value arbitrary choosen for test sake

//transmission delay
static const int D(15);
#endif
