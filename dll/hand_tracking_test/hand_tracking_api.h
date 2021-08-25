#ifndef HAND_TRACKING_API_H
#define HAND_TRACKING_API_H

#define EXPORT

/* 定义动态链接库dll的导出 */
#include <malloc.h>
#ifdef _WIN32
	#ifdef EXPORT
		#define EXPORT_API __declspec(dllexport)
	#else
		#define EXPORT_API __declspec(dllimport)
	#endif
#else
#include <stdlib.h>

	#ifdef EXPORT
		#define EXPORT_API __attribute__((visibility ("default")))
	#else
	#endif

#endif


struct PoseInfo;
struct GestureRecognitionResult;


/*
@brief 回调手势坐标点回调函数
@param[out] image_index 视频帧索引
@param[out] infos 存储坐标点数据的一维数组
@param[out] count 数组长度，坐标点数量
*/
typedef void(*LandmarksCallBack)(int image_index, PoseInfo* infos, int count);

/*
@brief 回调手势识别结果回调函数
@param[out] image_index 视频帧索引
@param[out] recogn_result 存储手势识别结果的一维数组
@param[out] count 数组长度，识别结果数量
*/
typedef void(*GestureResultCallBack)(int image_index, int* recogn_result, int count);



#ifdef __cplusplus
extern "C" {
#endif 

#ifndef EXPORT_API
#define EXPORT_API
#endif

	/*
	@brief 初始化Google Mediapipe
	@param[in] model_path 需要加载的模型路径
	@return 返回操作成功或者失败
		0 失败
		1 成功
	*/
	EXPORT_API int Mediapipe_Hand_Tracking_Init(const char* model_path);


	/*
	@brief 注册回调手势坐标点的回调函数
	@param func 回调函数指针
	@return 返回操作成功或者失败
		0 失败
		1 成功
	*/
	EXPORT_API int Mediapipe_Hand_Tracking_Reigeter_Landmarks_Callback(LandmarksCallBack func);


	/*
	@brief 注册手势识别结果的回调函数
	@param func 回调函数指针
	@return 返回操作成功或者失败
		0 失败
		1 成功
	*/
	EXPORT_API int Mediapipe_Hand_Tracking_Register_Gesture_Result_Callback(GestureResultCallBack func);


	/*
	@brief 检测视频帧
	@param[in] image_index 视频帧索引号
	@param[in] image_width 视频帧宽度
	@param[in] image_height 视频帧高度
	@param[in] image_data 视频帧数据
	@return 返回操作成功或者失败
		0 失败
		1 成功
	*/
	EXPORT_API int Mediapipe_Hand_Tracking_Detect_Frame(int image_index, int image_width, int image_height, void* image_data);

	/*
	@brief 检测视频帧
	@param[in] image_width 视频帧宽度
	@param[in] image_height 视频帧高度
	@param[in] image_data 视频帧数据
	@param[out] gesture_result - 手势识别结果
	@return 返回操作成功或者失败
		0 失败
		1 成功
	*/
	EXPORT_API int Mediapipe_Hand_Tracking_Detect_Frame_Direct(int image_width, int image_height, void* image_data ,GestureRecognitionResult& gesture_result);


	/*
	@brief 检测视频
	@param[in] video_path 视频路径
	@param[in] show_image 是否显示结果视频
	@return 返回操作成功或者失败
		0 失败
		1 成功
	*/
	EXPORT_API int Mediapipe_Hand_Tracking_Detect_Video(const char* video_path, int show_image);


	/*
	@brief Google Mediapipe释放
	@return 返回操作成功或者失败
		0 失败
		1 成功
	*/
	EXPORT_API int Mediapipe_Hand_Tracking_Release();


#ifdef __cplusplus
}
#endif 



#endif // !HAND_TRACKING_API_H
