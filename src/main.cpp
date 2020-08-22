#include <stdio.h>

//global info
#include "global_info.h"

//UI Pipeline (Ultralight HTML Engine)
#include <AppCore/App.h>
#include <AppCore/Window.h>
#include <AppCore/Overlay.h>
#include <AppCore/Monitor.h>

int main(int argc, char *argv[]){
    
    using namespace ultralight;
    //create main app
    Ref<App> main_app = App::Create();
    //create main window to fit as a fullscreen resolution size
    Monitor* main_monitor = main_app->main_monitor();
    Ref<Window> main_window = Window::Create(main_monitor, main_monitor->width() / main_monitor->scale(),
        main_monitor->height() / main_monitor->scale(), false, kWindowFlags_Maximizable);
    //set title of this window
    char title_buf[64];
    sprintf_s(title_buf, "Pytr Renderer [%s]", VERSION_NAME);
    main_window->SetTitle(title_buf);
    //set window to app
    main_app->set_window(main_window);
    ////set an overlay
    Ref<Overlay> overlay = Overlay::Create(main_window, main_window->width(), main_window->height(), 0, 0);
    ////specify overlay to to read from our homepage html
    overlay->view()->LoadHTML(read_html_file(INDEX_HTML).data());
    //run
    main_app->Run();

    return 0;
}