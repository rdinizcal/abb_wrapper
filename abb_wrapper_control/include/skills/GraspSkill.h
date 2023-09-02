/* GRASP SKILL - skill to grasp a dice (: */

// Basic includes

// ROS Service and Message Includes
#include "std_srvs/SetBool.h"
#include <geometry_msgs/Pose.h>

// Custom Includes
#include "Abb_client.h"

class GraspSkill {

    /// public variables and functions ------------------------------------------------------------
	public:
		GraspSkill(AbbClient abb_client, trajectory_msgs::JointTrajectory tmp_traj_arm, ros::Duration waiting_time);
        ~GraspSkill();

        std_srvs::SetBool operator()(geometry_msgs::Pose& pose);
        bool check_precondition();
        bool check_postcondition();

	/// private variables -------------------------------------------------------------------------
	private:
        AbbClient abb_client;
        trajectory_msgs::JointTrajectory tmp_traj_arm;
        ros::Duration waiting_time;

};