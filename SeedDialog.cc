#define _GLIBCXX_USE_CXX11_ABI 0
#include "SeedDialog.h"
#include <iostream>

SeedDialog::SeedDialog() {}

SeedDialog::SeedDialog(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder)
: Gtk::Window(cobject), m_refGlade(builder) {
	// signal handelrs
	m_refGlade->get_widget("seed_spin", m_pSeed);

	m_refGlade->get_widget("file_new", m_pNew);
	if (m_pNew) {
		m_pNew->signal_activate().connect(sigc::mem_fun(*this, &GameWindow::on_file_new));
	}
	m_refGlade->get_widget("file_quit", m_pQuit);
	if (m_pQuit) {
		m_pQuit->signal_activate().connect(sigc::mem_fun(*this, &GameWindow::on_file_quit));
	}
}

SeedDialog::~SeedDialog() {}


void SeedDialog::on_start() {

  // starts new game
}

void SeedDialog::on_cancel() {
	hide();
}