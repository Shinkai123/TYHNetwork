//
//  Camera.h
//  IOTCCamera
//
//  Created by lizhijian<lizhijian_21@163.com> on 2017/2/28.
//  Copyright © 2017年 concox. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CameraStructGroup.h"

/* Data transfer mode */
typedef enum : NSInteger {
    CONNECTION_MODE_NONE  = -1,
    CONNECTION_MODE_P2P = 0,
    CONNECTION_MODE_RELAY = 1,
    CONNECTION_MODE_LAN = 2,
} NETWORK_CONNECTION_MODE;

/* Camera connect status */
typedef enum : NSUInteger {
    CONNECTION_STATE_NONE = 0,
    CONNECTION_STATE_CONNECTING = 1,            //正在连接
    CONNECTION_STATE_CONNECTED,                 //已连接
    CONNECTION_STATE_DISCONNECTED,              //手动断开
    CONNECTION_STATE_CONNECT_FAILED,            //连接中断
    CONNECTION_STATE_UNKNOWN_DEVICE,            //设备不识别
    CONNECTION_STATE_WRONG_PASSWORD,            //密码错误
    CONNECTION_STATE_NOT_FIND_DEVICE,           //未找到设备（设备断电或未正常连接网络）
    CONNECTION_STATE_UID_INVALID,               //UID无效或过期,会自动断开连接
    
    CONNECTION_STATE_NOT_INITIALIZED,           //SDK未初始化
    CONNECTION_STATE_UID_CHECKING,              //正在检测UID的有效性
    CONNECTION_STATE_EXCEED_MAX_CHANNEL,        //Channel回话数已达到最大
    CONNECTION_STATE_CONNECT_EXCEPTION,         //内部连接异常或被异常中断
    CONNECTION_STATE_NETWORD_ANOMALY,           //网络异常，无法访问服务器（SSL校验失败）
    
    
//    CONNECTION_STATE_TIMEOUT = CONNECTION_STATE_CONNECT_FAILED,
//    CONNECTION_STATE_EXCEED_MAX_SESSION = CONNECTION_STATE_EXCEED_MAX_CHANNEL,
//    CONNECTION_STATE_UNSUPPORTED = CONNECTION_STATE_UNKNOWN_DEVICE,
} CAMERA_CONNECTION_STATE;

typedef enum : NSUInteger {
    CAMERA_EVENT_TYPE_NONE = 0,
    CAMERA_EVENT_TYPE_MOTION = 1,           //移动侦测
    CAMERA_EVENT_TYPE_HUMANOID = 3,         //人形侦测
    CAMERA_EVENT_TYPE_VOICE = 18,           //声音侦测
    CAMERA_EVENT_TYPE_VOICE_NO_VIDDEO = 19, //声音侦测没有录像
    CAMERA_EVENT_TYPE_SMS = 20,
} CAMERA_EVENT_TYPE;

//媒体文件格式列表
typedef enum : NSUInteger {
    MEDIA_FILE_CODEC_NONE       = 0,
    MEDIA_FILE_CODEC_H264       = 1,
    MEDIA_FILE_CODEC_G711       = 2,
    MEDIA_FILE_CODEC_AMR_NB     = 3,
    MEDIA_FILE_CODEC_AAC        = 4,
} MEDIA_FILE_CODEC;

@protocol CameraDelegate;
@class Monitor;
@class PanoramaMonitor;

@interface Camera : NSObject

@property (nonatomic,weak) id<CameraDelegate> delegate;
@property (readonly) NSString *name;
@property (readonly) NSString *uid;
@property (readonly) NSString *password;

@property (readonly) NETWORK_CONNECTION_MODE connectMode;   //0: P2P mode, 1: Relay mode, 2: LAN mode
@property (readonly) CAMERA_CONNECTION_STATE connectSate;
@property (readonly) NETWORK_CONNECTION_MODE sessionMode NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "Use connectMode");
@property (readonly) CAMERA_CONNECTION_STATE sessionState NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "Use connectSate");
@property (readonly) NSInteger videoCodecID;
@property (readonly) NSInteger audioCodecID;

@property (readonly) NSInteger nTimeZoneId;    //时区ID,默认243(Shanghai)
@property (readonly) NSInteger nPlatformId;    //平台ID,默认-1
@property (readonly) NSInteger nVersionNum;    //固件版本,默认0
@property (readonly) NSInteger nBatteryLevel;      //电量值(版本0~200,>100表示正在充电)
@property (readonly) NSInteger nNetworkType;       //网络类型，1:WIFI；2:3G
@property (readonly) NSInteger signalStrength;     //信号强度
@property (readonly) long long recordTime;         //直播时间戳（本地时间）
@property (readonly) NSInteger streamTag;          //0:live 1:timeline 2:timeline alarm 3:playback 4:nosdcard live
@property (readonly) BOOL isAlarming;          //是否正在报警
@property (readonly) BOOL isRecording;          //是否正在录像
@property (readonly) BOOL isImConnect;      //立即进行重连
@property (readonly) BOOL connected;   //是否已连接

