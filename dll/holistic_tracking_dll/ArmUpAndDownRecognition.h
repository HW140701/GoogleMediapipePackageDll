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
		int RecognizeProcess(const std::vector<Point2D>& pose_joint_points);
	};
}

#endif // !ARM_UP_AND_DOWN_RECOGNITION_H
