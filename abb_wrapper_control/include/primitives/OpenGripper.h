/* OPEN GRIPPER - opens the gripper (: */

// Basic includes
#include <ros/service.h>

// ROS Service and Message Includes
#include "std_srvs/SetBool.h"

// Custom Includes
#include "Abb_client.h"

class OpenGripper {

    /// public variables and functions ------------------------------------------------------------
	public:
		OpenGripper(AbbClient abb_client);
        ~OpenGripper();

        std_srvs::SetBool operator()();

	/// private variables -------------------------------------------------------------------------
	private:
        AbbClient abb_client;

};