#include <iostream> 
#include <opencv2/core/core.hpp> 
#include<opencv2/highgui/highgui.hpp> 
#include <opencv2/opencv.hpp>

#include "DynamicModuleLoader.h"

using namespace cv;
using namespace std;
using namespace DynamicModuleLoaderSpace;


struct PoseInfo {
	float x;
	float y;
};
struct GestureRecognitionResult
{
	int m_Gesture_Recognition_Result[2] = { -1,-1 };
	int m_HandUp_HandDown_Detect_Result[2] = { -1,-1 };
};

typedef void(*LandmarksCallBack)(int image_index, PoseInfo* infos, int count);
typedef void(*GestureResultCallBack)(int image_index, int* recogn_result, int count);



typedef int (*Func_Mediapipe_Hand_Tracking_Init)(const char* model_path);
typedef int (*Func_Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback)(LandmarksCallBack func);
typedef int (*Func_Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback)(GestureResultCallBack func);
typedef int (*Func_Mediapipe_Hand_Tracking_Detect_Frame)(int image_index, int image_width, int image_height, void* image_data);
typedef int (*Func_Mediapipe_Hand_Tracking_Detect_Frame_Direct)(int image_width, int image_height, void* image_data, GestureRecognitionResult& gesture_result);
typedef int (*Func_Mediapipe_Hand_Tracking_Detect_Video)(const char* video_path, int show_image);
typedef int (*Func_Mediapipe_Hand_Tracking_Release)();


std::string GetGestureResult(int result)
{
	std::string result_str = "未知手势";
	switch (result)
	{
	case 1:
		result_str = "One";
		break;
	case 2:
		result_str = "Two";
		break;
	case 3:
		result_str = "Three";
		break;
	case 4:
		result_str = "Four";
		break;
	case 5:
		result_str = "Five";
		break;
	case 6:
		result_str = "Six";
		break;
	case 7:
		result_str = "ThumbUp";
		break;
	case 8:
		result_str = "Ok";
		break;
	case 9:
		result_str = "Fist";
		break;

	default:
		break;
	}

	return result_str;
}

std::string GetHandUpHandDownResult(int result)
{
	std::string result_str = "未知";
	switch (result)
	{
	case -1:
		result_str = "未知";
		break;
	case 1:
		result_str = "手臂抬起";
		break;
	case 2:
		result_str = "手臂放下";
		break;

	default:
		break;
	}

	return result_str;
}

void LandmarksCallBackImpl(int image_index, PoseInfo* infos, int count)
{
	std::cout << "image_index：" << image_index << std::endl;
	std::cout << "hand joint num：" << count << std::endl;
	//for (int i = 0; i < count; ++i)
	//{
	//	float x = infos[i].x;
	//	float y = infos[i].y;

	//	//std::cout << "x=" << x << "," << "y=" << y << endl;
	//}
}

void GestureResultCallBackImpl(int image_index, int* recogn_result, int count)
{
	std::cout << "image_index：" << image_index << std::endl;
	for (int i = 0; i < count; ++i)
	{
		std::cout << "第" << i << "只手的识别结果为：" << GetGestureResult(recogn_result[i]) <<std::endl;
	}
}


