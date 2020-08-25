#ifndef UI_CLASSES_H
#define UI_CLASSES_H

#include <AppCore/App.h>
#include <AppCore/Window.h>
#include <AppCore/Overlay.h>

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

//listener for the entire app
class MainAppListener : public AppListener {
public:
    //************************************
    //THE UPDATE LOGIC LOOP OF OUR APP
    //************************************
    void OnUpdate() override {

    }
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

#endif // !UI_CLASSES_H
