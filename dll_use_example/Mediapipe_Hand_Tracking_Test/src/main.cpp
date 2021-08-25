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
	std::string result_str = "δ֪����";
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
	std::string result_str = "δ֪";
	switch (result)
	{
	case -1:
		result_str = "δ֪";
		break;
	case 1:
		result_str = "�ֱ�̧��";
		break;
	case 2:
		result_str = "�ֱ۷���";
		break;

	default:
		break;
	}

	return result_str;
}

void LandmarksCallBackImpl(int image_index, PoseInfo* infos, int count)
{
	std::cout << "image_index��" << image_index << std::endl;
	std::cout << "hand joint num��" << count << std::endl;
	//for (int i = 0; i < count; ++i)
	//{
	//	float x = infos[i].x;
	//	float y = infos[i].y;

	//	//std::cout << "x=" << x << "," << "y=" << y << endl;
	//}
}

void GestureResultCallBackImpl(int image_index, int* recogn_result, int count)
{
	std::cout << "image_index��" << image_index << std::endl;
	for (int i = 0; i < count; ++i)
	{
		std::cout << "��" << i << "ֻ�ֵ�ʶ����Ϊ��" << GetGestureResult(recogn_result[i]) <<std::endl;
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
		std::cout << "dll����" << std::endl;

		if (dllLoader.LoadDynamicModule(dll_path))
		{
			std::cout << "dll���سɹ���" << std::endl;

			// ��ȡMediapipe_Hand_Tracking_Init
			void* p_Mediapipe_Hand_Tracking_Init = dllLoader.GetFunction("Mediapipe_Hand_Tracking_Init");
			if (p_Mediapipe_Hand_Tracking_Init != nullptr)
			{
				Mediapipe_Hand_Tracking_Init = (Func_Mediapipe_Hand_Tracking_Init(p_Mediapipe_Hand_Tracking_Init));
				if (Mediapipe_Hand_Tracking_Init != nullptr)
				{
					std::cout << "Mediapipe_Hand_Tracking_Init��ȡ�ɹ�" << std::endl;
				}

			}
			else
			{
				std::cout << "�޷���dll���ҵ�Mediapipe_Hand_Tracking_Init" << std::endl;
			}

			// ��ȡMediapipe_Hand_Tracking_Reigeter_Landmarks_Callback
			void* p_Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback = dllLoader.GetFunction("Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback");
			if (p_Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback != nullptr)
			{
				Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback = (Func_Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback(p_Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback));
				if (Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback != nullptr)
				{
					std::cout << "Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback��ȡ�ɹ�" << std::endl;
				}
			}
			else
			{
				std::cout << "�޷���dll���ҵ�Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback" << std::endl;
			}

			// ��ȡMediapipe_Hand_Tracking_Register_Gesture_Result_Callback
			void* p_Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback = dllLoader.GetFunction("Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback");
			if (p_Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback != nullptr)
			{
				Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback = (Func_Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback(p_Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback));
				if (Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback != nullptr)
				{
					std::cout << "Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback��ȡ�ɹ�" << std::endl;
				}
			}
			else
			{
				std::cout << "�޷���dll���ҵ�Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback" << std::endl;
			}

			// ��ȡMediapipe_Hand_Tracking_Detect_Frame
			void* p_Mediapipe_Hand_Tracking_Detect_Frame = dllLoader.GetFunction("Mediapipe_Hand_Tracking_Detect_Frame");
			if (p_Mediapipe_Hand_Tracking_Detect_Frame != nullptr)
			{
				Mediapipe_Hand_Tracking_Detect_Frame = (Func_Mediapipe_Hand_Tracking_Detect_Frame(p_Mediapipe_Hand_Tracking_Detect_Frame));
				if (Mediapipe_Hand_Tracking_Detect_Frame != nullptr)
				{
					std::cout << "Mediapipe_Hand_Tracking_Detect_Frame��ȡ�ɹ�" << std::endl;
				}
			}
			else
			{
				std::cout << "�޷���dll���ҵ�Mediapipe_Hand_Tracking_Detect_Frame" << std::endl;
			}

			//��ȡMediapipe_Hand_Tracking_Detect_Frame_Direct
			void* p_Mediapipe_Hand_Tracking_Detect_Frame_Direct = dllLoader.GetFunction("Mediapipe_Hand_Tracking_Detect_Frame_Direct");
			if (p_Mediapipe_Hand_Tracking_Detect_Frame_Direct != nullptr)
			{
				Mediapipe_Hand_Tracking_Detect_Frame_Direct = (Func_Mediapipe_Hand_Tracking_Detect_Frame_Direct)(p_Mediapipe_Hand_Tracking_Detect_Frame_Direct);
				if (Mediapipe_Hand_Tracking_Detect_Frame_Direct != nullptr)
				{
					std::cout << "Mediapipe_Hand_Tracking_Detect_Frame_Direct��ȡ�ɹ�" << std::endl;
				}
			}
			else
			{
				std::cout << "�޷���dll���ҵ�Mediapipe_Hand_Tracking_Detect_Frame_Direct" << std::endl;
			}

			// ��ȡMediapipe_Hand_Tracking_Detect_Video
			void* p_Mediapipe_Hand_Tracking_Detect_Video = dllLoader.GetFunction("Mediapipe_Hand_Tracking_Detect_Video");
			if (p_Mediapipe_Hand_Tracking_Detect_Video != nullptr)
			{
				Mediapipe_Hand_Tracking_Detect_Video = (Func_Mediapipe_Hand_Tracking_Detect_Video(p_Mediapipe_Hand_Tracking_Detect_Video));
				if (Mediapipe_Hand_Tracking_Detect_Video != nullptr)
				{
					std::cout << "Mediapipe_Hand_Tracking_Detect_Video��ȡ�ɹ�" << std::endl;
				}
			}
			else
			{
				std::cout << "�޷���dll���ҵ�Mediapipe_Hand_Tracking_Detect_Video" << std::endl;
			}


			// ��ȡMediapipe_Hand_Tracking_Release
			void* p_Mediapipe_Hand_Tracking_Release = dllLoader.GetFunction("Mediapipe_Hand_Tracking_Release");
			if (p_Mediapipe_Hand_Tracking_Release != nullptr)
			{
				Mediapipe_Hand_Tracking_Release = (Func_Mediapipe_Hand_Tracking_Release(p_Mediapipe_Hand_Tracking_Release));
				if (Mediapipe_Hand_Tracking_Release != nullptr)
				{
					std::cout << "Mediapipe_Hand_Tracking_Release��ȡ�ɹ�" << std::endl;
				}
			}
			else
			{
				std::cout << "�޷���dll���ҵ�Mediapipe_Hand_Tracking_Release" << std::endl;
			}

		}
		else
		{
			std::cout << "dll����ʧ�ܣ�" << std::endl;
		}
	}
	else
	{
		std::cout << "dll������" << std::endl;
	}

	/* ��ʼ��Mediapipe Hand Tracking */
#ifdef _DEBUG
	std::string mediapipe_hand_tracking_model_path = ".././bin/Mediapipe_Hand_Tracking_Test/x64/Debug/hand_tracking_desktop_live.pbtxt";
#else
	std::string mediapipe_hand_tracking_model_path = "./hand_tracking_desktop_live.pbtxt";
#endif // _DEBUG
	
	if (Mediapipe_Hand_Tracking_Init(mediapipe_hand_tracking_model_path.c_str()))
	{
		std::cout << "��ʼ��ģ�ͳɹ�" << std::endl;
	}
	else
	{
		std::cout << "��ʼ��ģ��ʧ��" << std::endl;
	}

	// ע��ص�����
	if (Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback(LandmarksCallBackImpl))
	{
		std::cout << "ע������ص������ɹ�" << std::endl;
	}
	else
	{
		std::cout << "ע������ص�����ʧ��" << std::endl;
	}

	if (Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback(GestureResultCallBackImpl))
	{
		std::cout << "ע������ʶ�����ص������ɹ�" << std::endl;
	}
	else
	{
		std::cout << "ע������ʶ�����ص�����ʧ��" << std::endl;
	}

	/* 1 ��һ�ַ�ʽ��������Ƶ·��ʶ����Ƶ�е����� */

	//std::string test_video_path = "pjd-0028-Ch.mp4";
	//Mediapipe_Hand_Tracking_Detect_Video(test_video_path.c_str(), 1);


	//�򿪵�һ������ͷ
	VideoCapture cap(0);
	//�ж�����ͷ�Ƿ��
	if (!cap.isOpened())
	{
		cout << "����ͷδ�ɹ���" << endl;
	}

	//��������
	namedWindow("������ͷ", 1);

	int image_index = 0;
	while (1)
	{
		//����Mat����
		Mat frame;
		//��cap�ж�ȡһ֡�浽frame��
		bool res = cap.read(frame);
		if (!res)
		{
			break;
		}

		//�ж��Ƿ��ȡ��
		if (frame.empty())
		{
			break;
		}

		//���
		Mat copyMat;
		frame.copyTo(copyMat);

		// ǳ����
		/*Mat copyMat;
		copyMat = frame;*/

		uchar* pImageData = copyMat.data;


		/* 2 �ڶ��ַ�ʽ��������Ƶ֡��ͨ���ص������ص���� */
		//if (Mediapipe_Hand_Tracking_Detect_Frame(image_index, copyMat.cols, copyMat.rows, (void*)pImageData))
		//{
		//	//std::cout << "Mediapipe_Hand_Tracking_Detect_Frameִ�гɹ���" << std::endl;
		//}
		//else
		//{
		//	std::cout << "Mediapipe_Hand_Tracking_Detect_Frameִ��ʧ�ܣ�" << std::endl;
		//}

		/* 3 �����ַ�ʽ��������Ƶֱ֡�ӷ�������ʶ��������ͨ���ص��������ؽ�� */
		GestureRecognitionResult gestureRecognitionResult;
		if (Mediapipe_Hand_Tracking_Detect_Frame_Direct(copyMat.cols, copyMat.rows, (void*)pImageData, gestureRecognitionResult))
		{
			for (int i = 0; i < 2; ++i)
			{
				if (gestureRecognitionResult.m_Gesture_Recognition_Result[i] != -1)
				{
					std::cout << "��" << i << "ֻ�ֵ�����ʶ����Ϊ��" << GetGestureResult(gestureRecognitionResult.m_Gesture_Recognition_Result[i]) << std::endl;
				}

				if (gestureRecognitionResult.m_HandUp_HandDown_Detect_Result[i] != -1)
				{
					std::cout << "��" << i << "ֻ�ֵ�̧�ַ���ʶ����Ϊ��" << GetHandUpHandDownResult(gestureRecognitionResult.m_HandUp_HandDown_Detect_Result[i]) << std::endl;
				}
			}

		}
		else
		{
			std::cout << "Mediapipe_Hand_Tracking_Detect_Frame_Directִ��ʧ�ܣ�" << std::endl;
		}


		//��ʾ����ͷ��ȡ����ͼ��
		imshow("������ͷ", frame);
		//�ȴ�1���룬����������˳�ѭ��
		if (waitKey(1) >= 0)
		{
			break;
		}

		image_index += 1;
	}

	if (Mediapipe_Hand_Tracking_Release())
	{
		std::cout << "Mediapipe�ͷųɹ���" << std::endl;
	}
	else
	{
		std::cout << "Mediapipe�ͷ�ʧ�ܣ�" << std::endl;
	}


	cap.release();
	cv::destroyAllWindows();

	dllLoader.UnloadDynamicModule();

	getchar();

	return 0;
}