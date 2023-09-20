#include <wx/wx.h>
#include "windowframe.h"

class App : public wxApp {
public:
	bool OnInit();

};

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	wxImage::AddHandler(new wxPNGHandler);
	WindowFrame* window = new WindowFrame("Chamber");
	window->SetClientSize(1152, 648);
	window->Center();
	window->Show();
	return true;
}