//
//  CamSendCmdByJsonTool.h
//  IOTCamera
//
//  Created by YaoHua Tan on 2019/4/30.
//  Copyright © 2019 concox. All rights reserved.
//

#import <Foundation/Foundation.h>
@class AlarmAreaModel;

NS_ASSUME_NONNULL_BEGIN

#define DeviceServerIPAddress @"120.24.64.91"   //设备服务器地址

extern NSString *const didSendIOTypeString;

@interface CamSendCmdByJsonTool : NSObject

/**
 修改设备密码
 
 @param camera camera
 @param oldPwd 旧密码(最大长度32，超过的部分会被截取)
 @param newPwd 新密码(最大长度32，超过的部分会被截取)
 */
+ (void)changeCameraPwd:(Camera *)camera
                 oldPwd:(NSString *)oldPwd
                 newPwd:(NSString *)newPwd
                timeout:(CGFloat)timeout;

/**
 修改设备名称
 
 @param camera camera
 @param deviceName 要修改的设备名称(最大长度128，超过的部分会被截取)
 */
+ (void)changeCameraName:(Camera *)camera
              deviceName:(NSString *)deviceName
                 timeout:(CGFloat)timeout;

/**
 修改热点名称
 
 @param camera camera
 @param hotpotName 要修改的热点名称(最大长度32，超过的部分会被截取)
 */
+(void)updateHotpotName:(Camera *)camera
             hotpotName:(NSString *)hotpotName
                timeout:(CGFloat)timeout;

/**
 修改热点密码
 
 @param camera camera
 @param hotpotPwd 要修改的热点密码(最大长度32，超过的部分会被截取)
 */
+(void)changeHotpotPwd:(Camera *)camera
             hotpotPwd:(NSString *)hotpotPwd
               timeout:(CGFloat)timeout;

/**
 添加热点黑名单
 
 @param camera camera
 @param hotpotName 要添加的热点名称(最大长度32，超过的部分会被截取)
 */
+(void)addMacHotpotBlackList:(Camera *)camera
                         mac:(NSString *)mac
                     timeout:(CGFloat)timeout;

/**
 移出热点黑名单
 
 @param camera camera
 @param hotpotName 要移出的热点名称(最大长度32，超过的部分会被截取)
 */
+(void)removeMacFromHotpotBlackList:(Camera *)camera
                                mac:(NSString *)mac
                            timeout:(CGFloat)timeout;

/**
 给设备设置WIFI
 
 @param camera camera
 @param ssid WIFI名
 @param password WIFI密码(最大长度32，超过的部分会被截取)
 */
+ (void)setWiFi:(Camera *)camera
           ssid:(NSString*)ssid
       password:(NSString *)password
        timeout:(CGFloat)timeout;

/**
 设置推送通知类型
 
 @param camera camera
 @param mode 通知类型 1：铃声和震动  2：静音
 */
+ (void)setNotificationMode:(Camera *)camera
                       mode:(int)mode
                    timeout:(CGFloat)timeout;

/**
 删除报警消息
 
 @param camera camera
 @param eventArray 要删除的消息的事件时间，数组  //时间，从1970开始秒(UTC时间)
 */
+ (void)sendDeleteEventForCamera:(Camera *)camera
                       eventArray:(NSArray *)eventArray
                         timeout:(CGFloat)timeout;

/**
 解绑摄像机
 
 @param camera camera
 @param nickname 设备名称(最大长度128，超过的部分会被截取)
 @param userName 用户名(最大长度64，超过的部分会被截取)
 @param userPwd 用户密码(最大长度64，超过的部分会被截取)
 */
+ (void)unbindAccount:(Camera *)camera
              timeout:(CGFloat)timeout;

/**
 获取摄像机回放时间线(包括全天候录像、侦测录像),daNum为0时即获取3个小时的数据
 用法：
 在调用方法之前需调用 -(void)startGetTimeLineData;
 
 此方法的回调 - (void)camera:(Camera *)camera didGetLiveTimeLineData:(const u_char *)data size:(int)size;
 
 @param camera camera
 @param date 要获取回放数据的时间
 @param dayNum 范围，最多3天
 */
+ (void)getTimeLine:(Camera *)camera
               date:(NSDate *)date
             dayNum:(int)dayNum
            timeout:(CGFloat)timeout;

/**
 报警消息回放时间定位
 
 @param camera camera
 @param timePoint 回放消息的时间点
 */
+ (void)setPlayBackSeekTime:(Camera *)camera
                       time:(long)timePoint
                    timeout:(CGFloat)timeout;

/**
 直播回放时间定位（时间轴）
 
 @param camera camera
 @param date 当前要播放的时间点
 */
