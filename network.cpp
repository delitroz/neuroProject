#include "network.hpp"

#include <iostream>
#include <fstream>
#include <random>

using namespace std;

	//////////////////////////////
	//                          //
	// constructor & destructor //
	//                          //
	//////////////////////////////
	
Network::Network()
		:neurons_(N), //! by default ou network consist in a number N of neurons stocked in constant.hpp
		 connectionMap_(N, vector<int>()), //!contain N lines which are empty vectors
		 netClock_(0)
{	
	for(int i(0); i<N ; ++i)
	{
		Neuron n;
		neurons_[i] = n;
	}
    //DONE ! commenter comme il faut
    
    
    for (int i(0); i<N; ++i)
    {
		//!selection of the exitatory connection
		for (int E(0); E < Ce; ++E) 
		{
			connectionMap_[randomSelection(0,Ne-1,i)].push_back(i);
		}
		//!selection of the inhibitory connection
		for (int I(0); I < Ci; ++I) 
		{
			connectionMap_[randomSelection(Ne,N-1,i)].push_back(i);  
		}	
	}
}

Network::~Network()
{
	neurons_.clear();
	connectionMap_.clear();
}

	//////////////////////////////
	//                          //
	//			Display			//
	//                          //
	//////////////////////////////

void Network::displayNeurons()
{
	cout << "---Neurons---" << endl << endl;
	
	for (size_t i(0); i<N; ++i)
	{
		cout << "N" << i << endl;
	}
		
	cout << endl << endl;
}

void Network::displayConnectionMap()
{
	cout << "---Connection Map---" << endl << endl;
	cout << "   =========================================" << endl;
	for (size_t i(0); i<N; ++i)
	{
		cout << "N" << i << "	";
		for (size_t j(0); j<connectionMap_[i].size(); ++j)
		{
			cout << connectionMap_[i][j] << " ";
		}
		cout << endl;
		cout << "   -----------------------------------------" << endl;
	}
	cout << "   =========================================" << endl;
	cout << endl << endl;
}

void Network::displaySpikeTimes()
{
	cout << endl << endl << "---spikes---" << endl << endl;
	
	for (size_t i(0); i<N; ++i)
	{
		if(neurons_[i].getNumberOfSpike() != 0)
		{
			cout << endl << "---N"<< i <<"---" << endl << neurons_[i].getNumberOfSpike() << " spikes occured at times: " << endl;
			for(size_t j = 0; j < neurons_[i].getSpikeTimes().size(); ++j)
			{
				cout << "t = " << (neurons_[i].getSpikeTimes()[j])/10 << "ms" << endl;
			}
			cout << endl << endl;
		}
	}
}

void Network::displaySimulation()
{
	displayNeurons();
	displayConnectionMap();
	displaySpikeTimes();
}

	//////////////////////////////
	//                          //
	//			Print			//
	//                          //
	//////////////////////////////
	
void Network::printSpikeTimes()
{
	ofstream data;
	data.open("data_neuro.txt");
	
	if(data.fail())
	{
		cerr << "Error while opening the file" << endl;
	}
	else
	{
		for(int i(0); i<N; ++i)
		{
			for(size_t j(0); j<neurons_[i].getSpikeTimes().size(); ++j)
			{
				data << (neurons_[i].getSpikeTimes()[j])/10 << "\t" << i << "\n";
			}
		}
	}
}	
	
	//////////////////////////////
	//                          //
	//		Random Generator	//
	//                          //
	//////////////////////////////

int Network::randomSelection(int a, int b, int c)
{
	int r(0);
	
	static random_device rd; 
	static mt19937 gen(rd());
	static uniform_int_distribution<> dis(a,b);

	do
	{
		r = dis(gen);
	}while(r == c);
	
    return r;   
}

	//////////////////////////////
	//                          //
	//		  Simulation		//
	//                          //
	//////////////////////////////

void Network::runSimulation(unsigned int t_stop)
{		
		while(netClock_ < t_stop)
		{
			update();
			
			++netClock_;
		}
}

void Network::update()
{
	for(int E(0); E<Ne; ++E)
	{	
		if(neurons_[E].getSpike())
		{
			for (size_t i(0); i<connectionMap_[E].size(); ++i)
			{
				neurons_[connectionMap_[E][i]].getSpiked(Je);
			}
		}
	}
	for(int I(Ne); I<N; ++I)
	{	
		if(neurons_[I].getSpike())
		{
			for (size_t j(0); j<connectionMap_[I].size(); ++j)
			{
				neurons_[connectionMap_[I][j]].getSpiked(-Ji);
			}
		}
	}
	
	for (int i(0); i<N; ++i)
	{
		neurons_[i].update(0.0, true);
	}
}







