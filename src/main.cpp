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
public:
    //view instances
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

//Window resize event listener, enables an overlay in the window to resize dynamically
class ResizeWindowListener : public WindowListener {
public:
    //minimal width/height to shrink to
    uint32_t min_width;
    uint32_t min_height;
    //view instance to apply on
    RefPtr<Overlay> overlay;
    ResizeWindowListener(RefPtr<Overlay> o, uint32_t min_width, uint32_t min_height) {
        this->overlay = o;
        this->min_width = min_width;
        this->min_height = min_height;
    }

    void OnClose() override {

    }

    void OnResize(uint32_t width, uint32_t height) override {
        overlay.get()->Resize(max(min_width, width), max(min_height, height));
    }
};

int main(int argc, char *argv[]){
    
    //***********************************
    //APPLICATION SETUP
    //***********************************

    //create main app
    auto main_app = App::Create();
    //create main window to fit as a fullscreen resolution size
    Monitor* main_monitor = main_app->main_monitor();
    auto main_window = Window::Create(main_monitor, floor(main_monitor->width() / main_monitor->scale() / 1.3),
        floor(main_monitor->height() / main_monitor->scale() / 1.3), false, kWindowFlags_Borderless);
    //set title of this window
    char title_buf[64];
    sprintf_s(title_buf, "Pytr Renderer [%s]", VERSION_NAME);
    main_window->SetTitle(title_buf);
    //set window to app
    main_app->set_window(main_window);
    //create myapp instance
    MyApp my_app(main_window);
    //set up resize listener for main contents
    ResizeWindowListener* main_wind_listener = new ResizeWindowListener(my_app.overlay_, main_window->width() / 2, main_window->height() / 2);
    main_window->set_listener(main_wind_listener);

    //***********************************
    //APPLICATION RUN
    //***********************************

    //run
    main_app->Run();

    return 0;
}