void motorGroupControl(float groupSelect = 0, int speed = 0, int direction = 0, int distance = -1){
	int clawTolerance = 100;
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
	case 1://Chassis - move
		motor[chassisLeftFront] = sinDegrees(direction+45) * speed;
		motor[chassisLeftRear] = cosDegrees(direction+45) * speed;
		motor[chassisRightFront] = cosDegrees(direction+45) * speed;
		motor[chassisRightRear] = sinDegrees(direction+45) * speed;
		break;
	case 1.1://Chassis - rotate
		motor[chassisLeftFront]=speed;
		motor[chassisLeftRear]=speed;
		motor[chassisRightFront]=-speed;
		motor[chassisRightRear]=-speed;
		break;
	case 2://Arm
		motor[armLeft1] = speed;
		motor[armLeft2] = speed;
		motor[armRight1] = speed;
		motor[armRight2] = speed;
		break;
	case 3://Manipulator
		//motor[clawLeft] = speed;
		//motor[clawRight] = speed;

		if (speed>0){
			if (SensorValue[clawLeftAngle]-SensorValue[clawRightAngle]<-clawTolerance){
				motor[clawLeft] = speed;
				motor[clawRight] = 0;
			}
			else if (SensorValue[clawLeftAngle]-SensorValue[clawRightAngle]>clawTolerance){
				motor[clawLeft] = 0;
				motor[clawRight] = speed;
			}
			else {
				motor[clawLeft] = speed;
				motor[clawRight] = speed;
			}
		}
		else if (speed <0){
			if (SensorValue[clawLeftAngle]-SensorValue[clawRightAngle]<-clawTolerance){
				motor[clawLeft] = 0;
				motor[clawRight] = speed;
			}
			else if (SensorValue[clawLeftAngle]-SensorValue[clawRightAngle]>clawTolerance){
				motor[clawLeft] = speed;
				motor[clawRight] = 0;
			}
			else {
				motor[clawLeft] = speed;
				motor[clawRight] = speed;
			}
		}
		else {
			motor[clawLeft] = speed;
			motor[clawRight] = speed;
		}

		break;
	}
}
void setClawAngle(int angle = 0){ // angle is between 0 and 180.
}
