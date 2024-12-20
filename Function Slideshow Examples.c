void ExampleFunction(int NumVar, bool BoolVar);

task main()
{
  ExampleFunction(127, 1);
}

void ExampleFunction(int NumVar, bool BoolVar)
{
  if(BoolVar == 1)
  {
    motor(M_Motor_left) = NumVar;
    wait1Msec(1000);
  }
  else
  {
    motor(M_Motor_Right) = NumVar;
    wait1Msec(1000);
  }
}
