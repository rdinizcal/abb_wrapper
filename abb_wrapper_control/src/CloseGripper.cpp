/* Open Gripper Primitive - [description]
Authors: author1, author2, author3
Email: name@domain.com, name@domain.com, name@domain.com  */

#include "primitives/CloseGripper.h"

CloseGripper::CloseGripper(AbbClient abb_client){
    this->abb_client = abb_client;
}

std_srvs::SetBool CloseGripper::operator()(){

    std_srvs::SetBool set_bool_srv;

    if(!this->abb_client.call_closing_gripper(close)){
        ROS_ERROR("Could not close the gripper.");
        set_bool_srv.response.success = false;
        set_bool_srv.response.message = "The service call_closing_gripper was NOT performed correctly!";
    }  

    return set_bool_srv;
}