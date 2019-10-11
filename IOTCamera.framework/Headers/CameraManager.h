//
//  CameraManager.h
//  IOTCamera
//
//  Created by YaoHua Tan on 2019/7/11.
//  Copyright © 2019 concox. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN



@protocol CameraManagerDelegate <NSObject>
singleton_h(cameraManager);
@optional
/**
 设备绑定回调

 @param camera camera
 @param uidOrImei 设备uidOrImei
 @param camNewPwd 设备密码
 @param state 绑定结果，0：绑定成功  1：WiFi错误 2：设备配网成功，绑定服务器失败 3：绑定超时
 */
- (void)resultOfbindDevice:(Camera *)camera uidOrImei:(NSString *)uidOrImei camNewPwd:(NSString *)camNewPwd state:(NSInteger)state;


/**
 设备重连回调
 
 @param uid 被重连设备UIDorIMEI
 @param state 0：成功  1：重连超时
 */
- (void)resultOfReConnect:(NSString *)uid state:(NSInteger)state;

@required

/**
 指令发送后响应超时计时动作，每秒更新
 */
- (void)refreshCommondSendsTimeoutAction;

@end

@interface CameraManager : NSObject

@property (nonatomic, weak) id<CameraManagerDelegate> delegate;

/**
 添加摄像机
 
 @param camera 要添加的Camera
 @param password 要添加的Camera的设备密码
 */
- (void)addCamera:(Camera *)camera password:(NSString *)password;

/**
 删除指定camera
 
 @param camera 要删除camera
 */
- (void)removeCamera:(Camera *)camera;

/**
 移除所有设备
 */
- (void)removeAllCamera;

/**
 根据UID查找camera

 @param uid 查找camera
 @return camera
 */
- (Camera *)getCameraByUID:(NSString *)uid;

/**
 断开连接指定设备
 
 @param camera 要断开连接的设备
 */
- (void)disConnectCamera:(Camera *)camera;

/**
 所有设备断开连接
 */
- (void)disConnectAllCamera;

/**
 所有已断开设备进行重连
 */
- (void)reconnectAllDisconnectedCameras;


/**
 弱重连设备(已连接则不重连)，可以立即重连，无需等待
 
 @param camera 需要弱重连的设备
 */
- (void)reconnectOfflineCamera:(Camera *)camera;

/**
 弱重连设备(已连接则不重连），需等待时间为 time
 
 @param camera 需要弱重连的设备
 @param delayTime 需要等待的时间
 */
- (void)reconnectOfflineCamera:(Camera *)camera delayTime:(NSInteger)delayTime;

/**
 强重连(不判断连接状态)，无需等待，立即重连
 
 @param camera 需要强重连的camera
 */
- (void)forceReconnectCamera:(Camera *)camera;

/**
 强重连，需等待time
 
 @param camera 需要强重连的camera
 @param delayTime 等待时间
 */
- (void)forceReconnectCamera:(Camera *)camera delayTime:(NSInteger)delayTime;

/**
 绑定设备
 将App与设备建立绑定关系并将设备信息上传到服务器
 
 @param userName 账号
 @param userPassword 账号密码
 @param uidOrImei 要绑定的设备uidOrImei,必须20位或者15位
 @param nickName 设备名称
 @param defaultPwd 初始密码
 @param newPwd 要修改的密码
 @param bindMark 绑定类型 0:设备已联网  1：设备未联网   2：AP直连
 @param deviceType 设备类型
 */
- (void)bindDevice:(NSString *)userName userPassword:(NSString *)userPassword uidOrImei:(NSString *)uidOrImei nickName:(NSString *)nickName defaultPwd:(NSString *)defaultPwd newPwd:(NSString *)newPwd ssid:(NSString *)ssid ssidPwd:(NSString *)ssidPwd bindMark:(NSInteger)bindMark deviceType:(NSString *)deviceType;

/**
 修改设备名称
 
 @param camera 需要修改名称的camera
 @param userName 用户账号
 @param password 用户密码
 @param uidOrImei UID或IMIE
 @param changeName 要修改的名称
 */
- (void)changeCameraName:(Camera *)camera userName:(NSString *)userName password:(NSString *)password uidOrImei:(NSString *)uidOrImei changeName:(NSString *)changeName;

/**
 解绑设备
 将设备与App接触绑定关系并将设备信息从服务器删除
 
 @param camera 需要解绑camera
 @param userName 用户账号
 @param userPwd 用户密码
 @param uidOrImei UID或IMIE
 @param unbindType 解绑类型 2：Ap指令设备解绑， 1：正常配网流程的设备解绑
 */
- (void)unbindDevice:(Camera *)camera userName:(NSString *)userName userPwd:(NSString *)userPwd uidOrImei:(NSString *)uidOrImei unbindType:(NSInteger)unbindType;
/**
 已绑定设备但已离线，重新给设备配网
 注意，如已重置设备，如法使用此方法重新配网，需从服务器删除此设备重绑，使设备上线
 
 @param camera camera
 @param ssid 要配置的Wifi名
 @param ssidPwd 要配置的Wifi密码
 @param isAPMode 是否为连接设备热点进行设备连接，再设置WIFI信息
 */
- (void)changeWiFiForCamera:(Camera *)camera ssid:(NSString *)ssid ssidPwd:(NSString *)ssidPwd isAPMode:(BOOL)isAPMode;

@end

NS_ASSUME_NONNULL_END
