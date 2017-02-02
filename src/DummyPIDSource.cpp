/*
 * DummyPIDSource.cpp
 *
 *  Created on: Jan 20, 2015
 *      Author: Robot
 */

#include "DummyPIDSource.h"

double DummyPIDSource::PIDInput = 0.0;

double DummyPIDSource::PIDGet() //Name required by PID class
{
	return PIDInput;
}

void DummyPIDSource::InputEncVelocity(double leftVel, double rightVel)
{
	PIDInput = (leftVel + rightVel) / 2.0;
	//maybe change to += ?
}
