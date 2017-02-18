void motorGroupControl(float groupSelect = 0, int speed = 0, int angle = 0, int distance = -1, bool isSerial = true){
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
		motor[chassisLeftFront] = sinDegrees(angle+45) * speed;
		motor[chassisLeftRear] = cosDegrees(angle+45) * speed;
		motor[chassisRightFront] = cosDegrees(angle+45) * speed;
		motor[chassisRightRear] = sinDegrees(angle+45) * speed;
		break;
	case 1.1://Chassis - rotate
		motor[chassisLeftFront]=speed;
		motor[chassisLeftRear]=speed;
		motor[chassisRightFront]=speed;
		motor[chassisRightRear]=speed;
		break;
	case 2://Arm
		motor[armLeft1] = speed;
		motor[armLeft2] = speed;
		motor[armRight1] = speed;
		motor[armRight2] = speed;
		break;
	case 3://Manipulator
		motor[clawLeft] = ((speed>0)&&(SensorValue[clawLeftAngle]-SensorValue[clawRightAngle]<clawTolerance))||((speed<0)&&(SensorValue[clawLeftAngle]-SensorValue[clawRightAngle]>-clawTolerance)) ? speed : 0;
		motor[clawRight] = ((speed<0)&&(SensorValue[clawLeftAngle]-SensorValue[clawRightAngle]<clawTolerance))||((speed>0)&&(SensorValue[clawLeftAngle]-SensorValue[clawRightAngle]>-clawTolerance)) ? speed : 0;
		break;
	case 3.1: //Manipulator - angle control - angle is between 0 and 180. 0 degrees maps to ~350. 180 degrees maps to ~3450
		//The tick value is determined by (angle * 17.22) + 350
		int tickValueOfAngle = (0 <= angle && angle <= 180) ? round(angle * 17) + 350 : -1;
		speed = abs(speed);
		do {
			if (tickValueOfAngle != -1){
				motor[clawLeft] = (abs(SensorValue[clawLeftAngle] - tickValueOfAngle)>clawTolerance) ? sgn(SensorValue[clawLeftAngle] - tickValueOfAngle) * speed : 0;
				motor[clawRight] = (abs(SensorValue[clawRightAngle] - tickValueOfAngle)>clawTolerance) ? sgn(SensorValue[clawRightAngle] - tickValueOfAngle) * speed : 0;
			}
			else {
				break;
			}
		} while (isSerial && (abs(SensorValue[clawLeftAngle] - tickValueOfAngle)<=clawTolerance) && (abs(SensorValue[clawRightAngle] - tickValueOfAngle)<=clawTolerance)); //while it's running in serial mode AND it has NOT reached the completed angle
			break;
	}
}