+ (void)sendSetTimeLinePointForCamera:(Camera *)camera
                                 date:(NSDate *)date
                              timeout:(CGFloat)timeout;

/**
 切换到直播
 
 @param camera camera
 
 */
+ (void)switchPlayback2Realtime:(Camera *)camera
                        timeout:(CGFloat)timeout;

/**
 固件更新
 
 @param camera camera
 @param deviceParaType 设备系统类型 1：08系列（Linux）  2：09系列（安卓）
 */
+ (void)upgradeCameraFirmware:(Camera *)camera
                      timeout:(CGFloat)timeout;

/**
 获取系统参数
 
 @param camera camera
 */
+ (void)getCameraSettings:(Camera *)camera
                  timeout:(CGFloat)timeout;

/**
 获取热点参数
 
 @param camera camera
 */
+(void)getHotpotSettings:(Camera *)camera
                 timeout:(CGFloat)timeout;

/**
 获取摄像机设备中的WiFi列表
 
 @param camera camera
 */
+ (void)getWiFiList:(Camera *)camera
            timeout:(CGFloat)timeout;

/**
 设置直播画面的分辨率
 
 @param camera camera
 @param definition 清晰度 2：高清  3：标清
 */
+ (void)setLiveDefinition:(Camera *)camera
               definition:(int)definition
                  timeout:(CGFloat)timeout;

/**
 设置报警区域开关
 
 @param camera camera
 @param state 开关状态 YES:开
 */
+ (void)setAreaAlarmSwitch:(Camera *)camera
               switchState:(int)state
                   timeout:(CGFloat)timeout;

/**
 设置报警开关
 
 @param camera camera
 @param state 开关状态 YES：开
 */
+ (void)setAlertSwitch:(Camera *)camera
           switchState:(int)state
               timeout:(CGFloat)timeout;

/**
 人形检测开关
 
 @param camera camera
 @param state 开关状态 YES：开
 */
+ (void)setHumanoidDetection:(Camera *)camera
                       state:(int)state
                     timeout:(CGFloat)timeout;

/**
 热点开关
 
 @param camera camera
 @param state 开关状态 YES：开
 */
+ (void)setHotpot:(Camera *)camera
            state:(int)state
          timeout:(CGFloat)timeout;

/**
 全天报警录像开关
 
 @param camera camera
 @param state 开关状态 YES：开
 */
+ (void)setAllDayAlertSwitch:(Camera *)camera
                       state:(int)state
                     timeout:(CGFloat)timeout;

/**
 全天 SD 卡录像开关
 
 @param camera camera
 @param state 开关状态 YES：开
 */
+ (void)setAllDayMicroSDRecording:(Camera *)camera
                            state:(int)state
                          timeout:(CGFloat)timeout;

/**
 新的时段设置（可设置3个时间段）
 
 @param camera camera
 @param startTime 开始时间
 @param endTime 结束时间
 @param state 是否启用 YES：开
 @param timeRangeIndex 1、2、3：报警时间段标识
 */
+ (void)setAllowAlertTimeRange:(Camera *)camera
                     startTime:(CGPoint)startTime
                       endTime:(CGPoint)endTime
                         state:(int)state
                timeRangeIndex:(int)timeRangeIndex
                       timeout:(CGFloat)timeout;

/**
 新的时段设置（可设置3个时间段）
 
 @param camera camera
 @param startTime 开始时间
 @param endTime 结束时间
 @param state 是否启用 YES：开
 @param currentTimeIndex 1、2、3：报警时间段标识
 */
+ (void)setRecordingSchedule:(Camera *)camera
                   startTime:(CGPoint)startTime
                     endTime:(CGPoint)endTime
                       state:(int)state
            currentTimeIndex:(int)currentTimeIndex
                     timeout:(CGFloat)timeout;

/**
 移动侦测录像开关
 
 @param camera camera
 @param state 开关状态 YES：开
 */
+ (void)setRecording4MotionDetection:(Camera *)camera
                               state:(int)state
                             timeout:(CGFloat)timeout;

/**
 热点加密方式
 
 @param camera camera
 @param state 加密方式 NO:不加密   YES:加密
 */
+ (void)setHotpotEncription:(Camera *)camera
                      state:(int)state
                    timeout:(CGFloat)timeout;

/**
 WiFi跟3G/4G切换
 
 @param camera camera
 @param state YES:WIFI NO:3G/4G
 */
+ (void)switchNetwork:(Camera *)camera
                                 state:(int)state
                               timeout:(CGFloat)timeout;

/**
 格式化TF卡
 
 @param camera camera
 */
+ (void)formatExtStorage:(Camera *)camera
                 timeout:(CGFloat)timeout;


/**
 设置声音侦测
 
 @param camera camera
 @param state YES
 */
