//
//  Extension_TYHNetworkMoudle.swift
//  TYHNetwork
//
//  Created by YaoHua Tan on 2019/9/24.
//  Copyright © 2019 YaoHua Tan. All rights reserved.
//

import Foundation
import CTMediator
import Alamofire

public typealias TYHParams = Dictionary<String, Any>

//请求结果回调
public typealias TYHRequestResultCallBack = (_ result: [String: Any]?, _ data:Data?, _ error:Error?) -> ()

//配置参数回调
public typealias TYHConfigParamsCallBack = (_ url:String, _ params:[String: Any]) -> [String: Any]

//配置Header参数
public typealias TYHConfigHeadersCallBack = () -> [String : String]

//token失效过期回调
public typealias TYHRequestTokenTimeOutCallBack = () -> ()

//TargetName
let TYHTargetMoudleName = "TYHNetwork"
//TargetMoudleName
let TYHRequest_TargetName = "TYHNetwork"

//下载类的请求参数
enum TYHAction: String {
    //设置公共参数
    case TYHNetworkConfigParam = "networkConfigParam"
    //设置基础URL
    case TYHNetworkConfigBaseURL = "networkConfigBaseURL"
    //设置Header
    case TYHNetworkConfigHeader = "networkConfigHeader"
    //请求数据
    case TYHNetworkRequestData = "networkRequestData"
    //添加下载任务
    case TYHNetworkAddDownloadTask = "networkAddDownloadTask"
    //暂停下载任务
    case TYHNetworkPauseDownloadTask = "networkPauseDownloadTask"
    //恢复下载认识
    case TYHNetworkResumeDownloadTask = "networkResumeDownloadTask"
    //获取下载进度
    case TYHNetworkGetDownloadProgress = "networkGetDownloadProgress"
    //结束任务
    case TYHNetworkCancelDownloadTask = "networkCancelDownloadTask"
    //获取进度回调
    case TYHNetworkProgressCallBack = "networkProgressCallBack"
    //回调下载结果
    case TYHNetworkFinishCallBack = "NetworkFinishCallBack"
    //token失效过期回调
    case TYHNetworkRequestTokenTimeOutCallBack = "networkTokenTimeOutCallBack"
}

public extension CTMediator {
    //请求数据 URLConvertible:用于NSURL和String之间的相互转换
    func tyh_networkRequest(_ url: URLConvertible,
                            parameters: TYHParams? = [String:Any](),
                            requestType:HTTPMethod,
                            requestCallBack:@escaping TYHRequestResultCallBack) {
        let params = ["url" : url,
                      "params" : parameters as Any,
                      "requestType" : requestType,
                      "requestCallback" : requestCallBack] as [AnyHashable : Any]
        self.performTarget(TYHRequest_TargetName, action: TYHAction.TYHNetworkRequestData.rawValue, params: tyh_networkSetupTargetMoudleName(params), shouldCacheTarget: false)
    }
    
    //配置基础URL
    func tyh_networkConfingBaseURL(baseURL : String) {
        let params = ["baseURL" : baseURL] as [AnyHashable : Any]
        self.performTarget(TYHRequest_TargetName, action: TYHAction.TYHNetworkConfigBaseURL.rawValue, params: tyh_networkSetupTargetMoudleName(params), shouldCacheTarget: false)
    }
    
    //配置公共参数
    func tyh_networkConfigParams(configParamsCallBack : @escaping TYHConfigParamsCallBack) {
        let params = ["configParamsCallBack" : configParamsCallBack] as [AnyHashable : Any]
        self.performTarget(TYHRequest_TargetName, action: TYHAction.TYHNetworkConfigParam.rawValue, params: tyh_networkSetupTargetMoudleName(params), shouldCacheTarget: false)
    }
    
    //配置Header参数
    func tyh_networkConfigHeaderCallBack(configHeaderCallBack :@escaping TYHConfigHeadersCallBack) {
        let params = ["configHeaderCallBack" : configHeaderCallBack] as [AnyHashable : Any]
        self.performTarget(TYHRequest_TargetName, action: TYHAction.TYHNetworkConfigHeader.rawValue, params: tyh_networkSetupTargetMoudleName(params), shouldCacheTarget: false)
    }
    
