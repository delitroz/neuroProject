#ifndef neuron_HPP
#define neuron_HPP

#include <vector>
#include "constant.hpp"

using namespace std;

class Neuron
{
	public:

	//////////////////////////////
	//                          //
	// constructor & destructor //
	//                          //
	//////////////////////////////
	
	/*!
	 * @brief initialise a neuron with a null membrane potential, in a
	 * 		  non repository state, with an internal clock at t=0, with 
	 * 		  an empty buffer and in a non spiking state
	 * 	
	 */
		Neuron();
		
	/*!
	 * @brief destructor
	 */	
		~Neuron();
		
	//////////////////////////////
	//                          //
	//			Getters			//
	//                          //
	//////////////////////////////

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
	 * @brief tells which position of the buffer correspond to a time t
	 * 
	 * @param double t the time
	 * 
	 * @return int i the position corresponding
	 */	
		int getBufferPos (int t) const;
		
	/*!
	 * @brief get the information whether a neuron is spiking at a time t or not
	 * 
	 * @return spike_
	 */	
		bool getSpike ();
		
	//////////////////////////////
	//                          //
	//			Setters			//
	//                          //
	//////////////////////////////
	
	/*!
	 * @brief set the membrane potential to given number
	 * 
	 * @param double newPot new membrane potential
	 */
		void setMembranePotential(double newV);
	
	//////////////////////////////
	//                          //
	//		  Simulation		//
	//                          //
	//////////////////////////////
		
	/*!
	 * @brief update the state of a neuron at each time steps h during a
	 * 		  simulation
	 * 
	 * @param double I the external electric current applied on the neuron
	 * @param bool randomSpike if the neuron ca reciefe external random spike or not
	 */
		void update (double Iext, bool randomSpike);
		
	/*!
	 * @brief compute the embrane potential at time t+h
	 * 
	 * @param double h the time step
	 * @param double I the external electric current applied on the neuron
	 */ 
		void depolarisation (double Iext, double J);
		
	/*!
	 * @brief add the electrical imput recieved by the neuron in the buffer
	 * 
	 * @param double input 
	 */
		void getSpiked (double input);

	//////////////////////////////
	//                          //
	//		Random Generator	//
	//                          //
	//////////////////////////////
	
	/*!
	 * @brief generate a random spike from external neurons following a
	 * 		  poisson distribution 
	 */		
		int randomExtSpike();
		
	
	
	private:
	
		//!membrane potential
		double V_;
		
		//!collection of the times when the spikes occured
		vector<double> spikeTimes_;
		
		//!tells if the neuron is refractory or not
		bool refractory_;
		
		//!global clock of the neuron !in steps h!
		double neuroClock_;
		
		//!buffer: memory of the spikes recieved at a time t by the neuron
		vector<double> buffer_;
		
		//!tells if the neuron spike at that time t
		bool spike_;
		
};

#endif
