#include <kipr/wombat.h>

int main()
{
    //wait_for_light(1);
    shut_down_in(120);
    
    create_connect();
    enable_servos();
    set_servo_position(1, 1200);
    set_servo_position(0, 500);
    
    create_drive_direct(75,75);
    msleep(1000);
    
    create_drive_direct(-75,75);
    msleep(1200);
    
    create_drive_direct(-75,-75);
    msleep(1000);
    
    enable_servos();    
    set_servo_position(1, 800);   
    
    create_drive_direct(-500,500);
    msleep(1500);
    
    create_drive_direct(-75,75);
    msleep(4100);
        
    create_drive_direct(-75,-75);
    msleep(3000);
    
    enable_servos();
    set_servo_position(0, 300);
    
    create_drive_direct(75,75);
    msleep(2000);
    
    enable_servos();
    set_servo_position(0, 500);
    
    create_disconnect();
    create_stop();
    disable_servos();
    return 0;
}
