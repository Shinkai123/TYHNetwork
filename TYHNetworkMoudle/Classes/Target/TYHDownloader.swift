//
//  TYHDownloader.swift
//  TYHNetwork
//
//  Created by YaoHua Tan on 2019/9/24.
//  Copyright © 2019 YaoHua Tan. All rights reserved.
//

import UIKit

public enum DownloadState {
    case success
    case failture
}

class TYHDownloader: NSObject {
    var my_filePath:String = ""
    var downloadTask:URLSessionTask?
    var totalLen = 0
    var existLen = 0
    init(url:String,filePath:String) {
        super.init()
        var dataBytes = 0
        if FileManager.default.fileExists(atPath: filePath) {
            //                print(FileManager.default.contents(atPath: filePath)?.count)
            dataBytes = (FileManager.default.contents(atPath: filePath)?.count)!
        }else {
            FileManager.default.createFile(atPath: filePath, contents: nil, attributes: nil)
        }
        existLen = dataBytes
        // 0.2 获取请求对象
        let request = NSMutableURLRequest(url: URL(string: url)!)
        // 1.创建请求头信息
        let range = String(format: "bytes=%ld-",dataBytes)
        request.setValue(range, forHTTPHeaderField: "Range")
        // 2.创建任务
        let session = URLSession(configuration: URLSessionConfiguration.default, delegate: self, delegateQueue: OperationQueue.main)
        
        // 3.开始任务，并把任务放到字典中管理
        downloadTask = session.dataTask(with: request as URLRequest)
        // 4.用字典保存任务和路径
        my_filePath = filePath
    }
}

extension TYHDownloader:URLSessionDataDelegate {
    func urlSession(_ session: URLSession, dataTask: URLSessionDataTask, didReceive data: Data) {
        //0.0 下载进度
        let progress:CGFloat = CGFloat(existLen + Int(dataTask.countOfBytesReceived))/CGFloat(totalLen)
        //0.1 当前的URL
        let url = dataTask.response?.url?.absoluteString ?? ""
        //1.0 回调结果
        TYHDownloadManager.defalut.downloadProgressCallBack?(progress,data,url)
        //2.0 写入数据
        do {
            let fileHand = try FileHandle(forWritingTo: URL(string: my_filePath)!)
            fileHand.seekToEndOfFile()
            fileHand.write(data)
        } catch {

        }
    }
    
    func urlSession(_ session: URLSession, task: URLSessionTask, didCompleteWithError error: Error?) {
        //0.1 当前的URL
        let url = task.response?.url?.absoluteString ?? ""
        //1.0 成功和失败的判断
        if error == nil {
            TYHDownloadManager.defalut.downloadFinishCallBack?(.success, url)
            return
        }
        TYHDownloadManager.defalut.downloadFinishCallBack?(.failture, url)
    }
    
    func urlSession(_ session: URLSession, dataTask: URLSessionDataTask, didReceive response: URLResponse, completionHandler: @escaping (URLSession.ResponseDisposition) -> Void) {
        totalLen = Int(existLen + Int(response.expectedContentLength))
        completionHandler(.allow)
    }
}

//任务的操作管理
extension TYHDownloader {
    //暂停任务
    func pauseTask() {
        downloadTask?.suspend()
    }
    
    //取消任务
    func cancelTask() {
        downloadTask?.cancel()
    }
    
    //恢复任务
    func resumeTask() {
        downloadTask?.resume()
    }
}
