#include "network.hpp"

#include <iostream>

int main()
{
	Network net;
	
	net.runSimulation(10000);
	
	net.displaySpikeTimes();


	return 0;
}

