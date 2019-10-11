//
//  CmdStructTool.h
//  IOTCamera
//
//  Created by shinkai on 2019/3/6.
//  Copyright © 2019 concox. All rights reserved.
//

#ifndef CmdStructTool_h
#define CmdStructTool_h

typedef enum
{
    IOTYPE_USER_IPCAM_CMD_SET_NONE                                  = -1,   //初始值
    IOTYPE_USER_IPCAM_CMD_SET_PASSWORD                              = 0x00, //修改设备密码
    IOTYPE_USER_IPCAM_CMD_SET_DEVICE_NAME                           = 0x01, //修改设备名称
    IOTYPE_USER_IPCAM_CMD_SET_HOTPOT_SSID                           = 0x02, //修改热点名称
    IOTYPE_USER_IPCAM_CMD_SET_HOTPOT_PASSWORD                       = 0x03, //修改热点密码
    IOTYPE_USER_IPCAM_CMD_SET_HOTSPOT_BLOCK                         = 0x04, //添加热点黑名单
    IOTYPE_USER_IPCAM_CMD_SET_HOTSPOT_UNBLOCK_CLIENT                = 0x05, //移出热点黑名单
    IOTYPE_USER_IPCAM_CMD_SET_TIMEZONE                              = 0x06, //设置时区
    IOTYPE_USER_IPCAM_CMD_SET_WIFI                                  = 0x07, //设置WIFI
    IOTYPE_USER_IPCAM_CMD_SET_NOTIFY_MODE                           = 0x08, //设置推送通知类型
    IOTYPE_USER_IPCAM_CMD_GET_TIMELINE_EVENT                        = 0x09, //获取报警信息列表
    IOTYPE_USER_IPCAM_CMD_SET_DELETE_TIMELINE_EVENT                 = 0x10, //删除报警消息
    IOTYPE_USER_IPCAM_CMD_SET_BIND_STATUS                           = 0x11, //解绑摄像机
    IOTYPE_USER_IPCAM_CMD_GET_TIMELINE_INFO                         = 0x12, //获取摄像机回放时间线
    IOTYPE_USER_IPCAM_CMD_SET_RECORD_PLAYCONTROL                    = 0x13, //报警消息回放时间定位
    IOTYPE_USER_IPCAM_CMD_SET_TIMELINE_POINT                        = 0x14, //直播回放时间定位 / 切换直播
    /*  0: success  -1: no sd card  -2: no timeline list  -3: set error*/
    IOTYPE_USER_IPCAM_CMD_SET_MANUAL_UPGRADE                        = 0x15, //固件更新（Linux）
    /*s->buff[21] == 1 //更新失败  s->buff[21] == 0 //开始完成  s->buff[21] == 2 ////正在升级*/
    IOTYPE_USER_IPCAM_CMD_GET_SYS_PARAMS                            = 0x16, //获取系统参数
    IOTYPE_USER_IPCAM_CMD_GET_HOTPOT_PARAMS                         = 0x17, //获取热点参数
    IOTYPE_USER_IPCAM_CMD_GET_LISTWIFIAP                            = 0x18, //获取摄像机设备中的WiFi列表
    IOTYPE_USER_IPCAM_CMD_SET_STREAMCTRL                            = 0x19, //设置直播画面的分辨率
    IOTYPE_USER_IPCAM_CMD_SET_ENABLE_AREA_ALARM                     = 0x20, //设置报警区域开关
    IOTYPE_USER_IPCAM_CMD_SET_ALARM_ENABLE                          = 0x21, //设置报警开关
    IOTYPE_USER_IPCAM_CMD_SET_ENABLE_HUMAN_CHECK                    = 0x22, //人形检测开关
    IOTYPE_USER_IPCAM_CMD_SET_HOTPOT_STATE                          = 0x23, //热点开关
    IOTYPE_USER_IPCAM_CMD_SET_ENABLE_ALARM_RECORD_ALLDAY            = 0x24, //全天报警录像开关
    IOTYPE_USER_IPCAM_CMD_SET_ENABLE_TIMELINE_RECORD_ALLDAY         = 0x25, //全天 SD 卡录像开关
    IOTYPE_USER_IPCAM_CMD_SET_ALARM_TIME_INFO                       = 0x26, //设置报警时段
    IOTYPE_USER_IPCAM_CMD_SET_ENABLE_ALARM_RECORD_TIME_INTERVAL     = 0x27, //报警时段设置
    IOTYPE_USER_IPCAM_CMD_SET_ENABLE_TIMELINE_RECORD_TIME_INTERVAL  = 0x30, //时间轴录像时间段
    IOTYPE_USER_IPCAM_CMD_SET_RECORD                                = 0x33, //移动侦测开关
    IOTYPE_USER_IPCAM_CMD_SET_HOTPOT_ENCRIPTION_TYPE                = 0x34, //热点加密方式
    IOTYPE_USER_IPCAM_CMD_SET_SWITCH_WIFI_3G                        = 0x35, // WiFi跟3G/4G切换
    IOTYPE_USER_IPCAM_CMD_SET_FORMATEXTSTORAGE                      = 0x36, //格式化TF卡
    IOTYPE_USER_IPCAM_CMD_SET_VOLUMEALARM                           = 0x37, //设置声音侦测
    IOTYPE_USER_IPCAM_CMD_SET_MOTIONDETECT                          = 0x38, //设置移动侦测
    IOTYPE_USER_IPCAM_CMD_SET_AREA_ALARM                            = 0x39, //设置报警区域
    IOTYPE_USER_IPCAM_CMD_SET_VIDEO_ENABLED_ON_VOICE_DETECT         = 0x40, //设置声音侦测开启时是否录像
    IOTYPE_USER_IPCAM_CMD_SET_LED_STATUS                            = 0x31, //设置LED灯状态
    IOTYPE_USER_IPCAM_CMD_SET_VIDEOMODE                             = 0x42, //设置视频翻转
    IOTYPE_USER_IPCAM_CMD_SET_NIGHT_VISION_ENABLE                   = 0x43, //设置外红开关
    IOTYPE_USER_IPCAM_CMD_SET_CLOUD_STORAGE_ENABLE                  = 0x44, // 设置云端存储
    IOTYPE_USER_IPCAM_CMD_SET_PLAYBACK_ALARM                        = 0x45, //播放SD卡消息回放（开始）（暂停）（停止）(获取当前播放的视频时间长度)
    IOTYPE_USER_IPCAM_CMD_SET_INIT_PARAMS                           = 0x46, //发送首页的数据拿取，尤其是消息数量
    IOTYPE_USER_IPCAM_CMD_START_ROM_OTA                             = 0x47,//(Android) //开始OTA升级或获取OTA升级状态
    IOTYPE_USER_IPCAM_CMD_SET_ALARM_NOTICE                          = 0x48, //设置短信电话通知状态/设置短信电话通知号码/设置电话报警次数
    IOTYPE_USER_IPCAM_CMD_SET_SYSTEM_TIME                           = 0x49, //更新设备端时间
    IOTYPE_USER_IPCAM_CMD_SET_RECORD_DURATION                       = 0x50, //设置设备报警录像录制时长
    IOTYPE_USER_IPCAM_CMD_SET_SWITCH_ALARM_UPLOAD_AT_3G             = 0x51, //设置3G网络下是否支持报警视频上传
    IOTYPE_USER_IPCAM_CMD_SET_PUSH_CONTAIN_MEDIA                    = 0x52, //推送是否包含视频及图片资源
    IOTYPE_USER_IPCAM_CMD_SET_RESTART_CAMERA                        = 0x53, //重启设备
    IOTYPE_USER_IPCAM_CMD_SET_ALARM_WHISTLE                         = 0x54, //设置警笛报警功能
    IOTYPE_USER_IPCAM_CMD_SET_ALARM_WHISTLE_STATE                   = 0x55, //是否停止警笛报警
    IOTYPE_USER_IPCAM_CMD_SET_AP_LIVE                               = 0x56, //设备Ap直连
    IOTYPE_USER_IPCAM_CMD_SET_EMAIL                                 = 0x57, //邮箱推送设置
    IOTYPE_USER_IPCAM_CMD_SET_ENABLE_EMAIL                          = 0x58, //设置邮箱功能是否开启
    IOTYPE_USER_IPCAM_CMD_SET_ENABLE_HIGHT_SENSITIVITY              = 0x59, //人形侦测高灵敏度
    IOTYPE_USER_IPCAM_CMD_SET_VOLUMEALARM_SENSITIVITY               = 0x60, //声音侦测灵敏度
}IOTYPE_USER_IPCAM_CMD;

