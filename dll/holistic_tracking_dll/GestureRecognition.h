#ifndef GESTURE_RECOGNITION_H
#define GESTURE_RECOGNITION_H

#include <vector>
#include "GestureRecognition.h"
#include "TrackingDataStructure.h"

namespace GoogleMediapipeDetect {

	class GestureRecognition
	{
	public:
		GestureRecognition();
		virtual~GestureRecognition();

	public:
		int RecognizeProcess(const std::vector<Point2D>& single_hand_joint_points);

	private:
		float Vector2DAngle(const Vector2D& vec1, const Vector2D& vec2);
	};
}

#endif // !GESTURE_RECOGNITION_H