+ (void)setSoundDetection:(Camera *)camera
                    state:(int)state
                  timeout:(CGFloat)timeout;

/**
 设置声音侦测灵敏度
 
 @param camera camera
 @param value // 灵敏度：NO:0(Disabled)，YES:50(Max) ~ 100(Min):
 */
+ (void)setSoundDetectionSensitivity:(Camera *)camera
                    sensitivityValue:(int)value
                             timeout:(CGFloat)timeout;

/**
 设置移动侦测
 
 @param camera camera
 @param state YES:50 , NO:0
 */
+ (void)setMotionDetection:(Camera *)camera
                     state:(int)state
                   timeout:(CGFloat)timeout;

/**
 设置报警区域
 
 @param camera camera
 @param array 报警区域坐标数组
 */
+ (void)setAreaAlarm:(Camera *)camera
  areaAlarmParameter:(NSArray<AlarmAreaModel*>*)array
             timeout:(CGFloat)timeout;

///**
// 设置声音侦测开启时是否录像
// 
// @param camera camera
// @param state YES:开
// */
//+ (void)sendSetVideoOnVoiceDetectForCamera:(Camera *)camera
//                                     state:(int)state
//                                   timeout:(CGFloat)timeout;

/**
 设置LED灯状态
 
 @param camera camera
 @param state YES:开
 */
+ (void)setLedState:(Camera *)camera
              state:(int)state
            timeout:(CGFloat)timeout;

/**
 设置视频翻转
 
 @param camera camera
 @param state 0:关 1:开
 */
+ (void)setVideoMode:(Camera *)camera
               state:(int)state
             timeout:(CGFloat)timeout;

/**
 设置设备红外开关
 
 @param camera camera
 @param state  //0:关闭；1：开启；2：自动
 */
+ (void)setNightVision:(Camera *)camera
                 state:(int)state
               timeout:(CGFloat)timeout;

/**
 设置云端存储
 
 @param camera camera
 @param state YES:开 NO：关
 */
+(void)setCloudStorage:(Camera *)camera
                 state:(int)state
               timeout:(CGFloat)timeout;

/**
 播放SD卡消息回放（开始）
 
 @param camera camera
 @param time 被播放的视频的时间
 */
+ (void)playRecordingVideo:(Camera *)camera
                      time:(long)time
                   timeout:(CGFloat)timeout;

/**
 播放SD卡消息回放（暂停）
 
 @param camera camera
 @param time 被播放的视频的时间
 */
+ (void)pausePlayRecordingVideo:(Camera *)camera
                           time:(long)time
                        timeout:(CGFloat)timeout;

/**
 播放SD卡消息回放（停止）
 
 @param camera camera
 @param time 被播放的视频的时间
 */
+ (void)stopPlayRecordingVideo:(Camera *)camera
                          time:(long)time
                       timeout:(CGFloat)timeout;

/**
 获取当前播放的视频时间长度
 
 @param camera camra
 @param time 被播放的视频的时间
 */
+ (void)getVideoLength:(Camera *)camera
                  time:(long)time
               timeout:(CGFloat)timeout;

/**
 给设备设置推送信息
 
 @param camera camera
 @param deviceName 摄像机名称(最大长度128，超过的部分会被截取)
 @param appDevicePushId 设备推送ID
 @param defLanguageType 默认系统语言类型 1、2：中文  ，其他：英文
 */
+ (void)setPushSettings:(Camera *)camera
             deviceName:(NSString *)deviceName
        appDevicePushId:(int)appDevicePushId
        defLanguageType:(int)defLanguageType
                timeout:(CGFloat)timeout;

/**
 开始OTA升级或获取OTA升级状态
 
 @param camera camera
 @param state 1：check 2:install
 */
+ (void)getCameraOTAState:(Camera *)camera
                    state:(u_char)state
                  timeout:(CGFloat)timeout;

/**
 设置短信通知状态
 
 @param camera camera
 @param state YES:开
 */
+ (void)setSMSNotificationSwitch:(Camera *)camera
                           state:(int)state
                         timeout:(CGFloat)timeout;

/**
 设置电话通知状态
 
 @param camera camera
 @param state YES:开
 */
+ (void)setPhoneCallNotificationSwitch:(Camera *)camera
                                 state:(int)state
                               timeout:(CGFloat)timeout;

/**
 设置短信电话通知号码，默认3个已满替换第一个
 
 @param camera camera
 @param phoneNumberArray 电话数组
 */
+ (void)setSoSAlarmPhoneNumber:(Camera *)camera
              phoneNumberArray:(NSArray *)phoneNumberArray
                       timeout:(CGFloat)timeout;

/**
 设置电话报警次数
 
 @param camera camera
 @param count 需要拨打电话的次数
 */
