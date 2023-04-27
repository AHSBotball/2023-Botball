#include <kipr/wombat.h>

void turn(int side, int value, int lSpeed, int rSpeed) //create a function to make turns
{
    cmpc(side);
    while(gmpc(side) < value)
    {
        motor(0, rSpeed);
        motor(3, lSpeed);
    }
    ao();
}

void grabNoodle()
{
    set_servo_position(2, 2000); // close the claw
    msleep(500);
    set_servo_position(1, 0); //lift the noodle
    msleep(1500);
}

void dropNoodle()
{
	set_servo_position(1, 1200);
    msleep(500); //delay as to not have to much momentum when dropping the noodle
    set_servo_position(2, 1200);//drop the noodle
    msleep(500);
    set_servo_position(1, 600); //lift the claw back up to prepare to get another noodle
    msleep(500);
}



int main()
{
    //wait_for_light(3);
    shut_down_in(100);
	
    cmpc(3); 
    enable_servo(1);
    enable_servo(2);
    set_servo_position(1,650);
    set_servo_position(2, 1000);
    
    msleep(500); //delay
    
    //START of movement
	while(analog(1) < 3700)
    {
        motor(0, 100);
        motor(3, 100);
    }
    msleep(150);
    ao();
    
    msleep(100);
    
    turn(3, 2000, 80, -80); //turn around to get the first noodle

    ao();
    msleep(100);
    
    while(digital(0) == 0) // will always equal 0
    { 
        if(analog(0) > 2800) //if proximity sensor close 
        {
            msleep(450);// pause 
            ao();
            msleep(400);
            grabNoodle();
            
            motor(0, -100); //back up a bit b4 turning around
            motor(3, -100);
            msleep(100);
            ao();
            msleep(100);
            
			//turn around
            
            turn(3, 2300, 100, -100);
            
            msleep(100);
			//go forwards towards data center
            motor(0, 100);
            motor(3, 100);
            msleep(2300);
            ao();
                
            msleep(500); //wait a bit
            
            //DROP THE NOODLE
            
            dropNoodle();
            
            turn(0, 740, -100, 100); //turn to face the line

            msleep(100); //pause for a bit
            
            
            while (analog(1) < 3700)
            {
                motor(0, 100); //move forwards until line is seen
                motor(3, 100);
            }
			ao();
            msleep(300);
            
            turn(0, 2400, 0, 100);    //turn left towards noodle

            //go forwards towards the noodle
            
            while(analog(0) < 2800) //if proximity sensor far
            {
                ao();
                if(analog(1) > 3600) //line follower
                {
                    motor(0, 30); //if on line go forwards but a little right
                    motor(3, 50);
                }
                else
                {
                    motor(0, 50); //if not on line go forwards but a little left
                    motor(3, 30);
                }
            }
            //grab the noodle again
            printf("0");
            msleep(100);// pause to get closer to noodle
            motor(0, 50);
            motor(3, 50);
            msleep(1000);
            ao();
            msleep(400);
			grabNoodle();
            
            //DROP IT OFF (AGAIN)
            
            motor(0, -100); //back up a bit b4 turning around
            motor(3, -100);
            msleep(100);
            ao();
            msleep(100);
            
			//turn around
            
            turn(3, 2450, 100, -100);
            msleep(100);
            
			//go forwards towards data center
            motor(0, 100);
            motor(3, 100);
            msleep(2000);
            ao();
                
            msleep(500); //wait a bit

			dropNoodle();
            
            //GET THRID ONE AFTER THIS
            //return 0; //uncomment this line to stop code after second noodle is gotten
                     
            turn(0, 2600, -20, 100); //turn left towards line
            
            msleep(100); //take a little break
            
            while (analog(1) < 3700)
            {
                motor(0, 100); //move forwards until line is seen
                motor(3, 100);
            }
            msleep(400);
            ao();
            msleep(100);
			//turn left towards final noodle
			turn(0, 2100, 0, 100);
            
            while(analog(0) < 2800) //if proximity sensor far
            {
                ao();
                if(analog(1) > 3600) //line follower
                {
                    motor(0, 30); //if on line go forwards but a little right
                    motor(3, 50);
                }
                else
                {
                    motor(0, 50); //if not on line go forwards but a little left
                    motor(3, 30);
                }
            }
            ao();
            motor(3, 50);
            msleep(1200);// pause to get closer to noodle
            ao();
            msleep(400);
			grabNoodle();
            
            motor(0, -100); //back up a bit b4 turning around
            motor(3, -100);
            msleep(100);
            ao();
            msleep(100);
            
			//turn around
            
            turn(3, 2400, 100, -100);
            msleep(100);
            
			//go forwards towards data center
            motor(0, 100);
            motor(3, 100);
            msleep(2000);
            ao();
                
            msleep(500); //wait a bit

			dropNoodle();
            
            return 0;
        }
        else
        {
            motor(0, 100);
            motor(3, 100);
        }
		
	}

    return 0;
}

