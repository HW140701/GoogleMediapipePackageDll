#ifndef HAND_GESTURE_RECOGNITION_H
#define HAND_GESTURE_RECOGNITION_H

#include "hand_tracking_data.h"

#include <vector>


namespace GoogleMediapipeHandTrackingDetect {

	class HandGestureRecognition
	{
	public:
		HandGestureRecognition();
		virtual~HandGestureRecognition();

	public:
		int GestureRecognition(const std::vector<PoseInfo>& single_hand_joint_vector);

	private:
		float Vector2DAngle(const Vector2D& vec1, const Vector2D& vec2);

	};

}


#endif // !HAND_GESTURE_RECOGNITION_H
