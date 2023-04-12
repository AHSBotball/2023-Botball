#include <kipr/wombat.h>

int main()
{
    wait_for_light(3);
    shut_down_in(100);
	
    msleep(5000); //delay for icreate to start
	
    cmpc(3); 
    enable_servo(1);
    enable_servo(2);
    set_servo_position(1,600);
    set_servo_position(2, 1600);
    
    //START of movement
    cmpc(3);
    while (gmpc(3)<1500)
    {
        motor(3,100); //go forward a lil bit
        motor(0,100);
    } 
    ao();
    msleep(100);
    
    cmpc(3);
    while (gmpc(3)<2080)
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
            msleep(350);// pause 
            ao();
            msleep(500);
            set_servo_position(2, 2000); // close the claw
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
            motor(0, 100); //go forward towards data center
            motor(3, 100);
            msleep(1500);
            ao();

                
            msleep(500); //wait a bit

            set_servo_position(1, 750);
            msleep(500); //delay as to not have to much momentum when dropping the noodle
            set_servo_position(2, 1000);//drop the noodle
            msleep(500);
            set_servo_position(1, 600); //lift the claw back up to prepare to get another noodle
            msleep(500);
            
            cmpc(0); //NOTHING WORKS PAST HERE
            //NOTHING WORKS PAST HERE
            //NOTHING WORKS PAST HERE
            
            while(gmpc(0) < 1000)
            {
                motor(3, -100); //turn left
                motor(0, 100);
            }
            ao();
            msleep(100); //pause for a bit
            
            motor(0, 100);
            motor(3, 50);
            msleep(500);
            
            //go back to get the noodles NEW CODE AS OF 4/12/23
            
            while (analog(2) < 3700)
            {
                motor(0, 100); //move forwards until line is seen
                motor(3, 100);
            }
			ao();
            msleep(100);
            
            cmpc(0); //turn left towards line
            while(gmpc(0) < 1500)
            {
                motor(3, -100);
                motor(0, 100);
            }
            ao();
            
            //enter robot into loop where it does a line follwing until it is close to noodle
            
            if(analog(0) < 2900) //if proximity sensor far
            {
                if(analog(2) < 3700) //if robot not on line 
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
                  
        }
        else
        {
            motor(0, 100);
            motor(3, 100);
        }
		
	}
    return 0;
}