// AVIOCTRL Play Record Command
typedef enum
{
    AVIOCTRL_RECORD_PLAY_PAUSE            = 0x00,
    AVIOCTRL_RECORD_PLAY_STOP            = 0x01,
    AVIOCTRL_RECORD_PLAY_STEPFORWARD    = 0x02, //now, APP no use
    AVIOCTRL_RECORD_PLAY_STEPBACKWARD    = 0x03, //now, APP no use
    AVIOCTRL_RECORD_PLAY_FORWARD        = 0x04, //now, APP no use
    AVIOCTRL_RECORD_PLAY_BACKWARD        = 0x05, //now, APP no use
    AVIOCTRL_RECORD_PLAY_SEEKTIME        = 0x06, //now, APP no use
    AVIOCTRL_RECORD_PLAY_END            = 0x07,
    AVIOCTRL_RECORD_PLAY_START            = 0x10,
    AVIOCTRL_RECORD_PLAY_NOSDCARD       = 0x11,
    AVIOCTRL_RECORD_GETVIDEOINFO        = 0x12,
    AVIOCTRL_RECORD_FILE_NO_EXISTS      = 0x13,
    AVIOCTRL_RECORD_DOWNLOAD_START        = 0x100,
    AVIOCTRL_RECORD_DELETE                = 0x101,
    AVIOCTRL_RECORD_DOWNLOAD_END        = 0x102,
}ENUM_PLAYCONTROL;

