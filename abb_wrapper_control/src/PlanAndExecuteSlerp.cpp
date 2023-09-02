/* Plan and Execute Pose Primitive - [description]
Authors: author1, author2, author3
Email: name@domain.com, name@domain.com, name@domain.com  */

#include "primitives/PlanAndExecuteSlerp.h"

PlanAndExecuteSlerp::PlanAndExecuteSlerp(AbbClient abb_client, tmp_traj_arm, waiting_time){
    this->abb_client = abb_client;
    this->tmp_traj_arm = tmp_traj_arm;
    this->waiting_time = waiting_time;
}

std_srvs::SetBool PlanAndExecuteSlerp::operator()(geometry_msgs::Pose& pose, bool is_relative){

    std_srvs::SetBool set_bool_srv;

    // Setting zero pose as starting from present
    geometry_msgs::Pose present_pose = geometry_msgs::Pose();
    present_pose.position.x = 0.0; present_pose.position.y = 0.0; present_pose.position.z = 0.0;
    present_pose.orientation.x = 0.0; present_pose.orientation.y = 0.0; present_pose.orientation.z = 0.0; present_pose.orientation.w = 1.0;

    /* PLAN 1: Plan to POSE */

    if(!this->abb_client.call_slerp_service(pose, present_pose, is_relative, this->tmp_traj_arm, this->tmp_traj_arm)){
        ROS_ERROR("Could not plan to the specified pose.");
        set_bool_srv.response.success = false;
        set_bool_srv.response.message = "The service call_slerp_service was NOT performed correctly!";
        return set_bool_srv;
    }  

    /* EXEC 1: Going to POSE*/

    if(!this->abb_client.call_arm_control_service(this->tmp_traj_arm)){
        ROS_ERROR("Could not go to pose.");
        set_bool_srv.response.success = false;
        set_bool_srv.response.message = "The service call_arm_control_service was NOT performed correctly! Error in arm control.";
        return set_bool_srv;
    }

    /* WAIT 1: Wait to finish the task*/

    if(!this->abb_client.call_arm_wait_service(this->waiting_time)){ // WAITING FOR END EXEC
        ROS_ERROR("TIMEOUT!!! EXEC TOOK TOO MUCH TIME for going to Pre Grasp Pose");
        set_bool_srv.response.success = false;
        set_bool_srv.response.message = "The service call_arm_wait_service was NOT performed correctly! Error wait in arm control.";
        return set_bool_srv;
    }

    set_bool_srv.response.success = true;
    return set_bool_srv;
}