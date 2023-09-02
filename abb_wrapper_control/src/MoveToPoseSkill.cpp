/* Plan and Execute Pose Primitive - [description]
Authors: author1, author2, author3
Email: name@domain.com, name@domain.com, name@domain.com  */

#include "primitives/PlanAndExecutePose.h"
#include "skills/MoveToPoseSkill.h"

MoveToPoseSkill::MoveToPoseSkill(AbbClient abb_client, tmp_traj_arm, waiting_time){
    this->abb_client = abb_client;
    this->tmp_traj_arm = tmp_traj_arm;
    this->waiting_time = waiting_time;
}

std_srvs::SetBool MoveToPoseSkill::operator()(geometry_msgs::Pose& pose, bool is_relative){
    std_srvs::SetBool resp;
    
    plan_and_execute_pose = PlanAndExecutePose(this->abb_client, this->tmp_traj_arm,this->waiting_time);
    
    try {
        this->check_precondition();
        resp = plan_and_execute_pose();
        this->check_postcondition();
        resp.success = true;
    } catch (...) {
        resp.success = false;
    }

    return resp;
}

bool check_precondition(){
    return true;
}

bool check_postcondition(){
    return true;
}