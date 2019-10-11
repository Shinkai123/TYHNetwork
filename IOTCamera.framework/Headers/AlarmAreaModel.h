//
//  AlarmAreaModel.h
//  IOTCamera
//
//  Created by YaoHua Tan on 2019/9/5.
//  Copyright © 2019 concox. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AlarmAreaModel : NSObject

@property (nonatomic, assign) CGPoint topLeftPoint;
@property (nonatomic, assign) CGPoint bottomRightPoint;
@property (nonatomic, assign) NSInteger tag;

@end

NS_ASSUME_NONNULL_END
