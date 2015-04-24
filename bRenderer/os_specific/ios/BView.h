#ifndef B_BVIEW_H
#define B_BVIEW_H

#import <UIKit/UIKit.h>

#include "../../headers/Renderer_GL.h"

@class EAGLContext;

/* This is a UIView specifically designed for bRenderer and needs to be added to a window in your project */
@interface BView : UIView
{
@private
    GLint width;
    GLint height;
    
    // the time when the app was started
    double initialTime;
    
    GLuint defaultFramebuffer, colorRenderbuffer, depthRenderbuffer;
    
    // the display link is used to create a render loop
    CADisplayLink *displayLink;
    CAEAGLLayer *eaglLayer;
}

/* The OpenGL context with autogenerated getter and setter */
@property (nonatomic, retain) EAGLContext *context;

/* Control the renderer from within Objective-C code using these functions */
- (void) runRenderer;
- (void) stopRenderer;
- (void) terminateRenderer;

- (int) getViewWidth;
- (int) getViewHeight;
- (int) getViewPositionX;
- (int) getViewPositionY;

- (void) setFullscreen;
- (void) setViewWidth:(GLint)w setViewHeight:(GLint)h;
- (void) setViewPositionX:(GLint)x setViewPositionY:(GLint)y;
@end

#endif /* defined(B_BVIEW_H) */