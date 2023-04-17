#include <kipr/wombat.h>

int main()
{
    //wait_for_light(3);
    shut_down_in(100);
	
    cmpc(3); 
    enable_servo(1);
    enable_servo(2);
    set_servo_position(1,666);
    set_servo_position(2, 1600);
    
    msleep(500); //delay for icreate to start
    
    //START of movement
	while(analog(1) < 3700)
    {
        motor(0, 100);
        motor(3, 100);
    }
    msleep(150);
    ao(0);
    
    msleep(100);
    
    cmpc(3);
    while (gmpc(3)<2100)
    {
        motor(3,80); //turn around
        motor(0,-80);
    } 
    ao();
    msleep(100);
    
    while(digital(0) == 0) // will always equal 0
    { 
        if(analog(0) > 2900) //if proximity sensor close 
        {
            msleep(100);// pause 
            ao();
            msleep(400);
            set_servo_position(2, 1950); // close the claw
            msleep(500);
            set_servo_position(1, 0); //lift the noodle
            msleep(1000);
            
            motor(0, -100); //back up a bit b4 turning around
            motor(3, -100);
            msleep(1000);
            ao();
            msleep(100);
            
			//turn around
            cmpc(3);
            while(gmpc(3) < 2150)
            {
                motor(0, -100);
                motor(3, 100);
            }
            ao(); 
            msleep(100);
			//go forwards towards data center
            motor(0, 100);
            motor(3, 100);
            msleep(1000);
            ao();
                
            msleep(500); //wait a bit

            set_servo_position(1, 600);
            msleep(500); //delay as to not have to much momentum when dropping the noodle
            set_servo_position(2, 1000);//drop the noodle
            msleep(500);
            set_servo_position(1, 600); //lift the claw back up to prepare to get another noodle
            msleep(500);
            
            cmpc(0); //NOTHING WORKS PAST HERE
            printf("0");
            
            while(gmpc(0) < 1000)
            {
                motor(3, -100); //turn left to face line
                motor(0, 100);
            }
            ao();
            msleep(100); //pause for a bit
            
            
            while (analog(1) < 3700)
            {
                motor(0, 100); //move forwards until line is seen
                motor(3, 100);
            }
			ao();
            msleep(300);
            
            cmpc(0); //turn left towards line
            while(gmpc(0) < 2100)
            {
                motor(0, 100);
            }
            ao();
            
            //enter robot into loop where it does a line follwing until it is close to noodle
            
            if(analog(0) < 2900) //if proximity sensor far
            {
                if(analog(1) < 3700) //if robot not on line 
                {
                    motor(3, 70); //turn right
                    motor(1, 20);
                }
                else //on line
                {
                    motor(0, 100); // go forwards
                    motor(3, 100);
                }
            }
            //grab the noodle
            msleep(100);// pause 
            ao();
            msleep(400);
            set_servo_position(2, 1950); // close the claw
            msleep(500);
            set_servo_position(1, 0); //lift the noodle
            msleep(1000);
            
                  
        }
        else
        {
            motor(0, 100);
            motor(3, 100);
        }
        
		
	}
    return 0;
}
