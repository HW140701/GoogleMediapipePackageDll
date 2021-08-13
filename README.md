# Google_Mediapipe_Hand_Tracking_dll

# 1 项目简介

将Google Mediapipe中的手部追踪与识别功能封装成动态链接库，通过调用该库可以在桌面应用程序中进行手势识别以及得到手部关节坐标点。



# 2 项目组织

- dll文件夹包含了用于生成动态链接库的头文件、源文件、以及Bazel编译项目文件；
- dll_use_example包含一个Visual Studio 2019项目工程，主要是演示如何使用上述编译的动态链接库；

