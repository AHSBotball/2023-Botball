#include <kipr/wombat.h>

int main()
{
    enable_servo(1);
    enable_servo(2);
    set_servo_position(1, 0);
    set_servo_position(2, 1400);
    
    while(digital(0) == 0)
    {
        if(analog(2) < 1500)
        {
            //light
            while(digital(1) == 0)
            {
                while(analog(1) < 3900)
                {
                    printf("blind");
                    motor(0, 50);
                    motor(3, 50);
                }
                
                //after seeing line
                msleep(750);
                printf("LINE");
                ao();
                
   				clear_motor_position_counter(0);
    			clear_motor_position_counter(3);
    
   				while(get_motor_position_counter(0) > -850)
    			{
        			motor(0, -100);
        			motor(3, 100);
    			}
                //RIGHT TURN
                ao();
                msleep(700);//AFTER THE TURN
                
                motor(0, 72);
                motor(3, 70);
                msleep(7000);
                ao();
                return 0;                
            }
        }
        else
        {
            msleep(100);
        }
    }
    msleep(1000);
    return 0;
}
