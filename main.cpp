#include "neuron.hpp"

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	neuron n;
	double Iext(0.0),
		   t_a(0.0), 
		   t_b(0.0), 
		   t(0.0), 
		   t_stop(2000.0);
	
	do
	{
		cout << "Enter an extarnal electrical current value : ";
		cin >> Iext;
		cout << endl;
	}while(Iext <= 0.0);
	
	do
	{
		double entry(0.0);
		cout << "Enter a time a between 0 an 200ms: ";
		cin >> entry;
		t_a = entry*10;
		cout << endl;
	}while(t_a <= 0.0);

	do
	{
		double entry(0.0);
		cout << "Enter a time b between 0 and 200ms: ";
		cin >> entry;
		t_b = entry*10;
		cout << endl;	
	}while(t_b < t_a and t_b > t_stop and t_b <= h );	//we want our time interval [a,b[ to be included in [t_start, t_stop] and larger than h

	
	ofstream data;
	data.open("data.txt");
	if (data.fail())
	{
		cerr << "Error while opening the file" << endl;
	}	
	else
	{
		data << "Membrane potentials at time t: "<< endl << endl;
		cout << "---potential---" << endl;
		while(t < t_stop)
		{
			if(t >= t_a and t <= t_b)
			{
				n.update(h,t,Iext);
			}
			else
			{
				n.update(h,t,0.0);
			}
			
			data << "t = " << t/10 << "ms : " << n.getMembranePotential() << " mV" << endl;
			cout << "t = " << t/10 << "ms : " << n.getMembranePotential() << " mV" << endl;
			t +=h;
		}
		
		data << "Spikes occurred at times:" << endl;
		cout << "---spikes---" << endl;
		for(size_t i = 0; i < n.getSpikeTimes().size(); ++i)
		{
			data << "t = " << (n.getSpikeTimes()[i])/10 << "ms" << endl;
			cout << "t = " << (n.getSpikeTimes()[i])/10 << "ms" << endl;
		}
		
		data.close();
	}
	
	return 0;
}
