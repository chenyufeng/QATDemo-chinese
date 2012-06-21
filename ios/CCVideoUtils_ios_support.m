#import "CCVideoUtils_ios_support.h" 
#import <MediaPlayer/MediaPlayer.h> 
  
@implementation CCVideoUtils_iOS 
    
static CCVideoUtils_iOS* shared_ = NULL; 
 
+(CCVideoUtils_iOS*) shared { 
   if (!shared_) { 
       shared_ = [[CCVideoUtils_iOS alloc] init]; 
   } 
return shared_; 
} 
   
+(void)purge { 
	[shared_ release];
	shared_ = nil; 
} 

MPMoviePlayerController *playerViewController=NULL; 
int g_iPlayVideoState=0; 

+(void)updateOrientation:(UIInterfaceOrientation)interfaceOrientation {
	if(playerViewController)
	{
		if (interfaceOrientation == UIInterfaceOrientationLandscapeLeft) {
			[playerViewController.view setCenter:CGPointMake(384, 512)]; 
			[playerViewController.view setTransform:CGAffineTransformMakeRotation(-M_PI / 2)]; 
		}
		else if (interfaceOrientation == UIInterfaceOrientationLandscapeRight) {
			[playerViewController.view setCenter:CGPointMake(384, 512)]; 
			[playerViewController.view setTransform:CGAffineTransformMakeRotation(M_PI / 2)]; 
		}
	}
}
  
- (void)playVideo:(NSString*)filename showControls:(bool)showControls skipByTap:(bool)skipByTap  target:(cocos2d::CCObject*) target 
           selector:(cocos2d::SEL_CallFuncN)selector withObject:(cocos2d::CCNode*)object 
{ 
    CCLOGINFO(@"PlayVideo start"); 
  
	g_iPlayVideoState = 2; 
        
	NSURL* url; 
    
    if ([filename hasPrefix:@"http://"]) { 
        url = [NSURL URLWithString:filename]; 
    } else { 
        NSString* urlString = [[NSBundle mainBundle] pathForResource:filename ofType:nil]; 
        url = [NSURL fileURLWithPath:urlString]; 
    } 
        
    //CGRect rScreen; 
    //rScreen.origin.x = 0; 
    //rScreen.origin.y = 0; 
    //rScreen.size.width = 1024; 
    //rScreen.size.height = 768; 
    //rScreen = CGRect::CGRectMake(0,0, 480, 320);         
     
    MPMoviePlayerViewController *vc = [[MyMovieViewController alloc]  
                                        initWithContentURL:url]; 
	MPMoviePlayerController *player2 = vc.moviePlayer;
	player2.initialPlaybackTime = -1.0;
    
    [[NSNotificationCenter defaultCenter]  
      addObserver:self 
	  selector:@selector(movieFinishedCallback:) 
      name:MPMoviePlayerPlaybackDidFinishNotification 
      object:player2]; 
    if ([player2 respondsToSelector:@selector(setUseApplicationAudioSession:)]) { 
        [player2 setUseApplicationAudioSession: NO]; 
    } 
    playerViewController = player2; 
    m_pTarget = target; 
    m_Selector = selector; 
    m_pObject = object; 
     
    UIView* currentView = [UIApplication sharedApplication].keyWindow; 
	UIInterfaceOrientation orientation = [[UIApplication sharedApplication] statusBarOrientation];
     
    //---play partial screen--- 
    //    player2.view.frame = currentView.frame; 
    
   // if ([player2 respondsToSelector:@selector(setFullscreen:animated:)]) {   
        player2.fullscreen = true; 
		//player2.scalingMode = MPMovieScalingModeAspectFit;
        // Use the new 3.2 style API   
        player2.controlStyle = showControls ? MPMovieControlStyleFullscreen : MPMovieControlStyleNone; 
		
		cocos2d::CCSize size = cocos2d::CCDirector::sharedDirector()->getWinSize();
        [player2.view setBounds:CGRectMake(0, 0, size.width, size.height)]; 
	if (orientation == UIInterfaceOrientationLandscapeLeft) {
		[player2.view setCenter:CGPointMake(384, 512)]; 
		[player2.view setTransform:CGAffineTransformMakeRotation(-M_PI / 2)]; 
	}
	else {
		[playerViewController.view setCenter:CGPointMake(384, 512)]; 
		[playerViewController.view setTransform:CGAffineTransformMakeRotation(M_PI / 2)]; 
	}
		[player2.view setCenter:CGPointMake(384, 512)]; 
		[player2.view setTransform:CGAffineTransformMakeRotation(M_PI / 2)]; 
         
        player2.movieSourceType = MPMovieSourceTypeFile; 
        [player2 prepareToPlay]; 
    //} else { 
        // Use the old 2.0 style API  
    //    player2.movieControlMode = showControls ? MPMovieControlModeDefault : MPMovieControlModeHidden; 
    //} 
     
    if ([player2 respondsToSelector:@selector(view)]) { 
        if (!showControls && skipByTap) { 
            UIButton* skipButton = [UIButton buttonWithType:UIButtonTypeCustom]; 
            [skipButton addTarget:self action:@selector(skip:) forControlEvents:UIControlEventTouchUpInside]; 
            skipButton.frame = CGRectMake(0, 0, player2.view.bounds.size.width, player2.view.bounds.size.height); 
            //        [skipButton setBackgroundColor:[UIColor redColor]]; 
             
           [player2.view addSubview:skipButton]; 
        } 
         
        
        [currentView addSubview: vc.view]; 
        player2.shouldAutoplay=TRUE; 
    } 
     
    //---play movie--- 
    [player2 play]; 
	
    [[UIApplication sharedApplication] setStatusBarOrientation:orientation]; 
    [[UIApplication sharedApplication] setStatusBarHidden:YES]; 
    
    g_iPlayVideoState = 1; 
     
    CCLOGINFO(@"PlayVideo done"); 
} 
 
