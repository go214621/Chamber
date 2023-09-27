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
	static void makeBold(wxStaticText*);
};

enum PageID {
	PageID_CellOverview,
	PageID_Organelles,
	PageID_OrganellesCont,
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

	wxStaticText* compart = new wxStaticText(notebook->GetPage(PageID_Organelles), wxID_ANY, "Compartmentalisation", wxPoint(10, 200));
	makeBold(compart);
	wxStaticText* compartDesc = new wxStaticText(notebook->GetPage(PageID_Organelles), wxID_ANY, "allows for different metabolic reactions to occur in different places, and\n prevents reactions from interfering with each other.", wxPoint(10, 215));

	wxStaticText* energy = new wxStaticText(notebook->GetPage(PageID_Organelles), wxID_ANY, "Energy", wxPoint(250, 70));
	makeBold(energy);
	wxStaticText* energyDesc = new wxStaticText(notebook->GetPage(PageID_Organelles), wxID_ANY, "- Mitochondria (\"the powerhouse of the cell\")\n- Chloroplasts", wxPoint(250, 90));

	wxStaticBitmap* uniqueCellComponents = new wxStaticBitmap(notebook->GetPage(PageID_Organelles), wxID_ANY, wxBitmap("res/unique_cell_components.png", wxBITMAP_TYPE_PNG), wxPoint(10, 300));

	wxStaticText* nucleus = new wxStaticText(notebook->GetPage(PageID_Organelles), wxID_ANY, "Nucleus - stores the nucleolus.\nNucleolus - stores genetic information (chromosomes). DNA\nCANNOT leave here. rRNA combined with proteins form\nsubunits of ribosomes, which exit through nuclear pores.", wxPoint(550, 10));
	wxStaticBitmap* nucleusImage = new wxStaticBitmap(notebook->GetPage(PageID_Organelles), wxID_ANY, wxBitmap("res/organelle_nucleus.png", wxBITMAP_TYPE_PNG), wxPoint(550, 110));
	wxStaticBitmap* nuclearEnvelope = new wxStaticBitmap(notebook->GetPage(PageID_Organelles), wxID_ANY, wxBitmap("res/organelle_nuclear_envelope.png", wxBITMAP_TYPE_PNG), wxPoint(550, 390));

	// organelles, continued



	wxStaticText* ribosomes = new wxStaticText(notebook->GetPage(PageID_OrganellesCont), wxID_ANY, "Ribosomes", wxPoint(10, 10));
	makeBold(ribosomes);
	wxStaticText* ribosomesDesc = new wxStaticText(notebook->GetPage(PageID_OrganellesCont), wxID_ANY, "Comprised of ribosomal RNA and proteins.\nIts function is to synthesise proteins.\nCan be found in one of two locations:\nCytosol and bound either the ER or nuclear envelope.\nProteins made there go outside the cell.", wxPoint(10, 25));

	wxStaticBitmap* ribosomeImage = new wxStaticBitmap(notebook->GetPage(PageID_OrganellesCont), wxID_ANY, wxBitmap("res/organelle_ribosome.png", wxBITMAP_TYPE_PNG), wxPoint(10, 450));

	wxStaticText* er = new wxStaticText(notebook->GetPage(PageID_OrganellesCont), wxID_ANY, "Endoplasmic Reticulum", wxPoint(10, 10));
	makeBold(er);
	wxStaticText* erDesc = new wxStaticText(notebook->GetPage(PageID_OrganellesCont), wxID_ANY, "- Synthesises membranes\n- Compartmentalises the cell to keep proteins\nformed in the rough ER\nThere are two types:\n- ROUGH\n- SMOOTH\nThe rough ER contains ribosomes on its membrane\nThe smooth ER syntehsises lipids, metabolises\ncarbs, and detoxifies the cell.", wxPoint(10, 100));

	wxStaticBitmap* erImage = new wxStaticBitmap(notebook->GetPage(PageID_OrganellesCont), wxID_ANY, wxBitmap("res/organelle_endoplasmic_reticulum.png", wxBITMAP_TYPE_PNG), wxPoint(10, 250));

	wxStaticText* gc = new wxStaticText(notebook->GetPage(PageID_OrganellesCont), wxID_ANY, "Golgi Complex", wxPoint(300, 10));
	makeBold(gc);
	wxStaticText* gcDesc = new wxStaticText(notebook->GetPage(PageID_OrganellesCont), wxID_ANY, "Contains flattened membranous sacs called Cisternae\n- This separates the sacs from the cytosol\n- Each cisternae is not connected\nHas differentiality\nCis face - receives vesicles from ER\nTrans face - Sends vesicles out into cytosol, or into the\nplasma membrane for secretion\nThe golgi complex modifies and sorts materials,\nadds molecular tags, and packages materials to exit the cell.", wxPoint(300, 30));

	wxStaticBitmap* gcImage = new wxStaticBitmap(notebook->GetPage(PageID_OrganellesCont), wxID_ANY, wxBitmap("res/organelle_golgi_complex.png", wxBITMAP_TYPE_PNG), wxPoint(300, 250));

	wxStaticText* lysosome = new wxStaticText(notebook->GetPage(PageID_OrganellesCont), wxID_ANY, "Lysosomes", wxPoint(600, 10));
	makeBold(lysosome);
	wxStaticText* lysosomeDesc = new wxStaticText(notebook->GetPage(PageID_OrganellesCont), wxID_ANY, "Membranous sac with hydrolytic enzymes\nHydro - water\nlytic - break\nThe lysosome hydrolyses macromolecules in the cell\nSimilar to to lysosomes, Peroxisomes\ncatalyse reactions that produce peroxide (H2O2).\nAutophagy allows the cell to renew itself.", wxPoint(600, 30));

	wxStaticBitmap* lysosomeImage = new wxStaticBitmap(notebook->GetPage(PageID_OrganellesCont), wxID_ANY, wxBitmap("res/organelle_lysosome.png", wxBITMAP_TYPE_PNG), wxPoint(600, 250));

	wxStaticText* vacuole = new wxStaticText(notebook->GetPage(PageID_OrganellesCont), wxID_ANY, "Vacuole", wxPoint(900, 10));
	makeBold(vacuole);
	wxStaticText* vacuoleDesc = new wxStaticText(notebook->GetPage(PageID_OrganellesCont), wxID_ANY, "Large vesicles that stem from the ER and Golgi. There are multiple types:\n- Food Vacuole (form in Phagocytosis)\n- Contractile Vacuole\n- Central Vacuole (found in plants)\nThey commonly store water.", wxPoint(900, 30));

	wxStaticBitmap* vacuoleImage = new wxStaticBitmap(notebook->GetPage(PageID_OrganellesCont), wxID_ANY, wxBitmap("res/organelle_central_vacuole.png", wxBITMAP_TYPE_PNG), wxPoint(900, 250));

	// about page, just because
	wxHyperlinkCtrl* github = new wxHyperlinkCtrl(notebook->GetPage(PageID_About), wxID_ANY, "Chamber on GitHub", "https://github.com/go214621/Chamber", wxPoint(10, 10));

}	