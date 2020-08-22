#include <stdio.h>

//global info
#include "global_info.h"

//UI Pipeline (Ultralight HTML Engine)
#include <AppCore/App.h>
#include <AppCore/Window.h>
#include <AppCore/Overlay.h>
#include <AppCore/Monitor.h>
#include <AppCore/JSHelpers.h>

using namespace ultralight;

//app instance
class MyApp {
    RefPtr<Overlay> overlay_;
    RefPtr<Overlay> inspec_overlay;
public:
    MyApp(Ref<Window> win) {
        ///
        /// Create an Overlay using the same dimensions as our Window.
        ///
        overlay_ = Overlay::Create(win, win->width(), win->height(), 0, 0);

        ///
        /// Load a file from the FileSystem.
        ///
        ///  **IMPORTANT**: Make sure `file:///` has three (3) forward slashes.
        ///
        overlay_->view()->LoadURL("file:///index.html");

        //uncomment this section to do webpage debugging
        //RefPtr<View> inspector_view = overlay_->view()->inspector();
        //inspector_view->Resize(win->width(), win->height() - 500);
        ////create an inspector to debug
        //inspec_overlay = Overlay::Create(win, *inspector_view.get(), 0, 500);
        //inspec_overlay->Focus();
    }

    virtual ~MyApp() {}
};

int main(int argc, char *argv[]){
    
    //***********************************
    //APPLICATION SETUP
    //***********************************

    //create main app
    auto main_app = App::Create();
    //create main window to fit as a fullscreen resolution size
    Monitor* main_monitor = main_app->main_monitor();
    auto main_window = Window::Create(main_monitor, main_monitor->width() / main_monitor->scale() / 1.3,
        main_monitor->height() / main_monitor->scale() / 1.3, false, kWindowFlags_Titled|kWindowFlags_Resizable|kWindowFlags_Maximizable);
    //set title of this window
    char title_buf[64];
    sprintf_s(title_buf, "Pytr Renderer [%s]", VERSION_NAME);
    main_window->SetTitle(title_buf);
    //set window to app
    main_app->set_window(main_window);
    //create myapp instance
    MyApp my_app(main_window);


    //***********************************
    //APPLICATION RUN
    //***********************************

    //run
    main_app->Run();

    return 0;
}