- (void)skip:(UIButton*)button { 
    [playerViewController stop]; 
} 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
- (void) movieFinishedCallback:(NSNotification*) aNotification  
{ 
    CCLOGINFO(@"movieFinishedCallback"); 
    MPMoviePlayerController *player = [aNotification object]; 
    [[NSNotificationCenter defaultCenter] removeObserver:self name:MPMoviePlayerPlaybackDidFinishNotification object:player];     
     
	[player stop];
    if ([player respondsToSelector:@selector(view)]) { 
        [player.view removeFromSuperview]; 
		[player.view release];
    } 
    //[player release];   
	player = nil;  
    g_iPlayVideoState = 0; 
    
    [[UIApplication sharedApplication] setStatusBarHidden:YES]; 
     
    
    CCLOGINFO(@"movieFinishedCallback done"); 
     
    playerViewController = nil; 
     
     
    if (m_pTarget && m_Selector) { 
		cocos2d::CCNode* pTarget = (cocos2d::CCNode*)m_pTarget;
		(pTarget->*(m_Selector))(m_pObject); 
	} 
     
} 
  
@end


@implementation MyMovieViewController

// Override to allow orientations other than the default portrait orientation.
- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
	if (interfaceOrientation == UIInterfaceOrientationLandscapeLeft) {
		[playerViewController.view setCenter:CGPointMake(384, 512)]; 
		[playerViewController.view setTransform:CGAffineTransformMakeRotation(-M_PI / 2)]; 
	 }
	 else if (interfaceOrientation == UIInterfaceOrientationLandscapeRight) {
		 [playerViewController.view setCenter:CGPointMake(384, 512)]; 
		 [playerViewController.view setTransform:CGAffineTransformMakeRotation(M_PI / 2)]; 
	 }
	return UIInterfaceOrientationIsLandscape( interfaceOrientation );
	//return UIInterfaceOrientationIsPortrait(interfaceOrientation);
}

@end
 