int main()
{
	Func_Mediapipe_Hand_Tracking_Init Mediapipe_Hand_Tracking_Init = nullptr;
	Func_Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback = nullptr;
	Func_Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback = nullptr;
	Func_Mediapipe_Hand_Tracking_Detect_Frame Mediapipe_Hand_Tracking_Detect_Frame = nullptr;
	Func_Mediapipe_Hand_Tracking_Detect_Frame_Direct Mediapipe_Hand_Tracking_Detect_Frame_Direct = nullptr;
	Func_Mediapipe_Hand_Tracking_Detect_Video Mediapipe_Hand_Tracking_Detect_Video = nullptr;
	Func_Mediapipe_Hand_Tracking_Release Mediapipe_Hand_Tracking_Release = nullptr;

	DynamicModuleLoader dllLoader;

#ifdef _DEBUG
	std::string dll_path = ".././bin/Mediapipe_Hand_Tracking_Test/x64/Debug/Mediapipe_Hand_Tracking.dll";
#else
	std::string dll_path = "./Mediapipe_Hand_Tracking.dll";
#endif // DEBUG

	if(dllLoader.IsFileExist(dll_path))
	{
		std::cout << "dll存在" << std::endl;

		if (dllLoader.LoadDynamicModule(dll_path))
		{
			std::cout << "dll加载成功！" << std::endl;

			// 获取Mediapipe_Hand_Tracking_Init
			void* p_Mediapipe_Hand_Tracking_Init = dllLoader.GetFunction("Mediapipe_Hand_Tracking_Init");
			if (p_Mediapipe_Hand_Tracking_Init != nullptr)
			{
				Mediapipe_Hand_Tracking_Init = (Func_Mediapipe_Hand_Tracking_Init(p_Mediapipe_Hand_Tracking_Init));
				if (Mediapipe_Hand_Tracking_Init != nullptr)
				{
					std::cout << "Mediapipe_Hand_Tracking_Init获取成功" << std::endl;
				}

			}
			else
			{
				std::cout << "无法在dll中找到Mediapipe_Hand_Tracking_Init" << std::endl;
			}

			// 获取Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback
			void* p_Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback = dllLoader.GetFunction("Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback");
			if (p_Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback != nullptr)
			{
				Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback = (Func_Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback(p_Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback));
				if (Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback != nullptr)
				{
					std::cout << "Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback获取成功" << std::endl;
				}
			}
			else
			{
				std::cout << "无法在dll中找到Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback" << std::endl;
			}

			// 获取Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback
			void* p_Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback = dllLoader.GetFunction("Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback");
			if (p_Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback != nullptr)
			{
				Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback = (Func_Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback(p_Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback));
				if (Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback != nullptr)
				{
					std::cout << "Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback获取成功" << std::endl;
				}
			}
			else
			{
				std::cout << "无法在dll中找到Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback" << std::endl;
			}

			// 获取Mediapipe_Hand_Tracking_Detect_Frame
			void* p_Mediapipe_Hand_Tracking_Detect_Frame = dllLoader.GetFunction("Mediapipe_Hand_Tracking_Detect_Frame");
			if (p_Mediapipe_Hand_Tracking_Detect_Frame != nullptr)
			{
				Mediapipe_Hand_Tracking_Detect_Frame = (Func_Mediapipe_Hand_Tracking_Detect_Frame(p_Mediapipe_Hand_Tracking_Detect_Frame));
				if (Mediapipe_Hand_Tracking_Detect_Frame != nullptr)
				{
					std::cout << "Mediapipe_Hand_Tracking_Detect_Frame获取成功" << std::endl;
				}
			}
			else
			{
				std::cout << "无法在dll中找到Mediapipe_Hand_Tracking_Detect_Frame" << std::endl;
			}

			//获取Mediapipe_Hand_Tracking_Detect_Frame_Direct
			void* p_Mediapipe_Hand_Tracking_Detect_Frame_Direct = dllLoader.GetFunction("Mediapipe_Hand_Tracking_Detect_Frame_Direct");
			if (p_Mediapipe_Hand_Tracking_Detect_Frame_Direct != nullptr)
			{
				Mediapipe_Hand_Tracking_Detect_Frame_Direct = (Func_Mediapipe_Hand_Tracking_Detect_Frame_Direct)(p_Mediapipe_Hand_Tracking_Detect_Frame_Direct);
				if (Mediapipe_Hand_Tracking_Detect_Frame_Direct != nullptr)
				{
					std::cout << "Mediapipe_Hand_Tracking_Detect_Frame_Direct获取成功" << std::endl;
				}
			}
			else
			{
				std::cout << "无法在dll中找到Mediapipe_Hand_Tracking_Detect_Frame_Direct" << std::endl;
			}

			// 获取Mediapipe_Hand_Tracking_Detect_Video
			void* p_Mediapipe_Hand_Tracking_Detect_Video = dllLoader.GetFunction("Mediapipe_Hand_Tracking_Detect_Video");
			if (p_Mediapipe_Hand_Tracking_Detect_Video != nullptr)
			{
				Mediapipe_Hand_Tracking_Detect_Video = (Func_Mediapipe_Hand_Tracking_Detect_Video(p_Mediapipe_Hand_Tracking_Detect_Video));
				if (Mediapipe_Hand_Tracking_Detect_Video != nullptr)
				{
					std::cout << "Mediapipe_Hand_Tracking_Detect_Video获取成功" << std::endl;
				}
			}
			else
			{
				std::cout << "无法在dll中找到Mediapipe_Hand_Tracking_Detect_Video" << std::endl;
			}


			// 获取Mediapipe_Hand_Tracking_Release
			void* p_Mediapipe_Hand_Tracking_Release = dllLoader.GetFunction("Mediapipe_Hand_Tracking_Release");
			if (p_Mediapipe_Hand_Tracking_Release != nullptr)
			{
				Mediapipe_Hand_Tracking_Release = (Func_Mediapipe_Hand_Tracking_Release(p_Mediapipe_Hand_Tracking_Release));
				if (Mediapipe_Hand_Tracking_Release != nullptr)
				{
					std::cout << "Mediapipe_Hand_Tracking_Release获取成功" << std::endl;
				}
			}
			else
			{
				std::cout << "无法在dll中找到Mediapipe_Hand_Tracking_Release" << std::endl;
			}

		}
		else
		{
			std::cout << "dll加载失败！" << std::endl;
		}
	}
	else
	{
		std::cout << "dll不存在" << std::endl;
	}

	/* 初始化Mediapipe Hand Tracking */
#ifdef _DEBUG
	std::string mediapipe_hand_tracking_model_path = ".././bin/Mediapipe_Hand_Tracking_Test/x64/Debug/hand_tracking_desktop_live.pbtxt";
#else
	std::string mediapipe_hand_tracking_model_path = "./hand_tracking_desktop_live.pbtxt";
#endif // _DEBUG
	
	if (Mediapipe_Hand_Tracking_Init(mediapipe_hand_tracking_model_path.c_str()))
	{
		std::cout << "初始化模型成功" << std::endl;
	}
	else
	{
		std::cout << "初始化模型失败" << std::endl;
	}

	// 注册回调函数
	if (Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback(LandmarksCallBackImpl))
	{
		std::cout << "注册坐标回调函数成功" << std::endl;
	}
	else
	{
		std::cout << "注册坐标回调函数失败" << std::endl;
	}

	if (Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback(GestureResultCallBackImpl))
	{
		std::cout << "注册手势识别结果回调函数成功" << std::endl;
	}
	else
	{
		std::cout << "注册手势识别结果回调函数失败" << std::endl;
	}

	/* 1 第一种方式：传入视频路径识别视频中的手势 */

	//std::string test_video_path = "pjd-0028-Ch.mp4";
	//Mediapipe_Hand_Tracking_Detect_Video(test_video_path.c_str(), 1);


	//打开第一个摄像头
	VideoCapture cap(0);
	//判断摄像头是否打开
	if (!cap.isOpened())
	{
		cout << "摄像头未成功打开" << endl;
	}

	//创建窗口
	namedWindow("打开摄像头", 1);

	int image_index = 0;
	while (1)
	{
		//创建Mat对象
		Mat frame;
		//从cap中读取一帧存到frame中
		bool res = cap.read(frame);
		if (!res)
		{
			break;
		}

		//判断是否读取到
		if (frame.empty())
		{
			break;
		}

		//深拷贝
		Mat copyMat;
		frame.copyTo(copyMat);

		// 浅拷贝
		/*Mat copyMat;
		copyMat = frame;*/

		uchar* pImageData = copyMat.data;


		/* 2 第二种方式：传入视频帧并通过回调函数回调结果 */
		//if (Mediapipe_Hand_Tracking_Detect_Frame(image_index, copyMat.cols, copyMat.rows, (void*)pImageData))
		//{
		//	//std::cout << "Mediapipe_Hand_Tracking_Detect_Frame执行成功！" << std::endl;
		//}
		//else
		//{
		//	std::cout << "Mediapipe_Hand_Tracking_Detect_Frame执行失败！" << std::endl;
		//}

		/* 3 第三种方式：传入视频帧直接返回手势识别结果，不通过回调函数返回结果 */
		GestureRecognitionResult gestureRecognitionResult;
		if (Mediapipe_Hand_Tracking_Detect_Frame_Direct(copyMat.cols, copyMat.rows, (void*)pImageData, gestureRecognitionResult))
		{
			for (int i = 0; i < 2; ++i)
			{
				if (gestureRecognitionResult.m_Gesture_Recognition_Result[i] != -1)
				{
					std::cout << "第" << i << "只手的手势识别结果为：" << GetGestureResult(gestureRecognitionResult.m_Gesture_Recognition_Result[i]) << std::endl;
				}

				if (gestureRecognitionResult.m_HandUp_HandDown_Detect_Result[i] != -1)
				{
					std::cout << "第" << i << "只手的抬手放手识别结果为：" << GetHandUpHandDownResult(gestureRecognitionResult.m_HandUp_HandDown_Detect_Result[i]) << std::endl;
				}
			}

		}
		else
		{
			std::cout << "Mediapipe_Hand_Tracking_Detect_Frame_Direct执行失败！" << std::endl;
		}


		//显示摄像头读取到的图像
		imshow("打开摄像头", frame);
		//等待1毫秒，如果按键则退出循环
		if (waitKey(1) >= 0)
		{
			break;
		}

		image_index += 1;
	}

	if (Mediapipe_Hand_Tracking_Release())
	{
		std::cout << "Mediapipe释放成功！" << std::endl;
	}
	else
	{
		std::cout << "Mediapipe释放失败！" << std::endl;
	}


	cap.release();
	cv::destroyAllWindows();

	dllLoader.UnloadDynamicModule();

	getchar();

	return 0;
}