typedef enum
{
    ERR_INVALID_STATE = -1,
    // 安装阶段返回错误码
    /** 无效文件 */
    ERR_INVALID_FILE = 13,
    /** 内存不足 */
    ERR_LOW_MEMORY = 16,
    /** 存储空间不足 */
    ERR_LOW_SPACE = 17,
    /** 电量不足，小于30% */
    ERR_LOW_BATTERY = 18,
    /** 检查阶段 */
    RS_UI_STAGE_CHECK = 48,
    /** 检查结束 */
    RS_UI_STAGE_CHECK_END = 49,
    /** 下载阶段 */
    RS_UI_STAGE_DOWNLOAD = 50,
    /** 下载结束 */
    RS_UI_STAGE_DOWNLOAD_END = 51,
    /** 安装阶段 */
    RS_UI_STAGE_INSTALL = 52,
    /** 流程结束,非安装阶段 */
    RS_UI_STAGE_IDLE = 57,
    /** 检测失败 */
    ERR_CHECK_FAIL = 101,
    // 下载阶段返回错误码
    ERR_DOWNLOAD_FAIL = 102,
    /** 数据包和机器不匹配 */
    STATUS_CLIENT_UP_NOTMATCH = 1605,
    /** 升级包校验错误(下载后，发现校验值错误) */
    STATUS_CLIENT_UPVERIFY_FAILED = 1606,
}ENUM_AVIOCTRL_OTA_ROM_STATE;

//传递过来的参数
typedef struct
{
    unsigned short year;
    unsigned char month;
    unsigned char day;
}SEventDay;

typedef struct
{
    unsigned int  channel;
    SEventDay     stTime;
    unsigned char event;
    unsigned char index;
    unsigned char reserved[2];
}SMsgAVIoctrlGetTimeLineEventReq;

typedef struct
{
    unsigned short year;    // The number of year.
    unsigned char month;    // The number of months since January, in the range 1 to 12.
    unsigned char day;        // The day of the month, in the range 1 to 31.
    unsigned char wday;        // The number of days since Sunday, in the range 0 to 6. (Sunday = 0, Monday = 1, ...)
    unsigned char hour;     // The number of hours past midnight, in the range 0 to 23.
    unsigned char minute;   // The number of minutes after the hour, in the range 0 to 59.
    unsigned char second;   // The number of seconds after the minute, in the range 0 to 59.
}STimeDay;


