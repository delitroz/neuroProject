/*!
 * test2
 * @brief test the good functioning of a simple network constituted of
 * 		  two neurons n0 and n1, in which b is n0 is a pre-synaptic neuron
 * 		  of n1 and recieve an external current given by the user. When
 * 		  n0 spikes, it transmit a current of amplitude J to n1
 */

#include "neuron.hpp"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	Neuron n0,
		   n1;	
	
	Neuron* p_n1 = &n1;
	
	n0.addConection(p_n1);
		   
	double Iext(0.0), 
		   t(0.0), 
		   t_stop(200.0);
	
	do
	{
		cout << "Enter an extarnal electrical current value : ";
		cin >> Iext;
		cout << endl;
	}while(Iext <= 0.0);
	
	
	//cout << "---n1 potential---" << endl;
	while(t < t_stop)
	{
		n0.update(Iext);
		//cout << "t = " << t/10 << "ms : " << n0.getMembranePotential() << " mV" << endl;
		
		n1.update(0.0);
		cout << "t = " << t/10 << "ms : " << n1.getMembranePotential() << " mV" << endl;
				
		++t;
	}
	
	cout << endl << "---spikes---" << endl;
	
	cout << "---n0---" << endl << n0.getNumberOfSpike() << " spikes occured at times: " << endl;
	for(size_t i = 0; i < n0.getSpikeTimes().size(); ++i)
		{
			cout << "t = " << (n0.getSpikeTimes()[i])/10 << "ms" << endl;
		}
	
	cout << endl << "---n1---" << endl << n1.getNumberOfSpike() << " spikes occured at times: " << endl;
	for(size_t i = 0; i < n1.getSpikeTimes().size(); ++i)
		{
			cout << "t = " << (n1.getSpikeTimes()[i])/10 << "ms" << endl;
		}
	
	return 0;
}
