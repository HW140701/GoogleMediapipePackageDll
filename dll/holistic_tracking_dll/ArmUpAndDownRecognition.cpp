#include "ArmUpAndDownRecognition.h"

GoogleMediapipeDetect::ArmUpAndDownRecognition::ArmUpAndDownRecognition()
{

}

GoogleMediapipeDetect::ArmUpAndDownRecognition::~ArmUpAndDownRecognition()
{

}

int GoogleMediapipeDetect::ArmUpAndDownRecognition::RecognizeProcess(const std::vector<Point2D>& pose_joint_points)
{
	if (pose_joint_points.size() != 33)
		return ArmUpDown::NoResult;

	Point2D left_elbow = pose_joint_points[13];
	Point2D right_elbow = pose_joint_points[14];

	Point2D left_wrist = pose_joint_points[15];
	Point2D right_wrist = pose_joint_points[16];

	if (left_wrist.y > left_elbow.y && right_wrist.y > left_elbow.y)
	{
		return ArmUpDown::ArmDown;
	}
	else if (left_wrist.y < left_elbow.y && right_wrist.y < left_elbow.y)
	{
		return ArmUpDown::ArmUp;
	}
	else
	{
		return ArmUpDown::NoResult;
	}
}