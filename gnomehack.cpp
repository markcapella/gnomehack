
// Std C and c++.
#include <stdbool.h>
#include <string>

// Gnome library headers.
#include <gtk/gtk.h>

// Application.
#include "gnomehack.h"

using namespace std;


/** ********************************************************
 ** Module globals and consts.
 **/
GtkApplication* mApp;

GtkWidget* mWindow1;

GtkWidget* mWindow2;

GtkWidget* mConfirmDialog;


/** ********************************************************
 ** Module Entry.
 **/
int main(int argCount, char** argValues) {
    printf("\n%sgnomehack: main() Starts.%s\n",
        COLOR_BLUE, COLOR_NORMAL);

    // Init.
     mApp = gtk_application_new("inc.skyrmion.example",
        G_APPLICATION_FLAGS_NONE);

    // Trigger App start & shutdown routines.
    g_signal_connect(G_OBJECT(mApp), "activate",
        G_CALLBACK(applicationStart), NULL);
    g_signal_connect(G_OBJECT(mApp), "shutdown",
        G_CALLBACK(applicationStop), NULL);

    // Main.
    const int result = g_application_run(G_APPLICATION(mApp),
        argCount, argValues);

    // Uninit.
    g_object_unref(G_OBJECT(mApp));

    printf("\n%sgnomehack: main() Finishes.%s\n",
        COLOR_BLUE, COLOR_NORMAL);
    return result;
}

/** ********************************************************
 ** Application start.
 **/
static void applicationStart(GtkApplication* mApp,
    gpointer user_data) {

    printf("\n%sgnomehack: applicationStart() Starts.%s\n",
        COLOR_GREEN, COLOR_NORMAL);

    createWindow1();

    createWindow2();

    createDialog1();

    printf("\n%sgnomehack: applicationStart() Finishes.%s\n",
        COLOR_GREEN, COLOR_NORMAL);
}

/** ********************************************************
 ** Application stop.
 **/
static void applicationStop(GtkApplication* mApp,
    gpointer user_data) {

    printf("\n%sgnomehack: applicationStop() Starts.%s\n",
        COLOR_GREEN, COLOR_NORMAL);

    printf("\n%sgnomehack: applicationStop() Finishes.%s\n",
        COLOR_GREEN, COLOR_NORMAL);
}

/** ********************************************************
 ** Window 1.
 **/
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

void createWindow1() {
    mWindow1 = gtk_application_window_new(mApp);
    gtk_window_set_wmclass(GTK_WINDOW(mWindow1),
        "gnomehack", "gnomehackwindow1");

    gtk_window_set_default_size(GTK_WINDOW(mWindow1), 300, 200);
    gtk_container_set_border_width(GTK_CONTAINER(mWindow1), 10);

    gtk_window_set_title(GTK_WINDOW(mWindow1), "gnomehackwindow1");
    gtk_window_set_icon_from_file(GTK_WINDOW(mWindow1),
        "/usr/share/icons/hicolor/48x48/apps/gnomehackwindow1.png", NULL);

    gtk_window_move(GTK_WINDOW(mWindow1), 125, 150);
    gtk_widget_show(mWindow1);
}

#pragma GCC diagnostic pop

/** ********************************************************
 ** Window 2.
 **/
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

void createWindow2() {
    mWindow2 = gtk_application_window_new(mApp);
    gtk_window_set_wmclass(GTK_WINDOW(mWindow2),
        "gnomehack", "gnomehackwindow2");

    gtk_window_set_default_size(GTK_WINDOW(mWindow2), 350, 300);
    gtk_container_set_border_width(GTK_CONTAINER(mWindow2), 10);

    gtk_window_set_title(GTK_WINDOW(mWindow2), "gnomehackwindow2");
    gtk_window_set_icon_from_file(GTK_WINDOW(mWindow2),
        "/usr/share/icons/hicolor/48x48/apps/gnomehackwindow2.png", NULL);

    gtk_window_move(GTK_WINDOW(mWindow2), 500, 150);
    gtk_widget_show(mWindow2);
}

#pragma GCC diagnostic pop

/** ********************************************************
 ** Dialog 1.
 **/
void createDialog1() {
    mConfirmDialog =
        (GtkWidget*) g_object_new(GTK_TYPE_MESSAGE_DIALOG,
        "use-header-bar", false, "message-type", GTK_MESSAGE_INFO,
        "buttons", GTK_BUTTONS_NONE, NULL);

    // Remove icon that MessageDialog creates & we don't need.
    if (GTK_IS_BIN(mConfirmDialog)) {
        GtkWidget* child = gtk_bin_get_child(
            GTK_BIN(mConfirmDialog));
        if (child) {
            gtk_container_remove(
                GTK_CONTAINER(mConfirmDialog), child);
        }
    }

    gtk_window_set_title(GTK_WINDOW(mConfirmDialog), "gnomehackdialog1");
    gtk_window_set_icon_from_file(GTK_WINDOW(mConfirmDialog),
        "/usr/share/icons/hicolor/48x48/apps/gnomehackdialog2.png", NULL);
    gtk_widget_set_size_request(GTK_WIDGET(mConfirmDialog), 400, 350);

    gtk_window_move(GTK_WINDOW(mConfirmDialog), 800, 400);
    gtk_widget_show(mConfirmDialog);
}
