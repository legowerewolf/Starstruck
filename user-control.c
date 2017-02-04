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
			//Insert tank-style control code here
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
		EndTimeSlice();
	}
}
