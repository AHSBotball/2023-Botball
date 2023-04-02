#include <kipr/wombat.h>

int main()
{
    wait_for_light(2);
    shut_down_in(115);
	
    msleep(5000); //delay for icreate to start
	
    cmpc(3); 
    enable_servo(1);
    enable_servo(2);
    set_servo_position(1,550);
    set_servo_position(2, 1600);
   
        while (gmpc(3)<1720) // goes forward a bit 
        {
            motor(0,100);
            motor(3,100);
        }
    ao();
    msleep(1000); // pause for a bit
    
    cmpc(3);
    while (gmpc(3)<4125)
    {
        motor(3,100); // turn 270 deg
    }
    ao();
    msleep(1000);
    
       while(digital(0) == 0) // will always equal 0
    { 
        if(analog(0) > 2900) //if proximity sensor close 
        {
            msleep(500); // pause 
            ao();
            msleep(2000);
            set_servo_position(2, 2000); // close the claw
            msleep(500);
            set_servo_position(1, 0); //lift the noodle
            msleep(1000);
            
            motor(0, -100); //go backwards
            motor(3, -100);
            msleep(2500);
                
            set_servo_position(1, 750); 
            msleep(1000);
            cmpc(3);
            while(gmpc(3) > -1000)
            {
                motor(0, 100);
                motor(3, -100);
            }//make a turn
            ao(); //stop after the turn
            
            set_servo_position(2, 1000);//drop the noodle
            msleep(500);
            
            while(gmpc(3) < -310)
            {
                motor(0, -100);
                motor(3, 100);
            }
            ao();
            
            //get the poms GET THE POMS POOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOMS
		
	    ////VERY VERY VERY VERY UNFISHED AND NEEDS FURTHER TESTING AND PROGRAMMING
            if(analog(1) > 3600)
            {
                msleep(500); //move for a little bit to get the sensor centered on the line
                ao(); //stop moving
            }
            else
            {
                motor(0, 70); //move when not seeing black line
                motor(3, 70);
            }
            //after hitting line
            cmpc(3);
            while(gmpc(3) < 850)
            {
                motor(0, 100);
                motor(3, -100);
            }
            ao();//after the turn
            
            msleep(100);
            motor(0, 50);
            motor(3, 50); // placeholder code for a line follower
            
          }
        else
        {
            motor(0, 70);
            motor(3, 70);
        }
	}
    return 0;
}
