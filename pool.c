#include <kipr/wombat.h>

int main()
{
    //wait_for_light(3);
    shut_down_in(100);
	
    cmpc(3); 
    enable_servo(1);
    enable_servo(2);
    set_servo_position(1,700);
    set_servo_position(2, 1000);
    
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
    while (gmpc(3)<2000)
    {
        motor(3,80); //turn around
        motor(0,-80);
    } 
    ao();
    msleep(100);
    
    while(digital(0) == 0) // will always equal 0
    { 
        if(analog(0) > 2800) //if proximity sensor close 
        {
            msleep(150);// pause 
            ao();
            msleep(400);
            set_servo_position(2, 2000); // close the claw
            msleep(500);
            set_servo_position(1, 0); //lift the noodle
            msleep(1000);
            
            motor(0, -100); //back up a bit b4 turning around
            motor(3, -100);
            msleep(100);
            ao();
            msleep(100);
            
			//turn around
            cmpc(3);
            while(gmpc(3) < 2200)
            {
                motor(0, -100);
                motor(3, 100);
            }
            ao(); 
            msleep(100);
			//go forwards towards data center
            motor(0, 100);
            motor(3, 100);
            msleep(2300);
            ao();
                
            msleep(500); //wait a bit

            set_servo_position(1, 1200);
            msleep(500); //delay as to not have to much momentum when dropping the noodle
            set_servo_position(2, 1200);//drop the noodle
            msleep(500);
            set_servo_position(1, 600); //lift the claw back up to prepare to get another noodle
            msleep(500);
            
            cmpc(0);
            
            while(gmpc(0) < 740)
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
            while(gmpc(0) < 2400)
            {
                motor(0, 100);
            }
            ao();
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
            msleep(1300);// pause to get closer to noodle
            ao();
            msleep(400);
            set_servo_position(2, 1950); // close the claw
            msleep(500);
            set_servo_position(1, 0); //lift the noodle
            msleep(1000); 
            
            //DROP IT OFF (AGAIN)
            
            motor(0, -100); //back up a bit b4 turning around
            motor(3, -100);
            msleep(100);
            ao();
            msleep(100);
            
			//turn around
            cmpc(3);
            while(gmpc(3) < 2300)
            {
                motor(0, -100);
                motor(3, 100);
            }
            ao(); 
            msleep(100);
			//go forwards towards data center
            motor(0, 100);
            motor(3, 100);
            msleep(2000);
            ao();
                
            msleep(500); //wait a bit

            set_servo_position(1, 1200);
            msleep(500); //delay as to not have to much momentum when dropping the noodle
            set_servo_position(2, 1000);//drop the noodle
            msleep(500);
            return 0;
            //more stuff can be done after this
            //this last code only takes like 20 seconds to complete
        }
        else
        {
            motor(0, 100);
            motor(3, 100);
        }
        
		
	}

    return 0;
}
