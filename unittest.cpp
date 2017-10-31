#include "gtest/gtest.h"
#include "neuron.hpp"
#include "network.hpp"

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

	//////////////////////
	//					//
	//	Neurons Tests	//
	//					//
	//////////////////////

TEST (NeuronTest, SingleUpdate)
{
	Neuron n;

	double Iext(1.0);
	
	//!test for one update
	n.update(Iext, false);
	EXPECT_EQ(20.0*(1-exp(-0.1/20.0)), n.getMembranePotential());
}

TEST (NeuronTest, MultipleUpdate)
{
	/*!
	 *test after numerous update
	 *with an extenal current of 1 the membrane potential should tend 
	 *to 20 without reaching it
	 */
	Neuron n;
	
	double Iext(1.0);
	
	for (int i(0); i<2000; ++i)
	{
		n.update(Iext, false);
	}
	EXPECT_EQ(n.getMembranePotential(), 19.9991);
}

TEST (NeuronTest, PotentialRegression)
{
	/*!
	 *test of the exponential regression
	 *with an external current of 0 the membrane potential sould go back
	 *to 0 following an exponential curve
	 */
	
	Neuron n;
	
	n.setMembranePotential(10.0);
	
	double Iext(0.0);
		
	for (int i(0); i<2000; ++i)
	{
		n.update(Iext, false);
	}
	EXPECT_EQ(n.getMembranePotential(), 0.000453999);
}


TEST (NeuronTest, Spike)
{	
	/*!
	 * with an external current equal to 1.01 we observe the firsts spike at
	 * t= 92.4ms 186.9ms 281.4ms 375.9ms and 470.4ms
	 */
	 
	Neuron n;
		
	double Iext(1.01);

	for (int i(0); i<5000; ++i)
	{
		n.update(Iext, false);
	}
	EXPECT_EQ(n.getNumberOfSpike(), 5);
	EXPECT_EQ(n.getSpikeTimes()[0]/10, 92.4);
	EXPECT_EQ(n.getSpikeTimes()[1]/10, 186.9);
	EXPECT_EQ(n.getSpikeTimes()[2]/10, 281.4);
	EXPECT_EQ(n.getSpikeTimes()[3]/10, 375.9);
	EXPECT_EQ(n.getSpikeTimes()[4]/10, 470.4);
}

	//////////////////////
	//					//
	//	Network Tests	//
	//					//
	//////////////////////

TEST (NetworkTest, TotalConnection)
{

}
	