#pragma mark - Public Class API


/**
 初始化SDK

 @return YES:初始化成功
 */
+ (BOOL)initSDK;

/**
 释放SDK

 @return YES:释放成功
 */
+ (BOOL)uninitSDK;

/**
 重置SDK网络状态
 #若长期退至后台需调用此接口,且Camera其他操作需延时0.5~1秒之后执行

 @return YES：成功
 */
+ (BOOL)reInitSDK;

/**
 获取SDK版本

 @return 版本："1.0.0"
 */
+ (NSString *)getVersion;

/**
 获取媒体文件的音视频文件格式
 文件必须在沙盒中
 MEDIA_FILE_CODEC
 
 @param filePath 文件路径
 @return nil读取文件错误或非音视频文件
 */
+ (NSArray<NSNumber *> *)readCodecFromMediaFile:(NSString *)filePath;

/**
 获取已初始化的设备数量

 @return 设备数量
 */
+ (NSInteger)getTotalCameraCount;

#pragma mark - Public API

/**
 初始化设备

 @param name 设备名称
 @return camera
 */
- (instancetype)initCameraByName:(NSString *)name;

/**
 连接设备

 @param uid 20位UID，若长度不是20，内部可设置UID成功，但会提示无效
 @param password 设备密码(默认88888888)
 */
- (void)connect:(NSString *)uid password:(NSString *)password;

/**
 设置设备UID（当未连接或已断开连接才能设置成功）
 
 @param uid 设备UID
 */
- (void)setUID:(NSString *)uid;

/**
 设置设备password（当设备密码未被设置时，才能设置成功）；

 @param pwd 设备密码
 */
- (void)setPassword:(NSString *)pwd;

/**
 设置重连标识

 @param isImConnect YES：立即重连；NO，不重连
 */
- (void)setIsImConnect:(BOOL)isImConnect;


/**
 设置设备在线状态

 @param connected YES：在线；NO，离线
 */
- (void)setConnected:(BOOL)connected;

/**
 将摄像机断开连接
 内部会停止摄像机相关的一切操作
 */
- (void)disconnect;

/**
 开始显示，即开始接收及解码视频数据
 #需要加载视图Monitor或PanoramaMonitor
 */
- (void)startRealtimePlay:(Monitor *)monitor;

/**
 停止显示，即停止接收及解码视频数据
 */
- (void)stopRealtimePlay;

/**
 开始报警消息视频的回放（非时间轴）
 */
- (void)startPlayRecordingVideo:(Monitor *)monitor;

/**
 停止报警消息视频的回放（非时间轴）
 */
- (void)stopPlayRecordingVideo;

/**
 开始获取时间轴数据
 
 @param date 要获取回放数据的时间点
 @param dayNum 范围，最多3天
 */
- (void)startGetTimeLineData:(NSDate *)date dayNum:(NSInteger)dayNum;

/**
 停止获取时间轴数据
 */
- (void)stopGetTimeLineData;

/**
 设备开始向手机端发送音频数据
 */
- (void)startPlaySoundFromDevice;

/**
 设备停止向手机端发送音频数据
 */
- (void)stopPlaySoundFromDevice;

/**
 开始发送音频数据给设备
 */
- (void)startPlaySoundFromApp;

/**
 停止发送音频数据给设备
 */
- (void)stopPlaySoundFromApp;

/**
 向摄像机发送IO命令
 
 @param type 命令字
 @param data 数据Buffer
 @param dataSize 数据Buffer大小
 */
- (void)sendIOCtrlWithType:(NSInteger)type data:(char *)data dataSize:(NSInteger)dataSize;

/**
 获取设备密码

 @return 密码
 */
- (NSString *)getPassword;

/**
 获取连接状态

 @return 连接状态
 */
- (CAMERA_CONNECTION_STATE)getConnectionState;

/**
 获取视频截图
 
 @return 图片Image
 */
- (UIImage *)snapshot;

/**
 直播录制MP4视频文件，文件后缀名必须为mp4，否则底层默认添加".mp4"后缀
 视频数据流：H264，音频数据流：AAC
 
 @param filePath 沙盒视频文件路径
 @param width 视频帧宽
 @param height 视频帧高
 @return 开始录制返回YES
 */
- (BOOL)startRecordingVideo:(NSString *)filePath width:(NSInteger)width height:(NSInteger)height;

/**
 获取正在录制视频的时长

 @return 时长（毫秒）
 */
- (NSInteger)getRecordingVideoDuration;

/**
 停止直播录像
 */
- (void)stopRecordingVideo;

/**
 视频转码成H264+AAC数据流文件

 @param inFilePath 视频输入路径
 @param outFilePath 视频输出路径
 @return YES：开始转码
 */
- (BOOL)startVideoConverter:(NSString *)inFilePath outFilePath:(NSString *)outFilePath;
+ (BOOL)startVideoConverter:(NSString *)inFilePath outFilePath:(NSString *)outFilePath;
+ (BOOL)startVideoForceConverter:(NSString *)inFilePath outFilePath:(NSString *)outFilePath;    //强制转码