typedef struct
{
    STimeDay stTime;
    unsigned char event;
    unsigned char status;    // 0x00: Recording file exists, Event unreaded
    // 0x01: Recording file exists, Event readed
    // 0x02: Have Recording file in the event
    unsigned char reserved[2];
}SAvEvent;

typedef struct
{
    int command;   // get snap picture command. refer to ENUM_GET_SNAP_PICTURE_CONTROL
    int type;      // 0:event num 1:get one snap  2:get all snap     3:get event num and all snap
    int index;
    SEventDay stTime;
    SAvEvent  stSnap[80];
}SMsgAVIoctrlGetSnapAndEventNumReq;

typedef struct
{
    SAvEvent  stSnap[80];
}SMsgAVIoctrlLiveGetSnapReq;

//IOTYPE_USER_IPCAM_SET_INIT_PARAMS_RESP        = 0x938,
typedef struct
{
    char deviceNameEnable;
    char appInfoEnable;
    char timeZoneEnable;
    char eventNumEnable;
    int deviceNameResult;
    int appInfoResult;
    int timeZoneResult;
    int eventNum;
    SAvEvent newEvent;
}SMsgAVIoctrlSetInitParamsResp;


/*
 IOTYPE_USER_IPCAM_LISTEVENT_REQ            = 0x0318,
 ** @struct SMsgAVIoctrlListEventReq
 */
typedef struct
{
    unsigned int channel;         // Camera Index
    STimeDay stStartTime;         // Search event from ...
    STimeDay stEndTime;              // ... to (search event)
    unsigned char event;          // event type, refer to ENUM_EVENTTYPE
    unsigned char status;         // 0x00: Recording file exists, Event unreaded
    // 0x01: Recording file exists, Event readed
    // 0x02: No Recording file in the event
    unsigned char reserved[2];
}SMsgAVIoctrlListEventReq;

/*
 IOTYPE_USER_IPCAM_LISTEVENT_RESP        = 0x0319,
 ** @struct SMsgAVIoctrlListEventResp
 */
typedef struct
{
    unsigned int  channel;        // Camera Index
    unsigned int  total;        // Total event amount in this search session
    unsigned char index;        // package index, 0,1,2...;
    // because avSendIOCtrl() send package up to 1024 bytes one time, you may want split search results to serveral package to send.
    unsigned char endflag;        // end flag; endFlag = 1 means this package is the last one.
    unsigned char count;        // how much events in this package
    unsigned char reserved[1];
    SAvEvent stEvent[80];        // The first memory address of the events in this package
}SMsgAVIoctrlListEventResp;

typedef struct
{
    unsigned char tm_min;
    unsigned char tm_hour;
    unsigned char tm_mday;
    unsigned char tm_mon;
    unsigned int tm_year;
    unsigned char tm_sec;
}timeDate;

typedef struct
{
    long long int timelineMinBit;
}timelineHourInfo;

typedef struct
{
    timelineHourInfo timelineHour[24];
}timelineDayInfo;

typedef struct
{
    timeDate startTime;
    timeDate endTime;
    timelineDayInfo timelineDay[3];
}SMsgAVIoctrlGetTimelineInfoResp;

/*
 IOTYPE_USER_IPCAM_SET_PTZ_REQ
 IOTYPE_USER_IPCAM_PTZ_COMMAND    = 0x1001,    // P2P Ptz Command Msg
 ** @struct SMsgAVIoctrlPtzCmd
 */
typedef struct
{
    unsigned char control;    // PTZ control command, refer to ENUM_PTZCMD
    unsigned char speed;    // PTZ control speed
    short angle;    //发转动命令时表示需要转动角度
    unsigned char cruiseType;        //0：关闭巡航，1：全天巡航，2：自定义时间巡航
    unsigned char presetmode;        //0:全景模式  1：预设点模式
    STimeDay startTime;
    STimeDay endTime;
    short presetPoint[8][2];   //二维数组代表二维云台，现在只用一维
    char presetDuration;        //预设点停留时间
    unsigned char reserve[48];
} SMsgAVIoctrlPtzCmd;

