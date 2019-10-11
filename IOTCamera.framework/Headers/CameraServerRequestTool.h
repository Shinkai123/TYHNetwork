//
//  CameraServerRequestTool.h
//  IOTCamera
//
//  Created by YaoHua Tan on 2019/5/7.
//  Copyright © 2019 concox. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "SDImageCache.h"
#import "Singleton.h"

#define ServerPostType_zh 117
#define ServerPostType_en 117

typedef NS_ENUM(NSInteger, ServerRespondResult) {
    
    ServerRespondResultUnknownException = -1,
    ServerRespondResultNoNetwork = -2,
    
    ServerRespondResultSucceed = 0,             //操作或查询成功
    ServerRespondResultSystemException = 100,   //系统异常
    ServerRespondResultParameterError  = 101,   //请求参数不完整或格式不正确
    ServerRespondResultVerifyTimeOut   = 102,   //验证已经超时
    ServerRespondResultLinkTimeOut,             //验证链接已失效(错误或超时)
    ServerRespondResultUserNotExist    = 104,   //用户不存在
    ServerRespondResultDidRegister = 200,       //邮箱地址已经注册过
    ServerRespondResultNoVerify,                //该登录邮箱还没有进行验证
    ServerRespondResultDiscordedPWD,            //两次输入的密码不一致
    ServerRespondResultNoMail,                  //该邮箱地址没有注册过
    ServerRespondResultLoginError,              //登录邮箱或密码错误，未通过登录验证
    ServerRespondResultDidVerify,               //该邮箱已经验证过
    ServerRespondResultDeviceBounded = 300,     //设备已经绑定
    ServerRespondResultDeviceNone,              //设备没有找到，(该设备从没有人绑定过)
    ServerRespondResultDeviceNoUnbound,         //设备未绑定
    ServerRespondResultShareMailNoRegister,     //分享的邮箱没有注册过
    ServerRespondResultDeviceUnbounded,         //设备已经解绑过
    ServerRespondResultDeviceNotOneself,        //你不是该设备的主人
    ServerRespondResultDeviceHadShare,          //该摄像头已经分享给该用户，且该用户已经绑定了
    ServerRespondResultDeviceNoShareSelf,       //不能分享给自己
    ServerRespondResultPasswordError = 308,     //密码错误
    ServerRespondResultDeviceShareFail = 309,     //设备分享失败
    
    ServerRespondResultPhoneDidRegister = 500,          //手机号已被注册
    ServerRespondResultPhoneNoRegister = 501,           //该手机号没有注册过
    ServerRespondResultPhoneCodeTimeOut = 502,          //短信验证码已过期
    ServerRespondResultPhoneCodeSendFail = 503,         //短信验证码发送失败
    ServerRespondResultPhoneCodeSendMax = 504,          //短信验证码发送次数已超过最大限制次数
    ServerRespondResultPhoneCodeDiscordedPWD = 505,     //短信验证码不一致
    ServerRespondResultPhoneCodeInvalid = 506,          //短信验证码无效（验证码未发送或已过期）
    ServerRespondResultPhoneShareCodeInvalid = 507,     //短信分享口令无效（分享口令错误或已过期）
    ServerRespondResultPhoneShareAccountDiscorded = 508,     //被分享者手机号不一致
    ServerRespondResultPhoneCodeSendNormalButTimeOut = 509,     //短信发送正常，但响应超时
    ServerRespondResultWechatNoBindPhone = 510,     //微信登录未绑定手机号码
    ServerRespondResultPhoneIsBound = 511,      //手机号已被绑定
    ServerRespondResultWechatBoundPhone = 512,         //微信已绑定手机号
};

/**
 服务器数据访问回调接口
 
 @param uid 设备UID（当访问服务器登录、注册相关时为nil）
 @param success 成功返回YES
 @param resultCode 当无网络和访问错误时解析错误码返回的错误码
 @param result 1、登录相关返回的是返回码对象；2、报警信息时返回的是报警相关字典或列表等
 */
typedef void (^ServerCompletedBlock)(NSString *uid, BOOL success, id resultCode, id result);

/**
 获取服务器设备报警列表（回调）
 
 @param uid 设备UID
 @param success 成功拉取返回YES
 @param stateCode 拉取失败或数据异常等错误时返回的错误码解析字符串
 @param currentPage 获取的报警列表所在页
 @param totalPage 总页数
 @param count 报警数
 @param eventArray 报警列表
 */
typedef void (^EventListCompletedBlock)(NSString *uid, BOOL success, NSInteger stateCode, NSInteger currentPage, NSInteger totalPage, NSInteger count, NSArray *eventArray);


@interface CameraServerRequestTool : NSObject
singleton_h(ServerRequestTool);

