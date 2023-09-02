/* MOVE TO POSE SKILL - move to a pose <geometry_msgs/Pose.h> */

// Basic includes
#include "ros/ros.h"
#include <ros/service.h>

// ROS Service and Message Includes
#include "std_srvs/SetBool.h"
#include <geometry_msgs/Pose.h>

// Custom Includes
#include "Abb_client.h"

class MoveToPoseSkill {

    /// public variables and functions ------------------------------------------------------------
	public:
		MoveToPoseSkill(AbbClient abb_client, trajectory_msgs::JointTrajectory tmp_traj_arm, ros::Duration waiting_time);
        ~MoveToPoseSkill();

        std_srvs::SetBool operator()(geometry_msgs::Pose& pose);
        bool check_precondition();
        bool check_postcondition();

	/// private variables -------------------------------------------------------------------------
	private:
        AbbClient abb_client;
        trajectory_msgs::JointTrajectory tmp_traj_arm;
        ros::Duration waiting_time;

};