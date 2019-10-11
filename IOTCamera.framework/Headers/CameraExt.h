//
//  CameraExt.h
//  IOTCamera
//
//  Created by lizhijian on 2017/3/2.
//  Copyright © 2017年 concox. All rights reserved.
//

#import "Camera.h"

#ifndef IOTCAMERA_DEPRECATED
#define IOTCAMERA_DEPRECATED(value) __attribute__((deprecated(value)))
#endif

@interface Camera (CameraExt)

+ (NSString *)getIOTCameraVersion IOTCAMERA_DEPRECATED("Use +getVersion");
+ (NSString *)getBuildVersion IOTCAMERA_DEPRECATED("Use +getVersion");
+ (NSString *)getUIDLibVersion IOTCAMERA_DEPRECATED("已废弃，返回：4.1.3");

- (void)connect:(NSString *)uid IOTCAMERA_DEPRECATED("已废弃，Use -connect:password:");
- (void)start:(NSUInteger)channel account:(NSString *)account password:(NSString *)password IOTCAMERA_DEPRECATED("已废弃，Use -connect:password:");
- (void)stop:(NSUInteger)channel IOTCAMERA_DEPRECATED("已废弃，Use -disconnect");
- (void)stopAndDisconnect IOTCAMERA_DEPRECATED("已废弃，Use -disconnect");
- (void)startShow:(NSUInteger)channel IOTCAMERA_DEPRECATED("Use -startShow");
- (void)stopShow:(NSUInteger)channel IOTCAMERA_DEPRECATED("Use -stopShow");
- (void)startShowAtMsgPlayback:(NSUInteger)channel IOTCAMERA_DEPRECATED("Use -startShowAtMsgPlayback");
- (void)stopShowAtMsgPlayback:(NSUInteger)channel IOTCAMERA_DEPRECATED("Use -stopShowAtMsgPlayback");
- (void)startGetSnapPictureFromStream:(NSUInteger)channel filePath:(NSString*)filePath IOTCAMERA_DEPRECATED("Use -startGetSnapPictureWithFilePath:");
- (void)stopGetSnapPictureFromStream:(NSUInteger)channel IOTCAMERA_DEPRECATED("Use -stopGetSnapPicture");
- (void)startGetTimeLineFromStream:(NSUInteger)channel IOTCAMERA_DEPRECATED("Use -startGetTimeLine");
- (void)stopGetTimeLineFromStream:(NSUInteger)channel IOTCAMERA_DEPRECATED("Use -stopGetTimeLine");
- (void)startSoundToPhone:(NSUInteger)channel IOTCAMERA_DEPRECATED("Use -startSoundToPhone");
- (void)stopSoundToPhone:(NSUInteger)channel IOTCAMERA_DEPRECATED("Use -stopSoundToPhone");
- (void)startSoundToDevice:(NSUInteger)channel IOTCAMERA_DEPRECATED("Use -startSoundToDevice");
- (void)stopSoundToDevice:(NSUInteger)channel IOTCAMERA_DEPRECATED("Use -stopSoundToDevice");
- (void)sendIOCtrlToChannel:(NSUInteger)channel type:(NSInteger)type data:(char *)data dataSize:(NSInteger)dataSize IOTCAMERA_DEPRECATED("Use -sendIOCtrlWithType:data:dataSize:");
- (NSString *)getAccountOfChannel:(NSUInteger)channel IOTCAMERA_DEPRECATED("Use -getAccount");
- (NSString *)getPasswordOfChannel:(NSUInteger)channel IOTCAMERA_DEPRECATED("Use -getPassword");
- (NSInteger)getServiceTypeOfChannel:(NSUInteger)channel IOTCAMERA_DEPRECATED("已废弃，返回0");
- (CAMERA_CONNECTION_STATE)getConnectionStateOfChannel:(NSUInteger)channel IOTCAMERA_DEPRECATED("Use -getConnectionState");
- (UIImage *)getSnapshotWithChannel:(NSUInteger)channel IOTCAMERA_DEPRECATED("Use -snapshot");
- (BOOL)startRecordingForMP4:(NSString *)filePath width:(NSInteger)width height:(NSInteger)height IOTCAMERA_DEPRECATED("Use -startRecordingVideo:width:height");
- (NSInteger)getRecordingDurationForMP4 IOTCAMERA_DEPRECATED("Use -getRecordingVideoDuration");
- (void)stopRecording IOTCAMERA_DEPRECATED("Use -stopRecordingVideo");
- (void)setBackplayVoiceAlarmOnly:(BOOL)isOpen IOTCAMERA_DEPRECATED("已废弃");

@end
