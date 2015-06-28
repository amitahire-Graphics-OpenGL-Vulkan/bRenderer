#ifndef PROJECT_MAIN_H
#define PROJECT_MAIN_H

#include "bRenderer.h"

class ProjectMain : public IRenderProject
{
public:
	/* Constructor and Destructor */
    ProjectMain(){}
    virtual ~ProjectMain(){bRenderer::log("ProjectMain delted");}

    /* Initialize the Project */
    void init();
    
	//// RenderProject functions ////

	/* This function is executed when initializing the renderer */
	void initFunction();

	/* Draw your scene here */
	void loopFunction(const double &deltaTime, const double &elapsedTime);

	/* This function is executed when terminating the renderer */
	void terminateFunction();

	//// iOS specific ////

    /* For iOS only: Handle device rotation */
    void deviceRotated();
    
    /* For iOS only: Handle app going into background */
    void appWillResignActive();
    
    /* For iOS only: Handle app coming back from background */
    void appDidBecomeActive();
    
    /* For iOS only: Handle app being terminated */
    void appWillTerminate();
    
private:
    
	/* Helper Functions */
	float randomNumber(float min, float max);

	/* Variables */
	float randomTime;
	float cameraForward, cameraSideward;
	double mouseX, mouseY;
};

#endif /* defined(PROJECT_MAIN_H) */
