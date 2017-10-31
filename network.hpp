#ifndef network_HPP
#define network_HPP

#include "neuron.hpp"

#include <iostream>
#include <vector>

using namespace std;

class Network
{
	public:
	
	//////////////////////////////
	//                          //
	// constructor & destructor //
	//                          //
	//////////////////////////////
	
	/*!
	 * @brief initialise a network with a number N of neuron given by the
	 * 		  constant file, a matrix mapping all the connection between
	 * 		  these neurons and an internal clock at t=0
	 */	
		Network();
		
	/*!
	 * @brief destructor of Network class
	 */	
		~Network();
	
	//////////////////////////////
	//                          //
	//			Display			//
	//                          //
	//////////////////////////////
	
	/*!
	 * @brief display the list of neurons in the terminal
	 */
		void displayNeurons();
		
	/*!
	 * @brief display the connection map in the terminal
	 */
		void displayConnectionMap();
		
	/*!
	 * @brief display the spikes of each neuron in the terminal
	 */	
		void displaySpikeTimes();
		
	/*!
	 * @brief display all the aspect of a simulation listed above
	 */
		void displaySimulation();
		
	//////////////////////////////
	//                          //
	//			Print			//
	//                          //
	//////////////////////////////
		
	/*!
	 * @brief print the spikes of each neuron in an external text file
	 */	
	void printSpikeTimes();	
		
	//////////////////////////////
	//                          //
	//		Random Generator	//
	//                          //
	//////////////////////////////
	
	/*!
	 * @brief return a random number between a and b excluding a value c
	 * 		  we want to exclude a value to avoid having a neuron that 	
	 * 		  send spikes to himself
	 * 
	 * @param a minimum possible value
	 * @param b maximum possible value
	 * @param c value to exclude
	 * 
	 */
		int randomSelection(int a, int b, int c);
		

	
	//////////////////////////////
	//                          //
	//		  Simulation		//
	//                          //
	//////////////////////////////	
	
	/*!
	 * @brief run the simulation of a network from t=0 to t=t_stop
	 * 
	 * @param t_stop end time of the simulatioin
	 */	
		void runSimulation(unsigned int t_stop);
		
	/*!
	 * @brief update the state of the network for each time step h
	 */
		void update();
		
	

	
	private:
		
		//!list of all the neurons in the network
		vector <Neuron> neurons_;
		
		//!matrix that store the weigth of each connection for each
		//!in the form of whole numbers
		//!lines : neurons
		//!column : connections
		//!Xi,j = connection weight between the post-synaptic neuron Ni and the pre-synaptic neuron Nj
		vector< vector<int> > connectionMap_;
		
		//!local clock of the network
		unsigned int netClock_;
};

#endif
