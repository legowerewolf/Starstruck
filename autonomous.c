int auton = 1;

void pre_auton()
{
	bStopTasksBetweenModes = true;
	bDisplayCompetitionStatusOnLcd = false;

	const int autonCount=6; //$tag:var

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
	case 5: //Programming skills
		//subroutine code here
		break;
	case 6: //Worst-case scenario
		//subroutine code here
		break;
	}
	while(bIfiAutonomousMode){} //Stop autonomous code from looping after it has run once
}
