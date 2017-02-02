/*
 * DummyPIDOutput.h
 *
 *  Created on: Jan 20, 2015
 *      Author: Robot
 */

#ifndef SRC_DUMMYPIDOUTPUT_H_
#define SRC_DUMMYPIDOUTPUT_H_

#include "PIDOutput.h"

class DummyPIDOutput : public PIDOutput
{
public:
	virtual void PIDWrite(float output);
	double getPIDOutput();

private:
	static double PIDOutput;
};


#endif /* SRC_DUMMYPIDOUTPUT_H_ */
