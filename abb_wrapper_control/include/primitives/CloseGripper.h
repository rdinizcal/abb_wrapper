/* CLOSE GRIPPER - closes the gripper (: */

// Basic includes
#include <ros/service.h>

// ROS Service and Message Includes
#include "std_srvs/SetBool.h"

// Custom Includes
#include "Abb_client.h"

class CloseGripper {

    /// public variables and functions ------------------------------------------------------------
	public:
		CloseGripper(AbbClient abb_client);
        ~CloseGripper();

        std_srvs::SetBool operator()();

	/// private variables -------------------------------------------------------------------------
	private:
        AbbClient abb_client;

};