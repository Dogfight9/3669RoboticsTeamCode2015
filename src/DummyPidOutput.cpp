/*
 * DummyPidOutput.cpp
 *
 *  Created on: Jan 20, 2015
 *      Author: Robot
 */
#include "DummyPIDOutput.h"

double DummyPIDOutput::PIDOutput = 0.0;

void DummyPIDOutput::PIDWrite(float output)
{
	PIDOutput = output;
}

double DummyPIDOutput::getPIDOutput()
{
	return PIDOutput;
}

