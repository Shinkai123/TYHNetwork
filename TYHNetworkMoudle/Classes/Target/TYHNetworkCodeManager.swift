//
//  TYHNetworkCodeManager.swift
//  TYHNetwork
//
//  Created by YaoHua Tan on 2019/9/24.
//  Copyright © 2019 YaoHua Tan. All rights reserved.
//

import UIKit


let ServerRespondResultUnknownException        = -1 //未知错误

let ServerRespondResultNoNetwork               = -2 //无网络

let ServerRespondResultSuccessed                 = 0 //操作或查询成功

let ServerRespondResultSystemException         = 100 //系统异常

let ServerRespondResultParameterError          = 101 //请求参数不完整或格式不正确

let ServerRespondResultVerifyTimeOut           = 102 //验证已经超时

let ServerRespondResultLinkTimeOut             = 103 //验证链接已失效(错误或超时)

let ServerRespondResultUserNotExist            = 104 //用户不存在

let ServerRespondResultDidRegister             = 200 //邮箱地址已经注册过

let ServerRespondResultNoVerify                = 201 //该登录邮箱还没有进行验证

let ServerRespondResultDiscordedPWD            = 202 //两次输入的密码不一致

let ServerRespondResultNoMail                  = 203 //该邮箱地址没有注册过

let ServerRespondResultLoginError              = 204 //登录邮箱或密码错误，未通过登录验证

let ServerRespondResultDidVerify               = 205 //该邮箱已经验证过

let ServerRespondResultDeviceBounded           = 300 //设备已经绑定

let ServerRespondResultDeviceNone              = 301 //设备没有找到，(该设备从没有人绑定过)

let ServerRespondResultDeviceNoUnbound         = 302 //设备未绑定

let ServerRespondResultShareMailNoRegister     = 303 //分享的邮箱没有注册过

let ServerRespondResultDeviceUnbounded         = 304 //设备已经解绑过

let ServerRespondResultDeviceNotOneself        = 305 //你不是该设备的主人

let ServerRespondResultDeviceHadShare          = 306 //该摄像头已经分享给该用户，且该用户已经绑定了

let ServerRespondResultDeviceNoShareSelf       = 307 //不能分享给自己

let ServerRespondResultPasswordError           = 308 //密码错误

let ServerRespondResultDeviceShareFail         = 309 //设备分享失败

let ServerRespondResultPhoneNoRegister         = 501 //手机号已被注册

let ServerRespondResultPhoneCodeTimeOut        = 502 //短信验证码已过期

let ServerRespondResultPhoneCodeSendFail       = 503 //短信验证码发送失败

let ServerRespondResultPhoneCodeSendMax        = 504 //短信验证码发送次数已超过最大限制次数

let ServerRespondResultPhoneCodeDiscordedPWD   = 505 //短信验证码不一致

let ServerRespondResultPhoneCodeInvalid        = 506 //短信验证码无效（验证码未发送或已过期）

let ServerRespondResultPhoneShareCodeInvalid   = 507 //短信分享口令无效（分享口令错误或已过期）

let ServerRespondResultPhoneShareAccountDiscorded = 508 //被分享者手机号不一致

let ServerRespondResultPhoneCodeSendNormalButTimeOut = 509 //短信发送正常，但响应超时

let ServerRespondResultWechatNoBindPhone       = 510 //微信登录未绑定手机号码

let ServerRespondResultPhoneIsBound            = 511 //手机号已被绑定

let ServerRespondResultWechatBoundPhone        = 512 //微信已绑定手机号

public func TYHNetworkCode(_ code:Int) -> String {
    switch code {
    case ServerRespondResultUnknownException:
        return "未知错误"
    case ServerRespondResultNoNetwork:
        return "无网络"
    case ServerRespondResultSuccessed:
        return "成功"
    case ServerRespondResultSystemException:
        return "系统错误"
    case ServerRespondResultParameterError:
        return "参数错误"
    case ServerRespondResultVerifyTimeOut:
        return "验证已经超时"
    case ServerRespondResultLinkTimeOut:
        return "链接超时"
    case ServerRespondResultUserNotExist:
        return "用户不存在"
    case ServerRespondResultDidRegister:
        return "邮箱地址已经注册过"
    case ServerRespondResultNoVerify:
        return "邮箱未验证"
    case ServerRespondResultDiscordedPWD:
        return ""
    case ServerRespondResultNoMail:
        return "该邮箱地址没有注册过"
    case ServerRespondResultLoginError:
        return "登录邮箱或密码错误"
    case ServerRespondResultDidVerify:
        return "该邮箱已经验证过"
    case ServerRespondResultDeviceBounded:
        return "设备已经绑定"
    case ServerRespondResultDeviceNone:
        return "设备没有找到"
    case ServerRespondResultDeviceNoUnbound:
        return "设备未绑定"
    case ServerRespondResultShareMailNoRegister:
        return "邮箱未注册"
    case ServerRespondResultDeviceUnbounded:
        return "设备已解绑"
    case ServerRespondResultDeviceNotOneself:
        return "你不是改设备的主人"
    case ServerRespondResultDeviceHadShare:
        return "此设备已分享给改用户"
    case ServerRespondResultDeviceNoShareSelf:
        return "不能分享给自己"
    case ServerRespondResultPasswordError:
        return "密码错误"
    case ServerRespondResultDeviceShareFail:
        return "设备分享失败"
    case ServerRespondResultPhoneNoRegister:
        return "手机号已被注册"
    case ServerRespondResultPhoneCodeTimeOut:
        return "短信验证码已过期"
    case ServerRespondResultPhoneCodeSendFail:
        return "短信验证码发送失败"
    case ServerRespondResultPhoneCodeSendMax:
        return "短信验证码发送次数已超过最大限制次数"
    case ServerRespondResultPhoneCodeDiscordedPWD:
        return "短信验证码不一致"
    case ServerRespondResultPhoneCodeInvalid:
        return "短信验证码无效"
    case ServerRespondResultPhoneShareCodeInvalid:
        return "短信分享口令无效"
    case ServerRespondResultPhoneShareAccountDiscorded:
        return "被分享者手机号不一致"
    case ServerRespondResultPhoneCodeSendNormalButTimeOut:
        return "短信发送正常，但响应超时"
    case ServerRespondResultWechatNoBindPhone:
        return "微信登录未绑定手机号码"
    case ServerRespondResultPhoneIsBound:
        return "手机号已被绑定"
    case ServerRespondResultWechatBoundPhone:
        return "微信已绑定手机号"
    default:
        return "未知错误"
    }
}