    //添加下载任务
    func tyh_networkAddDownloadTask(_ url:String, filePath:String) {
        let params = ["url" : url,
        "filePath" : filePath] as [AnyHashable : Any]
        self.performTarget(TYHRequest_TargetName, action: TYHAction.TYHNetworkAddDownloadTask.rawValue, params: tyh_networkSetupTargetMoudleName(params), shouldCacheTarget: false)
    }
    
    
    //暂停下载任务
    func tyh_networkPauseDownloadTask(_ url : String) {
        let params = ["url" : url] as [AnyHashable : Any]
        self.performTarget(TYHRequest_TargetName, action: TYHAction.TYHNetworkPauseDownloadTask.rawValue, params: tyh_networkSetupTargetMoudleName(params), shouldCacheTarget: false)
    }
    
    //恢复下载任务
    func tyh_networkResumeDownloadTask(_ url : String) {
        let params = ["url" : url] as [AnyHashable : Any]
        self.performTarget(TYHRequest_TargetName, action: TYHAction.TYHNetworkResumeDownloadTask.rawValue, params: tyh_networkSetupTargetMoudleName(params), shouldCacheTarget: false)
    }
    
    //结束任务
    func tyh_networkCancelDownloadTask(_ url : String) {
        let params = ["url" : url] as [AnyHashable : Any]
        self.performTarget(TYHRequest_TargetName, action: TYHAction.TYHNetworkCancelDownloadTask.rawValue, params: tyh_networkSetupTargetMoudleName(params), shouldCacheTarget: false)
    }
    
    //获取下载进度
    func tyh_networkGetDownlandProgress(_ progressCallBack : @escaping DownloadProgressCallBack) {
        let params = ["progressCallBack" : progressCallBack] as [AnyHashable : Any]
        self.performTarget(TYHRequest_TargetName, action: TYHAction.TYHNetworkProgressCallBack.rawValue, params: tyh_networkSetupTargetMoudleName(params), shouldCacheTarget: false)
    }
    
    //下载结束回调
    func tyh_networkFinishCallBack(_ finishCallBack : @escaping DownloadFinishCallBack) {
        let params = ["finishCallBack" : finishCallBack] as [AnyHashable : Any]
        self.performTarget(TYHRequest_TargetName, action: TYHAction.TYHNetworkFinishCallBack.rawValue, params: tyh_networkSetupTargetMoudleName(params), shouldCacheTarget: false)
    }
    
    //token失效过期回调
    func tyh_networkRequestTokenTimeOutCallBack(_ finishCallBack : @escaping TYHRequestTokenTimeOutCallBack) {
        let params = ["finishCallBack" : finishCallBack]
        self.performTarget(TYHRequest_TargetName, action: TYHAction.TYHNetworkRequestTokenTimeOutCallBack.rawValue, params: tyh_networkSetupTargetMoudleName(params), shouldCacheTarget: false)
    }
    
    
    //增加swift区别参数
    func tyh_networkSetupTargetMoudleName(_ params:[AnyHashable : Any]) -> [AnyHashable : Any] {
        let params = NSMutableDictionary.init(dictionary: params)
        params[kCTMediatorParamsKeySwiftTargetModuleName] = TYHTargetMoudleName
        return params as! [AnyHashable : Any]
    }
}

//MARK:-错误码

//获取APP自定义显示的code码对应内容
let tyhNetworkGetAppErrorCodeMessage = "networkGetAppErrorCodeMessage"
//获取服务器端口默认返回的结果消息
let tyhNetworkGetServerMessage = "NetworkGetServerMessage"

public extension CTMediator {
    func tyh_networkGetAppErrorCodeMessage(_ code:Int) -> String {
        let params = ["code" : code]
        return self.performTarget(TYHRequest_TargetName, action: tyhNetworkGetAppErrorCodeMessage, params: tyh_networkSetupTargetMoudleName(params), shouldCacheTarget: false) as! String
    }
    
    //获取服务器接口默认返回的结果消息
    func tyh_networkGetServerMessage(_ jsonDict : [String : Any]) -> String {
        let params = ["jsonDict" : jsonDict]
        return self.performTarget(TYHRequest_TargetName, action: tyhNetworkGetServerMessage, params: tyh_networkSetupTargetMoudleName(params), shouldCacheTarget: false) as! String
    }
}
