/* PLAN AND EXECUTE POSE - plans and executes pose (: */

// Basic includes
#include "ros/ros.h"
#include <ros/service.h>

// ROS Service and Message Includes
#include "std_srvs/SetBool.h"
#include <geometry_msgs/Pose.h>

// Custom Includes
#include "Abb_client.h"

class PlanAndExecuteSlerp {

    /// public variables and functions ------------------------------------------------------------
	public:
		PlanAndExecuteSlerp(AbbClient abb_client, trajectory_msgs::JointTrajectory tmp_traj_arm, ros::Duration waiting_time);
        ~PlanAndExecuteSlerp();

        std_srvs::SetBool operator()(geometry_msgs::Pose& pose, bool is_relative);

	/// private variables -------------------------------------------------------------------------
	private:
        AbbClient abb_client;
        trajectory_msgs::JointTrajectory tmp_traj_arm;
        ros::Duration waiting_time;

};