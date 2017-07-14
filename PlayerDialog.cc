#define _GLIBCXX_USE_CXX11_ABI 0
#include "PlayerDialog.h"
#include <iostream>

PlayerDialog::PlayerDialog() {}

PlayerDialog::PlayerDialog(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder)
: Gtk::Dialog(cobject), m_refGlade(builder) {
	// signal handelrs
	m_refGlade->get_widget("human_button", m_pHuman);
	if (m_pHuman) {
		m_pHuman->signal_activate().connect(sigc::mem_fun(*this, &PlayerDialog::on_human));
	}
	m_refGlade->get_widget("computer_button", m_pComputer);
	if (m_pComputer) {
		m_pComputer->signal_activate().connect(sigc::mem_fun(*this, &PlayerDialog::on_computer));
	}
}

PlayerDialog::~PlayerDialog() {}


void PlayerDialog::on_computer() {
	hide();
}

void PlayerDialog::on_human() {
	hide();
}