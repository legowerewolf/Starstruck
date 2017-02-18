int auton = 1;

void pre_auton()
{
	bStopTasksBetweenModes = true;
	bDisplayCompetitionStatusOnLcd = false;

	const int autonCount=6; //$tag:var

	SensorType[in8] = sensorNone;
	wait1Msec(1000);
	SensorType[in8] = sensorGyro;
	wait1Msec(2000);

	clearLCDLine(0);
	clearLCDLine(1);

	resetMotorEncoder(chassisLeftFront);
	resetMotorEncoder(chassisLeftRear);
	resetMotorEncoder(chassisRightFront);
	resetMotorEncoder(chassisRightRear);

	while (bIfiRobotDisabled)//Loop while the robot is disabled (not running under autonomous code or driver control)
	{
		displayLCDString(1, 0, "<<");
		displayLCDString(1, 14, ">>");
		switch(auton){//Insert LCD display code for names of autonomous subroutines here
		case 1: //Left 1
			displayLCDCenteredString(0, "Left 1");
			break;
		case 2: //Left 2
			displayLCDCenteredString(0, "Left 2");
			break;
		case 3: //Blue - Left
			displayLCDCenteredString(0, "Right 1");
			break;
		case 4: //Blue - Right
			displayLCDCenteredString(0, "Right 2");
			break;
		case 5: //Programming Skills
			displayLCDCenteredString(0, "Skills");
			break;
		case 6: //Worst case scenario
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
	clearTimer(T1);
	switch(auton){
	case 1: //Left 1
		//subroutine code here
		// BEFORE ENCODER USAGE
		motorGroupControl(1.0, 127, 180);
		wait1Msec(2000);
		motorGroupControl(1.0, 127, 270);
		wait1Msec(1250);
		motorGroupControl(1.0, 127, 0);
		wait1Msec(500);
		motorGroupControl(1.0);
		motorGroupControl(3, -127);
		wait1Msec(2000);
		motorGroupControl(3);
		motorGroupControl(2, -127);
		motorGroupControl(1, 127, 180);
		wait1Msec(500);
		motorGroupControl(1);
		wait1Msec(1000);
		motorGroupControl(2);
		wait1Msec(500);
		motorGroupControl(3, 127);
		wait1Msec(500);
		break;
	case 2: //Left 2
		//subroutine code here
		motorGroupControl(1.0, 127, 180);
		wait1Msec(2000);
		motorGroupControl(1.0, 127, 270);
		wait1Msec(1250);
		motorGroupControl(1.0, 127, 0);
		wait1Msec(500);
		motorGroupControl(1.0);
		motorGroupControl(3, -127);
		wait1Msec(2000);
		motorGroupControl(3);
		motorGroupControl(2, -127);
		wait1Msec(1500);
		motorGroupControl(2);
		motorGroupControl(1, 127, 180);
		wait1Msec(500);
		motorGroupControl(1);
		motorGroupControl(3, 127);
		wait1Msec(500);
		//
		motorGroupControl(3, -127);
		motorGroupControl(2, 127);
		wait1Msec(1500);
		motorGroupControl(2);
		wait1Msec(500);
		motorGroupControl(3);
		motorGroupControl(1, 127);
		wait1Msec(2000);
		motorGroupControl(1);
		motorGroupControl(3, -127);
		wait1Msec(2000);
		motorGroupControl(3);
		break;
	case 3: //Right 1
		//subroutine code here
		motorGroupControl(1.0, 127, 180);
		wait1Msec(2000);
		motorGroupControl(1.0, 127, 90);
		wait1Msec(1500);
		motorGroupControl(1.0);
		motorGroupControl(3, -127);
		wait1Msec(2000);
		motorGroupControl(3);
		motorGroupControl(2, -127);
		wait1Msec(1500);
		motorGroupControl(2);
		motorGroupControl(1, 127, 180);
		wait1Msec(500);
		motorGroupControl(1);
		motorGroupControl(3, 127);
		wait1Msec(500);
		break;
	case 4: //Right 2
		//subroutine code here
		motorGroupControl(1.0, 127, 180);
		wait1Msec(2000);
		motorGroupControl(1.0, 127, 90);
		wait1Msec(1500);
		motorGroupControl(1.0);
		motorGroupControl(3, -127);
		wait1Msec(2000);
		motorGroupControl(3);
		motorGroupControl(2, -127);
		wait1Msec(1500);
		motorGroupControl(2);
		motorGroupControl(1, 127, 180);
		wait1Msec(500);
		motorGroupControl(1);
		motorGroupControl(3, 127);
		wait1Msec(500);
		//
		motorGroupControl(3, -127);
		motorGroupControl(2, 127);
		wait1Msec(1500);
		motorGroupControl(2);
		wait1Msec(500);
		motorGroupControl(3);
		motorGroupControl(1, 127);
		wait1Msec(2000);
		motorGroupControl(1);
		motorGroupControl(3, -127);
		wait1Msec(2000);
		motorGroupControl(3);
		break;
	case 5: //Programming skills
		//subroutine code here
		break;
	case 6: //Worst-case scenario
		//subroutine code here
		break;
	}
	//writeDebugStream("" + time1[T1]);
	displayLCDNumber(0, 0, time1[T1]);



	while(bIfiAutonomousMode){motorGroupControl();} //Stop autonomous code from looping after it has run once
}
