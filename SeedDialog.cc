#define _GLIBCXX_USE_CXX11_ABI 0
#include "SeedDialog.h"
#include <iostream>

SeedDialog::SeedDialog() {}

SeedDialog::SeedDialog(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder)
: Gtk::Dialog(cobject), m_refGlade(builder) {
	// signal handelrs
	m_refGlade->get_widget("seed_spin", m_pSeed);

	m_refGlade->get_widget("file_new", m_pStart);
	if (m_pStart) {
		m_pStart->signal_activate().connect(sigc::mem_fun(*this, &SeedDialog::on_start));
	}
	m_refGlade->get_widget("file_quit", m_pCancel);
	if (m_pCancel) {
		m_pCancel->signal_activate().connect(sigc::mem_fun(*this, &SeedDialog::on_cancel));
	}
}

SeedDialog::~SeedDialog() {}


void SeedDialog::on_start() {

  // starts new game
}

void SeedDialog::on_cancel() {
	hide();
}