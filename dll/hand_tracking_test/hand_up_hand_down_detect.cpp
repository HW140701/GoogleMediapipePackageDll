#include "hand_up_hand_down_detect.h"

GoogleMediapipeHandTrackingDetect::HandUpHandDownDetect::HandUpHandDownDetect()
{

}


GoogleMediapipeHandTrackingDetect::HandUpHandDownDetect::~HandUpHandDownDetect()
{

}


int GoogleMediapipeHandTrackingDetect::HandUpHandDownDetect::DetectHandUpOrHandDown(const std::vector<PoseInfo>& single_hand_joint_vector, int origin_image_height)
{
	if (single_hand_joint_vector.size() != 21)
		return -1;

	int result = -1;

	int wrist_y = single_hand_joint_vector[0].y;

	if (fabs(origin_image_height - wrist_y) > (origin_image_height / 3))
	{
		return HandUp_HandDown::HandUp;
	}
	else
	{
		return HandUp_HandDown::HandDown;
	}

}