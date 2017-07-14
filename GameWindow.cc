#define _GLIBCXX_USE_CXX11_ABI 0
#include "GameWindow.h"
#include <iostream>

GameWindow::GameWindow() {
  set_title("Gtk::FontChooserDialog example");

}

GameWindow::GameWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder)
: Gtk::Window(cobject), m_refGlade(builder) {
	// signal handelrs
	m_refGlade->get_widget("file_new", m_pNew);
	if (m_pNew) {
		m_pNew->signal_activate().connect(sigc::mem_fun(*this, &GameWindow::on_file_new));
	}
	m_refGlade->get_widget("file_new_seed", m_pNewSeed);
	if (m_pNewSeed) {
		m_pNewSeed->signal_activate().connect(sigc::mem_fun(*this, &GameWindow::on_file_new_seed));
	}
	m_refGlade->get_widget("file_quit", m_pQuit);
	if (m_pQuit) {
		m_pQuit->signal_activate().connect(sigc::mem_fun(*this, &GameWindow::on_file_quit));
	}
}

GameWindow::~GameWindow() {}


void GameWindow::on_file_new() {
	std::cout << "file new" << std::endl;
  // starts new game
}

void GameWindow::on_file_new_seed() {
    // starts new game with seed
	auto refBuilder = Gtk::Builder::create();
	try
	{
		refBuilder->add_from_file("new_seed.glade");
	}
	catch(const Glib::FileError& ex)
	{
		std::cerr << "FileError: " << ex.what() << std::endl;
		return;
	}
	catch(const Glib::MarkupError& ex)
	{
		std::cerr << "MarkupError: " << ex.what() << std::endl;
		return;
	}
	catch(const Gtk::BuilderError& ex)
	{
		std::cerr << "BuilderError: " << ex.what() << std::endl;
		return;
	}
	Gtk::Dialog* pDialog = nullptr;
	refBuilder->get_widget("seed_dialog", pDialog);
	if (pDialog) {
		int result = pDialog->run();
	}

}

void GameWindow::on_file_quit() {
	hide();
}