@property (nonatomic,strong) NSURLSessionDataTask *sessionDataUserLoginTask;
@property (nonatomic,strong) NSURLSessionDataTask *sessionDataEventListTask;
@property (nonatomic,strong) NSURLSessionDataTask *sessionDataEventCalendarTask;
@property (nonatomic,strong) NSURLSessionDataTask *sessionDataGetVerityCodeTask;

/**
 账户注册
 
 @param userName 注册账号（邮箱或手机号）
 @param password 账号密码
 @param phoneCode 手机号注册时的验证码
 @param completedBlock 回调
 */
+ (void)registerUser:(NSString *)userName
            password:(NSString *)password
           phoneCode:(NSString *)phoneCode
      completedBlock:(ServerCompletedBlock)completedBlock;

/**
 重新发送验证邮件
 
 @param userName 用户账号
 @param password 用户密码
 @param completedBlock 回调
 */
+ (void)sendValidateEmail:(NSString *)userName
                 password:(NSString *)password
           completedBlock:(ServerCompletedBlock)completedBlock;

/**
 账号登录
 
 @param userName 用户账号
 @param password 账号密码
 @param completedBlock 回调
 */
+ (void)userLogin:(NSString *)userName
         password:(NSString *)password
   completedBlock:(ServerCompletedBlock)completedBlock;

/**
 修改密码
 
 @param userName 用户账号
 @param oldPassword 用户旧密码
 @param newPassword 要修改的新密码
 @param completedBlock completedBlock
 */
+ (void)changePassword:(NSString *)userName
           oldPassword:(NSString *)oldPassword
           newPassword:(NSString *)newPassword
        completedBlock:(ServerCompletedBlock)completedBlock;

/**
 手机号注册的用户重置密码
 
 @param phone 手机号
 @param pwd 要修改的新密码
 @param smsCode 短信验证码
 @param completedBlock completedBlock
 */
+ (void)resetPassWordForPhone:(NSString *)phone
                          pwd:(NSString *)pwd
                      smsCode:(NSString *)smsCode
               completedBlock:(ServerCompletedBlock)completedBlock;

/**
 将设备绑定到服务器
 
 @param userName 用户账号
 @param userPassword 用户密码
 @param uid 设备UID
 @param deviceName 设备名称
 @param devicePass 设备密码
 @param devideType 设备类型
 @param completedBlock completedBlock
 */
+ (void)bindDevice:(NSString *)userName
      userPassword:(NSString *)userPassword
               uid:(NSString *)uid
        diviceName:(NSString *)deviceName
        devicePass:(NSString *)devicePass
        devideType:(NSString *)devideType
    completedBlock:(ServerCompletedBlock)completedBlock;

/**
 解绑设备
 
 @param userName 用户账号
 @param password 用户密码
 @param uid 设备UID
 @param completedBlock completedBlock
 */
+ (void)unbindDevice:(NSString *)userName
             userPwd:(NSString *)userPwd
                 uid:(NSString *)uid
      completedBlock:(ServerCompletedBlock)completedBlock;

/**
 设备获取绑定状态
 
 @param uid 设备UID
 @param completedBlock completedBlock
 */
+ (void)getBindStatusWithUid:(NSString *)uid
              completedBlock:(ServerCompletedBlock)completedBlock;

/**
 修改设备名称
 
 @param userName 用户账号
 @param password 用户密码
 @param uid 设备UID
 @param name 要修改的设备名称
 @param completedBlock completedBlock
 */
+ (void)changeCameraNamebyUid:(NSString *)userName
                     password:(NSString *)password
                          uid:(NSString *)uid
                         name:(NSString *)name
               completedBlock:(ServerCompletedBlock)completedBlock;

/**
 分享设备
 
 @param userName 用户名称
 @param password 用户密码
 @param uid 设备uid
 @param shareAccount 要分享的用户（邮箱或手机）
 @param completedBlock completedBlock
 */
+ (void)shareDevice:(NSString *)userName
           password:(NSString *)password
                uid:(NSString *)uid
       shareAccount:(NSString *)shareAccount
     completedBlock:(ServerCompletedBlock)completedBlock;

/**
 根据短信验证码添加分享设备
 
 @param phone 手机号码
 @param shareCode 分享码
 @param completedBlock 回调
 */
+ (void)bindingShareDeviceWithPhone:(NSString *)phone
                          shareCode:(NSString *)shareCode
                     completedBlock:(ServerCompletedBlock)completedBlock;

/**
 移除已分享的设备
 
 @param userName 用户名称
 @param password 用户密码
 @param uid 设备 uid
 @param shareAccount 被分享的邮箱
 @param completedBlock completedBlock
 */
