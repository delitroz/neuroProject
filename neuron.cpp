#include "neuron.hpp"

#include <iostream>
#include <cmath>

using namespace std;

neuron::neuron()
	  :V_(V_reset),
	   numberOfSpikes_(0),
	   refractory_(false),
	   neuroClock_(0)
{
	spikeTimes_.clear();
}

double neuron::getMembranePotential() const
{
	return V_;
}

int neuron::getNumberOfSpike() const
{
	return numberOfSpikes_;
}

vector<double> neuron::getSpikeTimes() const
{
	return spikeTimes_;
}

void neuron::update (double h, double t, double Iext)
{	
	//cout << neuroClock_ << endl;
	
	if(refractory_ == true)
	{
		if (!spikeTimes_.empty() and neuroClock_>= spikeTimes_.back()+tau_rp)
		{
			refractory_ = false;
		}
	}
	if(refractory_ == false and V_ < V_tresh)
	{
		depolarisation(h,Iext);
	}
	else if(refractory_ == false and V_ >= V_tresh)
	{
		spikeTimes_.push_back(t);
		V_ = V_reset;
		refractory_ = true;
		
	}
	
	++neuroClock_;
	
}

void neuron::depolarisation (double h, double Iext)
{
	V_ = exp(-(h/tau)) * V_ + Iext * R * (1-exp(-(h/tau)));  	
}
