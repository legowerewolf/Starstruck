#pragma platform(VEX2)
#pragma competitionControl(Competition)
#include "Vex_Competition_Includes.c"

int auton = 1;
int joyCh1 = 0;
int joyCh2 = 0;
int joyCh3 = 0;
int joyCh4 = 0;
int joyCh1Bias = 0;
int joyCh2Bias = 0;
int joyCh3Bias = 0;
int joyCh4Bias = 0;
const int joystickTolerance = 10; //$tag:var

void motorGroupControl(float groupSelect = 0, int speed = 0){
	switch(groupSelect){
	case 0://All motors
		motor[port1] = speed;
		motor[port2] = speed;
		motor[port3] = speed;
		motor[port4] = speed;
		motor[port5] = speed;
		motor[port6] = speed;
		motor[port7] = speed;
		motor[port8] = speed;
		motor[port9] = speed;
		motor[port10] = speed;
		break;
	case 1://Chassis - all
		//Insert command code for all chassis motors here.
		break;
		//Insert additional cases for subsets of chassis here.
	case 2://Arm
		//Insert command code for all arm motors here.
		break;
	case 3://Manipulator
		//Insert command code for all manipulator motors here.
		break;
	}
}

task joystickMacro()
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

//START competition-defined tasks and functions
void pre_auton()
{
	bStopTasksBetweenModes = true;
	bDisplayCompetitionStatusOnLcd = false;

	const int autonCount=5; //$tag:var

	clearLCDLine(0);
	clearLCDLine(1);

	while (bIfiRobotDisabled)//Loop while the robot is disabled (not running under autonomous code or driver control)
	{
		displayLCDString(1, 0, "<<");
		displayLCDString(1, 14, ">>");
		switch(auton){//Insert LCD display code for names of autonomous subroutines here
		case 1: //Red - Left
			displayLCDCenteredString(0, "Red - Left");
			break;
		case 2: //Red - Right
			displayLCDCenteredString(0, "Red - Right");
			break;
		case 3: //Blue - Left
			displayLCDCenteredString(0, "Blue - Left");
			break;
		case 4: //Blue - Right
			displayLCDCenteredString(0, "Blue - Right");
			break;
		case 5: //Worst case scenario
			displayLCDCenteredString(0, "WCS");
			break;
		}
		if (nLCDButtons==1){//Change the selected subroutine (left)
			while(nLCDButtons==1){}//Prevent the program from changing the selection multiple times on a single press
			auton--;
			if(auton<=0){
				auton=autonCount;
			}
		}else if (nLCDButtons==4){//Change the selected subroutine (right)
			while(nLCDButtons==4){}//Prevent the program from changing the selection multiple times on a single press
			auton++;
			if(auton>autonCount){
				auton=1;
			}
		}
	}
}

task autonomous()
{
	clearLCDLine(0);
	clearLCDLine(1);

	switch(auton){
	case 1: //Red - Left
		//subroutine code here
		break;
	case 2: //Red - Right
		//subroutine code here
		break;
	case 3: //Blue - Left
		//subroutine code here
		break;
	case 4: //Blue - Right
		//subroutine code here
		break;
	case 5: //Worst-case scenario
		//subroutine code here
		break;
	}
	while(bIfiAutonomousMode){} //Stop autonomous code from looping after it has run once
}

task usercontrol()
{
	startTask(joystickMacro);
	int userControlChassisMode=1; //$tag:var
	const int userControlChassisModeCount=1; //$tag:var
	while (true)
	{
		switch(userControlChassisMode)
		{
		case 1://Tank control
			//Insert joystick tank control code here.
			break;
		}
		if (vexRT[Btn6D]==1){//Rotate between control modes
			while(vexRT[Btn6D]==1){}
			userControlChassisMode--;
			if(userControlChassisMode<=0){
				userControlChassisMode=userControlChassisModeCount;
			}
		}
		else if (vexRT[Btn6U]==1){//Rotate between control modes
			while(vexRT[Btn6U]==1){}
			userControlChassisMode++;
			if(userControlChassisMode>userControlChassisModeCount){
				userControlChassisMode=1;
			}
		}

		if (vexRT[Btn7U]==1){//Manual triggering of the OTF recalibration routine
			while (vexRT[Btn7U]==1){}
			calJoy();
		}
	}
}
