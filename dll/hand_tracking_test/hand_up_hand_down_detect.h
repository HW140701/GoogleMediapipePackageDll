#ifndef HAND_UP_HAND_DOWN_DETECT_H
#define HAND_UP_HAND_DOWN_DETECT_H

#include "hand_tracking_data.h"

#include <vector>

namespace GoogleMediapipeHandTrackingDetect {
	class HandUpHandDownDetect
	{
	public:
		HandUpHandDownDetect();
		virtual~HandUpHandDownDetect();

	public:
		int DetectHandUpOrHandDown(const std::vector<PoseInfo>& single_hand_joint_vector,int origin_image_height);
	};
}


#endif // !HAND_UP_HAND_DOWN_DETECT_H
