/* Open Gripper Primitive - [description]
Authors: author1, author2, author3
Email: name@domain.com, name@domain.com, name@domain.com  */

#include "primitives/OpenGripper.h"

OpenGripper::OpenGripper(AbbClient abb_client){
    this->abb_client = abb_client;
}

std_srvs::SetBool OpenGripper::operator()(){

    std_srvs::SetBool set_bool_srv;

    if(!this->abb_client.call_opening_gripper(true)){
        ROS_ERROR("Could not open the gripper.");
        set_bool_srv.response.success = false;
        set_bool_srv.response.message = "The service call_opening_gripper was NOT performed correctly!";
    } 

    return set_bool_srv;
}