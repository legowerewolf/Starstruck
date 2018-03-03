int joystick[4];
int joystickBias[4];
const int joystickTolerance = 10; //$tag:var

task joystickMacro()//All macros should run nearly instantaneously.
{
	while(true){
		for (int x=0; x<4; x++){
			joystick[x] = abs(vexRT[x] - joystickBias[x])>joystickTolerance ? vexRT[x] - joystickBias[x] : 0;
		}
		EndTimeSlice();
	}
}

void calJoy(){//recalibrates joystick by saving values while joystick is released (On-The-Fly recalibration)
	if (abs(vexRT[Ch1]) < joystickTolerance && abs(vexRT[Ch2]) < joystickTolerance){
		joystickBias[Ch1] = vexRT[Ch1];
		joystickBias[Ch2] = vexRT[Ch2];
	}
	if (abs(vexRT[Ch4]) < joystickTolerance && abs(vexRT[Ch3]) < joystickTolerance){
		joystickBias[Ch3] = vexRT[Ch3];
		joystickBias[Ch4] = vexRT[Ch4];
	}
}

void initalizeJoystickCalibrationRoutines()
{
	joystick[Ch1]=0;
	joystick[Ch2]=0;
	joystick[Ch3]=0;
	joystick[Ch4]=0;
	joystickBias[Ch1]=0;
	joystickBias[Ch2]=0;
	joystickBias[Ch3]=0;
	joystickBias[Ch4]=0;
	calJoy();
	startTask(joystickMacro);
}