+ (void)removeSharing:(NSString *)userName
             password:(NSString *)password
                  uid:(NSString *)uid
         shareAccount:(NSString *)shareAccount
       completedBlock:(ServerCompletedBlock)completedBlock;

/**
 设备维护
 
 @param userName 用户名称
 @param password 用户密码
 @param uid 设备 uid
 @param firmwareVersion 设备版本
 @param completedBlock completedBlock
 */
+ (void)getCameraLatestFirmwareVersion:(NSString *)userName
                              password:(NSString *)password
                                   uid:(NSString *)uid
                       firmwareVersion:(NSString *)firmwareVersion
                        completedBlock:(ServerCompletedBlock)completedBlock;

/**
 查找摄像头从属关系
 
 @param uid 设备UID
 @param shareState //1: 查询摄像头的归属用户，谁的摄像头  0: 查询被分享的用户列表
 @param completedBlock completedBlock
 */
+ (void)getDeviceRelationship:(NSString *)uid
                   shareState:(NSInteger)shareState
               completedBlock:(ServerCompletedBlock)completedBlock;

/**
 删除服务器报警列表
 
 @param uid 设备UID
 @param devicePass 设备密码
 @param isAll 是否全部删除所有的报警列表
 @param alarmTimeArray 需要删除的报警事件的时间数组
 @param completedBlock completedBlock
 */
+ (void)deleteEvents:(NSString *)uid
          devicePass:(NSString *)devicePass
               isAll:(BOOL)isAll
      alarmTimeArray:(NSArray *)alarmTimeArray
      completedBlock:(ServerCompletedBlock)completedBlock;

/**
 获取摄像机报警列表
 
 @param userName 用户账号
 @param password 用户密码
 @param uid 设备UID
 @param startTime 开始时间（0时区）
 @param endTime 结束时间（0时区）
 @param pageNo 第几页
 @param eventListCompletedBlock eventListCompletedBlock
 */
+ (void)getEvents:(NSString *)userName
         password:(NSString *)password
              uid:(NSString *)uid
        startTime:(NSDate *)startTime
          endTime:(NSDate *)endTime
           pageNo:(NSInteger)pageNo
eventListCompleted:(EventListCompletedBlock)eventListCompletedBlock;

/**
 获取摄像机报警日历数据
 
 @param userName 用户账户
 @param password 用户密码
 @param uid 设备UID
 @param startTime 开始时间（0时区）
 @param endTime 结束时间（0时区）
 @param eventCalendarCompleted eventCalendarCompleted
 */
+ (void)getEventCalendar:(NSString *)userName
                password:(NSString *)password
                     uid:(NSString *)uid
               startTime:(NSDate *)startTime
                 endTime:(NSDate *)endTime
  eventCalendarCompleted:(ServerCompletedBlock)eventCalendarCompleted;


/**
 获取摄像机报警列表数目信息（首页摄像机列表）
 此方法未添加线程管理
 
 @param userName 用户账号
 @param password 用户密码
 @param uid 设备UID
 @param startTime 开始时间（0时区）
 @param endTime 结束时间（0时区）
 @param pageNo 第几页
 @param eventListCompletedBlock eventListCompletedBlock
 */
+ (void)getEventsNum:(NSString *)userName
            password:(NSString *)password
                 uid:(NSString *)uid
           startTime:(NSDate *)startTime
             endTime:(NSDate *)endTime
              pageNo:(NSInteger)pageNo
  eventListCompleted:(EventListCompletedBlock)eventListCompletedBlock;

/**
 App首次进入APP拉取门铃推送消息
 
 @param account 用户名
 */
+ (void)getDoorBellPushMsg:(NSString *)account
            completedBlock:(ServerCompletedBlock)completedBlock;

/**
 根据 IMEI 获取UUID
 
 @param imei 设备IMEI
 @param completedBlock 回调
 */
+ (void)getUUIDByIMEI:(NSString *)imei
       completedBlock:(ServerCompletedBlock)completedBlock;

/**
 邮箱登录-给邮箱绑定手机号
 
 @param userName 用户账号为邮箱
 @param phoneNumber 要被绑定的手机号
  @param smsCode 短信验证码
 @param completedBlock 回调
 */
+ (void)sendEmailBindPhone:(NSString *)userName
               phoneNumber:(NSString *)phoneNumber
                   smsCode:(NSString *)smsCode
            completedBlock:(ServerCompletedBlock)completedBlock;

/**
 手机号登录-给手机绑定邮箱
 
 @param phoneNumber 用户账号为手机号
 @param email 要被绑定的邮箱
 @param completedBlock 回调
 */
+ (void)sendPhoneBindEmail:(NSString *)phoneNumber
                     email:(NSString *)email
            completedBlock:(ServerCompletedBlock)completedBlock;

