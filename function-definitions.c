void motorGroupControl(float groupSelect = 0, int speed = 0, int direction = 0, int distance = 0){
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
		//Insert chassis code here. Add additional chassis-control cases as "case 1.x:"
		break;
	case 2://Arm
		//Insert arm code here. Add additional arm-control cases as "case 2.x:"
		break;
	case 3://Manipulator
		//Insert manipulator code here. Add additional manipulator-control cases as "case 3.x:"
		break;
	}
}