/*
 IOTYPE_USER_IPCAM_SET_PTZ_RESP                = 0x894,
 ** @struct SMsgAVIoctrlSetMotorResp
 */
typedef struct
{
    unsigned char control;
    char result; //  0:ture   -1 :fail
    char limit;  //  1:right limited  2:left limited  0:not limit
    unsigned char speed;    // PTZ control speed
    short angle;    //回复时表示收到命令时设备的位置
    unsigned char cruiseType;        //0：关闭巡航，1：全天巡航，2：自定义时间巡航
    unsigned char presetmode;        //0:全景模式  1：预设点模式
    STimeDay startTime;
    STimeDay endTime;
    short presetPoint[8][2];    //二维数组代表二维云台，现在只用一维  ，预设点内容为距离右边限位的步数，不是角度
    char presetDuration;        //预设点停留时间
    unsigned char reserve[48];
}SMsgAVIoctrlSetMotorResp;

/*
 IOTYPE_USER_IPCAM_EVENT_REPORT    = 0x1FFF,    // Device Event Report Msg
 */
/** @struct SMsgAVIoctrlEvent
 */
typedef struct
{
    STimeDay stTime;
    unsigned long time;     // UTC Time
    unsigned int  channel;     // Camera Index
    unsigned int  event;     // Event Type
    unsigned char reserved[4];
} SMsgAVIoctrlEvent;

/*
 IOTYPE_USER_IPCAM_RECORD_PLAYCONTROL     = 0x031A,
 ** @struct SMsgAVIoctrlPlayRecord
 */
typedef struct
{
    unsigned int channel;    // Camera Index
    unsigned int command;    // play record command. refer to ENUM_PLAYCONTROL
    unsigned int Param;        // command param, that the user defined
    STimeDay stTimeDay;        // Event time from ListEvent
    unsigned char reserved[4];
} SMsgAVIoctrlPlayRecord;

typedef struct
{
    STimeDay startTime;
    STimeDay endTime;
}DaylightSavingTimeInfo;

//alarm time info
typedef struct
{
    char startHour;
    char startMin;
    char endHour;
    char endMin;
}alarmTimeInfo;

typedef struct
{
    alarmTimeInfo alarmTimeInfos[6];
}SMsgAVIoctrlSetAlarmTimeInfoReq, SMsgAVIoctrlGetAlarmTimeInfoResp;


//alarm time info
typedef struct
{
    char start_hour;
    char start_min;
    char end_hour;
    char end_min;
}AlarmTimeInfo;

typedef struct AlarmInformation_t
{
    AlarmTimeInfo AlarmTimeInfos[6];
}AlarmInformation;

//IOTYPE_USER_IPCAM_GET_SYS_PARAMS_REQ
typedef struct DeviceInformation_t
{
    char model[16];
    char vendor[16];
    unsigned int version;
    int total_flash; //total_flash:-1   TF卡插入但是不支持格式
    int free_flash;  //free_flash:-1   TF卡插入但是不支持格式
}DeviceInformation;

typedef struct
{
    char enable;  //0:email close  1:email open
    char fun_support; //0: no support   1: support
    unsigned short port;
    
    char sMainServer[30];
    char sPasswd[30];
    char sMailFrom[30];
    
    char sMailTo[3][30];
    
    char encryption;
}EmailInfo;


// 报警区域
typedef struct
{
    unsigned short topLeftPointX;
    unsigned short topLeftPointY;
    unsigned short bottomRightPointX;
    unsigned short bottomRightPointY;
}AreaAlarmParameter;


//系统参数中获取的手机号码
typedef struct
{
    char sosNum[16];    //手机号码
}SosNoticeNum;

typedef struct
{
    int nTimeZoneOffset;
    int nTimeZoneStringId;
}TimeZoneInfo;

typedef struct
{
    timeDate timelinePoint;
}SMsgAVIoctrlSetTimelinePointReq;

