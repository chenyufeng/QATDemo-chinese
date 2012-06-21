//
//  RootViewController.mm
//  QATDemo
//
//  Created by chenyf on 4/3/12.
//  Copyright __MyCompanyName__ 2012. All rights reserved.
//

#import "RootViewController.h"
#import "cocos2d.h"
#import "CCVideoUtils_ios_support.h"

@implementation RootViewController

/*
 // The designated initializer.  Override if you create the controller programmatically and want to perform customization that is not appropriate for viewDidLoad.
- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    if ((self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil])) {
        // Custom initialization
    }
    return self;
}
*/

/*
// Implement loadView to create a view hierarchy programmatically, without using a nib.
- (void)loadView {
}
*/

/*
// Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
- (void)viewDidLoad {
    [super viewDidLoad];
}
 
*/
// Override to allow orientations other than the default portrait orientation.
- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
	/*if (interfaceOrientation == UIInterfaceOrientationLandscapeLeft) {
		cocos2d::CCDirector::sharedDirector()->setDeviceOrientation(cocos2d::kCCDeviceOrientationLandscapeRight);
	}
	else if (interfaceOrientation == UIInterfaceOrientationLandscapeRight) {
		cocos2d::CCDirector::sharedDirector()->setDeviceOrientation(cocos2d::kCCDeviceOrientationLandscapeLeft);
	}
	return NO;*/
	[CCVideoUtils_iOS updateOrientation: interfaceOrientation];
	return UIInterfaceOrientationIsLandscape( interfaceOrientation );
	//return UIInterfaceOrientationIsPortrait(interfaceOrientation);
}

- (void)willRotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration {
	if(UIInterfaceOrientationIsLandscape(toInterfaceOrientation)) {
		cocos2d::CCEGLView * pView = cocos2d::CCDirector::sharedDirector()->getOpenGLView();
		pView->setViewPortInPoints(0,0,1024,768);
	}
}

- (void)didReceiveMemoryWarning {
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
	cocos2d::CCDirector::sharedDirector()->purgeCachedData();
}

- (void)viewDidUnload {
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}


- (void)dealloc {
    [super dealloc];
}


@end
