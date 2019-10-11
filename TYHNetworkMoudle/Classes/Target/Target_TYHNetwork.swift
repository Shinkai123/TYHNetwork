//
//  Target_TYHNetwork.swift
//  TYHNetwork
//
//  Created by YaoHua Tan on 2019/9/25.
//  Copyright © 2019 YaoHua Tan. All rights reserved.
//

import UIKit
import Alamofire

var tyhConfigParamsCallBack: TYHConfigParamsCallBack? = nil
var tyhConfigHearderCallBack: TYHConfigHeadersCallBack? = nil
var tyhRequestTokenTimeOutCallBack: TYHRequestTokenTimeOutCallBack? = nil
var baseURL: String? = nil


@objc class Target_TYHNetwork: NSObject {
    //请求数据
    @objc func Action_networkRequestData(_ params: Dictionary<String, Any>) {
        guard let urlStr = params["url"] as? String,
              let parameters = params["params"] as? TYHParams,
              let type = params["requestType"] as? HTTPMethod,
              let requestCallback = params["requestCallback"] as? TYHRequestResultCallBack else {
            return
        }
        guard var tempBaseURL = baseURL else {
            return
        }
        tempBaseURL += urlStr
        var tempParams = parameters
        if tyhConfigParamsCallBack != nil {
            tempParams = tyhConfigParamsCallBack?(urlStr, parameters) ?? [String : Any]()
        }
        requestData(url: tempBaseURL, params: tempParams, type: type, requestCallback: requestCallback)
    }
    
    //配置基础URL
    @objc func Action_networkConfigBaseURL(_ params: Dictionary<String, Any>) {
        guard let tempBaseURL = params["baseURL"] as? String else {
            return
        }
        baseURL = tempBaseURL
    }
    
    //配置Header参数
    @objc func Action_networkConfigHeader(_ params: Dictionary<String, Any>) {
        guard let configHeadersCallBack = params["configHeaderCallBack"] as? TYHConfigHeadersCallBack else {
            return
        }
        tyhConfigHearderCallBack = configHeadersCallBack
    }
    
    //配置公共参数
    @objc func Action_networkConfigParams(_ params: Dictionary<String, Any>) {
        guard let configParamsCallBack = params["configParamsCallBack"] as? TYHConfigParamsCallBack else {
            return
        }
        tyhConfigParamsCallBack = configParamsCallBack
    }
    
    //添加下载任务
    @objc func Action_networkAddDownloadTask(_ params: Dictionary<String, Any>) {
        guard let url = params["url"] as? String, let filePath = params["filePath"] as? String else {
            return
        }
        TYHDownloadManager.defalut.downloadTask(url, filePath: filePath)
    }
    
    //暂停下载任务
    @objc func Action_networkPauseDownloadTask(_ params: Dictionary<String, Any>) {
        guard let url = params["url"] as? String else {
            return
        }
        TYHDownloadManager.defalut.pauseTask(url)
    }
    
    //恢复下载任务
    @objc func Action_networkResumeDownloadTadk(_ params: Dictionary<String, Any>) {
        guard let url = params["url"] as? String else {
            return
        }
        TYHDownloadManager.defalut.resumeTask(url)
    }
    
    //结束下载任务
    @objc func Action_networkCancelDownlandTask(_ params: Dictionary<String, Any>) {
        guard let url = params["url"] as? String else {
            return
        }
        TYHDownloadManager.defalut.cancelTask(url)
    }
    
    @objc func Action_networkProgressCallBack(_ params: Dictionary<String, Any>) {
        TYHDownloadManager.defalut.downloadProgressCallBack = params["progressCallback"] as? DownloadProgressCallBack
    }
    
    @objc func Action_networkFinishCallBack(_ params: Dictionary<String, Any>) {
        TYHDownloadManager.defalut.downloadFinishCallBack = params["finishCallBack"] as? DownloadFinishCallBack
    }
    
    @objc func Action_networkTokenTimeOutCallBack(_ param: Dictionary <String, Any>) {
        tyhRequestTokenTimeOutCallBack = param["finishCallBack"] as? TYHRequestTokenTimeOutCallBack
    }
}

// MARK -
extension Target_TYHNetwork {
    //网络请求
    fileprivate func requestData(url: URLConvertible,
                                 params: Parameters? = nil,
                                 type:HTTPMethod,
                                 requestCallback:@escaping TYHRequestResultCallBack) {
        request(url, method: type, parameters: params, encoding: URLEncoding.default, headers: tyhConfigHearderCallBack?()).responseJSON { (response) in
            var json: [String: Any]? = nil
            var error: NSError? = nil
            switch response.result {
            case .success(let caseJson):
                if let dict = caseJson as? [String : Any] {
                    json = dict
                    if let code = dict["code"] as? Int {
                        _ = TYHNetworkCode(code)
                    }
                } else {
                    error = NSError.init(domain: TYHNetworkCode(ServerRespondResultUnknownException), code: ServerRespondResultUnknownException, userInfo: nil)
                }
            case .failure(_):
                error = NSError.init(domain: TYHNetworkCode(ServerRespondResultUnknownException), code: ServerRespondResultUnknownException, userInfo: nil)
            }
            requestCallback(json, response.data, error)
        }
    }
}

//mark - 请求错误码
extension Target_TYHNetwork {
    //获取App自定义显示的code码对应内容
    @objc func Action_networkGetAppErrorCodeMessage(_ params: Dictionary<String, Any>) -> String {
        if let code = params["code"] as? Int {
            return TYHNetworkCode(code)
        }
        return TYHNetworkCode(9999)
    }
    
    //获取服务器接口默认返回的结果消息
    @objc func Action_networkGetServerMessage(_ params: Dictionary<String, Any>) -> String {
        if let dict = params["jsonDict"] as? [String : Any], let message = dict["message"] as? String {
            return message
        }
        return TYHNetworkCode(9999)
    }
}