//传递过来的参数
#define MAX_DELETE_NUM 100
typedef struct
{
    unsigned int index;
    STimeDay stTime[MAX_DELETE_NUM];
}SMsgAVIoctrlDelTimeLineEventReq;

//IOTYPE_USER_IPCAM_LIVE_GET_TIMELINE_INFO_REQ    = 0x961,
typedef struct
{
    STimeDay dataTime;      //时间轴时间
    int days;               //天数（需要的数据天数，1~3天）
    char type;              //2：Day，3:Hour
}SMsgAVIoctrlGetLiveTimeLineReq;

//数据包响应
typedef struct
{
    STimeDay startTime;      //数据开始时间
    unsigned char timeLine[3][60][60];      //3个小时的数据，10K
}SMsgAVIoctrlGetLiveTimeLineDataResp;


//IOTYPE_USER_IPCAM_SWITCH_ALARM_UPLOAD_AT_3G_REQ    = 0x963,
typedef struct
{
    int alarmUpload_enable;     //3G模式下报警是否上传，0：不支持，1：不上传，2：上传
}SMsgAVIoctrlSetAlarmUploadAt3GReq;

//IOTYPE_USER_IPCAM_SET_APP_INFO_REQ
//IOTYPE_USER_IPCAM_SET_APP_INFO_RESP

typedef struct
{
    unsigned int num;
    char appKey[36];
    char masterSecret[36];
}SMsgAVIoctrlSetAppInfoReq;


typedef struct
{
    int nIsSupportTimeZone;
    TimeZoneInfo TZInfo;
    int nIsSupportDaylightSavingTime;
    DaylightSavingTimeInfo DSTInfo;
}SMsgAVIoctrlTimeZone2;

#define MAX_DEVICE_NAME_LENGHT        128

//IOTYPE_USER_IPCAM_SET_INIT_PARAMS_REQ        = 0x937,
typedef struct
{
    char deviceNameEnable;
    char appInfoEnable;
    char timeZoneEnable;
    char eventNumEnable;
    char deviceName[MAX_DEVICE_NAME_LENGHT];
    SMsgAVIoctrlSetAppInfoReq appInfo;
    SMsgAVIoctrlTimeZone2 timeZone;
    char language;      //系统语言，0：ZH，1:EN
    char reserved[3];
}SMsgAVIoctrlSetInitParamsReq;

typedef struct
{
    char typeAreaAlarm;
    AreaAlarmParameter area_alarm_parameter[9];
}SMsgAVIoctrlSetAreaAlarmReq;

//IOTYPE_USER_IPCAM_SET_ALARM_NOTICE_REQ       = 0X953,
typedef struct
{
    SosNoticeNum sosNoticeNum[3];
    int noticeType;     //设置类型--> 0:不更改，1：短信通知，2：电话通知，3：电话次数
    char alarmNotice;   //0:关闭，1:开启
    char callCount;     //需要拨打电话的次数
    char reserved[6];
}SMsgAVIoctrlSetSoSAlarmNoticeReq;

//系统参数中获取的短信报警
typedef struct
{
    SosNoticeNum sosNoticeNum[3];
    char smsNotice;     //短信开关状态
    char phoneNotice;   //手机开关状态
    char callCount;     //拨打次数
    char reserved[1];   //保留位
}SosAlarmNotice;

/**
 The struct is only support 3.0+ sdk
 */
