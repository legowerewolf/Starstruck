task usercontrol()
{
	startTask(joystickMacro);

	int userControlChassisMode=2; //$tag:var
	const int userControlChassisModeCount=2; //$tag:var

	while (true)
	{
		switch(userControlChassisMode)
		{
		case 1://Tank control
			motor[chassisLeftFront] = joyCh3;
			motor[chassisLeftRear] = joyCh3;
			motor[chassisRightFront] = joyCh2;
			motor[chassisRightRear] = joyCh2;
			break;
		case 2://Arcade control
			motor[chassisLeftFront] = joyCh2 + joyCh4 + joyCh1;
			motor[chassisLeftRear] = joyCh2 + joyCh4 - joyCh1;
			motor[chassisRightFront] = joyCh2 - joyCh4 - joyCh1;
			motor[chassisRightRear]= joyCh2 - joyCh4 + joyCh1;
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

		if (vexRT[Btn8U] == 1){motorGroupControl(2.0, 127);}
		else if (vexRT[Btn8D] == 1){motorGroupControl(2.0, -127);}
		else{motorGroupControl(2.0);}

		if (vexRT[Btn8L] == 1){motorGroupControl(3.0, 127);}
		else if (vexRT[Btn8R] == 1){motorGroupControl(3.0, -127);}
		else{motorGroupControl(3.0);}

		if (vexRT[Btn7U]==1){//Manual triggering of the OTF recalibration routine
			while (vexRT[Btn7U]==1){}
			calJoy();
		}
		EndTimeSlice();
	}
}
