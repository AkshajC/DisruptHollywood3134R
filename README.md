INSTRUCTIONS FOR ANYONE WHO WANTS TO WORK ON AUTON:

Project Setup:
Install VS Code and in vs code search up Pros extension and download it (search online if you need help)

On the homepage of vs code click clone Git repository and copy and paste this link: https://github.com/AkshajC/3134RVexOverUnder

Project Format:
On the window on the side there is a list of files and folders click on src
You can find all the names of the motors and pistons along w/ what ports theyre on in botinit.cpp
Once in src click on autons and you'll see a function called disrupt_autonomous:
You can spin a motor at a certain velocity by setting the name of the motor = speed;
Example:
intake = 127; //motor speed is on a scale of -127 to 127
You can activate and deactivate pistons by doing name_of_piston.set_value()
Example:
blocker.set_value(true);
or
blocker.set_value(false);
You can wait time with pros::delay(time);
Example:
pros::delay(400); //time is in ms
there are 3 different functions for controlling the drive:
Use moveToPose(when u need to arrive at a point w/ a curve so if u start at (x, y, heading) = (0, 0, 0) and want to end up at (20, 20, 40) or (20, 20, 40)
and don't care too much about speed this is a very good option
chassis.moveToPose()
        /**
         * @brief Move the chassis towards the target pose
         *
         * Uses the boomerang controller
         *
         * @param x x location
         * @param y y location
         * @param theta target heading in degrees.
         * @param timeout longest time the robot can spend moving
         * @param forwards whether the robot should move forwards or backwards. true for forwards (default),
         * false for backwards
         * @param chasePower higher values make the robot move faster but causes more overshoot on turns. 0
         * makes it default to global value
         * @param lead the lead parameter. Determines how curved the robot will move. 0.6 by default (0 < lead <
         * 1)
         * @param maxSpeed the maximum speed the robot can move at. 127 at default
         * @param async whether the function should be run asynchronously. true by default
         */
        void moveToPose(float x, float y, float theta, int timeout, bool forwards = true, float chasePower = 0,
                        float lead = 0.6, float maxSpeed = 127, bool async = true);

example:
chassis.moveToPose(-30, -40, 90, 3000, true, 0, 0.6, 127, true);
Notes:
the first true change to false if the back of the robot is facing the path the bot should take
3000 is the max wait time for very large movements that may take over 3 seconds increase time
dont change 0 and 0.6 theyre complicated constants I have to explain in person
127 is max speed, lower it to go slower
true means the movement is automatically asynchronous so if u write smth like intake = 127; below the intake will
start running as the movement starts. if u set it to false it will run after the movement is completed

moveToPoint() is the next one its essentially a simpler version of moveToPose where if ur at (x,y) (0, 0) and want
to go to (10, 20) youll go there and end facing the point. it is faster movement btw. Every straight line movement should
be done w/ this
        /**
         * @brief Move the chassis towards a target point
         *
         * @param x x location
         * @param y y location
         * @param timeout longest time the robot can spend moving
         * @param maxSpeed the maximum speed the robot can move at. 127 by default
         * @param async whether the function should be run asynchronously. true by default
         */
        void moveToPoint(float x, float y, int timeout, bool forwards = true, float maxSpeed = 127, bool async = true);
Example:
chassis.moveToPoint(0, 10, 3000, true, 127, true);
These are overlapping parameters w/ last func

turnTo()
use turnTo to turn the robot in place to face a point
        /**
         * @brief Turn the chassis so it is facing the target point
         *
         * The PID logging id is "angularPID"
         *
         * @param x x location
         * @param y y location
         * @param timeout longest time the robot can spend moving
         * @param forwards whether the robot should turn to face the point with the front of the robot. true by
         * default
         * @param maxSpeed the maximum speed the robot can turn at. Default is 127
         * @param async whether the function should be run asynchronously. true by default
         */
        void turnTo(float x, float y, int timeout, bool forwards = true, float maxSpeed = 127, bool async = true);
again same parameters, but make forward false if u want back of bot to face point
Also u can comment the code that is already in the code in disrupt autonomous by highlighting and pressing cmd + click.
void disrupt_autonomous(){
  blocker.set_value(true);
	intake=127;
	chassis.moveToPose(-30, -40, 90, 3000, false, 0, 0.4, 127, true);
	intake=-127;
	chassis.moveToPoint(0, -40, 3000, false);
}

For further information reference these tutorials/docs:

https://pros.cs.purdue.edu/v5/api/index.html
https://github.com/LemLib/LemLib/blob/v0.5.0-rc4/docs/tutorials/4_auto_and_tuning.md
https://lemlib.github.io/LemLib/annotated.html
