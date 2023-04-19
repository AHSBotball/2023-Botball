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
    while (gmpc(3)<1900)
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
            set_servo_position(2, 1950); // close the claw
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

            set_servo_position(1, 1000);
            msleep(500); //delay as to not have to much momentum when dropping the noodle
            set_servo_position(2, 1000);//drop the noodle
            msleep(500);
            set_servo_position(1, 600); //lift the claw back up to prepare to get another noodle
            msleep(500);
            
            //get poms after this
            
            cmpc(0);
            while(gmpc(0) < 2100) //trun around towards line of poms
            {
                motor(0, 100);
                motor(3, -100);
            }
            ao();
            while(analog(1) < 3700) //go forwards until line is seen
            {
                motor(0, 100);
                motor(3, 100);
            }
            msleep(100);
            ao();
            
            cmpc(0); //turn left towards line
            while(gmpc(0) < 2400)
            {
                motor(0, 100);
                motor(3, -50);
            }
            ao();
            
            //line follower
            if(analog(1) < 3700) //not on line
            {
                motor(0, 20);
                motor(3, 80);
            }
            else
            {
                motor(0, 100);
                motor(3, 100);
            }
            
            msleep(1000);
            return 0;
            
            
            cmpc(0);
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
            
            //cmpc(3); //turn left towards line
            while(analog(1) < 2100)
            {
                motor(3, 100);
            }
            ao();
            
            //enter robot into loop where it does a line follwing until it is close to noodle
            
            if(analog(0) < 2900) //if proximity sensor far
            {
                motor(0, 100);
                motor(3, 100);
            }
            //grab the noodle again
            printf("0");
            msleep(1100);// pause 
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
            msleep(1000);
            ao();
                
            msleep(500); //wait a bit

            set_servo_position(1, 1000);
            msleep(500); //delay as to not have to much momentum when dropping the noodle
            set_servo_position(2, 1000);//drop the noodle
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
