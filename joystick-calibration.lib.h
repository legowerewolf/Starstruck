int joyCh1 = 0;
int joyCh2 = 0;
int joyCh3 = 0;
int joyCh4 = 0;
int joyCh1Bias = 0;
int joyCh2Bias = 0;
int joyCh3Bias = 0;
int joyCh4Bias = 0;
const int joystickTolerance = 10; //$tag:var

task joystickMacro()//All macros should run nearly instantaneously.
{
	while(true){
		joyCh1 = abs(vexRT[Ch1] - joyCh1Bias)>joystickTolerance ? vexRT[Ch1] - joyCh1Bias : 0;
		joyCh2 = abs(vexRT[Ch2] - joyCh2Bias)>joystickTolerance ? vexRT[Ch2] - joyCh2Bias : 0;
		joyCh3 = abs(vexRT[Ch3] - joyCh3Bias)>joystickTolerance ? vexRT[Ch3] - joyCh3Bias : 0;
		joyCh4 = abs(vexRT[Ch4] - joyCh4Bias)>joystickTolerance ? vexRT[Ch4] - joyCh4Bias : 0;
		EndTimeSlice();
	}
}

void calJoy(){//recalibrates joystick by saving values while joystick is released (On-The-Fly recalibration)
	if (abs(vexRT[Ch1]) < joystickTolerance && abs(vexRT[Ch2]) < joystickTolerance){
		joyCh1Bias = vexRT[Ch1];
		joyCh2Bias = vexRT[Ch2];
	}
	if (abs(vexRT[Ch4]) < joystickTolerance && abs(vexRT[Ch3]) < joystickTolerance){
		joyCh3Bias = vexRT[Ch3];
		joyCh4Bias = vexRT[Ch4];
	}
}
