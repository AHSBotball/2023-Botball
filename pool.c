#include <kipr/wombat.h>

int main()
{
    wait_for_light(3);
    shut_down_in(115);
	
    msleep(5000); //delay for icreate to start
	
    cmpc(3); 
    enable_servo(1);
    enable_servo(2);
    set_servo_position(1,600);
    set_servo_position(2, 1600);
   
        while (gmpc(3)<1720) // goes forward a bit 
        {
            motor(0,100);
            motor(3,100);
        }
    ao();
    msleep(1000); // pause for a bit
    
    cmpc(3);
    while (gmpc(3)<4200)
    {
        motor(3,100); // turn 270 deg
    }
    ao();
    msleep(1000);
    
    while(digital(0) == 0) // will always equal 0
    { 
        if(analog(0) > 2900) //if proximity sensor close 
        {
            msleep(400);// pause 
            ao();
            msleep(2000);
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
            while(gmpc(3) < 2250)
            {
                motor(0, -100);
                motor(3, 100);
            }
            ao(); 
            
            motor(0, 100); //go forward towards data center
            motor(3, 100);
            msleep(1500);
            ao();

                
            msleep(1000);

            set_servo_position(1, 750);
            msleep(200);
            set_servo_position(2, 1000);//drop the noodle
            msleep(500);
            
            cmpc(3); //turn around (again)
            while(gmpc(3) < 2000)
            {
                motor(0, -100);
                motor(3, 100);
            }
            ao(); 
            
            //get the poms GET THE POMS POOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOMS or noodles again
        }
        else
        {
            motor(0, 100);
            motor(3, 100);
        }
		
	}
    return 0;
}
