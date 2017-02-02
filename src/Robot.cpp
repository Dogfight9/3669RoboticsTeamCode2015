#include "WPILib.h"
#include "DummyPIDSource.h"
#include "DummyPIDOutput.h"
#include <math.h>

class Robot: public IterativeRobot
{

	CANTalon motor;
	CANTalon motor2;
	Joystick stick; // only joystick
	LiveWindow *lw;
	DummyPIDOutput DrivePIDOut;
	DummyPIDSource DrivePIDSource;
	PIDController DriveController;
	SmartDashboard *dash;
	CameraServer *camera1;
	CameraServer *camera2;

public:
	Robot() :
		motor(5),
		motor2(0),
		stick(0),		// as they are declared above.
		lw(NULL),
		DrivePIDOut(),
		DrivePIDSource(),
		DriveController(0.01, 0.0, 0.0, &DrivePIDSource, &DrivePIDOut,0.05)
	{
	}

private:
	void RobotInit()
	{
		lw = LiveWindow::GetInstance();
		camera1 = CameraServer::GetInstance();
		camera2 = CameraServer::GetInstance();
		camera1->SetQuality(50);
		camera2->SetQuality(50);
		camera1->StartAutomaticCapture("cam0");
		camera2->StartAutomaticCapture("cam1");
		motor.SetFeedbackDevice(CANTalon::QuadEncoder);
		motor2.SetFeedbackDevice(CANTalon::QuadEncoder);

		DriveController.Disable();

	}

	void AutonomousInit()
	{
		DriveController.Disable();
	}

	void AutonomousPeriodic()
	{

	}

	void TeleopInit()
	{
		lw->Run();
		//DriveController.Enable();
	}

	void TeleopPeriodic()
	{
		double Y = -stick.GetY();
		double X = stick.GetX();
		double rightVel = double(motor.GetEncVel())/12.0;
		double leftVel = -1.0*double(motor2.GetEncVel())/12.0;
		DrivePIDSource.InputEncVelocity(leftVel, rightVel);

		float setpoint = float(sqrt((X*X) + (Y*Y)));
		DriveController.SetSetpoint(setpoint * 1000.0);

		dash->PutString("Right Encoder Velocity",std::to_string(rightVel));
		dash->PutString("Left Encoder Velocity",std::to_string(leftVel));

		/*
		 * 1. Somehow get distance from center of joystick (hypotenuse of x and y)
		 * 2. Use that to set setpoint of PID
		 * 3. Use either the joystick angles or joystick values to set each motor independently
		 *
		 */

		double output = DrivePIDOut.getPIDOutput();

		motor.Set((Y - (X*0.8))* output);
		motor2.Set((Y + (X*0.8)) * output);
		Wait(0.01);
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);
