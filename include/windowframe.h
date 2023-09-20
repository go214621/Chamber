#pragma once
#include <wx/wx.h>
#include <wx/notebook.h>
#include <wx/hyperlink.h>

class WindowFrame : public wxFrame {
public:
	wxPanel* panel;
	wxNotebook* notebook;

	// functions
	WindowFrame(const wxString& title);
	void makeBold(wxStaticText*);
};

enum PageID {
	PageID_CellOverview,
	PageID_Organelles,
	PageID_OrganellesContinued,
	PageID_CellFunctions, // will also contain misc functions in more detail
	PageID_About
};

void WindowFrame::makeBold(wxStaticText* text) {
	wxFont font = text->GetFont();
	font.SetWeight(wxFONTWEIGHT_BOLD);
	text->SetFont(font);
}

// ctor



WindowFrame::WindowFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(1152, 648), wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)) {

	panel = new wxPanel(this);
	
	// tabs
	notebook = new wxNotebook(panel, wxID_ANY);
	notebook->AddPage(new wxNotebookPage(notebook, -1), "Cell Overview");
	notebook->AddPage(new wxNotebookPage(notebook, -1), "Organelles");
	notebook->AddPage(new wxNotebookPage(notebook, -1), "Organelles Continued");
	notebook->AddPage(new wxNotebookPage(notebook, -1), "Cell Functions");
	notebook->AddPage(new wxNotebookPage(notebook, -1), "About");
	notebook->SetSize(GetSize());
	notebook->Layout();


	wxStaticText* cellDefinition = new wxStaticText(notebook->GetPage(PageID_CellOverview), wxID_ANY, "Cells: the basic STRUCTURAL and FUNCTIONAL units of every organism.", wxPoint(10, 10));
	wxStaticText* cellComponents = new wxStaticText(notebook->GetPage(PageID_CellOverview), wxID_ANY, "All cells:\n1. are bound by a plasma membrane\n2. contain cytosol\n3. contain chromosomes\n4. contain ribosomes", wxPoint(10, 40));
	wxStaticText* cellTypes = new wxStaticText(notebook->GetPage(PageID_CellOverview), wxID_ANY, "There are two types of cells: PROKARYOTES and EUKARYOTES.", wxPoint(10, 130));
	
	wxStaticText* prokaryotes = new wxStaticText(notebook->GetPage(PageID_CellOverview), wxID_ANY, "Prokaryotes", wxPoint(10, 150));
	makeBold(prokaryotes);
	wxStaticText* prokaryoteDesc = new wxStaticText(notebook->GetPage(PageID_CellOverview), wxID_ANY, "- Bacteria and Archaea\n- DNA is in the nucleoid region\n- Generally smaller than Eukaryotes", wxPoint(10, 165));

	wxStaticText* eukaryotes = new wxStaticText(notebook->GetPage(PageID_CellOverview), wxID_ANY, "Eukaryotes", wxPoint(250, 150));
	makeBold(eukaryotes);
	wxStaticText* eukaryotesDesc = new wxStaticText(notebook->GetPage(PageID_CellOverview), wxID_ANY, "- Protists, Fungi, Animals, Plants\n- DNA in the nucleus\n- Contain membrane-bound organelles", wxPoint(250, 165));

	wxStaticBitmap* cellComponentsImage = new wxStaticBitmap(notebook->GetPage(PageID_CellOverview), wxID_ANY, wxBitmap("res/cell_components.png", wxBITMAP_TYPE_PNG), wxPoint(500, 10));
	wxStaticBitmap* cellTypesImage = new wxStaticBitmap(notebook->GetPage(PageID_CellOverview), wxID_ANY, wxBitmap("res/cell_types.png", wxBITMAP_TYPE_PNG), wxPoint(500, 250));
	

	// organelles

	wxStaticText* organelleDefinition = new wxStaticText(notebook->GetPage(PageID_Organelles), wxID_ANY, "Organelles: membrane-bound structures in Eukaryotes", wxPoint(10, 10));
	wxStaticText* organelleClasses = new wxStaticText(notebook->GetPage(PageID_Organelles), wxID_ANY, "There are two classifications of organelles: ENDOMEMBRANE and ENERGY.", wxPoint(10, 30));

	wxStaticText* endomembrane = new wxStaticText(notebook->GetPage(PageID_Organelles), wxID_ANY, "Endomembrane", wxPoint(10, 70));
	makeBold(endomembrane);
	wxStaticText* endomembraneDesc = new wxStaticText(notebook->GetPage(PageID_Organelles), wxID_ANY, "- Nuclear Envelope\n- Endoplasmic Reticulum\n- Golgi Complex\n- Lysosomes\n- Vesicles/Vacuoles\n- Plasma Membranes", wxPoint(10, 90));

	wxStaticText* energy = new wxStaticText(notebook->GetPage(PageID_Organelles), wxID_ANY, "Energy", wxPoint(250, 70));
	makeBold(energy);
	wxStaticText* energyDesc = new wxStaticText(notebook->GetPage(PageID_Organelles), wxID_ANY, "- Mitochondria (\"the powerhouse of the cell\")\n- Chloroplasts", wxPoint(250, 90));

	wxStaticBitmap* uniqueCellComponents = new wxStaticBitmap(notebook->GetPage(PageID_Organelles), wxID_ANY, wxBitmap("res/unique_cell_components.png", wxBITMAP_TYPE_PNG), wxPoint(10, 300));

	wxStaticText* nucleus = new wxStaticText(notebook->GetPage(PageID_Organelles), wxID_ANY, "Nucleus - stores the nucleolus.\nNucleolus - stores genetic information (chromosomes). DNA\nCANNOT leave here. rRNA combined with\nproteins form subunits of\nribosomes, which exit through\nnuclear pores.", wxPoint(550, 10));
	wxStaticBitmap* nucleusImage = new wxStaticBitmap(notebook->GetPage(PageID_Organelles), wxID_ANY, wxBitmap("res/organelle_nucleus.png", wxBITMAP_TYPE_PNG), wxPoint(550, 130));
	wxStaticBitmap* nuclearEnvelope = new wxStaticBitmap(notebook->GetPage(PageID_Organelles), wxID_ANY, wxBitmap("res/organelle_nuclear_envelope.png", wxBITMAP_TYPE_PNG), wxPoint(550, 400));

	
}	