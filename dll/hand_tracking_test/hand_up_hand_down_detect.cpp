#include "hand_up_hand_down_detect.h"

GoogleMediapipeHandTrackingDetect::HandUpHandDownDetect::HandUpHandDownDetect()
{

}


GoogleMediapipeHandTrackingDetect::HandUpHandDownDetect::~HandUpHandDownDetect()
{

}


int GoogleMediapipeHandTrackingDetect::HandUpHandDownDetect::DetectHandUpOrHandDown(const std::vector<PoseInfo>& single_hand_joint_vector, int origin_image_height)
{
	int result = -1;

	if (single_hand_joint_vector.size() != 21)
		return result;
	

	int wrist_y = single_hand_joint_vector[0].y;
	int middle_finger_tip_y = single_hand_joint_vector[12].y;
	int diff_y = middle_finger_tip_y - wrist_y;

	int half_origin_image_height = origin_image_height / 2;


	if (diff_y > 0)
	{
		if (wrist_y > half_origin_image_height)
		{
			return HandUp_HandDown::HandDown;
		}
		else
		{
			return HandUp_HandDown::HandUp;
		}
	}
	else
	{
		return HandUp_HandDown::HandUp;
	}
	//if (fabs(origin_image_height - wrist_y) > (origin_image_height / 3))
	//{
	//	return HandUp_HandDown::HandUp;
	//}
	//else
	//{
	//	return HandUp_HandDown::HandDown;
	//}

	return result;

}