#include "main.h"
#include "AppDelegate.h"
#include "cocos2d.h"

USING_NS_CC;
/*
int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // create the application instance
    AppDelegate app;
    return Application::getInstance()->run();
}
*/

int main()
{
    // create the application instance
    AppDelegate app;
    //cocos2d::CCEGLView* eglView;
    //eglView->init("TestCPP",960,540);
    return Application::getInstance()->run();
}
