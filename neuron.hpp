#ifndef neuron_HPP
#define neuron_HPP

#include <vector>
#include "constant.hpp"

using namespace std;

class neuron
{
	public:
	
	/*!
	 * @brief initialise a neuron with a standard membrane potentiel and
	 * 		  an empty spike historic
	 */
		neuron();
	 

	/*!
	 * @brief get the membrane potential of the neuron
	 */
		double getMembranePotential() const;
		
		
	/*!
	 * @brief get the number of spikes the neuron has done during a simulation 
	 */
		int getNumberOfSpike() const;
	
	/*!
	 * @brief get all the times a spike occured in the neuron
	 */
		vector<double> getSpikeTimes() const;
		
	/*!
	 * @brief update the state of a neuron at each time steps h during a
	 * 		  simulation
	 * 
	 * @param double h the time step
	 * 		  double t the current time t of the simulation
	 * 		  double I the external electric current applied on the neuron
	 */
		void update (double h, double t, double Iext);
		
	/*!
	 * @brief compute the embrane potential at time t+h
	 * 
	 * @param double h the time step
	 * 		  double I the external electric current applied on the neuron
	 */ 
		void depolarisation (double h, double Iext);
	
	private:
		//membrane potential
		double V_;
		
		//number of spikes produced by the neuron
		int numberOfSpikes_;
		
		//collection of the times when the spikes occured
		vector<double> spikeTimes_;
		
		//tells if the neuron is refractory or not
		bool refractory_;
		
		//show since when the neuron is refractory
		unsigned int refractoryClock_;
		
		//global clock of the neuron !in steps h!
		unsigned int neuroClock_;
};

#endif
