#ifndef TRACKING_DATA_STRUCTURE_H
#define TRACKING_DATA_STRUCTURE_H

namespace GoogleMediapipeDetect {

	struct Point2D
	{
		float x;
		float y;
	};

	typedef Point2D Vector2D;

	enum Gesture
	{
		NoGesture = -1,
		One = 1,
		Two = 2,
		Three = 3,
		Four = 4,
		Five = 5,
		Six = 6,
		ThumbUp = 7,
		Ok = 8,
		Fist = 9
	};

	enum ArmUpDown
	{
		NoResult = -1,
		ArmUp = 1,
		ArmDown = 2
	};

}

#endif // !TRACKING_DATA_STRUCTURE_H