/**
 检测手机端与设备端连接的网络信息

 @param netInfo 摄像机网络信息获取回调接口
 */
- (void)checkNetworkInfo:(void (^)(CameraNetInfo_Ex *))netInfo;

/**
 获取当前视频队列的帧数
 #一般情况请勿使用！！！
 */
- (NSInteger)getVideoFrameCount;

#pragma mark - State

/**
 开启硬件解码（默认开启）
 #车载SDK除外（默认已关闭）
 
 @param enable YES：开启
 */
- (void)setGPUDecode:(BOOL)enable;

/**
 获取硬件解码开关状态
 
 @return YES：开启
 */
- (BOOL)getGPUDecodeState;


/**
 是否需要解码(默认 YES)

 @param enable NO:会将原始视频流数据传出
 */
- (void)isNeedDecode:(BOOL)enable;


/**
 获取是否需要解码开关状态

 @return YES：开启
 */
-(BOOL)getNeedDecodeState;

/**
 是否正在监听
 
 @return YES：正在对讲
 */
- (BOOL)isPlaySoundFromDevice;

/**
 是否正在对讲
 
 @return YES：正在对讲
 */
- (BOOL)isPlaySoundFromApp;

#pragma mark - Setting custom


/**
 自定义返回接口，自用（外部无用）

 @param camera 需要返回结果只的设备
 @param dataDic 带有返回值的字典
 @param type 返回的指令值
 */
- (void)customReturnResultByDelegate:(Camera *)camera dataDic:(NSMutableDictionary *)dataDic type:(NSInteger)type;

#pragma mark - Monitor/PanoramaMonitor

/**
 标注正方形画面全景摄像机

 @param isSquarePanoramic YES:正方形画面全景摄像机
 */
- (void)setSquarePanoramic:(BOOL)isSquarePanoramic;

@end

@protocol CameraDelegate <NSObject>

@optional
/**
 设备在线状态的代理
 
 @param camera 当前Camera
 @param status 设备状态
 */
- (void)camera:(Camera *)camera didChangeConnectStatus:(CAMERA_CONNECTION_STATE)status;

/**
 设备发送命令后，设备传回的回调
 
 @param camera 当前camera
 @param type 命令类型
 @param data 传回的数据
 @param size 数据大小
 */
- (void)camera:(Camera *)camera didReceiveIOCtrlWithType:(NSInteger)type data:(const u_char *)data dataSize:(NSInteger)size;

/**
 直播时，与视频流同时传过来的视频信息，0.25秒更新一次
 
 @param camera 当前的camera
 @param videoWidth 视频的宽
 @param videoHeight 视频的高
 @param fps 视频帧率
 @param videoBps 视频码流
 @param audioBps 音频码流
 @param onlineNm 在线人数
 @param frameCount 总帧数
 @param incompleteFrameCount 丢帧次数
 */
- (void)camera:(Camera *)camera didReceiveFrameInfoWithVideoWidth:(NSInteger)videoWidth videoHeight:(NSInteger)videoHeight videoFPS:(NSInteger)fps videoBPS:(NSInteger)videoBps audioBPS:(NSInteger)audioBps onlineNm:(NSInteger)onlineNm frameCount:(NSInteger)frameCount incompleteFrameCount:(NSInteger)incompleteFrameCount;


/**
 如果选择自己解码，则返回码流

 @param camera camera
 @param videoData 视频码流
 @param size buffer大小
 */
- (void)camera:(Camera *)camera didReceiveVidoStremsData:(const u_char *)videoData size:(NSInteger)size;  //一旦代理，SDK中的视频显示控件Monitor将无效


/**
 如果选择自己解码，则返回码流

 @param camera camera
 @param audioData 音频码流
 @param size buffer大小
 @param codecId 解码器
 @param timeStamp 时间戳
 */
- (void)camera:(Camera *)camera didReceiveAudioStremsData:(const u_char *)audioData size:(NSInteger)size codecId:(NSInteger)codecId timeStamp:(NSInteger)timeStamp;

/**
 获取时间轴数据代理

 @param camera camera
 @param data 时间轴数据
 @param size 数据大小
 */
- (void)camera:(Camera *)camera didGetLiveTimeLineData:(const u_char *)data size:(NSInteger)size;

/**
 开始录像代理

 @param camera camera
 @param videoFilePath 录像保存路径
 */
- (void)camera:(Camera *)camera didStartRecordVideoWithPath:(NSString *)videoFilePath;

/**
 录像结束代理

 @param camera camera
 @param videoFilePath 录像保存路径
 */
- (void)camera:(Camera *)camera didRecordVideoWithPath:(NSString *)videoFilePath;

- (void)camera:(Camera *)camera didReceiveVideoRawDataFrame:(const u_char *)videoData videoWidth:(NSInteger)width videoHeight:(NSInteger)height;      //一旦代理，SDK中的视频显示控件Monitor将无效
- (void)camera:(Camera *)camera didReceiveVideoRawImageFrame:(UIImage *)imageFrame;     //一旦代理，SDK中的视频显示控件Monitor将无效



@end
