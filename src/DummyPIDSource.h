/*
 * DummyPIDSource.h
 *
 *  Created on: Jan 20, 2015
 *      Author: Robot
 */

#ifndef SRC_DUMMYPIDSOURCE_H_
#define SRC_DUMMYPIDSOURCE_H_

#include "PIDSource.h"

class DummyPIDSource : public PIDSource
{

public:

	double PIDGet();
	void InputEncVelocity(double leftVel, double rightVel);


private:
	static double PIDInput;
};



#endif /* SRC_DUMMYPIDSOURCE_H_ */
