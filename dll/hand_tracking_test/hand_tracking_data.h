#ifndef HAND_TRACKING_DATA_H
#define HAND_TRACKING_DATA_H

struct PoseInfo {
	float x;
	float y;
};

typedef PoseInfo Point2D;
typedef PoseInfo Vector2D;


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


#endif // !HAND_TRACKING_DATA_H