+ (void)setSoSAlarmNoticeCount:(Camera *)camera
                         count:(int)count
                       timeout:(CGFloat)timeout;

/**
 更新设备端时间
 
 @param camera camera
 */
+ (void)synCameraSystemTime:(Camera *)camera
                    timeout:(CGFloat)timeout;

/**
 设置设备报警录像录制时长
 
 @param camera camera
 @param duration 录制时长 5s、10s、15s
 */
+ (void)setRecordDuration:(Camera *)camera
                 duration:(int)duration
                  timeout:(CGFloat)timeout;

/**
 设置移动网络下是否支持报警视频上传
 
 @param camera camera
 @param state YES:允许
 */
+ (void)setUpload4MobileNetwork:(Camera *)camera
                          state:(int)state
                        timeout:(CGFloat)timeout;

/**
 推送是否包含视频及图片资源
 
 @param camera camera
 @param type 1：视频，2：图片；3：文字
 */
+ (void)setPushIncludeMedia:(Camera *)camera
                       type:(int)type
                    timeout:(CGFloat)timeout;

/**
 重启设备
 
 @param camera camera
 */
+ (void)reboot:(Camera *)camera
       timeout:(CGFloat)timeout;

/**
 设置人形侦测触发是否开启警笛报警功能
 
 @param camera camera
 @param alarmWhistleWhenHumanCheck 人形侦测触发是否开启警笛报警 YES:开
 */
+ (void)setAlarmWhistle4HumanoidDetection:(Camera *)camera
               alarmWhistleWhenHumanCheck:(int)alarmWhistleWhenHumanCheck
                                  timeout:(CGFloat)timeout;

/**
 设置移动侦测触发是否开启警笛报警功能
 
 @param camera camera
 @param alarmWhistleWhenMotionDetect 移动侦测触发是否开启警笛报警 YES:开
 */
+ (void)setAlarmWhistle4MotionDetection:(Camera *)camera
           alarmWhistleWhenMotionDetect:(int)alarmWhistleWhenMotionDetect
                                timeout:(CGFloat)timeout;

/**
 设置声音侦测触发是否开启警笛报警功能
 
 @param camera camera
 @param alarmWhistleWhenVoiceDetect 声音侦测触发是否开启警笛报警 YES:开
 */
+ (void)setAlarmWhistle4SoundDetection:(Camera *)camera
           alarmWhistleWhenVoiceDetect:(int)alarmWhistleWhenVoiceDetect
                               timeout:(CGFloat)timeout;

/**
 设置警笛报警时长
 
 @param camera camera
 @param alarmWhistleDuration 报警时长 15s 30s 60s
 */
+ (void)setAlarmWhistleDuration:(Camera *)camera
           alarmWhistleDuration:(int)alarmWhistleDuration
                        timeout:(CGFloat)timeout;

/**
 是否停止警笛报警
 
 @param camera camera
 @param isStop YES:停止
 */
+ (void)stopAlarmWhistle:(Camera *)camera
                  isStop:(int)isStop
                 timeout:(CGFloat)timeout;

/**
 设备Ap直连
 
 @param camera camera
 @param apLive YES：AP直连
 */
+ (void)setApConnection:(Camera *)camera
                 apLive:(int)apLive
                timeout:(CGFloat)timeout;

/**
 邮箱推送设置
 
 @param camera camera
 @param port 端口号
 @param sMainServer 登录邮箱 (最大长度30，超过的部分会被截取)
 @param sPasswd 邮箱密码 (最大长度30，超过的部分会被截取)
 @param sMailFrom 发送邮箱 (最大长度30，超过的部分会被截取)
 @param sMailTo 接收邮箱 (最大长度30，超过的部分会被截取)
 @param encryption 加密方式 0:No Encryption 1:SSL Encryption 2:TLS Encryption
 */
+ (void)setEmailSMTP:(Camera *)camera
                port:(int)port
         sMainServer:(NSString *)sMainServer
             sPasswd:(NSString *)sPasswd
           sMailFrom:(NSString *)sMailFrom
             sMailTo:(NSArray<NSString *> *)sMailTo
          encryption:(int)encryption
             timeout:(CGFloat)timeout;

/**
 设置邮箱功能是否开启
 
 @param camera camera
 @param state YES:开启
 */
+ (void)setEmailPush:(Camera *)camera
               state:(int)state
             timeout:(CGFloat)timeout;

/**
 人形侦测高灵敏度
 
 @param camera camera
 @param state 0:关闭 1：开启
 */
+ (void)setHumanoidDectionSensitivity:(Camera *)camera
                                state:(int)state
                              timeout:(CGFloat)timeout;


@end



NS_ASSUME_NONNULL_END
