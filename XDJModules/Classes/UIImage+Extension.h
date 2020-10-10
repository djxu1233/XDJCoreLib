//
//  UIImage+Extension.h
//  BMY_H5
//
//  Created by MAC on 2018/10/4.
//  Copyright © 2018年 MAC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (Extension)

/**
 *  @brief  根据颜色生成纯色图片
 *
 *  @param color 颜色
 *
 *  @return 纯色图片
 */
+ (UIImage *)imageWithColor:(UIColor *)color;

/**
 生成一张渐变色的图片
 @param colors 颜色数组
 @param rect 图片大小
 @return 返回渐变图片
 */
+ (UIImage *)gradientImageWithColors:(NSArray *)colors startPoint:(CGPoint)startPoint endPoint:(CGPoint)endPoint rect:(CGRect)rect;

/**
 @brief 画一个倒三角
 @param size 三角形的大小
 @param tintColor 三角形的颜色
 @return 返回三角形图片
 */
+ (UIImage *)triangleImageWithSize:(CGSize)size tintColor:(UIColor *)tintColor;

/** 按给定的方向旋转图片 */
- (UIImage*)rotate:(UIImageOrientation)orient;


/*
 图片的缩处理
 
 我这里首先用的是缩的处理。
 这里我将图片分为三种情况进行处理
 
 1）宽高均大于1280，取较大值等于1280，较大值等比例压缩
 
 2）宽或高一个大于1280，取较大的等于1280，较小的等比压缩
 
 3）宽高均小于1280，压缩比例不变
 
 对于缩的处理，图片是不会失真的，只是变小而已。
 */
+(UIImage *)zipScaleWithImage:(UIImage *)sourceImage;

/*
 图片的压处理
 
 对于“压”的功能，使用的UIImageJPEGRepresentation或UIImagePNGRepresentation方法实现。
 这里我也分了三种关于图片画质的压缩
 
 1）图片大于1M的，将压缩系数调整到0.7
 
 2）图片在0.5M<image<1M,将压缩系数调整到0.8
 
 3）图片小雨0.5M，压缩系数可以写0.9或者1
 */
+ (NSData *)zipNSDataWithImage:(UIImage *)sourceImage;

/*
 图片的压缩处理
 先进行图片的缩小处理
 然后再进行压处理
 */
+ (NSData *)zipDataWithImage:(UIImage *)sourceImage;

@end
