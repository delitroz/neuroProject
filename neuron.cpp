#include "neuron.hpp"

#include <iostream>
#include <cmath>
#include <random>

using namespace std;

	//////////////////////////////
	//                          //
	// constructor & destructor //
	//                          //
	//////////////////////////////
	
Neuron::Neuron(neuron_type type) 
	  :V_(V_reset),
	   refractory_(false),
	   neuroClock_(0),
	   buffer_(D+1, 0.0),
	   type_(type)
{}

Neuron::~Neuron()
{
	buffer_.clear();
	spikeTimes_.clear();
}

	//////////////////////////////
	//                          //
	//			Getters			//
	//                          //
	//////////////////////////////
	
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

int Neuron::getBufferPos (int t) const
{
	int i = t % (D+1);
	return i;
}

bool Neuron::isExcitatory()
{
	if(type_ == E)
	{
		return true;
	}
	else
	{
		return false;
	}
}

	//////////////////////////////
	//                          //
	//			Setters			//
	//                          //
	//////////////////////////////
	
void Neuron::setMembranePotential(double newV)
{
	V_ = newV;
}
	
	//////////////////////////////
	//                          //
	//		  Simulation		//
	//                          //
	//////////////////////////////

bool Neuron::update(double Iext, bool randomSpike) 
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
		/*!
		 * we create a variable J that contain the information comming 
		 * from the buffer plus the random noise created with poisson
		 * distribution
		 */
		double J(0.0);
		if(randomSpike)
		{
			J = randomExtSpike()*Ji + buffer_[getBufferPos(neuroClock_)];
		}
		else
		{
			J = buffer_[getBufferPos(neuroClock_)];
		}
		depolarisation(Iext, J);
	}
	else if(!refractory_ and V_ >= V_tresh)
	{
		spikeTimes_.push_back(neuroClock_);
	
		V_ = V_reset;
		
		refractory_ = true;	 
		
		return true;
	}
	
	buffer_[getBufferPos(neuroClock_)] = 0.0;
	
	++neuroClock_;
	
	return false;
}

void Neuron::depolarisation (double Iext, double J)
{
	V_ = V_*exp(-h/tau) + Iext*R*(1-exp(-h/tau)) + J; 
}

void Neuron::getSpiked(double input)
{	
	int i = getBufferPos(neuroClock_+D);

	buffer_[i] += input;
}

	//////////////////////////////
	//                          //
	//		Random Generator	//
	//                          //
	//////////////////////////////
	
int Neuron::randomExtSpike()
{
	double lambda = V_ext*Ce;
	
	static random_device rd;
	static mt19937 gen(rd());
	static poisson_distribution<> d(lambda);
	
	return d(gen);
}

