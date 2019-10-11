//
//  ViewController.swift
//  TYHNetwork
//
//  Created by YaoHua Tan on 2019/9/24.
//  Copyright © 2019 YaoHua Tan. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        self.view.addSubview(testBtn)
        
    }

    lazy var testBtn: UIButton  =  {
        let testBtn = UIButton()
        testBtn.frame = CGRect(x: 100, y: 100, width: 200, height: 50)
        testBtn.setTitle("test", for: UIControl.State.normal)
        testBtn.setTitleColor(UIColor.white, for: UIControl.State.normal)
        testBtn.backgroundColor = UIColor.blue
        testBtn.layer.cornerRadius = 5.0
        testBtn.layer.masksToBounds = true
        testBtn.addTarget(self, action: #selector(ViewController.testAction), for: UIControl.Event.touchUpInside)
        return testBtn
    }()
    
    @objc func testAction() {
        
        CTMediator.sharedInstance()?.tyh_networkConfigParams(configParamsCallBack: { (url, params) -> [String : Any] in
            let params = NSMutableDictionary.init()
            params.setValue("1210480377@qq.com", forKey: "email")
            params.setValue("pass", forKey: "123456")
            return params as! TYHParams
        })
        
        let params1 = ["email" : "1210480377@qq.com", "pass" : "123456"]

//        params1.setValue("1210480377@qq.com", forKey: "email")
//        params1.setValue("123456", forKey: )
//        return params as! TYHParams
        CTMediator.sharedInstance()?.tyh_networkRequest("userLogin.api", parameters: params1 as? TYHParams, requestType: .post, requestCallBack: { (responseJson, result, error) in
            print("\(String(describing: responseJson))")
        })
    }
}

