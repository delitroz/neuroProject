/*!
 * Test1
 * @brief test the good functioning of a single neuron recieving an 
 * 	      external current given by the user
 */

#include "neuron.hpp"

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	
	Neuron n;
	
	n.setMembranePotential(10.0);
	
	double Iext(0.0);
		
	cout << "---potential---" << endl << endl;
		
	for (int i(0); i<5000; ++i)
	{
		n.update(Iext, false);
		cout << "t = " << i/10 << "ms : " << n.getMembranePotential() << " mV" << endl;
	}
	
	cout << endl << endl << "---spikes---" << endl << endl;
	
	cout << n.getNumberOfSpike() << " spikes occured at times: " << endl;
	for(size_t i = 0; i < n.getSpikeTimes().size(); ++i)
	{
		cout << "t = " << (n.getSpikeTimes()[i])/10 << "ms" << endl;
	}	
	
	return 0;
}
