
// Color styling.
#define COLOR_RED "\033[0;31m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_BLUE "\033[1;34m"
#define COLOR_NORMAL "\033[0m"


static void applicationStart(GtkApplication* app,
     gpointer user_data);
static void applicationStop(GtkApplication* app,
     gpointer user_data);

void createWindow1();

void createWindow2();

void createDialog1();
