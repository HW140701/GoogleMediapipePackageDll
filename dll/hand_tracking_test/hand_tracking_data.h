#ifndef HAND_TRACKING_DATA_H
#define HAND_TRACKING_DATA_H

struct PoseInfo {
	float x;
	float y;
};

typedef PoseInfo Point2D;
typedef PoseInfo Vector2D;


struct GestureRecognitionResult
{
	int m_Gesture_Recognition_Result[2] = {-1,-1};
	int m_HandUp_HandDown_Detect_Result[2] = {-1,-1};
};

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

enum HandUp_HandDown
{
	NoHand = -1,
	HandUp = 1,
	HandDown = 2
};


#endif // !HAND_TRACKING_DATA_H
