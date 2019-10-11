//
//  TYHDownloadManager.swift
//  TYHNetwork
//
//  Created by YaoHua Tan on 2019/9/24.
//  Copyright © 2019 YaoHua Tan. All rights reserved.
//

import Foundation
//import Alamofire

//下载进度回调
public typealias DownloadProgressCallBack = (_ progress:Any, _ data:Data, _ url:String) -> ()
//下载结果回调
public typealias DownloadFinishCallBack = (_ result:DownloadState, _ url : String) -> ()

class TYHDownloadManager: NSObject {
    static let defalut: TYHDownloadManager = TYHDownloadManager ()
    
    //下载进度回调
    public var downloadProgressCallBack : DownloadProgressCallBack?
    //下载结果回调
    public var downloadFinishCallBack : DownloadFinishCallBack?
    
    //存储下载请求
    fileprivate var taskEntrepot : NSMutableDictionary = NSMutableDictionary()
    
    //开始下载
    public func downloadTask(_ url: String, filePath: String) {
        let download = TYHDownloader (url:url, filePath : filePath)
        download.resumeTask()
        taskEntrepot[url] = download
    }
}

//任务的操作管理
extension TYHDownloadManager {
    //暂停任务
    func pauseTask(_ url:String) {
        if taskEntrepot[url] != nil {
            let downloadTask = taskEntrepot[url] as! TYHDownloader
            downloadTask.pauseTask()
        }
    }
    
    //取消任务
    func cancelTask(_ url:String) {
        if taskEntrepot[url] != nil {
            let downloadTask = taskEntrepot[url] as! TYHDownloader
            downloadTask.cancelTask()
        }
    }

    //恢复任务
    func resumeTask(_ url:String) {
        if taskEntrepot[url] != nil {
            let downloadTask = taskEntrepot[url] as! TYHDownloader
            downloadTask.resumeTask()
        }
    }
}
