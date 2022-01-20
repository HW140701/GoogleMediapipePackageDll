#ifndef ARM_UP_AND_DOWN_RECOGNITION_H
#define ARM_UP_AND_DOWN_RECOGNITION_H

#include <vector>

#include "TrackingDataStructure.h"

namespace GoogleMediapipeDetect {
	class ArmUpAndDownRecognition 
	{
	public:
		ArmUpAndDownRecognition();
		virtual~ArmUpAndDownRecognition();

	public:
		bool RecognizeProcess(const std::vector<Point2D>& pose_joint_points,int& left_arm_result,int& right_arm_result);
	};
}

#endif // !ARM_UP_AND_DOWN_RECOGNITION_H
