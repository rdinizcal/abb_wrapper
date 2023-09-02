/* Grasp Skill - [description]
Authors: author1, author2, author3
Email: name@domain.com, name@domain.com, name@domain.com  */

#include "primitives/OpenGripper.h"
#include "primitives/CloseGripper.h"
#include "skills/GraspSkill.h"

GraspSkill::GraspSkill(AbbClient abb_client){
    this->abb_client = abb_client;
}

std_srvs::SetBool GraspSkill::operator()(){
    std_srvs::SetBool resp;
    
    open_gripper = OpenGripper(this->abb_client);
    close_gripper = CloseGripper(this->abb_client);
    
    try {
        this->check_precondition();
        open_gripper(); // guarantees that the gripper is open
        resp = close_gripper();
        this->check_postcondition();
        resp.success = true;
    } catch (...) {
        resp.success = false;
    }

    return resp;
}

bool check_precondition(){
    // here we can check the pose of the object to be picked is the correct one
    // we can also check whether the orientation of the gripper is the correct one
    // we must throw an exception in case it is not!
    return true;
}

bool check_postcondition(){
    return true;
}