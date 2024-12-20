void DriveStraight(int FastSpeed, int SlowSpeed, int cts);

task mian()
{
	DriveStraight(120, 110, 800);
	resetMotorEncoder(M_Motor_Right);
	while(getMotorEncoder(M_Motor_Right) < 840 * 2.5)
	{
		motor(M_Motor_Left) = 10;
		motor(M_Motor_Right) = 110;
	}
	motor(M_Motor_Left) = 0;
	motor(M_Motor_Right) = 0;
	DriveStraight(100, 90, 1200); 
}

void DriveStraight(int FastSpeed, int SlowSpeed, int cts)
{
	resetMotorEncoder(M_Motor_Left);
	resetMotorEncoder(M_Motor_Right);
	while(getMotorEncoder(M_Motor_Left) < cts)
	{
		if(getMotorEncoder(M_Motor_Right) > getMotorEncoder(M_Motor_Left))
		{
			motor(M_Motor_Left) = FastSpeed;
			motor(M_Motor_Right) = SlowSpeed;
		}
		if(getMotorEncoder(M_Motor_Right) < getMotorEncoder(M_Motor_Left))
		{
			motor(M_Motor_Left) = SlowSpeed;
			motor(M_Motor_Right) = FastSpeed;
		}
		if(getMotorEncoder(M_Motor_Right) == getMotorEncoder(M_Motor_Left))
		{
			motor(M_Motor_Left) = SlowSpeed;
			motor(M_Motor_Right) = SlowSpeed;
		}
	}
	motor(M_Motor_Left) = 0;
	motor(M_Motor_Right) = 0;
}