/**
 向手机端发送验证码
 
 @param phoneNumber 手机号
 @param isReg 只有注册是传 1 ，其他不传
 @param completedBlock 回调
 */
+ (void)sendSMSCodeWithPhone:(NSString *)phoneNumber
                       isReg:(NSInteger)isReg
              completedBlock:(ServerCompletedBlock)completedBlock;

/**
 校验短信验证码
 
 @param phoneNumber 手机号
 @param code 校验码
 @param completedBlock 回调
 */
+ (void)verifySMSCodeWithPhone:(NSString *)phoneNumber code:(NSString *)code completedBlock:(ServerCompletedBlock)completedBlock;

/**
 更换新邮箱或新手机号
 
 @param account 用户账号（原邮箱/原手机号）
 @param pass 登录密码
 @param newAccount 新邮箱/新手机号
 @param smsCode 新手机号的短信验证码
 */
+ (void)changeEmailOrPhone:(NSString *)account
                      pass:(NSString *)pass
                newAccount:(NSString *)newAccount
                   smsCode:(NSString *)smsCode
            completedBlock:(ServerCompletedBlock)completedBlock;

/**
 根据email或phone获取用户信息
 
 @param account 邮箱/手机号
 */
+ (void)getUserInfo:(NSString *)account
     completedBlock:(ServerCompletedBlock)completedBlock;

/**
 微信登录
 
 @param code token
 */
+(void)weChatLogin:(NSString *)code
    completedBlock:(ServerCompletedBlock)completedBlock;

/**
 微信登录-绑定手机号码
 
 @param phone 要被绑定的手机号
 @param smsCode 验证码
 @param password 密码
 */
+(void)weChatBindPhone:(NSString *)phoneNumber
               smsCode:(NSString *)smsCode
              password:(NSString *)password
              bindType:(int)bindType
        completedBlock:(ServerCompletedBlock)completedBlock;

/**
 微信解绑手机号
 
 @param phone 微信绑定的手机号
 */
+ (void)weChatUnBindPhone:(NSString *)phoneNumber
           completedBlock:(ServerCompletedBlock)completedBlock;

/**
 获取设备供应商信息
 
 @param uid 设备UID/IMEI
 */
+ (void)getDealerInfo:(NSString *)uid
       completedBlock:(ServerCompletedBlock)completedBlock;

/**
 意见反馈
 
 @param suggestionAccount 反馈意见的账号
 @param pass 反馈账号的密码
 @param uid 设备uid/imei
 @param suggestionContent 账号所反馈内容
 */
+ (void)insertSuggestion:(NSString *)suggestionAccount
                    pass:(NSString *)pass
                    uid:(NSString *)uid
       suggestionContent:(NSString *)suggestionContent
          completedBlock:(ServerCompletedBlock)completedBlock;

/**
 获取设备绑定状态
 
 @param uid 设备UID/IMEI
 
 */
+(void)getDeviceBoundStatus:(NSString *)uid
             completedBlock:(ServerCompletedBlock)completedBlock;


/**
 Linux平台系列设备向服务器获取版本信息

 @param completedBlock completedBlock
 */
+ (void)getDeviceOfLinuxVersionFormServer:(ServerCompletedBlock)completedBlock;

#pragma mark - 亚马逊推送

/**
 向服务器提供需要推送的IMEIS
 
 @param deviceToken deviceToken
 @param imeis 需要推送的设备的uid/IMEI 集合
 @param photoType 手机类型
 @param flag 发送标识(第几次发送)
 */
+(void)setDeviceNotificationInfo:(NSString *)deviceToken
                           imeis:(NSString *)imeis
                       phoneType:(NSString *)photoType
                            flag:(NSInteger)flag
                  completedBlock:(ServerCompletedBlock)completedBlock;

/**
 App退出登录时，注销推送
 
 @param deviceToken deviceToken
 */
+(void)cancelPush:(NSString *)deviceToken
   completedBlock:(ServerCompletedBlock)completedBlock;

/**
 推送角标重置
 
 @param deviceToken DeviceToken
 
 */
+(void)resetBadge:(NSString *)deviceToken
   completedBlock:(ServerCompletedBlock)completedBlock;

/**
 下载文件,默认调用接口即立即下载
 
 @param inferfacePath 网络服务器URL地址
 @param savePath      文件保存路径
 @param filePathBlack 文件保存完成的地址回调，为nil表示失败
 */
+ (NSURLSessionDownloadTask *)downloadVideo:(NSString *)inferfacePath
                                   savePath:(NSString *)savePath
                            downloadSuccess:(void (^)(NSURL *fileURLPath))filePathBlack
                                   progress:(void (^)(CGFloat progress))progress
                                  totalSize:(void (^)(unsigned long long))totalSize;
@end

