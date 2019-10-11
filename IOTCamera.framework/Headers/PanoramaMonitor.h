//
//  PanoramaMonitor.h
//  IOTCamera
//
//  Created by lzj<lizhijian_21@163.com> on 2017/12/19.
//  Copyright © 2017年 concox. All rights reserved.
//

#import <GLKit/GLKit.h>

typedef enum : NSUInteger {
    PANORAME_SHOW_TYPE_NONE = 0,            //默认模式1
    PANORAME_SHOW_TYPE_CIRCULAR = 1,        //圆形
    PANORAME_SHOW_TYPE_DOUBLEPLANE = 2,     //双平面
    PANORAME_SHOW_TYPE_CYLINDER = 3,        //圆柱
    PANORAME_SHOW_TYPE_FOURVIEW = 4,        //四视口
    PANORAME_SHOW_TYPE_SINGLEPLANE = 5,     //单平面
    PANORAME_SHOW_TYPE_HEMISPHERE_A = 6,    //半球A
    PANORAME_SHOW_TYPE_HEMISPHERE_B = 7,    //半球B
    PANORAME_SHOW_TYPE_ORIGINAL = 8,        //原始
    PANORAME_SHOW_TYPE_MAX,                 //无效
} PANORAME_SHOW_TYPE;

@interface PanoramaMonitor : GLKView

@property (nonatomic,strong) UIImage *image;
@property (nonatomic,assign) BOOL isSquarePanoramic;//正方形画面全景摄像机

- (instancetype)init;

/**
 初始化全景摄像机视图

 @param frame view的frame大小
 @return 视图对象
 */
- (instancetype)initWithFrame:(CGRect)frame;

/**
 刷新显示
 */
- (void)refreshShow;

/**
 改变视图显示模式(类型)

 @param showType 视图类型(PANORAME_SHOW_TYPE)
 */
- (void)changeShowType:(PANORAME_SHOW_TYPE)showType;

/**
 开启自动巡航
 */
- (void)startAutoCruise;

/**
 关闭自动巡航
 */
- (void)stopAutoCruise;

/**
 使用RGB显示一帧画面

 @param w 画面宽度
 @param h 画面高度
 @param ppdata RGB24数据地址
 */
- (void)displayRGB:(int)w height:(int)h data:(void**)ppdata;

/**
 设置半圆相关参数

 @param angle 半球模式下圆弧大小(0~360)
 @param radius 中心显示的圆在视图上所占的比例(0~1.0)
 @param x x起点在视图x轴上所占的比例(0~1.0)
 @param y y起点在视图y轴上所占的比例(0~1.0)
 */
- (void)setVideoAngle:(CGFloat)angle radius:(CGFloat)radius offsetX:(CGFloat)x offsetY:(CGFloat)y;

/**
 每秒刷新的帧数

 @param count 帧数,默认为25帧
 */
- (void)preferredFramesPerSecond:(NSUInteger)count;

/**
 画面旋转角度，默认是0度
 #默认只对单圆、单面模式有作用
 #可能在某些特殊场景或画面试下需要手动旋转画面达到效果

 @param angle 角度(0~360);
 */
- (void)setVideoRotationAngle:(CGFloat)angle;

/**
 是否正在执行轻扫手势动画

 @return YES:正在执行动画
 */
- (BOOL)isRunPanAnimation;

@end
