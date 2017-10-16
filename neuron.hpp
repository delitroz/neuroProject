#ifndef neuron_HPP
#define neuron_HPP

#include <vector>
#include "constant.hpp"

using namespace std;

class Neuron
{
	public:
	
	/*!
	 * @brief initialise a neuron with a null membrane potential
	 * 		  						   an empty spike historic
	 * 								   non-repository mode
	 * 								   a clock at t=0
	 * 								   no connection
	 * 								   an empty buffer
	 */
		Neuron();
	 

	/*!
	 * @brief get the membrane potential of the neuron
	 */
		double getMembranePotential() const;
		
		
	/*!
	 * @brief get the number of spikes the neuron has done during a simulation 
	 */
		size_t getNumberOfSpike() const;
	
	/*!
	 * @brief get all the times a spike occured in the neuron
	 */
		vector<double> getSpikeTimes() const;
		
	/*!
	 * @brief update the state of a neuron at each time steps h during a
	 * 		  simulation
	 * 
	 * @param double I the external electric current applied on the neuron
	 */
		void update (double Iext);
		
	/*!
	 * @brief compute the embrane potential at time t+h
	 * 
	 * @param double h the time step
	 * 		  double I the external electric current applied on the neuron
	 */ 
		void depolarisation (double h, double Iext, double J);
		
	/*!
	 * @brief add a new neuron in the collection of post-synaptic neurons
	 *
	 * @param neuron to add
	 */
		void addConection (Neuron* other);
		
	/*!
	 * @brief add the amplitude of a spike in the spikeMemory
	 * 
	 * @param int t time at which the spike occured in the pre-synaptic
	 * 				neuron
	 */
		void getSpike ();
		
	/*!
	 * @brief tells which position of the buffer correspond to a time t
	 * 
	 * @param double t the time
	 * 
	 * @return int i the position corresponding
	 */	
		int getBufferPos (int t);
	
	private:
		//membrane potential
		double V_;
		
		//collection of the times when the spikes occured
		vector<double> spikeTimes_;
		
		//tells if the neuron is refractory or not
		bool refractory_;
		
		//global clock of the neuron !in steps h!
		unsigned int neuroClock_;
		
		//collection of post-synaptic neurons
		vector<Neuron*> postNeurons_;
		
		//buffer: memory of the spikes recieved at a time t by the neuron
		vector<double> buffer_;
};

#endif
