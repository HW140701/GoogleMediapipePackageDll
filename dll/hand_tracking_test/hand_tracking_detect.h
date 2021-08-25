#ifndef HAND_TRACKING_DETECT_H
#define HAND_TRACKING_DETECT_H

#include <cstdlib>
#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "mediapipe/framework/calculator_framework.h"
#include "mediapipe/framework/formats/image_frame.h"
#include "mediapipe/framework/formats/image_frame_opencv.h"
#include "mediapipe/framework/port/file_helpers.h"
#include "mediapipe/framework/port/opencv_highgui_inc.h"
#include "mediapipe/framework/port/opencv_imgproc_inc.h"
#include "mediapipe/framework/port/opencv_video_inc.h"
#include "mediapipe/framework/port/parse_text_proto.h"
#include "mediapipe/framework/port/status.h"

#include "mediapipe/framework/formats/detection.pb.h"
#include "mediapipe/framework/formats/landmark.pb.h"
#include "mediapipe/framework/formats/rect.pb.h"

#include "hand_tracking_data.h"


namespace GoogleMediapipeHandTrackingDetect {

	typedef void(*LandmarksCallBack)(int image_index,PoseInfo* infos, int count);
	typedef void(*GestureResultCallBack)(int image_index, int* recogn_result, int count);

	class HandTrackingDetect
	{
	public:
		HandTrackingDetect();
		virtual ~HandTrackingDetect();

	public:
		int InitGraph(const char* model_path);
		int RegisterLandmarksCallback(LandmarksCallBack func);
		int RegisterGestureResultCallBack(GestureResultCallBack func);
		int DetectFrame(int image_index, int image_width, int image_height, void* image_data);
		int DetectFrame_Direct(int image_width, int image_height, void* image_data,GestureRecognitionResult& gesture_result);
		int DetectVideo(const char* video_path, int show_image);
		int Release();

	private:
		absl::Status Mediapipe_InitGraph(const char* model_path);

		absl::Status Mediapipe_RunMPPGraph(int image_index, int image_width, int image_height, void* image_data);

		absl::Status Mediapipe_RunMPPGraph_Direct(int image_width, int image_height, void* image_data, GestureRecognitionResult& gesture_result);

		absl::Status Mediapipe_RunMPPGraph(const char* video_path, int show_image);

		absl::Status Mediapipe_ReleaseGraph();


	private:
		bool m_bIsInit;
		bool m_bIsRelease;

		const char* m_kInputStream;
		const char* m_kOutputStream;
		const char* m_kWindowName;
		const char* m_kOutputLandmarks;

		LandmarksCallBack m_LandmarksCallBackFunc;
		GestureResultCallBack m_GestureResultCallBackFunc;

		mediapipe::CalculatorGraph m_Graph;

		std::unique_ptr<mediapipe::OutputStreamPoller> m_pPoller;
		std::unique_ptr<mediapipe::OutputStreamPoller> m_pPoller_landmarks;

	};

}


#endif // HAND_TRACKING_DETECT_H
