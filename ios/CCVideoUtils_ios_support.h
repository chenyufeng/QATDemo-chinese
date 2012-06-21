#import <Foundation/Foundation.h>  
#import <MediaPlayer/MediaPlayer.h> 
#import "cocos2d.h" 

@interface CCVideoUtils_iOS : NSObject { 
	MPMoviePlayerController* movieplayer;
	cocos2d::CCObject*			m_pTarget; 
	cocos2d::SEL_CallFuncN      m_Selector; 
	cocos2d::CCNode*            m_pObject; 
} 

+(CCVideoUtils_iOS*) shared; 
+(void)purge; 
+(void)updateOrientation:(UIInterfaceOrientation)interfaceOrientation;
    
-(void)playVideo:(NSString*)filename showControls:(bool)showControls skipByTap:(bool)skipByTap target:(cocos2d::CCObject*) target 
           selector:(cocos2d::SEL_CallFuncN)selector withObject:(cocos2d::CCNode*)object; 
    
@end 


@interface MyMovieViewController: MPMoviePlayerViewController {
	
}

@end