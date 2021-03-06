/**
 * @file turtle_control.cpp
 * @brief The implementation file for TurtleControl
 */

#include "turtle_control.h"

const float GOAL_RAD = .5;
const int RAND_RANGE = 1000;
const int MAX_XY = 10;

float get_rand() 
{
    return ((rand() % RAND_RANGE)/static_cast<float>(RAND_RANGE));
}

TurtleControl::TurtleControl()
{
    //This stuff is to spawn a random turtle called pose.  To access its messages you will use pose/topic
    //Seed the rng
    srand(time(NULL));
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("spawn");

    //Build the service request
    turtlesim::Spawn srv;
    srv.request.name = "goal";
    srv.request.x = get_rand() * MAX_XY;
    srv.request.y = get_rand() * MAX_XY;
    srv.request.theta = (rand() % 2*3.14) - 3.14;
    client.waitForExistence();
    client.call(srv);

    //This sets up the subscribers
    //This will set up a subscriber for your turtles pose
    pose_sub = nh.subscribe<turtlesim::Pose>("turtle1/pose", 1, &TurtleControl::poseCallback, this);
    //This sets up a subscriber for the goals pose
    goal_pose_sub = nh.subscribe<turtlesim::Pose>("goal/pose", 1, &TurtleControl::goalPoseCallback, this);

    //This will publish twist messages to your turtle
    /*
     * FILL IN PARAMETERS HERE
     */
    //twist_pub = nh.advertise<geometry_msgs::Twist>();
}

void TurtleControl::poseCallback(const turtlesim::Pose::ConstPtr& msg)
{
    //This will get the information that from your turtle
    //more information: http://docs.ros.org/api/turtlesim/html/msg/Pose.html
    pose = *msg;
}

void TurtleControl::goalPoseCallback(const turtlesim::Pose::ConstPtr& msg)
{
    //Code to get goal position here
}

void TurtleControl::update()
{
    geometry_msgs::Twist turtle_twist;
    //Code to create a twist message and publish it here

    //Check if you are already next to the goal

    //Figure out if you are facing the goal, if not turn by modifying turtle_twist.angular.z

    //Once you are facing the target drive straight until you are within the GOAL_RAD
    //You can move forward by modifying turtle_twist.linear.x

    //Publish the turtle_twist to cmd_vel message
}