typedef struct
{
    char passwd[8];
    unsigned int tz_string_id;
    unsigned char app_id;
    unsigned char ftp_upload_type;
    unsigned char sound_off;
    unsigned char reserved[17];
    unsigned char ip_addr[4];
    unsigned char mac[6];
    unsigned char tz_offset;
    unsigned char platform;
    unsigned char binded;
    unsigned char record_type;
    char upload_type;
    unsigned char record_quality;
    unsigned char quality;
    unsigned char self_adaption_quality;
    unsigned char flip_mirror;
    unsigned char flicker_mode;
    unsigned char luminance;
    unsigned char contrast;
    unsigned char hue;
    unsigned char satuature;
    unsigned char led_off;
    unsigned char wds_enable;
    unsigned char night_vision_enable;  //0:关闭；1：开启；2：自动
    unsigned char volume;
    unsigned char alarm_enable;         //0:开启，1:关闭
    unsigned char motion_detect_sensitivity;
    unsigned char volume_alarm_sensitivity;
    unsigned char battery_level;
    unsigned char pd_level;
    unsigned char notify_mode;
    unsigned char mic_enable;
    AlarmInformation alarm_info;
    char reserved1[4];
    DeviceInformation device_info;
    DaylightSavingTimeInfo dst_info;
    char ota_local_version[32];             //OTA本地版本
    char ota_server_version[32];            //OTA服务器版本
    char alarmUpload_enable;                //3G模式下报警是否上传，0：不支持，1：不上传，2：上传
    char reserve[171];                      //预留空间
    char on_3g;                             //3G模式,0:WIFI，1:3G，2：无SIM卡
    char dropBoxAuthorizeState;             //设备DropBox认证状态
    char devideLanguage;                    //设备系统语言类型，0:ZH，1:EN
    char alarmDuration;                     //报警消息时长
    SosAlarmNotice sosAlarmNotice;          //电话短信结构体
    char cloud_storage_enable;              //云端存储,0:不允许，1：允许
    char enableAlarmRecAllDay;              //0:不允许全天报警 1：允许全天报警
    char enableTimeLineRecAllDay;           //0:不允许全天SD卡录像 1：允许全天SD卡录像
    char enableAlarmRecTimeInterval1;
    char enableAlarmRecTimeInterval2;
    char enableAlarmRecTimeInterval3;
    char enbaleTimeLineRecTimeInterval1;
    char enableTimeLineRecTimeInterval2;
    char enbaleTimeLineRecTimeInterval3;
    char enbale_humanoid_detection;         //人形检测
    char hotpot_enable;                     //热点
    char enableVideoOnVoiceDetect;          //当声音侦测时，是否启动录制视频画面
    char isSupportVoiceDetect;              //是否支持声音侦测
    char isSupportHumanoidDetection;        //支持人形检测    //(BETY位置:461)
    char pushMediaContentType;              //推送是否包含图片和视频资源，0：不支持，1：开启，2：关闭
    char faceRectMinimumWidth;              //人脸识别截图时人脸的宽度最小值，小于这个值不截图 ,范围50--100
    int faceRectLeftOffSet;                 //人脸检测区域左偏移量
    int faceRectRightOffSet;                //人脸检测区域右偏移量
    int faceRectTopOffSet;                  //人脸检测区域上偏移量
    int faceRectBottomOffSet;               //人脸检测区域下偏移量
    int faceRectMaximumWidth;               //人脸识别截图时人脸的宽度最大值，大于这个值不截图，范围
    char voiceEnabledOnFaceDetect;          //人脸截图时是否发出声音，0不发出，1发出（默认为0）
    char cameraZoomValue;                   //变焦倍数，默认0，最大10
    
    char reserve1;
    char alarmWhistleDuration;
    char alarmWhistleWhenHumanCheck;
    char alarmWhistleWhenMotionDetect;
    char alarmWhistleWhenVoiceDetect;
    char supportAlarmWhistle;
    char isPrivateMode;  //隐私模式 0：不是，非0：是
    EmailInfo email_alarm_info;
    char enableHightSensitivity; //char 1; 0不允许， 1 允许   侦测高灵敏度
    char supportAreaAlarm; // index 681; char 1; 0不支持， 1 支持
    char enableAreaAlarm;  // index 682; char 1; 0不允许， 1 允许
    char typeAreaAlarm; // 报警区域类型 目前只定义 0：矩形
    AreaAlarmParameter area_alarm_parameter[9];
} SMsgAVIoctrlGetSysParamsResp, SMsgAVIoctrlSetSysParamsReq;

#define MAX_PARAMS_LEN 1024
typedef struct
{
    char params[MAX_PARAMS_LEN];     //通用设置接口
}SMsgAVIoctrlSetCommonParamsReq;

typedef struct
{
    char result[MAX_PARAMS_LEN];     //通用接收接口
}SMsgAVIoctrlSetCommonParamsResp;



#endif /* CmdStructTool_h */
