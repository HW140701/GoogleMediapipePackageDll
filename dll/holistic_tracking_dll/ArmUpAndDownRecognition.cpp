#include "ArmUpAndDownRecognition.h"

GoogleMediapipeDetect::ArmUpAndDownRecognition::ArmUpAndDownRecognition()
{

}

GoogleMediapipeDetect::ArmUpAndDownRecognition::~ArmUpAndDownRecognition()
{

}

bool GoogleMediapipeDetect::ArmUpAndDownRecognition::RecognizeProcess(const std::vector<Point2D>& pose_joint_points, int& left_arm_result, int& right_arm_result)
{
	if (pose_joint_points.size() != 33)
		return false;

	Point2D left_elbow = pose_joint_points[13];
	Point2D right_elbow = pose_joint_points[14];

	Point2D left_wrist = pose_joint_points[15];
	Point2D right_wrist = pose_joint_points[16];

	// ¼ì²â×óÊÖ
	if (left_wrist.y > left_elbow.y)
	{
		left_arm_result = (int)ArmUpDown::ArmDown;
	}
	else if (left_wrist.y < left_elbow.y)
	{
		left_arm_result = (int)ArmUpDown::ArmUp;
	}
	else
	{
		left_arm_result = (int)ArmUpDown::NoResult;
	}

	// ¼ì²âÓÒÊÖ
	if (right_wrist.y > left_elbow.y)
	{
		right_arm_result = ArmUpDown::ArmDown;
	}
	else if (right_wrist.y < left_elbow.y)
	{
		right_arm_result = ArmUpDown::ArmUp;
	}
	else
	{
		right_arm_result = ArmUpDown::NoResult;
	}

	return true;
}