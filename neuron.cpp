#include "neuron.hpp"

#include <iostream>
#include <cmath>

using namespace std;

Neuron::Neuron()
	  :V_(V_reset),
	   refractory_(false),
	   neuroClock_(0),
	   buffer_(D+1, 0.0) 
{
	spikeTimes_.clear();
	postNeurons_.clear();
}

double Neuron::getMembranePotential() const
{
	return V_;
}

size_t Neuron::getNumberOfSpike() const
{
	return spikeTimes_.size();
}

vector<double> Neuron::getSpikeTimes() const
{
	return spikeTimes_;
}

void Neuron::addConection(Neuron* other)
{
	postNeurons_.push_back(other);
}

void Neuron::getSpike()
{	
	int i = getBufferPos(neuroClock_+D);
	cout << "n1: currently at place " << getBufferPos(neuroClock_) << endl;
	cout << "n1: spike stocked in place " << i << endl;
	cout << "n1: J should be add at time " << neuroClock_+D << endl;
	
	buffer_[i] += J;
}

void Neuron::update (double Iext)
{		
	if(refractory_)
	{
		if (!spikeTimes_.empty() and neuroClock_>= spikeTimes_.back()+tau_rp)
		{
			refractory_ = false;
		}
	}
	else if(!refractory_ and V_ < V_tresh)
	{
		depolarisation(h,Iext,buffer_[getBufferPos(neuroClock_)]);
	}
	else if(!refractory_ and V_ >= V_tresh)
	{
		spikeTimes_.push_back(neuroClock_);
		
		if(!postNeurons_.empty())
		{
			for (size_t i(0); i < postNeurons_.size(); ++i)
			{
				cout << "n0: HAVE A SPIKE" << endl;
				postNeurons_[i]->getSpike();
			}
		}
		
		V_ = V_reset;
		refractory_ = true;
		 
	}
	buffer_[getBufferPos(neuroClock_)] = 0.0;
	
	++neuroClock_;
}

void Neuron::depolarisation (double h, double Iext, double J)
{
	V_ = (exp(-(h/tau)) * V_) + (Iext * R * (1-exp(-(h/tau)))) + J;  
}

int Neuron::getBufferPos (int t)
{
	int i = t % (D+1);
	return i;
}
